#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int n,arr[109][109];
bool ans[109];
vector <int> res;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            if (arr[i][j]==1){
                ans[i]=1;
            }else if (arr[i][j]==2){
                ans[j]=1;
            }else if (arr[i][j]==3){
                ans[i]=1;ans[j]=1;
            }
        }
    }
    for (int i=0;i<n;i++){
        if (!ans[i]) res.push_back(i+1);
    }
    n=res.size();
    printf("%d\n",n);
    for (int i=0;i<n;i++){
        printf("%d",res[i]);
        if (i!=n-1) printf(" ");
    }
    if (n!=0) printf("\n");
    return 0;
}