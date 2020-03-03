#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int n;

int main()
{
    scanf("%d",&n);
    if (n%2){
        printf("-1\n");
    }else{
        for (int i=1;i<=n;i+=2){
            printf("%d %d",i+1,i);
            if (i+2<n){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

