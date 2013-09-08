/*
ID:sachinn2
PROG:namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#define DICT_SIZE 4617
using namespace std;



string two = "ABC";
string three = "DEF";
string four = "GHI";
string five = "JKL";
string six = "MNO";
string seven = "PRS";
string eight = "TUV";
string nine = "WXY";



bool match(string &s, string &num)
{
  int s_size = s.size();
  int num_size = num.size();
  
  if(s_size == num_size)
  {
    for(int i = 0; i < num_size; i ++)
    {
      string num_sub_str = num.substr(i,1);
      string s_sub_str = s.substr(i, 1);

      if(0 == num_sub_str.compare("2"))
      {
	string two_sub_str1 = two.substr(0, 1);
	string two_sub_str2 = two.substr(1, 1);
	string two_sub_str3 = two.substr(2, 1);

	if(!((0 == s_sub_str.compare(two_sub_str1)) ||
       	     (0 == s_sub_str.compare(two_sub_str2)) ||
	     (0 == s_sub_str.compare(two_sub_str3))))
	{
	  return false;
	}
      }
      if(0 == num_sub_str.compare("3"))
      {
	string three_sub_str1 = three.substr(0, 1);
	string three_sub_str2 = three.substr(1, 1);
	string three_sub_str3 = three.substr(2, 1);

	if(!((0 == s_sub_str.compare(three_sub_str1)) ||
       	     (0 == s_sub_str.compare(three_sub_str2)) ||
	     (0 == s_sub_str.compare(three_sub_str3))))
	{
	  return false;
	}
      }
      if(0 == num_sub_str.compare("4"))
      {
	string four_sub_str1 = four.substr(0, 1);
	string four_sub_str2 = four.substr(1, 1);
	string four_sub_str3 = four.substr(2, 1);

	if(!((0 == s_sub_str.compare(four_sub_str1)) ||
       	     (0 == s_sub_str.compare(four_sub_str2)) ||
	     (0 == s_sub_str.compare(four_sub_str3))))
	{
	  return false;
	}
      }
      if(0 == num_sub_str.compare("5"))
      {
	string five_sub_str1 = five.substr(0, 1);
	string five_sub_str2 = five.substr(1, 1);
	string five_sub_str3 = five.substr(2, 1);

	if(!((0 == s_sub_str.compare(five_sub_str1)) ||
       	     (0 == s_sub_str.compare(five_sub_str2)) ||
	     (0 == s_sub_str.compare(five_sub_str3))))
	{
	  return false;
	}
      }
      if(0 == num_sub_str.compare("6"))
      {
	string six_sub_str1 = six.substr(0, 1);
	string six_sub_str2 = six.substr(1, 1);
	string six_sub_str3 = six.substr(2, 1);

	if(!((0 == s_sub_str.compare(six_sub_str1)) ||
       	     (0 == s_sub_str.compare(six_sub_str2)) ||
	     (0 == s_sub_str.compare(six_sub_str3))))
	{
	  return false;
	}
      }
      if(0 == num_sub_str.compare("7"))
      {
	string seven_sub_str1 = seven.substr(0, 1);
	string seven_sub_str2 = seven.substr(1, 1);
	string seven_sub_str3 = seven.substr(2, 1);

	if(!((0 == s_sub_str.compare(seven_sub_str1)) ||
       	     (0 == s_sub_str.compare(seven_sub_str2)) ||
	     (0 == s_sub_str.compare(seven_sub_str3))))
	{
	  return false;
	}
      }
      if(0 == num_sub_str.compare("8"))
      {
	string eight_sub_str1 = eight.substr(0, 1);
	string eight_sub_str2 = eight.substr(1, 1);
	string eight_sub_str3 = eight.substr(2, 1);

	if(!((0 == s_sub_str.compare(eight_sub_str1)) ||
       	     (0 == s_sub_str.compare(eight_sub_str2)) ||
	     (0 == s_sub_str.compare(eight_sub_str3))))
	{
	  return false;
	}
      }
      if(0 == num_sub_str.compare("9"))
      {
	string nine_sub_str1 = nine.substr(0, 1);
	string nine_sub_str2 = nine.substr(1, 1);
	string nine_sub_str3 = nine.substr(2, 1);

	if(!((0 == s_sub_str.compare(nine_sub_str1)) ||
       	     (0 == s_sub_str.compare(nine_sub_str2)) ||
	     (0 == s_sub_str.compare(nine_sub_str3))))
	{
	  return false;
	}
      }
    }
  }
  else
  {
    return false;
  }
  return true;
}

int main(void)
{
  
  ofstream fout("namenum.out");
  ifstream fin("namenum.in");
  ifstream fin1("dict.txt");


  list <std::string> dictionary;
  string num;
  int i;
  for(i = 0; i < DICT_SIZE; i++)
  {
    string word;
    fin1 >> word;
    dictionary.push_back(word);
  }
  fin1.close();
    
  fin >> num;
  fin.close();
  int count = 0;

  for(list <string> ::iterator it = dictionary.begin(); it != dictionary.end(); it++)
  {
    if(true == match(*it, num))
    { 
      fout << *it << endl;
      count++;
    }
  }

  if(0 == count)
  {
    fout << "NONE" << endl;
  }
      
  return 0;
}

