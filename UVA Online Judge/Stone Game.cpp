#include <iostream>
#include <stdio.h>

using namespace std;
long long n,x,y;

int main()
{
    while(scanf("%lld",&n),n){
        scanf("%lld",&x);
        for (long long i=0;i<n-1;i++){
            scanf("%lld",&y);
            x=x^y;
        }
        if (x) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
