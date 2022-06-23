#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {                             
	vector<int> ivec(10, 2);             // 创建含10个值为2的元素的vector容器
	vector<int>::iterator iter;	         // 声明迭代器对象
	vector<int>::reverse_iterator riter;          // 声明迭代器对象
	
    iter=ivec.begin();
	*iter+=10;

    riter=ivec.rend()-1;
	*riter+=10;

    iter=ivec.end()-1;
    *iter=100;

    riter=ivec.rbegin();
    *riter-=20;

    for(iter=ivec.begin();iter!=ivec.end();++iter)
        cout<<*iter<<' ';
	cout<<endl;
    for(vector<int>::reverse_iterator riter=ivec.rbegin();riter!=ivec.rend();++riter)
        cout<<*riter<<' ';
}
