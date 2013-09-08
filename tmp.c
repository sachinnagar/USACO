#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  int x = 3;
  int y = 4;
  int(*arr)[y] = malloc(x*y*sizeof(int));

  int i,j;
  for(i =0; i < 3; i++)
  {
    for(j=0; j< 4;j++)
    {
      arr[i][j] = i;
    }
  }


  for(i =0; i < 3; i++)
  {
    for(j=0; j< 4;j++)
    {
      printf("%d\t",arr[i][j]);
    }
    printf("\n");
  }

  return(0);
}
