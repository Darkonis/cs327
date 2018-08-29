#include <stdio.h>

#include <stdlib.h>
#include "chessboard.h"

int isACircle=0;
int *path;
int **chessboard;
int recLevel=0;
void chessboardDefine(int x,int y, int isCircular)//remember to remove isCircular
{
  path=malloc(x*y*sizeof(int));
  chessboard=(int**)malloc(sizeof(int*)*y);
  for(int i=0;i<x;i++)
    {
      for(int k=0;k<y;k++)
	{
	  chessboard[i][k]=0;//initilizes the chessboard
	}
    }
  makeAMove(0,0,x,y);//begin recursion
}

void makeAMove(int xPos,int yPos,int xMax,int yMax)
  {
    visit(xPos,yPos);//mark this point as visited and increment the recursion level
  if(recLevel==xMax*yMax-1)
    {
      //if the recursion has reached the point where all points must have been hit print the path
      char outpath[xMax*yMax*2];
      for(int i =0;i<xMax*yMax;i+=2)
	{
	  outpath[i]=path[i];
	  outpath[i+1]=',';
	}
      printf("%s", outpath);//print the path to this point
    }
  
  
  if(xPos+3<xMax) // condition three right 1 up
    {
      if(yPos-1>=0)
	{
	  if(chessboard[xPos+3][yPos-1]==0)
	    {
	      makeAMove(xPos+3,yPos-1,xMax,yMax);
	    }
	}
    }
  if(xPos+3<xMax) //condition three right 1 one down
    {
      if(yPos+1<yMax)
        {
          if(chessboard[xPos+3][yPos+1]==0)
            {
              makeAMove(xPos+3,yPos+1,xMax,yMax);
            }
        }
    }
  if(xPos-3>=0)//condition 3 left 1 up
    {
      if(yPos-1>=0)
        {
          if(chessboard[xPos-3][yPos-1]==0)
            {
              makeAMove(xPos-3,yPos-1,xMax,yMax);
            }
        }
    }
    if(xPos-3>=0)//condition three left 1 down
    {
      if(yPos+1<yMax)
        {
          if(chessboard[xPos-3][yPos+1]==0)
            {
              makeAMove(xPos-3,yPos+1,xMax,yMax);
            }
	}
    }
 if(xPos+1<xMax) // condition 1 right 3 up                                                                                                                                                             
    {
      if(yPos-3>=0)
        {
          if(chessboard[xPos+3][yPos-1]==0)
            {
              makeAMove(xPos+3,yPos-1,xMax,yMax);
            }
        }
    }
  if(xPos+1<xMax) //condition 1 right 3 one down                                                                                                                                                        
    {
      if(yPos+3<yMax)
        {
          if(chessboard[xPos+3][yPos+1]==0)
            {
              makeAMove(xPos+3,yPos+1,xMax,yMax);
            }
	}
    }
  if(xPos-1>=0)//condition 1 left 3 up                                                                                                                                                                      
    {
      if(yPos-3>=0)
        {
          if(chessboard[xPos-3][yPos-1]==0)
            {
              makeAMove(xPos-3,yPos-1,xMax,yMax);
            }
	}
    }
    if(xPos-1>=0)//condition 1 left 3 down                                                                                                                                                              
    {
      if(yPos+3<yMax)
        {
          if(chessboard[xPos-3][yPos+1]==0)
            {
              makeAMove(xPos-3,yPos+1,xMax,yMax);
            }
	}
    }

    unvisit(xPos,yPos);
}
void visit(int xPos,int yPos)
{
  
  path[recLevel]=(xPos+1);
  chessboard[xPos][yPos]=1;



  recLevel++;
}
void unvisit(int xPos, int yPos)
{
  chessboard[xPos][yPos]=0;
    recLevel--;
}
