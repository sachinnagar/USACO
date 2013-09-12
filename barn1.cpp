/*
ID:sachinn2
PROG:barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
  
  ofstream fout("barn1.out");
  ifstream fin("barn1.in");

  int num_boards;
  int num_stalls;
  int num_cows;

  fin >> num_boards >> num_stalls >> num_cows;

  vector <int> stalls_list((num_stalls + 1), 1);
  vector <int> unsorted_list(num_cows, 0);

  int starting_stall = 0;
  int last_stall = num_stalls;
  int stall_with_cow;
   
  for(int m = 0; m < num_cows; m++)
  {
    fin >> stall_with_cow; 

    unsorted_list[m] = stall_with_cow;
  }

  sort(unsorted_list.begin(), unsorted_list.end());

  for(int i = 0; i < num_cows; i++)
  {
    if(0 == i)
    {
      starting_stall = unsorted_list[i];
    }
    if((num_cows - 1) == i)
    {
      last_stall = unsorted_list[i];
    }

    stalls_list[unsorted_list[i]] = -1;           // stalls which has cows
  }

  vector <int> final_stall_list;           // stalls list after merging stall with cows and without cows.

  int j = starting_stall;

  while(j <= last_stall)
  {
    int cow_pres = 0;
    int cow_not_pres = 0;
    while((-1 == stalls_list[j]) &&
          (j <= last_stall))
    {
      cow_pres += stalls_list[j];
      j++;
    }
    if(cow_pres != 0)
    {
      final_stall_list.push_back(cow_pres);
    }

    while((1 == stalls_list[j]) &&
          (j <= last_stall))
    {
      cow_not_pres += stalls_list[j];
      j++;
    }
    if(cow_not_pres != 0)
    {
      final_stall_list.push_back(cow_not_pres);
    }
  }
  
  int max_boards_req = 0;   // count maximum number of boards required
  int min_stalls_covered = 0;  // count minimum number of stalls covered.
  int final_list_size = final_stall_list.size();
  for(int k = 0; k < final_list_size; k++)
  {
    if(final_stall_list[k] < 0)
    {
      max_boards_req++;
      min_stalls_covered = min_stalls_covered - final_stall_list[k];
    }
  }


  if(max_boards_req <= num_boards)
  {
    fout << min_stalls_covered << endl;
    fin.close();
    fout.close();
    return 0;
  }

  int gap = 1;
  int index;
  bool flag = true;
  while(flag)
  {
    for(index = 0; index < final_list_size; index++)
    {
      if(final_stall_list[index] == gap)
      {
	max_boards_req--;
	min_stalls_covered = min_stalls_covered + gap;

	if(max_boards_req == num_boards)
	{
	  fout << min_stalls_covered << endl;
	  flag = false;
	  break;
	}
      }
    }

    gap++;
  }
  fin.close();
  fout.close();
  return 0;
}

