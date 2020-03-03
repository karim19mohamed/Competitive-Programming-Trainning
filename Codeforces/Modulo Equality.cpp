#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
int n;
long long m,a[2009],b[2009],c[2009],ans=1000000009;

int main()
{
    scanf("%d %lld",&n,&m);
    for (int i=0;i<n;++i) scanf("%lld",&a[i]);
    for (int i=0;i<n;++i) scanf("%lld",&b[i]);
    sort(b,b+n);
    long long x;
    for (int i=0;i<n;++i){
        (b[i]-a[0]>=0) ? x=(b[i]-a[0])%m : x=b[i]-a[0]+m ;
        if (x<ans){
            for (int i=0;i<n;++i){
                c[i]=(a[i]+x)%m;
            }
            sort(c,c+n);
            bool e=1;
            for (int i=0;i<n;++i) if (c[i]!=b[i]) e=0;
            if (e) ans=x;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
