#include <iostream>
#include <stdio.h>

using namespace std;
long long n,k;
long long arr[100009];
long long ans;

int main()
{
    scanf("%lld %lld",&n,&k);
    for (long long i=0;i<n;++i){
        scanf("%lld",&arr[i]);
    }
    bool x=0;
    long long c=arr[k-1];
    for(long long i=k-1;i<n;++i){
        if (arr[i]!=c){
            x=1;
            break;
        }
    }
    if (x==1) printf("-1");
    else{
        bool x=0;
        long long idx=-1;
        for (long long i=k-2;i>=0;--i){
            if (arr[i]!=c) {
                idx=i+1;
                break;
            }
        }
        (idx!=-1) ? ans=idx : ans=0;
        printf("%lld",ans);
    }
    return 0;
}
