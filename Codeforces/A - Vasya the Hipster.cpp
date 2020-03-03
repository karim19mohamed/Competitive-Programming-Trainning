#include <iostream>
#include <stdio.h>

using namespace std;
int a,b,n,m;

int main()
{
    scanf("%d%d",&a,&b);
    n=min(a,b);
    m=max(a,b);
    m=(m-n)/2;
    printf("%d %d\n",n,m);
    return 0;
}