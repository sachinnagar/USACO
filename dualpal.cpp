/*
ID:sachinn2
PROG:dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

#define MIN_NUM 1
#define MAX_NUM 9999

using namespace std;

void base_convert(int num, int base, vector <char> &converted)
{

  while(0 != num)
  {
    int rem = num % base;
    num = num / base;
    if(rem > 9)
    {
      rem = rem + 55;
    }
    else
    {
      rem = rem + 48;
    }
  
    converted.insert(converted.begin(),rem); 
  }
}

bool is_palindrome(vector <char> &num)
{
  int size = num.size();

  for(int i = 0; i < size/2; i++)
  {
    if(num[i] != num[size - i - 1])
    {
      return false;
    }
  }
  return true;
}

int main(void)
{
  
  ofstream fout("dualpal.out");
  ifstream fin("dualpal.in");


  int num_count;
  int greater_than;

  fin >> num_count;
  fin >> greater_than;
  fin.close();


  int l = 1;
  for(int i = (greater_than + 1); l <= num_count; i++)
  {

    int count = 0;
    for(int base = 2; base <= 10; base++)
    {
       
      vector <char> converted_num;

      base_convert(i , base, converted_num);

      if(true == is_palindrome(converted_num))
      {
	count++;
      }
      if(2 == count)
      {
	l++;
	fout << i << endl;
	break;
      }
    }
  }
  fout.close();
  return 0;
}

