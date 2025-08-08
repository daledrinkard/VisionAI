/*
 * DROP.c
 *
 *  Created on: Aug 5, 2025
 *      Author: daled
 */


#include "POP.h"

void POP0(void)
{
  R_PFS->PORT[3].PIN[12].PmnPFS_b.PODR = 1;
}
void POP1(void)
{
  R_PFS->PORT[8].PIN[10].PmnPFS_b.PODR = 1;
}
void POP2(void)
{
  R_PFS->PORT[8].PIN[11].PmnPFS_b.PODR = 1;
}
void POP3(void)
{
  R_PFS->PORT[0].PIN[11].PmnPFS_b.PODR = 1;
}

void DROP0(void)
{
  R_PFS->PORT[3].PIN[12].PmnPFS_b.PODR = 0;
}
void DROP1(void)
{
  R_PFS->PORT[8].PIN[10].PmnPFS_b.PODR = 0;
}
void DROP2(void)
{
  R_PFS->PORT[8].PIN[11].PmnPFS_b.PODR = 0;
}
void DROP3(void)
{
  R_PFS->PORT[0].PIN[11].PmnPFS_b.PODR = 0;
}
