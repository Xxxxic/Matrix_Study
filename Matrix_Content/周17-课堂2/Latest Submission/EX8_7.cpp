#include <iostream>
#include <map>
using namespace std;
int main() {
	map <char, int>m;
	int i;
	
	//put pairs into map
	for(int i=65;i<=90;++i)
    {
        m.insert(pair<char,int>(i,i));
    }
	
	char ch;
	cout <<"enter key:";
	cin >>ch;
	map<char, int>::iterator p;
	
	//find value given key ch
	p=m.find(ch);
	
	if (p!=m.end())
		cout <<"Its ASCII value is " <<p->second;
	else
		cout <<"Key not in map." ;
	return 0;
}

