#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
double a,b,ma,mb,ans;

int main()
{
    scanf("%lf %lf",&a,&b);
    if (b>a) printf("-1\n");
    else if (b!=a) {
        ma=floor((a-b)/(2*b));
        mb=floor((a+b)/(2*b));
        ma=(a-b)/(2*ma);
        mb=(a+b)/(2*mb);
        ans=min(ma,mb);
        printf("%.11lf\n",ans);
    }else{
        mb=floor((a+b)/(2*b));
        ans=(a+b)/(2*mb);
        printf("%.11lf\n",ans);
    }
    return 0;
}
