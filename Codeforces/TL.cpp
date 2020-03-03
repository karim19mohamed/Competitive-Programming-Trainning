#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
int n,m,a[109],b[109],min_a=1000,min_b=1000,max_a;
int ans;

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        min_a=min(min_a,a[i]);
        max_a=max(max_a,a[i]);
    }
    for (int i=0;i<m;++i){
        scanf("%d",&b[i]);
        min_b=min(min_b,b[i]);
    }
    ans=max_a;
    min_a*=2;
    if( (ans<min_a && min_a>=min_b) || (ans>=min_b) ){
        printf("-1\n");
    }else if (ans<min_a){
        printf("%d\n",min_a);
    }else{
        printf("%d\n",ans);
    }
    return 0;
}
