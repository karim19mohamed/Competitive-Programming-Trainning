#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
int n,s,t,d[109],q,w;
long long sum,ans;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&d[i]);
        sum+=d[i];
    }
    scanf("%d%d",&s,&t);
    q=min(s,t);
    w=max(s,t);
    for (int i=q-1;i<w-1;i++){
        ans+=d[i];
    }
    sum=abs(ans-sum);
    ans=min(ans,sum);
    printf("%lld\n",ans);
    return 0;
}