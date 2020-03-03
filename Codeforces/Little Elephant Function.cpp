#include <iostream>
#include <stdio.h>

using namespace std;
int n;

int main()
{
    scanf("%d",&n);
    printf("%d ",n);
    for (int i=1;i<n;i++){
        printf("%d",i);
        if (i!=n-1) printf(" ");
    }
    printf("\n");
    return 0;
}
