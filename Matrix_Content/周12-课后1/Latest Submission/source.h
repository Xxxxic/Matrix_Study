#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

bool cmp_price(TaoBaoItem a,TaoBaoItem b){
    return a.price > b.price;
}
bool cmp_sales(TaoBaoItem a,TaoBaoItem b){
    return a.volume_of_sales > b.volume_of_sales;
}

class SortByPrice : public SortInterface {
public:
  virtual void DoSort(TaoBaoItem item[], int size)
  {
      sort(item,item+size,cmp_price);
  }
};
 
class SortBySales : public SortInterface {
 public:
  virtual void DoSort(TaoBaoItem item[], int size)
  {
        sort(item,item+size,cmp_sales);
  }
};



class TaoBao {
 public:
  TaoBao(SortInterface* strategy):strategy_(strategy) {}
  
  void SetSortStrategy(SortInterface* strategy)
  {
      strategy_ = strategy;
  }
 
  // Use current strategy_ to do the sort.
  void sort(TaoBaoItem item[], int size)
  {
      strategy_->DoSort(item,size);
  }
 
 private:
  SortInterface *strategy_;
};
