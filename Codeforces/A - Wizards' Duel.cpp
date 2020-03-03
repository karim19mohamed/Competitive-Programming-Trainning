#include <iostream>
#include <stdio.h>

using namespace std;
double ans,l,p,q;

int main()
{
    scanf("%lf%lf%lf",&l,&p,&q);
    ans=p*l/(p+q);
    printf("%.6lf\n",ans);
    return 0;
}
