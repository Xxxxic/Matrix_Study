#include <iostream>
#include <string>
#include<set>
#include<map>
using namespace std;

int main() 
{            
    map<int,multiset<int>> total;
    int n;
    cin>>n;
    while(n--)
    {
        string op;
        int id;
        cin>>op>>id;
        if(op=="new"){
            multiset<int> t;
            total.insert(make_pair(id,t));
        }
        else if(op=="add"){
            int num;
            cin>>num;
            auto it=total.find(id);
            it->second.insert(num);
        }
        else if(op=="merge"){
            int id2;
            cin>>id2;
            auto it1=total.find(id);
            auto it2=total.find(id2);
            for(auto i=it2->second.begin();i!=it2->second.end();++i)
                it1->second.insert(*i);
            it2->second.clear();
        }
        else if(op=="unique"){
            auto it=total.find(id);
            set<int>s(it->second.begin(),it->second.end());
            it->second.clear();
            it->second.insert(s.begin(), s.end());
        }
        else if(op=="out"){
            auto it=total.find(id);
            if(!it->second.empty()){
                for(auto i=it->second.begin();i!=it->second.end();++i)
                    cout<<*i<<' ';
            cout<<endl;
            }
        }
    }

	return 0;
}