#include<iostream>
using namespace std;

#define Namespace

extern int inflag ;

namespace mfc {
  extern int inflag;
}

namespace owl {
  extern int inflag;
}
void Handle();

void Handle()
{
    mfc::inflag++;
    owl::inflag--;
    inflag=inflag%100;

    return;
}