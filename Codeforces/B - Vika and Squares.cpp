#include <iostream>
#include <stdio.h>

using namespace std;
long long n,arr[400009],a=10000000000,b,c,ans;

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        arr[i+n]=arr[i];
        a=min(a,arr[i]);
    }
    ans=a*n;
    for (long long i=0;i<2*n;i++){
        arr[i]-=a;
        if (arr[i]!=0){
            b++;
        }else{
            c=max(c,b);
            b=0;
        }
    }
    ans+=c;
    printf("%lld\n",ans);
    return 0;
}