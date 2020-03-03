#include <iostream>
#include <stdio.h>

using namespace std;
int n,m;
long long k;
bool girl[109],boy[109],g[109],b[109];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) for (int j=1;j<=m;++j){
        if (!girl[j] || !boy[i]){
            k++;
            girl[j]=boy[i]=1;
        }
    }
    printf("%lld\n",k);
    for (int i=1;i<=n;++i) for (int j=1;j<=m;++j){
        if (!g[j] || !b[i]){
            printf("%d %d\n",i,j);
            g[j]=b[i]=1;
        }
    }
    return 0;
}