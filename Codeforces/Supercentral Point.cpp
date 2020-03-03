#include <iostream>
#include <stdio.h>

using namespace std;
int n,arr[209][2],ans;
bool r,l,u,d;


int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&arr[i][0],&arr[i][1]);
    for (int i=0;i<n;i++){
        int supx=arr[i][0],supy=arr[i][1];
        r=l=d=u=0;
        for (int j=0;j<n;j++){
            if (supx==arr[j][0] && supy<arr[j][1]) u=1;
            if (supx==arr[j][0] && supy>arr[j][1]) l=1;
            if (supx>arr[j][0] && supy==arr[j][1]) d=1;
            if (supx<arr[j][0] && supy==arr[j][1]) r=1;
        }
        if (r && l && d && u) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
