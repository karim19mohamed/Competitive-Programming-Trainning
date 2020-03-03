#include <iostream>
#include <stdio.h>

using namespace std;
int n,arr[1009];
bool ans=1;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);
    while (arr[0]!=0){
        for (int i=0;i<n;i++){
            if (i%2==0){
                if (arr[i]==n-1){
                    arr[i]=0;
                }else{
                    arr[i]++;
                }
            }else{
                if (arr[i]==0){
                    arr[i]=n-1;
                }else{
                    arr[i]--;
                }
            }
        }
    }
    for (int i=0;i<n;i++) if(arr[i]!=i) ans=0;
    if (ans) printf("Yes\n");
    else printf("No\n");
    return 0;
}