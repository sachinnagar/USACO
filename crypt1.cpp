/*
ID:sachinn2
PROG:crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool is_present_in_list(auto int number,
                        auto int numbers,
                        vector <int> const &numbers_list)
{
  for(auto int i = 0; i < numbers; i++)
  {
    if(number == numbers_list[i])
    {
      return true;
    }
  }

  return false;
}

bool is_cryptarithm(auto int first,
                    auto int second,
		    auto int numbers,
		    vector <int> const &numbers_list)
{

  if((false == is_present_in_list((first % 10), numbers, numbers_list)) ||
     (false == is_present_in_list(((first / 10) % 10), numbers, numbers_list)) ||
     (false == is_present_in_list((first / 100), numbers, numbers_list)))
  {
    return false;
  }

  if((false == is_present_in_list((second % 10), numbers, numbers_list)) ||
     (false == is_present_in_list((second / 10), numbers, numbers_list)))
  {
    return false;
  }

  int multiple1 = first * (second % 10);

  if((multiple1 / 1000) >= 1)
    return false;

  int multiple2 = first * (second / 10);

  
  if((multiple2 / 1000) >= 1)
    return false;

  
  if((false == is_present_in_list((multiple1 % 10), numbers, numbers_list)) ||
     (false == is_present_in_list(((multiple1 / 10) % 10), numbers, numbers_list)) ||
     (false == is_present_in_list((multiple1 / 100), numbers, numbers_list)))
  {
    return false;
  }
  
    
  if((false == is_present_in_list((multiple2 % 10), numbers, numbers_list)) ||
     (false == is_present_in_list(((multiple2 / 10) % 10), numbers, numbers_list)) ||
     (false == is_present_in_list((multiple2 / 100), numbers, numbers_list)))
  {
    return false;
  }

  multiple2 = multiple2 * 10;

  int final_result = multiple1 + multiple2;

  if((final_result / 10000) >= 1)
    return false;


  if((false == is_present_in_list((final_result % 10), numbers, numbers_list)) ||
     (false == is_present_in_list(((final_result / 10) % 10), numbers, numbers_list)) ||
     (false == is_present_in_list(((final_result / 100) % 10), numbers, numbers_list)) ||
     (false == is_present_in_list((final_result / 1000), numbers, numbers_list)))
  {
    return false;
  }

  return true;

}

int main(void)
{
  
  ofstream fout("crypt1.out");
  ifstream fin("crypt1.in");

  int numbers;

  vector <int> numbers_list;

  fin >> numbers;

  int number;

  for(auto int index = 0; index < numbers; index++)
  {
    fin >> number;
    numbers_list.push_back(number);
  }

  int unique_sol = 0;

  for(auto int first = 111; first <= 999; first++)
  {
    for(auto int second = 11; second <= 99; second++)
    {
      if(true == is_cryptarithm(first, second, numbers, numbers_list))
      {
	unique_sol++;
      }
    }
  } 


  fout << unique_sol << endl;

  fin.close();
  fout.close();
  return 0;
}

