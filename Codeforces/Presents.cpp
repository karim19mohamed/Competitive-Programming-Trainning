#include <iostream>
#include <stdio.h>

using namespace std;
int n,arr[109],ans[109];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        ans[arr[i]-1]=i+1;
    }
    for (int i=0;i<n;i++){
        printf("%d",ans[i]);
        if (i!=n-1) printf(" ");
    }
    printf("\n");
    return 0;
}
