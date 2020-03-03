#include <iostream>
#include <stdio.h>

using namespace std;
long long n,a,ans;

int main()
{
    scanf("%lld",&n);
    for (int i=0;i<n;i++){
        scanf("%lld",&a);
        ans^=i;
    }
    if (ans!=0) printf("first player\n");
    else printf("second player\n");
    return 0;
}
