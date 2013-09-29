/*
ID:sachinn2
PROG:hamming
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

bool check_validity_in_list(vector <int> &final_word_list,
                            int start,
			    int D)
{
 
  int list_size = final_word_list.size();
  for(int i = 0; i < list_size; i++)
  {
    bitset <8> xor_bitset(start ^ final_word_list[i]);
    if(D > xor_bitset.count())
    {
      return false;
    }
  }
  return true;
}



int main(void)
{
  ofstream fout("hamming.out");
  ifstream fin("hamming.in");

  int N;
  int B;
  int D;

  fin >> N >> B >> D;

  int max_num_allowed = pow(2, B) - 1;


  vector <int> final_word_list;
  int start = 0;
  int count = 0; 
  bool flag = true;

  while(true == flag)
  {
    if(start == 0)
    {
      final_word_list.push_back(start);
      count++;
    }

    start++;

    if((count == N) || (start > max_num_allowed))
    {
      break;
    }

    if(true == check_validity_in_list(final_word_list, start, D))
    {
      final_word_list.push_back(start);
      count++;
    }
  }

  int list_size = final_word_list.size();

  fout << final_word_list[0];

  for(int a = 1; a < list_size; a++)
  {
    if((a % 10) == 0)
    {
      fout << endl << final_word_list[a];
    }
    else
    {
      fout << " " << final_word_list[a];
    }
  }
  fout << endl;

  fin.close();
  fout.close();
  return 0;
}


