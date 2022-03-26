#include "songList.h"
#include<cstring>
using namespace std;


SongList::SongList(const std::string _owner, unsigned int _size, unsigned int _capacity, std::string* _songs) {
    owner = _owner;
    size = _size;
    capacity = _capacity;
    songs = new string[capacity];
    for (int i = 0; i < capacity; i++)
        songs[i] = _songs[i];
}
SongList::SongList(const SongList& songList) {
    owner = songList.owner;
    size = songList.size;
    capacity = songList.capacity;
    songs = new string[capacity];
    for (int i = 0; i < capacity; i++)
        songs[i] = songList.songs[i];
}

void SongList::removeSong(const std::string& song) {
    int exist = 0,i=0;
    for (; i < size; i++) {
        if (!strcmp(songs[i].c_str(), song.c_str()))  //equals
        {
            exist = 1;
            break;
        }
    }
    if (exist) {
        for (int j = i; j < size; j++)
            songs[j] = songs[j+1];
    }
    else
        return;
}

void SongList::addSong(const std::string& song) {
    int exist = 0, i = 0;
    for (; i < size; i++) {
        if (!strcmp(songs[i].c_str(), song.c_str()))  //equals
        {
            exist = 1;
            break;
        }
    }
    if (exist) return;
    if (size >= capacity) {
        //string* temp;
        //capacity *= 2;
        //temp = (string*)realloc(songs, sizeof(string) * capacity); //扩容
        //if (temp == NULL) cout << "relloc false";
        //songs = temp;
        capacity *= 2;
        string* temp = new string[capacity];
        /*memcpy(temp, songs, sizeof(songs) * size);*/
        for (int i = 0; i < size; i++)
            temp[i] = songs[i];
        delete[] songs;
        songs = temp;
    }
    songs[size] = song;
    size++;
}

void SongList::clearSong() {
    size = 0;
}

SongList & SongList::operator=(const SongList& songList) {
    if (this == &songList) return *this;
    owner = songList.owner;
    size = songList.size;
    capacity = songList.capacity;
    songs = new string[capacity];
    for (int i = 0; i < capacity; i++)
        songs[i] = songList.songs[i];
    return *this;
}

ostream& operator<<(ostream& os, const SongList& songList) {
    if (songList.size == 0) {
        os << songList.owner << "'s SongList is Empty." << endl;
        return os;
    }
    os << "owner:" << songList.owner << endl << "Songs:" << endl;
    for (int i = 0; i < songList.size; i++)
        os << songList.songs[i] << endl;
    return os;
}

SongList::~SongList() {
    if(songs!=nullptr)
        delete[] songs;
}