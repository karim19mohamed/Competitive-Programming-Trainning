#include <iostream>
#include <stdio.h>

using namespace std;
long long n,a[2009],b[2009],ans;
int x,y;

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        a[x+y]++;
        b[x-y+1000]++;
    }
    long long z;
    for (long long i=0;i<2009;i++){
        z=(a[i]*a[i]-a[i])/2;
        ans=ans+z;
        z=(b[i]*b[i]-b[i])/2;
        ans=ans+z;
    }
    printf("%lld\n",ans);
    return 0;
}