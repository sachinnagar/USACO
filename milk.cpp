/*
ID:sachinn2
PROG:milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

struct mystruct
{
  int price;
  unsigned long long amount_milk;
};

typedef struct mystruct price_and_qty;

bool compare_fun(price_and_qty const &first, price_and_qty const &second)
{
  return (first.price < second.price);
}
  

int main(void)
{
  
  ofstream fout("milk.out");
  ifstream fin("milk.in");

  unsigned long long total_milk_qty;
  int num_farmers;

  vector <price_and_qty> farmers_list;


  fin >> total_milk_qty;
  fin >> num_farmers;

  int price;
  unsigned long long per_farmer_milk_qty;

  for(int i = 0; i < num_farmers; i++)
  {
    price_and_qty farmer;
    fin >> price;
    fin >> per_farmer_milk_qty;

    farmer.price = price;
    farmer.amount_milk = per_farmer_milk_qty;

    farmers_list.push_back(farmer);
  }

  sort(farmers_list.begin(), farmers_list.end(), compare_fun);

  int list_size = farmers_list.size();

  int total_amount_to_pay = 0;

  for(int j = 0; j < list_size; j++)
  {
    if(farmers_list[j].amount_milk >= total_milk_qty)
    {
      total_amount_to_pay = total_amount_to_pay + (total_milk_qty * farmers_list[j].price);
      break;
    }
    else
    {
      total_milk_qty -= farmers_list[j].amount_milk;
      total_amount_to_pay = total_amount_to_pay + (farmers_list[j].amount_milk * farmers_list[j].price);
    }
  }
  fout << total_amount_to_pay << endl;

  fin.close();
  fout.close();
  return 0;
}

