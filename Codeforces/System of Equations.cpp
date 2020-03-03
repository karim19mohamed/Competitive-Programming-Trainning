#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
long long n,m,a,b,ans;

int main()
{
    scanf("%lld %lld",&n,&m);
    for (long long i=0;i<max(n,m)+1;++i){
        for (long long j=0;j<max(n,m)+1;++j){
            a=i*i+j;
            b=j*j+i;
            if (a==n && b==m) ++ans;
        }
    }

    printf("%lld\n",ans);
    return 0;
}
