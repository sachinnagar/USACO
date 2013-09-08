/*
ID:sachinn2
PROG:ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define NAME_LEN
int main(void)
{
  //char comet[NAME_LEN];
  // char group[NMAE_LEN];
  ofstream fout("ride.out");
  ifstream fin("ride.in");

  string comet;
  string group;
  
  fin >> comet;
  fin >> group;
  
  int comet_len = comet.length();
  int group_len = group.length();
  int comet_product = 1;
  int group_product = 1;
  
  for(int i = 0; i < comet_len; i ++)
  {
    comet_product = comet_product * (((char)comet.at(i)) - 64);
  }
  
  for(int i = 0; i < group_len; i ++)
  {
    group_product = group_product * (((char)group.at(i)) - 64);
  }
  
  if((comet_product % 47) == (group_product % 47))
  {
    fout << "GO"<<endl;
  }
  else
  {
    fout << "STAY"<<endl;
  }

  return 0;
}
  
  
  
 
  
