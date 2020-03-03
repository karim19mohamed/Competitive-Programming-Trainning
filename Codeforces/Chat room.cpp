#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
string s;
int a=1;

int main()
{
    cin >> s;
    for (int i=0;i<s.length();++i){
        if (a==1 and s[i]=='h') ++a;
        else if (a==2 and s[i]=='e') ++a;
        else if (a==3 and s[i]=='l') ++a;
        else if (a==4 and s[i]=='l') ++a;
        else if (a==5 and s[i]=='o'){
            ++a;
            break;
        }
    }

    (a==6)? printf("YES\n") : printf("NO\n") ;
    return 0;
}
