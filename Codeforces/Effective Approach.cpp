#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
int n,m,a[100009],b[100009],pos[100009];
long long ans1,ans2;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    scanf("%d",&m);
    for (int i=0;i<m;++i){
        scanf("%d",&b[i]);
        ans1+=(long long) (pos[b[i]])+1;
        ans2+=(long long)(n)-(long long)(pos[b[i]]);
    }
    printf("%lld %lld\n",ans1,ans2);
    return 0;
}
