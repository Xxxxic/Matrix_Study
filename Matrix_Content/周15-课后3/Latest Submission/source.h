#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int num;
	string t;
	Node() :num(0), t("") {}
	Node(int n, string _t) :num(n), t(_t) {}
};
bool cmp1(Node a, Node b) //a.num > b.num为降序
{
	return a.num > b.num;
}
bool cmp2(Node a, Node b) //a.t[0] < b.t[0]为升序
{
	return a.num == b.num && a.t[0] < b.t[0];
}

template<class T>
class Counter
{
public:
	vector<Node> a; //= vector<Node>();
	void count(T t) {
		int flag = 0;
		for (vector<Node>::iterator iter = a.begin(); iter != a.end(); iter++) {
			if ((*iter).t == t) {
				(*iter).num++;
				flag = 1;
				break;
			}
		}
		if (!flag) {
			Node* temp = new Node(1, t);
			a.push_back(*temp);
		}
	}
	void discard_less_than(int n) {
		sort(a.begin(), a.end(), cmp1);
		for (vector<Node>::iterator iter = a.begin(); iter != a.end(); ) {
			if ((*iter).num < n)
				iter = a.erase(iter);
			else
				iter++;
		}
		sort(a.begin(), a.end(), cmp2);
	}
	friend ostream& operator<<(ostream& os, Counter<T> const& t) {
		for (vector<Node>::const_iterator iter = t.a.begin(); iter != t.a.end(); iter++) {
			cout << (*iter).t << ' ' << (*iter).num << endl;
		}
		return os;
	}
};
////友元函数不用加作用域
//template<class T,class Node>
//ostream& operator<<(ostream& os, Counter<T> const& t){
//	for (class vector<Node>::iterator iter = t.a.begin(); iter != t.a.end(); iter++) {
//		cout << (*iter).t << endl;
//	}
//	return os;
//}