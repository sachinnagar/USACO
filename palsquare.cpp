/*
ID:sachinn2
PROG:palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

#define MIN_NUM 1
#define MAX_NUM 300

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
  
  ofstream fout("palsquare.out");
  ifstream fin("palsquare.in");


  int base;

  fin >> base;
  fin.close();


  for(int i = MIN_NUM; i <= MAX_NUM; i++)
  {

    vector <char> converted_num;
    vector <char> converted_square;
  
    base_convert((i * i), base, converted_square);
    
    if(true == is_palindrome(converted_square))
    {
      base_convert(i, base, converted_num);
      int j;
      for(j = 0; j < converted_num.size(); j++)
      {
	fout << converted_num[j];
      }
      fout << " ";

      for(j = 0; j < converted_square.size(); j++)
      {
	fout << converted_square[j];
      }
      fout << endl;
    }
  }
  return 0;
}

