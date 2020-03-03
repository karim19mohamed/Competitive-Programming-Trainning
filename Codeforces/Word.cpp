#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
string s;
int l=0,u=0;

int main()
{
    cin >> s;
    for (int i=0;i<s.length();++i){
        if (s[i]>90) ++l;
        else ++u;
    }
    if (u>l){
        for (int i=0;i<s.length();++i){
            if (s[i]>90) s[i]-=32;
        }
    }else{

        for (int i=0;i<s.length();++i){
            if (s[i]<=90) s[i]+=32;
        }
    }
    cout << s << endl;
    return 0;
}
