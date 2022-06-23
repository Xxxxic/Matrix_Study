#include <iostream>
#include <stack>
using namespace std;

// bool empty(); // to judge whether the stack is empty.
// void push(typename); // push an element into the stack.
// void pop(); // pop an element from the stack, will make error if you try to pop from an empty stack.
// typename top(); // return the element on the top of the stack.

bool Matched(const string& s, int l)
{
    stack<char> stack;
    for(int i=0;i<l;++i)
    {
        if(s[i]=='['||s[i]=='{'||s[i]=='(')
            stack.push(s[i]);
        else if(stack.empty())
            return 0;
        else if((s[i]==')'&&stack.top()=='(') || (s[i]==']'&&stack.top()=='[') || (s[i]=='}'&&stack.top()=='{'))
            stack.pop();
        else
            return 0;
    }
    if(stack.empty())
        return 1;
    else 
        return 0;
}
