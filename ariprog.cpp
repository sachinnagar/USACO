/*
ID:sachinn2
PROG:ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;

int main()
{
  ifstream fin("ariprog.in");
  ofstream fout("ariprog.out");
  int Q,m;
  fin >> Q >> m;
  bool X[125001];

  memset(X,0,sizeof(X));

  vector <pair <int,int> > Y;

  int G=125001;
  for(int i = 0;i < m+1;i++)
  {
    for(int j = i;j <= m;j++)
    {
      X[i*i+j*j]=1;
    }
  }
  for (int it = 0;it < G;it++)
  {
    if (X[it] == 1)    
    {
      for (int Z = 1;Z <= G;Z++)
      {
	if((Z*(Q-1)+it) > G)
	  break;
	int a = it;
	bool ok = true;
	for(int i = 0;i < Q-1;i++)
	{
	  a +=Z;
	  if(X[a]==0) 
	  {
	    ok = false; 
	    break;
	  }
	}
	if(ok)
	{
	  Y.push_back(make_pair(Z,it));
	}
      }  
    }
  }
  sort(Y.begin(),Y.end());
  if(Y.size()==0)
  {
    fout <<"NONE"<< endl;
  }
  else  
  {
    for (int i=0;i<Y.size();i++)    
    {
      fout <<Y[i].second<<" "<<Y[i].first <<endl;      
    }
  }
  return 0;
}

