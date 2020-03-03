#include <iostream>
#include <stdio.h>

using namespace std;
int k,l,m,n;
long long ans, d;

int main()
{
    scanf("%d%d%d%d%lld",&k,&l,&m,&n,&d);
    ans=d;
    for (int i=1;i<=d;i++){
        if (i%k!=0 && i%l!=0 && i%m!=0 && i%n!=0) ans--;
    }
    printf("%lld\n",ans);
    return 0;
}
