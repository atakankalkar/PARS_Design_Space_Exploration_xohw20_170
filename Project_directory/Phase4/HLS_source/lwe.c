#include "lwe.h"
#include "luts.h"
#include "stdlib.h"
#include "global.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#define NEW_RND_BOTTOM 1
#define NEW_RND_LARGE 32 - 9
#define NEW_RND_MID 32 - 6
#define Mconst 2401607092007494
#define POLY_MASK_32 0xB4BCD35C
#define POLY_MASK_31 0X7A5BC2E3
typedef unsigned int uint;
unsigned int lfsr32 = 0xABCDE;
unsigned int lfsr31 = 0x23456789;

uint32_t clz(uint32_t x) {

	#pragma HLS PIPELINE II=1
	unsigned n = 0;
	if (x <= 0x0000ffff) n += 16, x <<= 16;
	if (x <= 0x00ffffff) n +=  8, x <<= 8;
	if (x <= 0x0fffffff) n +=  4, x <<= 4;
	if (x <= 0x3fffffff) n +=  2, x <<= 2;
	if (x <= 0x7fffffff) n ++;
	return n;

}

void fwd_ntt2(uint16_t a[]) {
  int i, j, k, m;
  uint32_t u1, t1, u2, t2;
  uint32_t primrt, omega;

  i = 0;
  for (m = 2; m <= M / 2; m = 2 * m) {
#pragma HLS PIPELINE II=1
    primrt = primrt_omega_table[i];
    omega = primrt_omega_table[i + 1];
    i++;

    for (j = 0; j < m; j += 2) {
#pragma HLS loop_flatten
      for (k = 0; k < M; k = k + 2 * m) {
#pragma HLS PIPELINE II=1

        u1 = a[j + k];
        t1 = mod(omega * a[j + k + 1]);

        u2 = a[j + k + m];
        t2 = mod(omega * a[j + k + m + 1]);

        a[j + k] = mod(u1 + t1);
        a[j + k + 1] = mod(u2 + t2);

        a[j + k + m] = mod(u1 - t1);
        a[j + k + m + 1] = mod(u2 - t2);

      }
      omega = omega * primrt;
      omega = mod(omega);
    }
  }

  primrt = FWD_CONST1; // mpz_set_str(primrt,"5118",10);
  omega = FWD_CONST2; // mpz_set_str(omega,"1065",10);
  for (j = 0; j < M / 2; j++) {
#pragma HLS PIPELINE II=1
    t1 = omega * a[2 * j + 1];
    t1 = mod(t1);
    u1 = a[2 * j];
    a[2 * j] = mod(u1 + t1);
    a[2 * j + 1] = mod(u1 - t1);

    omega = omega * primrt;
    omega = mod(omega);
  }
}



uint16_t mod(uint32_t x) {
  int a = (int) x;
#pragma HLS PIPELINE II=1
  uint64_t lowbits = (uint64_t)((uint64_t) Mconst * a)&(uint64_t)(0xFFFFFFFFFFFFFFFF);
   uint32_t lowbits_r =(uint32_t)lowbits;
   uint32_t lowbits_l =(uint32_t)(lowbits>>32);
   uint64_t pp1 =(uint64_t)lowbits_r*MODULUS;
   uint64_t pp2 =(uint64_t)lowbits_l*MODULUS;
   pp1 =(uint32_t)((uint64_t)pp1>>32);
   pp2= (uint64_t)(pp2+pp1);
   int ret3=(uint32_t)((uint64_t)pp2>>32);
   ret3=ret3-((MODULUS-1)&(a>>31));
   if(ret3<0)
 	  ret3+=MODULUS;
  return (uint32_t) ret3;
}

void coefficient_mul2(uint16_t out[M], uint16_t b[], uint16_t c[]) {
  // a = b * c
  int j;

  for (j = 0; j < M; j++) {
#pragma HLS PIPELINE II=1
    out[j] = mod((uint32_t)((uint32_t)b[j] * (uint32_t)c[j]));
  }
}

void coefficient_add2(uint16_t out[M], uint16_t b[M], uint16_t c[M])
{
  // a = b + c
  int j;

  for (j = 0; j < M; j++) {
#pragma HLS PIPELINE II=1
	  out[j] = mod((uint32_t)(b[j] + c[j]));
  }
}
void rearrange2(uint16_t a[M]) {

  uint32_t i;
  uint32_t bit1, bit2, bit3, bit4, bit5, bit6, bit7;
  uint32_t swp_index;

  uint16_t u1, u2;

  for (i = 1; i < M / 2; i++) {
#pragma HLS PIPELINE II=1
    bit1 = i % 2;
    bit2 = (i >> 1) % 2;
    bit3 = (i >> 2) % 2;
    bit4 = (i >> 3) % 2;
    bit5 = (i >> 4) % 2;
    bit6 = (i >> 5) % 2;
    bit7 = (i >> 6) % 2;

#ifdef NTT512
    int bit8 = (i >> 7) % 2;
    swp_index = bit1 * 128 + bit2 * 64 + bit3 * 32 + bit4 * 16 + bit5 * 8 +
                bit6 * 4 + bit7 * 2 + bit8;
#else
    swp_index = bit1 * 64 + bit2 * 32 + bit3 * 16 + bit4 * 8 + bit5 * 4 +
                bit6 * 2 + bit7;
#endif

    if (swp_index > i) {
      u1 = a[2 * i];
      u2 = a[2 * i + 1];

      a[2 * i] = a[2 * swp_index];
      a[2 * i + 1] = a[2 * swp_index + 1];

      a[2 * swp_index] = u1;
      a[2 * swp_index + 1] = u2;
    }
  }
}

void init_lfsrs(void)
{
    lfsr32 = 0xABCDE; //seed values
    lfsr31 = 0x23456789;
}

int shift_lfsr(uint *lfsr,  uint polymonial_mask)
{
	//init_lfsrs();
    int feedback;
#pragma HLS PIPELINE II=1
    feedback = *lfsr & 1;
    *lfsr >>= 1;
    if (feedback == 1)
        *lfsr ^= polymonial_mask;
    return *lfsr;
}


int get_random(void)
{

    /*this random number generator shifts the 32-bit LFSR twice before XORing
      it with the 31-bit LFSR. the bottom 16 bits are used for the random number*/
    shift_lfsr(&lfsr32, POLY_MASK_32);
    return(shift_lfsr(&lfsr32, POLY_MASK_32) ^ shift_lfsr(&lfsr31, POLY_MASK_31));
}

uint32_t get_rand()
		{
	//init_lfsrs();
		  uint32_t rnd = get_random();
		  rnd |= 0x80000000; // set the least significant bit
		  return rnd;
		}

		uint32_t get_rand_basic()
		{
		  return rand();
		}
uint32_t knuth_yao_single_number(uint32_t *rnd, int * sample_in_table)
{
  int distance;
  int row, column;

  uint32_t index, sample, sample_msb;

#ifdef DEBUG_PRINTF
  printf("Start rnd:%x\n", *rnd);
#endif
  index = (*rnd) & 0xff;
  (*rnd) = (*rnd) >> 8;

  sample = lut1[index]; // M elements in lut1
  sample_msb = sample & 16;
  if (sample_msb == 0) // lookup was successful
  {
    if ((*rnd) == NEW_RND_BOTTOM) {
      (*rnd) = get_rand();
    }
    sample = sample & 0xf;
    if ((*rnd) & 1)
      sample = (MODULUS - sample); // 9th bit in rnd is the sign
    (*rnd) = (*rnd) >> 1;
    // We know that in the next call we will need 8 bits!
    if (clz(*rnd) > (NEW_RND_LARGE)) {
      (*rnd) = get_rand();
    }
#ifdef DEBUG_PRINTF
    printf("lut1:%x\n", sample);
#endif
    *sample_in_table=1;
    return sample;
  } else {
    if (clz(*rnd) > (NEW_RND_MID)) {
      (*rnd) = get_rand();
    }
    distance = sample & KN_DISTANCE1_MASK;
    index = ((*rnd) & 0x1f) + 32 * distance;
    (*rnd) = (*rnd) >> 5;
    if ((*rnd) == NEW_RND_BOTTOM) {
      (*rnd) = get_rand();
    }
    sample = lut2[index]; // 224 elements in lut2
    sample_msb = sample & 32;
    if (sample_msb == 0) // lookup was successful
    {
      sample = sample & 31;
      if ((*rnd) & 1)
        sample = (MODULUS - sample); // 9th bit in rnd is the sign
      (*rnd) = (*rnd) >> 1;
      if (clz(*rnd) > (NEW_RND_LARGE)) {
        (*rnd) = get_rand();
      }
#ifdef DEBUG_PRINTF
      printf("lut2:%x\n", sample);
#endif
      *sample_in_table=1;
      return sample;
    } else {
      // Real knuth-yao bitscanning
      distance = sample & KN_DISTANCE2_MASK;
      for (column = 13; (column < PMAT_MAX_COL); column++) {
#pragma HLS loop_flatten
#pragma HLS PIPELINE II=1
        distance = distance * 2 + ((*rnd) & 1);
        (*rnd) = (*rnd) >> 1;
        if ((*rnd) == NEW_RND_BOTTOM) {
          (*rnd) = get_rand();
        }
#ifdef DEBUG_PRINTF
        printf("rnd:%x, dist:%d, col:%d\n", (*rnd), distance, column);
#endif

        // Read probability-column 0 and count the number of non-zeros
        for (row = 54; row >= 0; row--) {
#pragma HLS PIPELINE II=1
          distance = distance - pmat[row][column];
          if (distance < 0) {
#ifdef DEBUG_PRINTF
            printf("rnd:%d", (*rnd));
#endif
            if ((*rnd) & 1)
              sample = (MODULUS - row);
            else
              sample = row;
            (*rnd) = (*rnd) >> 1;
            if (clz(*rnd) > (NEW_RND_LARGE)) {
              (*rnd) = get_rand();
            }

            *sample_in_table=0;
            return sample;
          }
        }
        // rnd = rnd >> 1;
      }
    }
  }

  *sample_in_table=0;
  return 0xffffffff;
}

void knuth_yao2(uint16_t a[M]) {
  int i;
  uint32_t rnd;
  int sample_in_table;
  rnd = get_rand();
  for (i = 0; i < M / 2; i++) {
#ifdef DISABLE_KNUTH_YAO
    a[2 * i + 1] = 0;
    a[2 * i] = 0;
#else
    a[2 * i] = knuth_yao_single_number(&rnd,&sample_in_table);
    a[2 * i+1] = knuth_yao_single_number(&rnd,&sample_in_table);
#endif
  }
}
void RLWE_enc2(uint16_t a[M], uint16_t c1[M], uint16_t c2[M], uint16_t m[M], uint16_t p[M])
{


  int i;
  uint16_t e1[M], e2[M], e3[M];
  uint16_t encoded_m[M];
  for (i = 0; i < M; i++) {
#pragma HLS PIPELINE II=1
    encoded_m[i] = m[i] * QBY2; // encoding of message
  }

  knuth_yao2(e1);
  	knuth_yao2(e2);
  	knuth_yao2(e3);

  coefficient_add2(e3, e3, encoded_m); // e3 <-- e3 + m

  fwd_ntt2(e1);
  fwd_ntt2(e2);
  fwd_ntt2(e3);

  // m <-- a*e1
  coefficient_mul2(c1, a, e1);  // c1 <-- a*e1
  coefficient_add2(c1, e2, c1); // c1 <-- e2 + a*e1(tmp_m);
  coefficient_mul2(c2, p, e1);  // c2 <-- p*e1
  coefficient_add2(c2, e3, c2); // c2<-- e3 + p*e1

  rearrange2(c1);
  rearrange2(c2);
}
void inv_ntt2(uint16_t a[M]) {
  int j, k, m;
  uint32_t u1, t1, u2, t2;
  uint32_t primrt, omega;
  primrt = 0;

  for (m = 2; m <= M / 2; m = 2 * m) {
#pragma HLS loop_flatten
#pragma HLS PIPELINE II=1
#ifdef NTT512
    switch (m) {
    case 2:
      primrt = 12288;
      break;
    case 4:
      primrt = 10810;
      break;
    case 8:
      primrt = 7143;
      break;
    case 16:
      primrt = 10984;
      break;
    case 32:
      primrt = 3542;
      break;
    case 64:
      primrt = 4821;
      break;
    case 128:
      primrt = 1170;
      break;
    case 256:
      primrt = 5755;
      break;
    }
#else
    switch (m) {
    case 2:
      primrt = 7680;
      break;
    case 4:
      primrt = 3383;
      break;
    case 8:
      primrt = 5756;
      break;
    case 16:
      primrt = 1728;
      break;
    case 32:
      primrt = 7584;
      break;
    case 64:
      primrt = 6569;
      break;
    case 128:
      primrt = 6601;
      break;
    }
#endif

    omega = 1;
    for (j = 0; j < m / 2; j++) {
      for (k = 0; k < M / 2; k = k + m) {
#pragma HLS PIPELINE II=1
        t1 = omega * a[2 * (k + j) + 1];
        t1 = mod(t1);
        u1 = a[2 * (k + j)];
        t2 = omega * a[2 * (k + j + m / 2) + 1];
        t2 = mod(t2);
        u2 = a[2 * (k + j + m / 2)];

        a[2 * (k + j)] = mod(u1 + t1);
        a[2 * (k + j + m / 2)] = mod(u1 - t1);

        a[2 * (k + j) + 1] = mod(u2 + t2);
        a[2 * (k + j + m / 2) + 1] = mod(u2 - t2);
      }
      omega = omega * primrt;
      omega = mod(omega);
    }
  }

  primrt = INVCONST1;
  omega = 1;
  for (j = 0; j < M;) {
#pragma HLS PIPELINE II=1
    u1 = a[j];
    j++;
    t1 = omega * a[j];
    t1 = mod(t1);

    a[j - 1] = mod(u1 + t1);
    a[j] = mod(u1 - t1);
    j++;

    omega = omega * primrt;
    omega = mod(omega);
  }
  uint32_t omega2 = INVCONST2;
  primrt = INVCONST3;
  omega = 1;

  for (j = 0; j < M;) {
#pragma HLS PIPELINE II=1
    a[j] = mod(omega * a[j]);

    a[j] = mod(a[j] * SCALING);

    j++;
    a[j] = mod(omega2 * a[j]);

    a[j] = mod(a[j] * SCALING);
    j++;

    omega = omega * primrt;
    omega = mod(omega);
    omega2 = omega2 * primrt;
    omega2 = mod(omega2);
  }
}

void RLWE_dec2(uint16_t c1[M], uint16_t c2[M], uint16_t r2[M])
{

  coefficient_mul2(c1, c1, r2); // c1 <-- c1*r2
  coefficient_add2(c1, c1, c2); // c1 <-- c1*r2 + c2
  inv_ntt2(c1);

}
void encdec(uint16_t a[M],uint16_t c1[M],uint16_t c2[M],uint16_t m[M],uint16_t p[M],uint16_t r2[M]){

#pragma HLS INTERFACE s_axilite port=r2 bundle=S_AXI_BUNDLE
#pragma HLS INTERFACE s_axilite port=p bundle=S_AXI_BUNDLE
#pragma HLS INTERFACE s_axilite port=m bundle=S_AXI_BUNDLE
#pragma HLS INTERFACE s_axilite port=c2 bundle=S_AXI_BUNDLE
#pragma HLS INTERFACE s_axilite port=c1 bundle=S_AXI_BUNDLE
#pragma HLS INTERFACE s_axilite port=a bundle=S_AXI_BUNDLE
#pragma HLS INTERFACE s_axilite port=return bundle=S_AXI_BUNDLE

	RLWE_enc2(a,c1,c2,m,p);
	RLWE_dec2(c1,c2,r2);

}
