#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
int n,a,sum,ans;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a);
        sum+=a;
    }
    for (int i=1;i<=5;++i){
        if ((sum+i)%(n+1)!=1) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
