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
#define MAX_NUM 100000000

/* first i will try to genertae all the palindromes keeping in mind that those should be primes, so i can leave even digit for last digit. and then chekc whether that number is prime or not..
*/

typedef unsigned int UINT;

using namespace std;

void generate_one_digit_palindrome(vector <UINT> &palindrome_list) 
{
  for(auto int a = 1; a <= 9; a += 2)
  {
    palindrome_list.push_back(a);
  }
}

void generate_two_digit_palindrome(vector <UINT> &palindrome_list) 
{
  UINT x;

  for(auto int a = 1; a <= 9; a += 2)
  {
    x = (a * 10) + a;
    palindrome_list.push_back(x);
  }
}

void generate_three_digit_palindrome(vector <UINT> &palindrome_list) 
{
  UINT x;

  for(auto int a = 1; a <= 9; a += 2)
  {
    for(auto int b = 0; b <= 9; b++)
    {
      x = (a * 100) + (b * 10) + a;
      palindrome_list.push_back(x);
    }
  }
}


void generate_four_digit_palindrome(vector <UINT> &palindrome_list) 
{
  UINT x;

  for(auto int a = 1; a <= 9; a += 2)
  {
    for(auto int b = 0; b <= 9; b++)
    {
      x = (a * 1000) + (b * 100) + (b * 10) + a;
      palindrome_list.push_back(x);
    }
  }
}


void generate_five_digit_palindrome(vector <UINT> &palindrome_list) 
{
  UINT x;

  for(auto int a = 1; a <= 9; a += 2)
  {
    for(auto int b = 0; b <= 9; b++)
    {
      for(auto int c = 0; c <= 9; c++)
      {
        x = (a * 10000) + (b * 1000) + (c * 100) + (b * 10) + a;
        palindrome_list.push_back(x);
      }
    }
  }
}


void generate_six_digit_palindrome(vector <UINT> &palindrome_list) 
{
  UINT x;

  for(auto int a = 1; a <= 9; a += 2)
  {
    for(auto int b = 0; b <= 9; b++)
    {
      for(auto int c = 0; c <= 9; c++)
      {
        x = (a * 100000) + (b * 10000) + (c * 1000) + (c * 100) + (b * 10) + a;
        palindrome_list.push_back(x);
      }
    }
  }
}

void generate_seven_digit_palindrome(vector <UINT> &palindrome_list) 
{
  UINT x;

  for(auto int a = 1; a <= 9; a += 2)
  {
    for(auto int b = 0; b <= 9; b++)
    {
      for(auto int c = 0; c <= 9; c++)
      {
	for(auto int d = 0; d <= 9; d++)
	{
	  x = (a * 1000000) + (b * 100000) + (c * 10000) + (d * 1000) + (c * 100) + (b * 10) + a;
          palindrome_list.push_back(x);
	}
      }
    }
  }
}

void generate_eight_digit_palindrome(vector <UINT> &palindrome_list) 
{
  UINT x;

  for(auto int a = 1; a <= 9; a += 2)
  {
    for(auto int b = 0; b <= 9; b++)
    {
      for(auto int c = 0; c <= 9; c++)
      {
	for(auto int d = 0; d <= 9; d++)
	{
	  x = (a * 10000000) + (b * 1000000) + (c * 100000) + (d * 10000) + (d * 1000) + (c * 100) + (b * 10) + a;
          palindrome_list.push_back(x);
	}
      }
    }
  }
}

bool is_prime(UINT num)
{
  UINT num_sqrt = (UINT)sqrt(num);

  for(auto UINT i = 3; i <= num_sqrt; i += 2)
  {
    if((num % i) == 0)
    {
      return false;
    }
  }
  return true;
}

int main(void)
{
  
  ofstream fout("pprime.out");
  ifstream fin("pprime.in");

  UINT first, second;
  fin >> first >> second;
  
  // array of function pointers
  void (*palindrome_fun_ptr[9])(vector <UINT> &);

  palindrome_fun_ptr[1] = generate_one_digit_palindrome;
  palindrome_fun_ptr[2] = generate_two_digit_palindrome;
  palindrome_fun_ptr[3] = generate_three_digit_palindrome;
  palindrome_fun_ptr[4] = generate_four_digit_palindrome;
  palindrome_fun_ptr[5] = generate_five_digit_palindrome;
  palindrome_fun_ptr[6] = generate_six_digit_palindrome;
  palindrome_fun_ptr[7] = generate_seven_digit_palindrome;
  palindrome_fun_ptr[8] = generate_eight_digit_palindrome;

  vector <UINT> palindrome_list;

  // calculate the length of two given numbers
  ostringstream cnvrt_strng1;
  cnvrt_strng1 << first;
  string first1 = cnvrt_strng1.str();

  int first_size = first1.length();

  ostringstream cnvrt_strng2;
  cnvrt_strng2 << second;
  string second1 = cnvrt_strng2.str();

  int second_size = second1.length();
   
  if(second == MAX_NUM)
  {
    second_size--;
  }

  // generate palindromes whose length is of length form first to second
  for(auto int index = first_size; index <= second_size; index++)
  {
    palindrome_fun_ptr[index](palindrome_list);
  }
 
  UINT list_size = palindrome_list.size();

  for(auto int i = 0; i < list_size; i++)
  {
    if((palindrome_list[i] >= first) &&
       (palindrome_list[i] <= second) &&
       (true == is_prime(palindrome_list[i])))
    {
      fout << palindrome_list[i] << endl;
    }
  }

  fin.close();
  fout.close();
      
  return 0;
}

