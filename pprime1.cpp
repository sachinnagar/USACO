/*
ID:sachinn2
PROG:pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

/* first i will try to genertae all the primes within given range . and then i will iterate over all the generated 
   primes to check whether that number is palindrome or not.
*/

typedef unsigned int UINT;

using namespace std;

void generate_primes(vector <bool> &prime_list, UINT range)
{
  auto UINT x;
  UINT range_sqre = (UINT)sqrt(range);
  for(auto UINT i = 3; i <= range_sqre; i += 2)
  {
    if(true == prime_list[i])
    {
      x = i * i;
      while(x <= range)
      {
	prime_list[x] = false;
	x += i + i;
      }
    }
  }
}

bool is_palindrome(UINT a)
{
  ostringstream cnvrt_strng;
  cnvrt_strng << a;
  string temp = cnvrt_strng.str();
  string tmp = temp;
  reverse(temp.begin(), temp.end());
  
  if(temp.compare(tmp) == 0)
  {
    return true;
  }
  return false;
}
int main(void)
{
  
  ofstream fout("pprime.out");
  ifstream fin("pprime.in");

  UINT first, second;
  fin >> first >> second;

  vector <bool> prime_list((second + 1), true);

  generate_primes(prime_list, second);
 
  if(0 == (first % 2))
  {
    first = first + 1;
  }
  for(auto UINT a = first; a <= second; a += 2)
  {
    if((true == prime_list[a]) &&
       (true == is_palindrome(a)))
    {
      fout << a << endl;
    }
  }

  fin.close();
  fout.close();
      
  return 0;
}

