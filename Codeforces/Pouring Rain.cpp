#include <iostream>
#include <stdio.h>

using namespace std;
const double pi=3.1415926;
double d,h,v,e,ans,dom;

int main()
{
    scanf("%lf%lf%lf%lf",&d,&h,&v,&e);
    dom=v-pi*((d*d)/4)*e;
    if (dom<=0){
        printf("NO\n");
    }else{
        ans=(pi*((d*d)/4)*h)/dom;
        printf("YES\n%.5lf\n",ans);
    }
    return 0;
}
