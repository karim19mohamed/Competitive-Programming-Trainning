#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
string s;
int c0,c1;
bool one,zero;

int main()
{
    cin >> s;
    for (int i=0;i<s.length();++i){
        //cout << c0 << "  "  << c1 << endl;
        if (c0==7 || c1==7) break;
        if (!one && s[i]=='1'){
            one=1; zero=0; c1=1; c0=0;
        }else if (!zero && s[i]=='0'){
            zero=1; one=0; c0=1; c1=0;
        }else if (one && s[i]=='1'){
            ++c1;
        }else if (zero && s[i]=='0'){
            ++c0;
        }
    }

    (c0==7 || c1==7)? printf("YES\n") : printf("NO\n") ;
    return 0;
}
