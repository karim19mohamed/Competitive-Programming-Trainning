#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int t;
long long s,n,num,ans;
bool chk[1009];

long long gcd (long long x,long long y){
    if (y==0) return x;
    else return gcd(y,x % y);
}

int main()
{
    freopen("car.in", "r", stdin);
    scanf("%d",&t);
    while (t--){
        scanf("%lld%lld",&s,&n);
        num=s;
        ans=0;
        for (int i=s;i<=n;i++){
            chk[i]=1;
            for (int j=s;j<=n;j++){
                if (chk[j]==0 && gcd(i,j)==1){
                    ans++;
                    break;
                }
            }
            chk[i]=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
