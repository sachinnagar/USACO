/*
ID:sachinn2
PROG:transform
LANG: C++
*/

#include <fstream>
#include <vector>


using namespace std;

bool ninty_degree(vector< vector<char> > &original_map,
                  vector< vector<char> > &transformed_map,
	          int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(original_map[i][j] != transformed_map[j][size - i - 1])
      {
	return false;
      }
    }
  }
  return true;
}
bool one_eighty_degree(vector< vector<char> > &original_map,
                       vector< vector<char> > &transformed_map,
		       int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(original_map[i][j] != transformed_map[size - i - 1][size - j - 1])
      {
	return false;
      }
    }
  }
  return true;
}
bool two_seventy_degree(vector< vector<char> > &original_map,
                        vector< vector<char> > &transformed_map,
			int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(original_map[i][j] != transformed_map[size - j - 1][i])
      {
	return false;
      }
    }
  }

  return true;
}
bool reflection(vector< vector<char> > &original_map,
                vector< vector<char> > &transformed_map,
		int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(original_map[j][i] != transformed_map[j][size - i - 1])
      {
	return false;
      }
    }
  }


  return true;
}
bool combination(vector< vector<char> > &original_map,
                 vector< vector<char> > &transformed_map,
		 int size)
{
  vector< vector<char> > transformed_map1 = transformed_map;

  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      transformed_map1[j][i] = transformed_map[j][size - i - 1];
    }
  }

  if(true == ninty_degree(original_map, transformed_map1, size))
  {
    return true;
  }
  if(true == one_eighty_degree(original_map, transformed_map1, size))
  {
    return true;
  }
  if(true == two_seventy_degree(original_map, transformed_map1, size))
  {
    return true;
  }

  return false;
}
bool no_change(vector< vector<char> > &original_map,
               vector< vector<char> > &transformed_map,
	       int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(original_map[i][j] != transformed_map[i][j])
      {
	return false;
      }
    }
  }
  return true;
}

int main(void)
{

  ofstream fout("transform.out");
  ifstream fin("transform.in");
  
  int size;
  char c;

  fin >> size;

  vector< vector<char> > original_map(size, vector <char> (size));
  vector< vector<char> > transformed_map(size, vector <char> (size));

  int i, j;

  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size; j++)
    {
      fin >> c;
      original_map[i][j] = c;
    }
  }

  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size; j++)
    {
      fin >> c;
      transformed_map[i][j] = c;
    }
  }

  if(true == ninty_degree(original_map, transformed_map, size))
  {
    fout << "1" << endl;
  }
  else if(true == one_eighty_degree(original_map, transformed_map, size))
  {
    fout << "2" << endl;
  }
  else if(true == two_seventy_degree(original_map, transformed_map, size))
  {
    fout << "3" << endl;
  }
  else if(true == reflection(original_map, transformed_map, size))
  {
    fout << "4" << endl;
  }
  else if(true == combination(original_map, transformed_map, size))
  {
    fout << "5" << endl;
  }
  else if(true == no_change(original_map, transformed_map, size))
  {
    fout << "6" << endl;
  }
  else
  {
    fout << "7" << endl;
  }
  return 0;
}




