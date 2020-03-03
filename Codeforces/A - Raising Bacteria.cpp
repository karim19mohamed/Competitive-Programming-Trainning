#include <iostream>
#include <bitset>
#include <stdio.h>

using namespace std;
long long n,ans;
bitset <32> x;

int main()
{
    scanf("%lld",&n);
    x=n;
    ans=x.count();
    printf("%lld\n",ans);
    return 0;
}
