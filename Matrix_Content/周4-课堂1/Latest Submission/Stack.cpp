#include<iostream>
#include <stddef.h>
#include"Stack.hpp"
using namespace std;


Stack::Stack(){
    node* data=NULL;
}
Stack::Stack(const Stack& s){
    this->data=s.data;
}
Stack::~Stack(){
    delete[] data;
}
void Stack::push(int a){
    data->next->num=a;
}
void Stack::pop(){
	if(!Stack::empty()) return ;
    node* temp=data;
    if(temp->next==NULL){
    	temp=NULL;
    	return ;
	}
    for(;temp->next->next!=NULL;temp=temp->next){
		temp->next=NULL;
		return ;
	}   
}
int Stack::top() const{
    if(!Stack::empty()) return 0;
    else{
        node* temp=data;
		int i;
    	for(i=0;temp!=NULL&&temp->next!=NULL;temp=temp->next){}
        return temp->num;
    }
}
bool Stack::empty() const{
	node* temp=data;
	int i;
    for(i=0;temp!=NULL&&temp->next!=NULL;temp=temp->next){}
    return i;
}
void Stack::clear(){
    node* temp=data;
	delete[] data;
    node* data=NULL;
}
