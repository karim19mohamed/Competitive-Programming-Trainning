#include <iostream>
#include <stdio.h>

using namespace std;
long long x,y,ans;

int main()
{
    scanf("%lld%lld",&x,&y);
    ans=x;
    long long w,num,k,ten,res;
    while (1){
        ans++;
        w=ans;
        ten=1;
        res=0;
        while (w!=0){
            k=w%10;
            w/=10;
            if (k==4 || k==7){
                res+=k*ten;
                ten*=10;
            }
        }
        if (res==y) break;
    }
    printf("%lld\n",ans);
    return 0;
}
