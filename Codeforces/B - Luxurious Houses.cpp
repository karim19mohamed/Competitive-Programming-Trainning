#include <iostream>
#include <stdio.h>

using namespace std;
long long n,h[100009],ans[100009],m;

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;++i) scanf("%lld",&h[i]);
    for (long long i=n-1;i>=0;--i){
        ans[i]= (m-h[i]>=0)? m-h[i]+1 : 0 ;
        m=max(m,h[i]);
    }
    for (long long i=0;i<n;++i){
        printf("%lld",ans[i]);
        if (i!=n-1) printf(" ");
    }
    printf("\n");
    return 0;
}
