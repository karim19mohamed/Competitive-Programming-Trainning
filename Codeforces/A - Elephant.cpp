#include <iostream>
#include <stdio.h>

using namespace std;
long long x,ans;

int main()
{
    scanf("%lld",&x);
    for (int i=5;i>0;i--){
        ans+=x/i;
        x%=i;
        if (x==0) break;
    }
    printf("%lld\n",ans);
    return 0;
}