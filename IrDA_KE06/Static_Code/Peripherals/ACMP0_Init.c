/** ###################################################################
 **     Filename    : ACMP0_Init.c
 **     Processor   : MKE06Z128LK4
 **     Abstract    :
 **          This file implements the ACMP0 module initialization
 **          according to the Peripheral Initialization settings, and
 **          defines interrupt service routines prototypes.
 **
 **     Contents    :
 **         Int   - void ACMP0_Init(void);
 **
 **     Copyright : 1997 - 2015 Freescale Semiconductor, Inc.
 **     All Rights Reserved.
 **
 **     Redistribution and use in source and binary forms, with or without modification,
 **     are permitted provided that the following conditions are met:
 **
 **     o Redistributions of source code must retain the above copyright notice, this list
 **       of conditions and the following disclaimer.
 **
 **     o Redistributions in binary form must reproduce the above copyright notice, this
 **       list of conditions and the following disclaimer in the documentation and/or
 **       other materials provided with the distribution.
 **
 **     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 **       contributors may be used to endorse or promote products derived from this
 **       software without specific prior written permission.
 **
 **     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 **     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 **     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 **     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 **     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 **     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 **     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 **     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 **     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 **     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **
 **     http: www.freescale.com
 **     mail: support@freescale.com
 ** ###################################################################*/

/*!
 * @file ACMP0_Init.c
 * @brief This file implements the ACMP0 module initialization according to the
 *        Peripheral Initialization settings, and defines interrupt service
 *        routines prototypes.
 */


/* MODULE ACMP0_Init. */

#include "ACMP0_Init.h"
#include "MKE06Z4.h"
#include "Init_Config.h"

#ifdef __cplusplus
extern "C" {
#endif

void ACMP0_Init(void) {

  ACMP0_CS = 0;

  /* Register 'ACMP0_CS' initialization */
  #ifdef ACMP0_CS_VALUE_1
  ACMP0_CS = ACMP0_CS_VALUE_1;
  #endif

  /* Register 'ACMP0_C1' initialization */
  #ifdef ACMP0_C1_VALUE
  ACMP0_C1 = ACMP0_C1_VALUE;
  #endif

  /* Register 'ACMP0_C2' initialization */
  #ifdef ACMP0_C2_VALUE
  ACMP0_C2 = ACMP0_C2_VALUE;
  #endif

  /* Register 'ACMP0_C0' initialization */
  #ifdef ACMP0_C0_VALUE
  ACMP0_C0 = ACMP0_C0_VALUE;
  #endif

  /* Register 'ACMP0_CS' initialization */
  #if ACMP0_CS_MASK_2
    #if ACMP0_CS_MASK_2 == 0xFF
  ACMP0_CS = ACMP0_CS_VALUE_2;
    #elif ACMP0_CS_MASK_2 == ACMP0_CS_VALUE_2
  ACMP0_CS |= ACMP0_CS_VALUE_2;
    #elif ACMP0_CS_VALUE_2 == 0
  ACMP0_CS &= ~ACMP0_CS_MASK_2;
    #else
  ACMP0_CS = (ACMP0_CS & (~ACMP0_CS_MASK_2)) | ACMP0_CS_VALUE_2;
    #endif
  #elif defined(ACMP0_CS_VALUE_2)
  ACMP0_CS = ACMP0_CS_VALUE_2;
  #endif
}

#ifdef __cplusplus
}
#endif

/* END ACMP0_Init. */

/** ###################################################################
 **
 **     This file is a part of Processor Expert static initialization
 **     library for Freescale microcontrollers.
 **
 ** ################################################################### */
