
#include "novelServer.h"
#include <cstring>
using namespace std;

Novel::Novel(const char *title_, const char *content_) {
    title = new char[strlen(title_) + 1];
    contentSize = strlen(content_) + 1;
    content = new char[contentSize];

    strcpy(title, title_);
    for (int i = 0; i < contentSize; ++i) {
        content[i] = content_[i];
    }
}


Novel::Novel(const Novel &novel) {
    contentSize = novel.contentSize;
    title = new char[strlen(novel.title) + 1];
    content = new char[contentSize];
    strcpy(title,  novel.title);
    strcpy(content,  novel.content);
}

Novel &Novel::operator=(const Novel &novel) {
    if (&novel != this) {
        if (title != nullptr || content != nullptr) {
            delete[] title;
            delete[] content;
        }
        contentSize = novel.contentSize;
        title = new char[strlen(novel.title) + 1];
        content = new char[contentSize];
        strcpy(title, novel.title);
        strcpy(content,  novel.content);
    }
    return *this;
}

Novel::~Novel() {
    delete[] title;
    title = nullptr;
    delete[] content;
    content = nullptr;
}

NovelServer::NovelServer(const NovelServer &novelServer) {
    maxNum = novelServer.maxNum;
    novelNum = novelServer.novelNum;
    novelList = new Novel[maxNum];
    for (int i = 0; i < novelNum; ++i) {
        novelList[i] = novelServer.novelList[i];
    }
}

void NovelServer::addNovelInTheEnd(Novel &novel) {
    if (novelNum == maxNum) {
        std::cout << "Storage Full. Add Novel Fail." << std::endl;
    } else {
        novelList[novelNum++] = novel;
    }
}

void NovelServer::removeNovelInTheEnd() {
    novelNum = (novelNum - 1 < 0) ? 0 : novelNum - 1;
}


NovelServer &NovelServer::operator=(const NovelServer &novelServer) {
    if (&novelServer != this) {
        if (novelList != nullptr) {
            delete[] novelList;
        }
        maxNum = novelServer.maxNum;
        novelNum = novelServer.novelNum;
        novelList = new Novel[maxNum];
        for (int i = 0; i < novelNum; ++i) {
            novelList[i] = novelServer.novelList[i];
        }
    }
    return *this;
}

NovelServer::~NovelServer() {
    delete[] novelList;
    novelList = nullptr;
}