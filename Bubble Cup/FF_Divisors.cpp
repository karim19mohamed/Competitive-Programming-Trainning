#include <iostream>
#include <stdio.h>

using namespace std;
long long n,ans,m;
long long s;
void div();

int main()
{
    while (scanf("%lld",&n),n){
        ans=0;
        div();
        printf("%lld\n",ans);
    }
    return 0;
}
void div(){
    s=2;
    m=1;
    ans++;
    if (n==1) return;
    while (s!=n+1){
        if (n%s==0){
            ans++;
        }
        s++;
    }
}
