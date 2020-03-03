#include <iostream>
#include <stdio.h>

using namespace std;
int k,l,m;
long long n[59];
bool arr[1000009];

int main()
{
    scanf("%d%d%d",&k,&l,&m);
    for (int i=0;i<m;++i) scanf("%lld",&n[i]);
    for (long long i=1;i<1000009;++i){
        if (i-k>=0){
            if (!arr[i-k]){
                arr[i]=1;
                continue;
            }
        }
        if (i-l>=0){
            if (!arr[i-l]){
                arr[i]=1;
                continue;
            }
        }
        if (!arr[i-1]){
            arr[i]=1;
            continue;
        }
    }
    for (int i=0;i<m;++i){
        if (arr[n[i]]) printf("A");
        else printf("B");
    }
    printf("\n");
    return 0;
}
