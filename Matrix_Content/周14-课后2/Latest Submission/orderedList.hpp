#include <iostream>
using namespace std;

class OrderedList
{
public:
    struct Node {
        int n;
        Node* next;
        Node():n(0),next(nullptr) {}
    };
    Node* root;
    OrderedList() {
        root = new Node;
    }
    virtual void insert(int val) = 0;
    virtual void printList() const
    {
        if (root != NULL)
        {
            Node* p = root->next;
            while (p != NULL)
            {
                cout << p->n << " ";
                p = p->next;
            }
        }
        cout << endl;
    }
    virtual ~OrderedList() {
        Node* p = NULL;
        while (root != NULL)
        {
            p = root;
            root = root->next;
            delete p;
        }
    }
};

class AscendOrderedList :public OrderedList
{
public:
    void insert(int val)
    {
        Node* p = root;
        while (p->next != NULL)
        {
            if (val <= p->next->n)
                break;
            p = p->next;
        }
        Node* temp = new Node;
        temp->n = val;
        temp->next = p->next;
        p->next = temp;
    }
};

class DescendOrderedList :public OrderedList
{
public:
    void insert(int val)
    {
        Node* p = root;
        while (p->next != NULL)
        {
            if (val >= p->next->n)
                break;
            p = p->next;
        }
        Node* temp = new Node;
        temp->n = val;
        temp->next = p->next;
        p->next = temp;
    }
};