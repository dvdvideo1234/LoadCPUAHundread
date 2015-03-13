#include <process.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "main.h"

int iArr[LOADCPU_ARR_LEN];

void gotoXY(short int x,short int y)
{
   SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), (COORD){x,y} );
}

void Thread( void* pParams )
{
  int i, num = 0;

  while(42)
  {
    for (i = 0; i < LOADCPU_ARR_LEN; i++)
    {
      iArr[i] = (i*(--num))-i;
    }
  }
}

int main( void )
{
  int i = 0, iThr;

  if(LOADCPU_RUN_BG)
  {
    ShowWindow(GetForegroundWindow(),SW_HIDE);
    iThr = LOADCPU_THR_CNT;
  }
  else
  {
    printf("Desired threads count: ");
    scanf("%d",&iThr);
  }

  if(iThr <= 0)
  {
    return 0;
  }

  for(i=0;i<iThr;i++)
  {
    _beginthread( Thread, 1000, NULL );
  }

  if(!LOADCPU_RUN_BG)
  {
    printf("Threads allocated !\n");
    i = 0;
  }

  while(42)
  {
    if(!LOADCPU_RUN_BG)
    {
      gotoXY(0,2);
      printf("Iteration: %d            \n",i++);
    }
  }

  return 0;
}
