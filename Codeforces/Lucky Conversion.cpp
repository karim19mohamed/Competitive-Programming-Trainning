#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>

using namespace std;
string a,b;
long long na,nb,d,ans;
bool flag;

int main()
{
    cin >> a >> b;
    for (long long i=0;i<a.size();i++){
        if (a[i]=='4') na++;
        if (b[i]=='4') nb++;
    }
    if (na>nb) flag=1;
    d=abs(na-nb);
    ans+=d;
    for (long long i=0;i<a.size();i++){
        if (d==0) break;
        if (flag){
            if (a[i]!=b[i] && a[i]=='4'){
                a[i]='7';
                d--;
            }
        }else{
            if (a[i]!=b[i] && a[i]=='7'){
                a[i]='4';
                d--;
            }
        }
    }
    d=0;
    for (long long i=0;i<a.size();i++){
        if (a[i]!=b[i]) d++;
    }
    ans+=(d/2);
    printf("%lld\n",ans);
    return 0;
}
