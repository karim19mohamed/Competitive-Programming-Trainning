#include <iostream>
#include <stdio.h>
#include <cmath>


using namespace std;
long long a,b,c,r,t;

int main()
{
    scanf("%lld",&t);
    for(long long i=0;i<t;++i){
        scanf("%lld %lld %lld %lld",&a,&b,&c,&r);
        if (a<c-r){
            if (b<=a) printf("%lld\n",abs(a-b));
            else if (b<=c-r) printf("%lld\n",abs(a-b));
            else if (b>=c-r && b<=c+r) printf("%lld\n",abs(a-(c-r)));
            else if (b>c+r) printf("%lld\n",abs(a-(c-r))+abs(b-(c+r)));
        }else if (a>=c-r && a<=c+r){
            if (b<c-r) printf("%lld\n",abs(b-(c-r)));
            else if (b>=c-r && b<=c+r) printf("0\n");
            else if (b>c+r) printf("%lld\n",abs(b-(c+r)));
        }else if (a>c+r){
            if (b>a) printf("%lld\n",abs(b-a));
            else if (b>=c+r) printf("%lld\n",abs(b-a));
            else if (b>=c-r && b<=c+r)printf("%lld\n",abs(a-(c+r)));
            else if (b<c-r) printf("%lld\n",abs(a-(c+r))+abs(b-(c-r)));
        }
    }
    return 0;
}
