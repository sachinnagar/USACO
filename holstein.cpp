/*
ID:sachinn2
PROG:holstein
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
using namespace std;

int find_min_feed_type(vector < vector <int> > &feed_list, 
                       vector <int> &vitamin_req,
		       int vitamin_types,
		       int feed_types)
{
  vector <int> resulting_feed(vitamin_types, 0);
  int min = 16;
  int min_val = 0;
  int min_bit_count = 16;
  int start = 1;
  bool flag = false;

  while(true)
  {
    bitset <15> feed_order(start);
    if(feed_order.count() > feed_types)
    {
      break;
    }
    fill(resulting_feed.begin(), resulting_feed.end(), 0);
    for(int a = 0; a < 15; a++)
    {
      if((feed_order.count() <= feed_types) && (feed_order.test(a) == true))
      {
	for(int b = 0; b < vitamin_types; b++)
	{
	  resulting_feed[b] += feed_list[a][b];
	}
      }
    }
    flag = true;
    for(int c = 0; c < vitamin_types; c++)
    {
      if(vitamin_req[c] > resulting_feed[c])
      {
	flag = false;
	break;
      }
    }

    if(flag == true)
    {
      if((feed_order.count() < min) &&
	 (feed_order.count() < min_bit_count))
      {
	min_val = start;
	min_bit_count = feed_order.count();
      }
    }
    start++;
    if(start > 32767)
    {
      break;
    }
  }
  return min_val;
}

int main(void)
{
  ofstream fout("holstein.out");
  ifstream fin("holstein.in");

  int vitamin_types;
  int feed_types;

  fin >> vitamin_types;

  vector <int> vitamin_req;

  int vitamin_qty;
  for(int i = 0; i < vitamin_types; i++)
  {
    fin >> vitamin_qty;
    vitamin_req.push_back(vitamin_qty);
  }

  fin >> feed_types;

  vector < vector <int> > feed_list(15, vector <int>(25, -1));

  for(int a = 0; a < feed_types; a++)
  {
    for(int b = 0; b < vitamin_types; b++)
    {
      fin >> vitamin_qty;
      feed_list[a][b] = vitamin_qty;
    }
  }

  int bit_feed_count = find_min_feed_type(feed_list, vitamin_req, vitamin_types, feed_types);

  bitset <15> bit_feed(bit_feed_count);

  fout << bit_feed.count();

  for(int j = 0; j < 15; j++)
  {
    if(bit_feed.test(j) == true)
    {
      fout << " " << (j + 1);
    }
  }
  fout << endl;

  fin.close();
  fout.close();
  return 0;
}


