/*
ID:sachinn2
PROG:sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

int calculate_comp(vector <int> &unsorted_list, 
                   int num_of_items)
{
  int array[4] = {0};
  vector <int> sorted_list;

  for(int a = 0; a < num_of_items; a++)
  {
    array[unsorted_list[a]]++;
  }
  
  int count = 0;

  // calculate direct swap

  for(int i = array[1]; i < (array[1] + array[2]); i++)
  {
    if(unsorted_list[i] == 1)
    {
      for(int j = 0; j < array[1]; j++)
      {
	if(unsorted_list[j] == 2)
	{
	  swap(unsorted_list[i], unsorted_list[j]);
	  count++;
	  break;
	}
      }
    }
  }

  for(int k = (array[1] + array[2]); k < num_of_items; k++)
  {
    if(unsorted_list[k] == 1)
    {
      for(int l = 0; l < array[1]; l++)
      {
	if(unsorted_list[l] == 3)
	{
	  swap(unsorted_list[k], unsorted_list[l]);
	  count++;
	  break;
	}
      }
    }
  }
  for(int m = array[1]; m < (array[1] + array[2]); m++)
  {
    if(unsorted_list[m] == 3)
    {
      for(int n = (array[1] + array[2]); n < num_of_items; n++)
      {
	if(unsorted_list[n] == 2)
	{
	  swap(unsorted_list[m], unsorted_list[n]);
	  count++;
	  break;
	}
      }
    }
  }

  // count indirect swap;
  int indirect_count = 0;

  for(int p = 0; p < num_of_items; p++)
  {
    if(p < array[1])
    {
      if((unsorted_list[p] == 2) || (unsorted_list[p] == 3))
      {
	indirect_count++;
      }
    }
    else if(p < (array[1] + array[2]))
    {
      if((unsorted_list[p] == 1) || (unsorted_list[p] == 3))
      {
	indirect_count++;
      }
    }
    else
    {
      if((unsorted_list[p] == 1) || (unsorted_list[p] == 2))
      {
	indirect_count++;
      }
    }
  }

  int total_min_count = count + (2 * (indirect_count / 3));
  return total_min_count;
}
      
int main(void)
{
  
  ofstream fout("sort3.out");
  ifstream fin("sort3.in");

  vector <int> unsorted_list;
  int num_of_item;
  int num;

  fin >> num_of_item;

  for(register int i = 0; i < num_of_item; i++)
  {
    fin >> num;
    unsorted_list.push_back(num);
  }

  int num_of_min_cmparsion = calculate_comp(unsorted_list, num_of_item);

  fout << num_of_min_cmparsion << endl; 
  fin.close();
  fout.close();
  return 0;
}

