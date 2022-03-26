#include "novelServer.h"
#include "novelServer.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

Novel::Novel(const char* title_, const char* content_) {
    // this->title = new char[strlen(title_) + 1];
    // this->content = new char[strlen(content_) + 1];
    title = new char[1000];
    strcpy(title, title_);
    content = new char[1000];
    strcpy(content, content_);
    contentSize=strlen(content);
}

Novel::Novel(const Novel& novel) {
    // if (title != NULL) delete[] title;
    // if (content != NULL) delete[] content;
    // title = new char[strlen(novel.title) + 1];
    // content = new char[strlen(novel.content) + 1];
    title = new char[1000];
    strcpy(title, novel.title);
    content = new char[1000];
    strcpy(content, novel.content);
    contentSize=strlen(content);
}

Novel & Novel::operator=(const Novel& novel) {
    if(this==&novel) return *this;
    if (title == nullptr){
        title=new char[1000];
        content=new char[1000];
    }
    // if (title != NULL)   delete[]title;
    // title = new char[strlen(novel.title) + 1];
    // if (title != NULL)   strcpy(title, novel.title);
    // if (novel.content == NULL) {
    //     content = NULL;
    //     return *this;
    // }
    // if (content != NULL)   delete[]content;
    // content = new char[strlen(novel.content) + 1];
    // if (content != NULL)   strcpy(content, novel.content);
    strcpy(title, novel.title);
    strcpy(content, novel.content);
    contentSize=novel.contentSize;

    return *this;
}
Novel::~Novel() {
    delete[] title;
    delete[] content;
}



NovelServer::NovelServer(const NovelServer& novelServer) {
    novelNum = novelServer.novelNum;
    maxNum = novelServer.maxNum;
    novelList = new Novel[maxNum];
    // *novelList = *novelServer.novelList;
    for(int i=0;i<novelNum;i++)
        novelList[i]=novelServer.novelList[i];
}
void NovelServer::addNovelInTheEnd(Novel& novel)     // add Novel when novelNum won't exceed maxNum, no need to check duplicate
{
    if (novelNum == maxNum) return;
    // novelNum++;
    novelList[novelNum] = novel;
    novelNum++;
}
void NovelServer::removeNovelInTheEnd()             // remove the last novel when novelNum won't less than 0
{
    if (novelNum) return;
    novelNum--;
}
NovelServer& NovelServer::operator=(const NovelServer& novelServer) {
    if(this==&novelServer) return *this;
    novelNum = novelServer.novelNum;
    maxNum = novelServer.maxNum;
    if (novelList != nullptr)   delete[]novelList;
    novelList = new Novel[maxNum];
    // *novelList = *novelServer.novelList;
    for(int i=0;i<novelNum;i++)
        novelList[i]=novelServer.novelList[i];
    return* this;
}
NovelServer::~NovelServer() {
    if (novelList != nullptr)   delete[]novelList;
}