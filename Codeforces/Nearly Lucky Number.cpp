#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
string s;
int x=0;

int main()
{
    cin >> s;
    for (int i=0;i<s.length();++i){
        if (s[i]=='7' || s[i]=='4') ++x;
    }
    //cout << x << endl;
    if (x==4 || x==7) printf("YES\n");
    else  printf("NO\n");
    return 0;
}
