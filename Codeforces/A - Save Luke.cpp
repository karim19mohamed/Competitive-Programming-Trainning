#include <iostream>
#include <stdio.h>

using namespace std;
double d,l,vi,ve,ans;

int main()
{
    scanf("%lf%lf%lf%lf",&d,&l,&vi,&ve);
    ans=(l-d)/(vi+ve);
    printf("%.7lf\n",ans);
    return 0;
}