#include <iostream>
#include <stdio.h>

using namespace std;
int n,m,r,c,t;
int a,b,d,e;

int main()
{
    scanf("%d",&t);
    while (t--){
        scanf("%d%d%d%d",&n,&m,&r,&c);
        r++;c++;
        a=r-1;
        b=c-1;
        d=n-r;
        e=m-c;
        if (a^b^d^e) printf("Gretel\n");
        else printf("Hansel\n");
    }
    return 0;
}
