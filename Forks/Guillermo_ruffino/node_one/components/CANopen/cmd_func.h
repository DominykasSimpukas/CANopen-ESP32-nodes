#ifndef __cmd_func_H__
#define __cmd_func_H__

/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
/******************************************************************************
* Exported definitions and macros
******************************************************************************/

/******************************************************************************
* Exported types
******************************************************************************/

/******************************************************************************
* Exported variables
******************************************************************************/

/******************************************************************************
* Prototypes of exported functions
******************************************************************************/
void CMD_Send_Byte_GIMLI_Control    (bool state);
void CMD_Send_Byte_Central_Control  (bool state);
uint8_t CMD_Request_Upload_Status   (void);
void CMD_Send_Byte_Auto_Mode_Toggle (bool state);
float *CMD_Request_Upload_Current_of_selected_motor (uint8_t motor_no);
#endif /*__cmd_func_H__*/