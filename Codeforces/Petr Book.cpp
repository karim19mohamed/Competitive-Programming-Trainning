#include <iostream>
#include <stdio.h>

using namespace std;
int n,arr[7],ans;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<7;i++){
        scanf("%d",&arr[i]);
    }
    while (n>0){
        for (int i=0;i<7;i++){
            n-=arr[i];
            ans=i+1;
            if (n<=0) break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
