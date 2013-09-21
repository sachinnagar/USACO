/*
ID:sachinn2
PROG:sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#define MAX_LEN 8


typedef unsigned int UINT;

using namespace std;

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

void genetate_one_length_superprime(vector <UINT> &sup_prime_list)
{
  sup_prime_list.push_back(2);
  sup_prime_list.push_back(3);
  sup_prime_list.push_back(5);
  sup_prime_list.push_back(7);
}

void genetate_two_length_superprime(vector <UINT> &sup_prime_list)
{
  UINT x;

  for(auto int a = 2; a <= 7; ((a == 2) ? (a += 1) : (a += 2)))
  {
    for(auto int b = 1; b <= 9; b += 2)
    {
      x = (a * 10) + b;
      if(true == is_prime(x))
      {
	sup_prime_list.push_back(x);
      }
    }
  }
}

void genetate_three_length_superprime(vector <UINT> &sup_prime_list)
{
  UINT x;

  for(auto int a = 2; a <= 7; ((a == 2) ? (a += 1) : (a += 2)))
  {
    for(auto int b = 1; b <= 9; b += 2)
    {
      x = (a * 10) + b;
      if(false == is_prime(x))
      {
	continue;
      }
      for(auto int c = 1; c <= 9; c += 2)
      {
	x = (a * 100) + (b * 10) + c;
	if(true == is_prime(x))
	{
	  sup_prime_list.push_back(x);
	}
      }
    }
  }
}

void genetate_four_length_superprime(vector <UINT> &sup_prime_list)
{
  UINT x;

  for(auto int a = 2; a <= 7; ((a == 2) ? (a += 1) : (a += 2)))
  {
    for(auto int b = 1; b <= 9; b += 2)
    {
      x = (a * 10) + b;
      if(false == is_prime(x))
      {
	continue;
      }
      for(auto int c = 1; c <= 9; c += 2)
      {
	x = (a * 100) + (b * 10) + c;
	if(false == is_prime(x))
	{
	  continue;
	}
	for(auto int d = 1; d <= 9; d += 2)
	{
	  x = (a * 1000) + (b * 100) + (c * 10) + d;
          if(true == is_prime(x))
	  {
	    sup_prime_list.push_back(x);
	  }
	}
      }
    }
  }
}

void genetate_five_length_superprime(vector <UINT> &sup_prime_list)
{
  UINT x;

  for(auto int a = 2; a <= 7; ((a == 2) ? (a += 1) : (a += 2)))
  {
    for(auto int b = 1; b <= 9; b += 2)
    {
      x = (a * 10) + b;
      if(false == is_prime(x))
      {
	continue;
      }
      for(auto int c = 1; c <= 9; c += 2)
      {
	x = (a * 100) + (b * 10) + c;
	if(false == is_prime(x))
	{
	  continue;
	}
	for(auto int d = 1; d <= 9; d += 2)
	{
	  x = (a * 1000) + (b * 100) + (c * 10) + d;
          if(false == is_prime(x))
	  {
	    continue;
	  }
	  for(auto int e = 1; e <= 9; e += 2)
	  {
	    x = (a * 10000) + (b * 1000) + (c * 100) + (d * 10) + e;
	    if(true == is_prime(x))
	    {
	      sup_prime_list.push_back(x);
	    }
	  }
	}
      }
    }
  }
}

void genetate_six_length_superprime(vector <UINT> &sup_prime_list)
{
  UINT x;

  for(auto int a = 2; a <= 7; ((a == 2) ? (a += 1) : (a += 2)))
  {
    for(auto int b = 1; b <= 9; b += 2)
    {
      x = (a * 10) + b;
      if(false == is_prime(x))
      {
	continue;
      }
      for(auto int c = 1; c <= 9; c += 2)
      {
	x = (a * 100) + (b * 10) + c;
	if(false == is_prime(x))
	{
	  continue;
	}
	for(auto int d = 1; d <= 9; d += 2)
	{
	  x = (a * 1000) + (b * 100) + (c * 10) + d;
          if(false == is_prime(x))
	  {
	    continue;
	  }
	  for(auto int e = 1; e <= 9; e += 2)
	  {
	    x = (a * 10000) + (b * 1000) + (c * 100) + (d * 10) + e;
	    if(false == is_prime(x))
	    {
	      continue;
	    }
	    for(auto int f = 1; f <= 9; f += 2)
	    {
	      x = (a * 100000) + (b * 10000) + (c * 1000) + (d * 100) + (e * 10) + f;
	      if(true == is_prime(x))
	      {
		sup_prime_list.push_back(x);
	      }
	    }
	  }
	}
      }
    }
  }
}

void genetate_seven_length_superprime(vector <UINT> &sup_prime_list)
{
  UINT x;

  for(auto int a = 2; a <= 7; ((a == 2) ? (a += 1) : (a += 2)))
  {
    for(auto int b = 1; b <= 9; b += 2)
    {
      x = (a * 10) + b;
      if(false == is_prime(x))
      {
	continue;
      }
      for(auto int c = 1; c <= 9; c += 2)
      {
	x = (a * 100) + (b * 10) + c;
	if(false == is_prime(x))
	{
	  continue;
	}
	for(auto int d = 1; d <= 9; d += 2)
	{
	  x = (a * 1000) + (b * 100) + (c * 10) + d;
          if(false == is_prime(x))
	  {
	    continue;
	  }
	  for(auto int e = 1; e <= 9; e += 2)
	  {
	    x = (a * 10000) + (b * 1000) + (c * 100) + (d * 10) + e;
	    if(false == is_prime(x))
	    {
	      continue;
	    }
	    for(auto int f = 1; f <= 9; f += 2)
	    {
	      x = (a * 100000) + (b * 10000) + (c * 1000) + (d * 100) + (e * 10) + f;
	      if(false == is_prime(x))
	      {
		continue;
	      }
	      for(auto int g = 1; g <= 9; g += 2)
	      {
		x = (a * 1000000) + (b * 100000) + (c * 10000) + (d * 1000) + (e * 100) + (f * 10) + g;
		if(true == is_prime(x))
		{
		  sup_prime_list.push_back(x);
		}
	      }
	    }
	  }
	}
      }
    }
  }
}


void genetate_eight_length_superprime(vector <UINT> &sup_prime_list)
{
  UINT x;

  for(auto int a = 2; a <= 7; ((a == 2) ? (a += 1) : (a += 2)))
  {
    for(auto int b = 1; b <= 9; b += 2)
    {
      x = (a * 10) + b;
      if(false == is_prime(x))
      {
	continue;
      }
      for(auto int c = 1; c <= 9; c += 2)
      {
	x = (a * 100) + (b * 10) + c;
	if(false == is_prime(x))
	{
	  continue;
	}
	for(auto int d = 1; d <= 9; d += 2)
	{
	  x = (a * 1000) + (b * 100) + (c * 10) + d;
          if(false == is_prime(x))
	  {
	    continue;
	  }
	  for(auto int e = 1; e <= 9; e += 2)
	  {
	    x = (a * 10000) + (b * 1000) + (c * 100) + (d * 10) + e;
	    if(false == is_prime(x))
	    {
	      continue;
	    }
	    for(auto int f = 1; f <= 9; f += 2)
	    {
	      x = (a * 100000) + (b * 10000) + (c * 1000) + (d * 100) + (e * 10) + f;
	      if(false == is_prime(x))
	      {
		continue;
	      }
	      for(auto int g = 1; g <= 9; g += 2)
	      {
		x = (a * 1000000) + (b * 100000) + (c * 10000) + (d * 1000) + (e * 100) + (f * 10) + g;
		if(false == is_prime(x))
		{
		  continue;
		}
		for(auto int h = 1; h <= 9; h += 2)
		{
		  x = (a * 10000000) + (b * 1000000) + (c * 100000) + (d * 10000) + (e * 1000) + (f * 100) + (g * 10) + h;
		  if(true == is_prime(x))
		  {
		    sup_prime_list.push_back(x);
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
}


int main(void)
{
  
  ofstream fout("sprime.out");
  ifstream fin("sprime.in");

  UINT num;
  fin >> num;
  
  // array of function pointers
  void (*sup_prime_fun_ptr[9])(vector <UINT> &);

  sup_prime_fun_ptr[1] = genetate_one_length_superprime;
  sup_prime_fun_ptr[2] = genetate_two_length_superprime;
  sup_prime_fun_ptr[3] = genetate_three_length_superprime;
  sup_prime_fun_ptr[4] = genetate_four_length_superprime;
  sup_prime_fun_ptr[5] = genetate_five_length_superprime;
  sup_prime_fun_ptr[6] = genetate_six_length_superprime;
  sup_prime_fun_ptr[7] = genetate_seven_length_superprime;
  sup_prime_fun_ptr[8] = genetate_eight_length_superprime;

  vector <UINT> sup_prime_list;

  sup_prime_fun_ptr[num](sup_prime_list);

 
  UINT list_size = sup_prime_list.size();

  for(auto int i = 0; i < list_size; i++)
  {
    fout << sup_prime_list[i] << endl;
  }

  fin.close();
  fout.close();
      
  return 0;
}

