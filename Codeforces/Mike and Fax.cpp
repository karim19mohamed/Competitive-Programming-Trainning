#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>

using namespace std;
string s;
bool ans=1;
int k,a,b,d=1;
stack <char> c;

int main()
{
    cin >> s >> k;
    a=s.size()/k;
    if (a%2) b=(a+1)/2;
    if (a==0){
        ans=0;
    }else if (a!=1){
        for (int i=0;i<=s.size();i++){
            if (i%a==0 && !c.empty()){
                ans=0;
                break;
            }else{
                d=1;
            }
            if (a%2 && d==b) continue;
            if (!c.empty()){
                if (c.top()==s[i]) c.pop();
            }else{
                c.push(s[i]);
            }
            d++;
        }
    }
    (ans) ? printf("YES\n") : printf("NO\n");
    return 0;
}
