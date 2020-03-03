#include <iostream>
#include <stdio.h>

using namespace std;
int n,m,x,y;
bool ans=1,arr[109];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i){
        scanf("%d",&x);
        for (int j=0;j<x;++j){
            scanf("%d",&y);
            arr[y-1]=1;
        }
    }
    for (int i=0;i<m;++i){
        if (arr[i]==0) ans=0;
    }
    ((ans)?printf("YES\n"):printf("NO\n"));
    return 0;
}