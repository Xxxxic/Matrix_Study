#include <iostream>
using namespace std;

template <typename T> //genericStack.h
class Stack
{
public:
	Stack(){
        top=new Node;
    }
	~Stack(){
        while(!isEmpty()){
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }
	void push(T obj){
        Node* temp=new Node(obj);
        temp->next=top->next;
        top->next=temp;
    }
	void pop(){
        Node* t=top->next;
        if(t){
            top->next=t->next;
            delete t;
        }
    }
	T getTop() const{
        return top->next->element;
    }
	bool isEmpty() const{
        return top->next==NULL;
    }

private:
	struct Node // 栈结点类型
	{
		T element; // 结点中存放的元素
		Node *next;			 // 指向下一结点的指针
        Node():next(NULL) {}
        Node(T obj):element(obj),next(NULL) {}
	};
	Node *top; // 栈顶
};
