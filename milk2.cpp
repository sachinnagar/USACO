/*
ID:sachinn2
PROG:milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#define START_TIME 500
#define MAX_TIME (1000000 + 1)

using namespace std;

ofstream fout("milk2.out");
ifstream fin("milk2.in");

void add_into_time_table(unsigned char time_table[],
                         int start_time,
			 int end_time)
{
  for(int i = start_time; i < end_time; i++)
  {
    time_table[i] = 1;
  }
  return;
}

void calculate_largest_milking_and_largest_idle_time(unsigned char time_table[],
                                                     int min,
						     int max)
{
  int max_milking_time = 0;
  int max_idle_time = 0;
  int i = min;
  while(i <= max)
  {
    int max_milking = 0;
    int max_idle = 0;

    while((1 == time_table[i]) &&
          (i <= max))
    {
      max_milking++;
      i++;
    }
    if(max_milking > max_milking_time)
    {
      max_milking_time = max_milking;
    }

    while((0 == time_table[i]) &&
          (i <= max))
    {
      max_idle++;
      i++;
    }
    if(max_idle > max_idle_time)
    {
      max_idle_time = max_idle;
    }
  }

  fout << max_milking_time  <<" "<< max_idle_time << endl; 
}

int main(void)
{
  
  unsigned char time_table[MAX_TIME] = {0};
  int num_farmers;
  int start_time;
  int end_time;
  int min = MAX_TIME;
  int max = 0;

  fin >> num_farmers;

  for(int i = 0; i < num_farmers; i++)
  {
    fin >> start_time;
    fin >> end_time;

    if(start_time < min)
    {
      min = start_time;
    }
    if((end_time - 1) > max)
    {
      max = (end_time - 1);
    }

    add_into_time_table(time_table, 
                        start_time,
			end_time);

  }

  calculate_largest_milking_and_largest_idle_time(time_table,
                                                  min,
						  max);
  return 0;
}

