#include "manager.h"

bool RoomManager::InsertAppointment(const int& date){
    if(_room1.count(date)) return 0;
    else{
        _room1.insert(date);
        return 1;
    }
}
bool RoomManager::InsertAppointment(const int& date, const string& event){
    if(_room2.count(date)) return 0;
    else{
        _room2.insert(pair<int,string>(date,event));
        return 1;
    }
}
bool RoomManager::CancelAppointment(const int& room_id, const int& date){
    if(room_id==1)
        return _room1.erase(date);
    else
        return _room2.erase(date);
}
void RoomManager::PrintAppointments(const int& room_id) const{
    if(room_id==1){
        for(set<int>::iterator p=_room1.begin();p!=_room1.end();p++)
            cout<<*p<<' ';
    }
    else{
        for(auto it=_room2.begin();it!=_room2.end();++it)
            cout<<it->first<<"("<<it->second.c_str()<<")"<<' ';
    }
}