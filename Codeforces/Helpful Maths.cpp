#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>

using namespace std;
string s,ans;
int x1,x2,x3;

int main()
{
    cin >> s;
    for (int i=0;i<s.length();i+=2){
        if (s[i]=='1') ++x1;
        else if (s[i]=='2') ++x2;
        else ++x3;
    }
    for (int i=0;i<x1;++i) ans+="1+";
    for (int i=0;i<x2;++i) ans+="2+";
    for (int i=0;i<x3;++i) ans+="3+";
    ans.erase(ans.length()-1,ans.length()-1);
    cout << ans << endl;
    return 0;
}

