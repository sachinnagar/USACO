/*
ID:sachinn2
PROG:gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#define TRUE 1
#define FALSE 0
using namespace std;

class Person
{
  private:
  int total_asset;
  string name;

  public:
  void setPersonName(string nname)
  {
    name = nname;
  }
  string getPersonName(void)
  {
    return name;
  }
  void setPersonAsset(int asset)
  {
    total_asset = asset;
  }
  int getPersonAsset(void)
  {
    return total_asset;
  }
  void addPersonAsset(int asset)
  {
    total_asset = total_asset + asset;
  }
};



int main(void)
{
  ofstream fout("gift1.out");
  ifstream fin("gift1.in");
  int test = TRUE;
  int num_people;
  fin >> num_people;
  
  Person *persons = new Person[num_people];
  string people_name;
  for(int i = 0; i < num_people; i ++)
  {
    fin >> people_name;
    persons[i].setPersonName(people_name);
    persons[i].setPersonAsset(0);
  }
  
  while(TRUE)
  {
    int total_gift_money;
    int num_gift_takers;
    int cont = 0;

    string gift_giver_name;
    string gift_taker_name;
    
    if(fin.eof())
    {
      break;
    }

    fin >> gift_giver_name;
    fin >> total_gift_money >> num_gift_takers;

    
    for(int j = 0; j < num_people; j ++)
    {
      if(0 == gift_giver_name.compare(persons[j].getPersonName()))
      {
        if(0 == num_gift_takers) 
        {
          persons[j].addPersonAsset(total_gift_money);
          cont = 1;
          break;
        }
        else
        {
          persons[j].addPersonAsset(-(total_gift_money));
          persons[j].addPersonAsset(total_gift_money % num_gift_takers);
          break;
        }
      }
    } 
    if(1 == cont)
    {
      continue;
    }   
    for(int i = 0; i < num_gift_takers; i ++)
    {
      fin >> gift_taker_name;
      for(int j = 0; j < num_people; j ++)
      {
        if(0 == gift_taker_name.compare(persons[j].getPersonName()))
        {
          persons[j].addPersonAsset(total_gift_money / num_gift_takers);
          break;
        }
      }
    }   
  }
  for(int i = 0; i < num_people; i ++)
  {
    fout << persons[i].getPersonName() << " " << persons[i].getPersonAsset() << endl;
  } 
  return 0;
}
     
