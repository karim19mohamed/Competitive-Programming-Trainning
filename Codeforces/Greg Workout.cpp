#include <iostream>
#include <stdio.h>

using namespace std;
int n,x,a,b,c;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&x);
        if (i%3==0) a+=x;
        else if (i%3==1) b+=x;
        else if (i%3==2) c+=x;
    }
    int m=0;
    m=max(a,b);
    m=max(m,c);
    if (m==a) printf("chest\n");
    else if (m==b) printf("biceps\n");
    else if (m==c) printf("back\n");
    return 0;
}
