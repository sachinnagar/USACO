/*
ID:sachinn2
PROG:friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#define START_YEAR 1900
using namespace std;

bool is_leap_year(int num_year)
{
  if(0 == (num_year % 100)) 
  {
    if(0 == (num_year % 400))
    {
      return true;
    }
  }
  else
  {
    if(0 == (num_year % 4))
    {
      return true;
    }
  }
  return false;
}

int main(void)
{
  ofstream fout("friday.out");
  ifstream fin("friday.in");
  int days[7] = {0};
  int months[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
  int num_year;
  fin >> num_year;

  int starting_days = 12;
  int selected_day = 0;
  
  for(int start = START_YEAR; start < (START_YEAR + num_year); start++)
  {
    bool is_leap = is_leap_year(start);
    
    for(int start_mnth = 0; start_mnth < 12; start_mnth++)
    {
      if(2 == start_mnth)
      {
	if(true == is_leap)
	{
	  starting_days = 29;
	}
	else
	{
	  starting_days = 28;
	}
      }
      else if(0 == start_mnth)
      {
	if(START_YEAR == start)
	{
	  starting_days = 12;
	}
	else
	{
	  starting_days = 31;
	}
      }
      else 
      {
	starting_days = months[start_mnth - 1];
      }
      days[((starting_days % 7) + selected_day) % 7]++;
      selected_day = ((starting_days % 7) + selected_day) % 7;
    }
  }

  fout << days[5] <<" ";
  fout << days[6] <<" ";
  fout << days[0] <<" ";
  fout << days[1] <<" ";
  fout << days[2] <<" ";
  fout << days[3] <<" ";
  fout << days[4] <<endl;

  return 0;
}
