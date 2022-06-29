#include<iostream>
#include<string>
#include<limits.h>
#include<stdlib.h>
using namespace std;

int myStoi(string string_num){
    if(string_num.empty()){
        throw(string("invalid stoi argument"));
    }
    
    size_t index = 0;
    bool neg = false;
    while(string_num[index] == ' ')
        index++;
    
    if(string_num[index] == '-'){
        neg = true;
        index++;
    }
    else{
        neg = false;
        if(string_num[index] == '+'){
            index++;
        }
    }

    int cutoff, acc, cutlim, base = 10;
    cutoff = neg ? INT_MIN : INT_MAX;
	cutlim = cutoff % base;
	cutoff /= base;
	if (neg) {
		if (cutlim > 0) {
			cutlim -= base;
			cutoff += 1;
		}
		cutlim = -cutlim;
	}
    for(acc=0; index < string_num.size(); index++){
        int num;
        if (isdigit(string_num[index]))
			num = string_num[index]-'0';
        else
            throw(string("invalid stoi argument"));

        if(neg){
            if (acc < cutoff || (acc == cutoff && num > cutlim)) {
                throw(string("stoi argument out of range"));
			} 
            else {
				acc *= base;
				acc -= num;
			}
        }
        else
        {
            if (acc > cutoff || (acc == cutoff && num > cutlim)) {
				throw(string("stoi argument out of range"));
			} else {
				acc *= base;
				acc += num;
			}
        }
        
    }
    return acc;
}