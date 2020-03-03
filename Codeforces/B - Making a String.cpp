#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int n;
long long a[30],ans,b=1000000009;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        a[i]=-a[i];
    }
    sort(a,a+n);
    for (int i=0;i<n;i++){
        a[i]=-a[i];
        if (b==0) break;
        if (a[i]<b){
            ans+=a[i];
            b=a[i];
        }else{
            b--;
            ans+=b;
        }
    }
    printf("%lld\n",ans);
    return 0;
}