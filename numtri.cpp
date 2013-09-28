/*
ID:sachinn2
PROG:numtri
LANG: C++
*/


#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main ()
{
  ofstream fout("numtri.out");
  ifstream fin("numtri.in");

  vector <vector <int> > triangle(1000, vector <int> (1000, -1));

  int num_rows;

  fin >> num_rows;
  int value;

  for(auto int i = 0; i < num_rows; i++)
  {
    for(auto int j = 0; j < (i + 1); j++)
    {
      fin >> value;
      triangle[i][j] = value;
    }
  }

  for(int k = (num_rows - 2); k >= 0; k--)
  {
    for(int l = 0; l < (k + 1); l++)
    {
      if(triangle[k + 1][l] > triangle[k + 1][l + 1])
      {
	triangle[k][l] = triangle[k][l] + triangle[k + 1][l];
      }
      else
      {
	triangle[k][l] = triangle[k][l] + triangle[k + 1][l + 1];
      }
    }
  }
  fout << triangle[0][0] << endl;

  fout.close();
  fin.close();
  return 0;
}


