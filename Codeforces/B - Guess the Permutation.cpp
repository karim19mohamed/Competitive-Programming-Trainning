#include <iostream>
#include <stdio.h>

using namespace std;
int n,arr[59][59],ans[59],m[59],a;
bool c[59];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        a=0;
        for (int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            a=max(a,arr[i][j]);
        }
        m[i]=a;
    }
    for (int i=0;i<n;i++){
        for (int j=1;j<=n;j++){
            if (!c[j] && j>=m[i]){
                c[j]=1;
                ans[i]=j;
                break;
            }
        }
    }
    for (int i=0;i<n;i++){
        printf("%d",ans[i]);
        if (i!=n-1) printf(" ");
    }
    return 0;
}