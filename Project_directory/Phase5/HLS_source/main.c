
//#include "luts.h"
#include "lwe.h"
#include "stdio.h"
#include "lwe_original.h"
#include "global.h"


int main()
{
int i;

uint16_t large2[256];
for(i=0;i<256;i++){
	large2[i]=i;
}
uint16_t large3[256];
for(i=0;i<256;i++){
	large3[i]=i;
}
uint16_t large4[256];
for(i=0;i<256;i++){
	large4[i]=i;
}
uint16_t large5[256];
for(i=0;i<256;i++){
	large5[i]=i;
}
uint16_t large6[256];
for(i=0;i<256;i++){
	large6[i]=i;
}
uint16_t large7[256];
for(i=0;i<256;i++){
	large7[i]=i;
}

encryptdecrypt(large2,large3,large4,large5,large6,large7);

printf("bitti");
for(i=0;i<256;i++){
	printf("out :%d\n\r",large3[i]);
}
	return 0;
}

