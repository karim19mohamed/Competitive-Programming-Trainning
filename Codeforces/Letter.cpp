#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
char s1[209],s2[209];
map <char,int> m;
bool ans=1;

int main()
{
    for (int i=0;i<209;++i) s2[i]=' ';
    cin.getline(s1,sizeof(s1));
    cin.getline(s2,sizeof(s2));
    for (int i=0;i<209;++i){
        if (s1[i]!=' ') ++m[s1[i]];
    }
    for (int i=0;i<209;++i){
        if (s2[i]!=' ' ){
            if(m[s2[i]]){
                --m[s2[i]];
            }else {
                //cout << s2[i] << " " << m[s2[i]] << endl;
                ans=0;
                break;
            }
        }
    }
    (ans) ? printf("YES\n"):printf("NO\n");
    return 0;
}
