#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"
#include "chessboard.c"
int main()
{
  int x=0;
  int y=0;
  printf("please enter a length value\n");
  scanf("%d",&x);
  printf("please enter a height value\n");
  scanf("%d",&y);
  chessboardDefine(x,y,0);
  return 0;	
}

