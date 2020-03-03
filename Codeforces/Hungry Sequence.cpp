#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
int n;
long long ans;
bool b[10000009],not_b[10000009];

int main()
{
    scanf("%d",&n);
    for (long long i=2;i<10000000;++i){
        if (ans>100000) break;
        if (!not_b[i]){
            b[i]=1;
            ans++;
            int x=2,k=i;
            while(k*x<10000001){
                not_b[k*x]=1;
                ++x;
            }
        }

    }
    printf("2");
    for (long long i=3;i<10000000 && n>1;++i){
        if (b[i]){
            printf(" %lld",i);
            --n;
        }
    }
    printf("\n");
    return 0;
}
