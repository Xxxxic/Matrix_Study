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
//友元函数不用加作用域
//template<class T,class Node>
//ostream& operator<<(ostream& os, Counter<T> const& t){
//	for (class vector<Node>::iterator iter = t.a.begin(); iter != t.a.end(); iter++) {
//		cout << (*iter).t << endl;
//	}
//	return os;
//}

//1.首先在自定义类里面塞stl是丑陋的做法 下次试试用数组的做法优化下
//2.在类外定义模板类函数 要求在接口实现中的类名称后面加入模板类参数：Counter<T>::Counter()  否则报错缺少模板参数列表
//3.const vector作为函数形参时，要使用迭代器，必须用const_iterator，否则编译不通过。   vector<Node>::const_iterator my = test.begin()
//4.在vs里面会遇到奇怪的问题：语法错误: 意外的令牌“标识符”，预期的令牌为“;”    原因是编译器无法识别模板中的迭代器类型，于是在迭代器前面加上class
//class vector<Node>::const_iterator iter = t.a.begin()
//5.vector::erase()的实质是将迭代器后面的元素全部复制一遍，往前移动一个位置
//所以如果直接遍历删除 iter++的话会有错误 iter会变成野指针 所以用iter = a.erase(iter);返回删掉元素的下一个位置
//6.注意vector的初始化：https://blog.csdn.net/qq_42247231/article/details/107242326?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-2-107242326-blog-89137520.pc_relevant_antiscanv4&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-2-107242326-blog-89137520.pc_relevant_antiscanv4&utm_relevant_index=3
//7.迭代器的交换可以用std::iter_swap(iterator a,iterator b)
//8.友元模板函数类外实现方式