#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
long long a,b,c,arr[1002009],ans;

int main()
{
    scanf("%lld %lld %lld",&a,&b,&c);
    for (long long i=1;i<=1000001;++i){
        for (long long j=1;j<=1000001/i;++j){
            ++arr[i*j];
        }
    }
    for (long long i=1;i<=a;++i){
        for (long long j=1;j<=b;++j){
            for (long long k=1;k<=c;++k){
                ans+=arr[i*j*k];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
