#include <iostream>
#include <stdio.h>

using namespace std;
int arr[48],t,n;
int ones;

int main()
{
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        ones=0;
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            if (arr[i]==1) ones++;
        }
        if (ones==n){
            if (ones%2==0){
                printf("John\n");
            }else{
                printf("Brother\n");
            }
        }else{
            for (int i=1;i<n;++i) arr[0]^=arr[i];
            if (arr[0]==0){
                printf("Brother\n");
            }else{
                printf("John\n");
            }
        }
    }
    return 0;
}
