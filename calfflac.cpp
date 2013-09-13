/*
ID:sachinn2
PROG:calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

struct my_struct
{
  int original_index;
  char letter;
};

int find_largest_palindrome(vector <struct my_struct> const &modified_str,
                             int &starting_index,
			     int &last_index)
{
  int largest_palindrome = 1;
  
  int str_size = modified_str.size();
  int forward,backward;

  for(int i = 0; i < str_size; i++)
  {
    forward = i;
    backward = i;
    int local_palindrome = 1;

    while((((forward + 1) < str_size) && ((backward - 1) >= 0)) &&
            (modified_str[forward + 1].letter == modified_str[backward - 1].letter))
    {

      local_palindrome += 2;

      if(local_palindrome > largest_palindrome)
      {
        starting_index = modified_str[backward - 1].original_index;
        last_index = modified_str[forward + 1].original_index;
	largest_palindrome = local_palindrome;
      }
      forward++;
      backward--;
    }

    forward = i;
    backward = i;
    local_palindrome = 0;

    while((((forward + 1) < str_size) && ((backward) >= 0)) &&
            (modified_str[forward + 1].letter == modified_str[backward].letter))
    {
      
      local_palindrome += 2;

      if(local_palindrome > largest_palindrome)
      {
        starting_index = modified_str[backward].original_index;
        last_index = modified_str[forward + 1].original_index;
	largest_palindrome = local_palindrome;
      }
      forward++;
      backward--;
    }
  }

  return largest_palindrome;
}

int main(void)
{
  
  ofstream fout("calfflac.out");
  ifstream fin("calfflac.in");

  vector <struct my_struct> modified_string;

  string str, s1;

  while(getline(fin, s1))
  {
    str.append("\n");
    str.append(s1);
  }

  int str_size = str.size(); 
  
  for(auto int index = 0; index < str_size; index++)
  {
    if(((str[index] >= 'A') && (str[index] <= 'Z')) ||
       ((str[index] >= 'a') && (str[index] <= 'z')))
    {
      struct my_struct mapping;
      mapping.original_index = index;

      if((str[index] >= 'A') && (str[index] <= 'Z'))
      {
	mapping.letter = str[index] + ('a' - 'A');
      }
      else
      {
	mapping.letter = str[index];
      }

      modified_string.push_back(mapping);
    }
  }

  int starting_index = 0;
  int last_index = 0;

  int largest_palindrom = find_largest_palindrome(modified_string, starting_index, last_index);

 
  fout << largest_palindrom << endl;
  for(int i = starting_index; i <= last_index; i++)
  {
    fout << str[i];
  }
  fout << endl;

  fin.close();
  fout.close();
  return 0;
}

