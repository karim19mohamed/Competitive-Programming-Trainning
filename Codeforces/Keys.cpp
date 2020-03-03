#include <iostream>
#include <stdio.h>

using namespace std;
int t;
long long n,m,h,studID,d,ans;
long long arr[1000009];

int main()
{
    //freopen ("keys.in","w",stdin);
    scanf("%d",&t);
    for (int i=0;i<t;++i){
        ans=0;
        scanf("%lld%lld%lld",&n,&m,&h);
        for (long long j=0;j<h;++j){
            scanf("%lld%lld",&studID,&d);
            if (d>=n-m+1 && arr[studID]!=i+1){
                ans++;
                arr[studID]=i+1;
            }
        }
        printf("Case %d: %lld\n",i+1,ans);
    }
    return 0;
}
