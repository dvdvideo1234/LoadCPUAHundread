#include <process.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ARR_LEN 100000000

int iArr[ARR_LEN];

void gotoXY(short int x,short int y)
{
   SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), (COORD){x,y} );
}

void Thread( void* pParams )
{
  int i, num = 0;

  while ( 1 )
  {
    for (i = 0; i < ARR_LEN; i++)
    {
      iArr[i] = (i*(--num))-i;
    }
  }
}

int main( void )
{
  int i = 0, iThr;

  printf("Desired threads count: ");
  scanf("%d",&iThr);
  for(i=0;i<iThr;i++)
  {
      _beginthread( Thread, 1000, NULL );
  }

  printf("Threads allocated !\n");
  i = 0;
  while( 1 )
  {
    gotoXY(0,2);
    printf("Iteration: %d            \n",i++);
  }

  return 0;
}
