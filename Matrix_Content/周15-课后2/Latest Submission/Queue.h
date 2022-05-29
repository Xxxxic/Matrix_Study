#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//该队列采取首尾都放元素的做法 
//因为如果不这样在构造函数时new Node()将会使main函数里面Job多构造一次 导致id多1
template<typename T>
class Queue {
public:
    //首不放元素的话 构造函数就new Node()
    Queue() :node_num(0),front_node(nullptr),back_node(nullptr) {}
    Queue(const Queue& a) :node_num(a.node_num) {
        Node* t = a.front_node;
        //如果a不为空
        if (t) {
            front_node = new Node(t->element);
            Node* p = front_node;
            while (t->next)
            {
                t = t->next;
                p->next = new Node(t->element);
                p = p->next;
            }
            back_node = p;
        }
    }
    ~Queue() {
        while (!empty())
        {
            Node* t = front_node;
            front_node = t->next;
            delete t;
            node_num--;
        }
    }
    bool empty() {
        return node_num == 0;
    }
    int size() {
        return node_num;
    }
    T front() const {
        return front_node->element;
    }
    T back() const {
        return back_node->element;
    }
    void push(T element) {
        Node* temp = new Node(element);
        if (back_node){
            back_node->next = temp;
            back_node = temp;
        }
        else{
            back_node = temp;
            front_node = temp;
        }  
        node_num++;
    }
    void pop() {
        if (empty())
            return;
        Node* t = front_node;
        front_node = t->next;
        if (node_num == 1)
            back_node = front_node;
        delete t;
        node_num--;
    }
    void swap(Queue& q) {
        Node* f = front_node;
        Node* b = back_node;
        int num = node_num;

        front_node = q.front_node;
        back_node = q.back_node;
        node_num = q.node_num;

        q.front_node = f;
        q.back_node = b;
        q.node_num = num;
    }
    //开始想重载= 但是直接复制赋值会调用拷贝构造 浅拷贝在释放时会出问题 要写深拷贝
    //所以直接调换地址

private:
    struct Node {
        T element;
        Node* next;
        Node(T ele, Node* n = NULL) {
            element = ele;
            next = n;
        }
    };
    Node* front_node;
    Node* back_node;
    int node_num;
};