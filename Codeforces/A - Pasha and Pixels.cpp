#include <iostream>
#include <stdio.h>

using namespace std;
int n,m,i,j,ans;
bool arr[1009][1009];
long long k;

int main()
{
    scanf("%d%d%lld",&n,&m,&k);
    bool w=1;
    for (long long z=0;z<k;z++){
        scanf("%d%d",&i,&j);
        arr[i][j]=1;
        if (arr[i+1][j] && arr[i+1][j-1] && arr[i][j-1] && w){
            ans=z+1;w=0;
        }else if (arr[i][j+1] && arr[i+1][j+1] && arr[i+1][j] && w){
            ans=z+1;w=0;
        }else if (arr[i-1][j] && arr[i-1][j-1] && arr[i][j-1] && w){
            ans=z+1;w=0;
        }else if (arr[i-1][j] && arr[i-1][j+1] && arr[i][j+1] && w){
            ans=z+1;w=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}