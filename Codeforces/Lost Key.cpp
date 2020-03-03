#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;
int t,n;
long long ans;
int w=60;

int main()
{
    freopen("alost.in", "r", stdin);
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        ans=w*n;
        printf("%lld\n",ans);
    }
    return 0;
}
