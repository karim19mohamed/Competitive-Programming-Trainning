#include <iostream>
#include <stdio.h>

using namespace std;
int n,t;

int main()
{
    scanf("%d%d",&n,&t);
    if (n==1 && t==10){
        printf("-1");
    }else if (t!=10){
        printf("%d",t);
        for (int i=1;i<n;++i) printf("0");
    }else if (t==10){
        printf("%d",t);
        for (int i=2;i<n;++i) printf("0");
    }
    printf("\n");
    return 0;
}