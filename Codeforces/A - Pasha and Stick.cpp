#include <iostream>
#include <stdio.h>

using namespace std;
long long n,ans;

int main()
{
    scanf("%lld",&n);
    if (n%2==1){
        printf("0\n");
    }else{
        n/=2;
        if (n%2==1){
            ans=n/2;
        }else{
            ans=(n/2)-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}