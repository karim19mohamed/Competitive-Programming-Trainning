#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
long double r,xa,ya,xb,yb,d;
long long ans;

int main()
{
    scanf("%llf%llf%llf%llf%llf",&r,&xa,&ya,&xb,&yb);
    d=sqrt( ( (xa-xb)*(xa-xb) )+( (ya-yb)*(ya-yb) ) );
    d=ceil(d/(2*r));
    ans=d;
    printf("%lld\n",ans);
    return 0;
}