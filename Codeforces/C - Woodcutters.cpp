#include <iostream>
#include <stdio.h>

using namespace std;
long long n,x[100009],h[100009],ans=1;

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;i++){
        scanf("%lld%lld",&x[i],&h[i]);
    }
    if (n==1){
        printf("%lld\n",ans);
    }else{
        ans++;
        for (long long i=1;i<n-1;i++){
            if (x[i]-h[i]>x[i-1]){
                ans++;
            }else if (x[i]+h[i]<x[i+1]){
                ans++;
                x[i]=x[i]+h[i];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}