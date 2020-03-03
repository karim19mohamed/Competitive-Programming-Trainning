#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
long long x,y,n,k;
bool t;

int main()
{
    scanf("%lld %lld %lld",&y,&k,&n);
    long long i=1;
    while (i*k<=n){
        if (i*k-y>0){
            x=i*k-y;
        }else{
            ++i;
            continue;
        }
        if (!t){
            printf("%lld",x);
            t=1;
        }else{
            printf(" %lld",x);
        }
        ++i;
    }
    if (x==0) printf("-1");
    printf("\n");
    return 0;
}
