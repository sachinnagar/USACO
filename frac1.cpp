/*
ID:sachinn2
PROG:frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp_fun(pair <int, int>  const &first_pair, pair <int, int> const &second_pair)
{
  int mul = (first_pair.second) * (second_pair.second);

  return (((mul / (first_pair.second)) * (first_pair.first)) < ((mul / (second_pair.second)) * (second_pair.first)));
}

bool search_vector(vector < pair <int, int> > &fraction_list, int size, pair <int, int> const &elem)
{
  int mul;
  for(register int i = 0; i < size; i++)
  {
    mul = (fraction_list[i].second) * (elem.second);
    
    if(((mul / (fraction_list[i].second)) * (fraction_list[i].first)) ==  ((mul / (elem.second)) * (elem.first)))
    {
      return true;
    }
  }
  return false;
}

int gcd(int a, int b)
{
  if(a%b == 0) 
  {
    return b;
  }
  return gcd(b, a%b);
}

int main(void)
{
  
  ofstream fout("frac1.out");
  ifstream fin("frac1.in");

  vector < pair < int, int > > fraction_list;
  pair <int, int> fraction;

  int num;
  fin >> num;

  fraction = make_pair(0, 1);
  fraction_list.push_back(fraction);



  for(register int numen = 1; numen < num; numen++)
  {
    for(register int denom = num; denom >= 1; denom--)
    {
      if(gcd(numen, denom) > 1)
      {
	continue;
      }
      if(denom < numen)
      {
	break;
      }
      fraction = make_pair(numen, denom);
      fraction_list.push_back(fraction);
    }
  }

  if(num == 1)
  {
    fraction = make_pair(1, 1);
    fraction_list.push_back(fraction);
  }
  sort(fraction_list.begin(), fraction_list.end(), cmp_fun);

  for(vector < pair < int, int > > ::iterator it = fraction_list.begin(); it != fraction_list.end(); it++)
  {
    fout << it->first << "/" << it->second << endl;

  }
  fin.close();
  fout.close();
  return 0;
}

