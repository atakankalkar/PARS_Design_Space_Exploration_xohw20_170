// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.4
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef XENCRYPTDECRYPT_H
#define XENCRYPTDECRYPT_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xencryptdecrypt_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 S_axi_bundle_BaseAddress;
} XEncryptdecrypt_Config;
#endif

typedef struct {
    u32 S_axi_bundle_BaseAddress;
    u32 IsReady;
} XEncryptdecrypt;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XEncryptdecrypt_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XEncryptdecrypt_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XEncryptdecrypt_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XEncryptdecrypt_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XEncryptdecrypt_Initialize(XEncryptdecrypt *InstancePtr, u16 DeviceId);
XEncryptdecrypt_Config* XEncryptdecrypt_LookupConfig(u16 DeviceId);
int XEncryptdecrypt_CfgInitialize(XEncryptdecrypt *InstancePtr, XEncryptdecrypt_Config *ConfigPtr);
#else
int XEncryptdecrypt_Initialize(XEncryptdecrypt *InstancePtr, const char* InstanceName);
int XEncryptdecrypt_Release(XEncryptdecrypt *InstancePtr);
#endif

void XEncryptdecrypt_Start(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_IsDone(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_IsIdle(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_IsReady(XEncryptdecrypt *InstancePtr);
void XEncryptdecrypt_EnableAutoRestart(XEncryptdecrypt *InstancePtr);
void XEncryptdecrypt_DisableAutoRestart(XEncryptdecrypt *InstancePtr);

u32 XEncryptdecrypt_Get_a_BaseAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_a_HighAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_a_TotalBytes(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_a_BitWidth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_a_Depth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Write_a_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Read_a_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Write_a_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Read_a_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Get_c1_BaseAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_c1_HighAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_c1_TotalBytes(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_c1_BitWidth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_c1_Depth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Write_c1_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Read_c1_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Write_c1_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Read_c1_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Get_c2_BaseAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_c2_HighAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_c2_TotalBytes(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_c2_BitWidth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_c2_Depth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Write_c2_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Read_c2_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Write_c2_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Read_c2_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Get_m_BaseAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_m_HighAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_m_TotalBytes(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_m_BitWidth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_m_Depth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Write_m_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Read_m_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Write_m_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Read_m_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Get_p_BaseAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_p_HighAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_p_TotalBytes(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_p_BitWidth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_p_Depth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Write_p_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Read_p_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Write_p_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Read_p_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Get_r2_BaseAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_r2_HighAddress(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_r2_TotalBytes(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_r2_BitWidth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Get_r2_Depth(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_Write_r2_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Read_r2_Words(XEncryptdecrypt *InstancePtr, int offset, int *data, int length);
u32 XEncryptdecrypt_Write_r2_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);
u32 XEncryptdecrypt_Read_r2_Bytes(XEncryptdecrypt *InstancePtr, int offset, char *data, int length);

void XEncryptdecrypt_InterruptGlobalEnable(XEncryptdecrypt *InstancePtr);
void XEncryptdecrypt_InterruptGlobalDisable(XEncryptdecrypt *InstancePtr);
void XEncryptdecrypt_InterruptEnable(XEncryptdecrypt *InstancePtr, u32 Mask);
void XEncryptdecrypt_InterruptDisable(XEncryptdecrypt *InstancePtr, u32 Mask);
void XEncryptdecrypt_InterruptClear(XEncryptdecrypt *InstancePtr, u32 Mask);
u32 XEncryptdecrypt_InterruptGetEnabled(XEncryptdecrypt *InstancePtr);
u32 XEncryptdecrypt_InterruptGetStatus(XEncryptdecrypt *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif