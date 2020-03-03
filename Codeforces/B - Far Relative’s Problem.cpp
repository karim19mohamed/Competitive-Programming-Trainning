#include <iostream>
#include <stdio.h>

using namespace std;
int n,m,f,ans;
int arr[5009][3];
char c;

int main()
{
    scanf ("%d",&n);
    for (int i=0;i<n;i++){
        cin >> c >> arr[i][1] >> arr[i][2];
        if (c=='M') arr[i][0]=1;
    }
    for (int k=1;k<369;k++){
        m=0;f=0;
        for (int i=0;i<n;i++){
            if (arr[i][1]<=k && arr[i][2]>=k){
                if (arr[i][0]==1){
                    m++;
                }else{
                    f++;
                }
            }
        }
        ans=max(ans,2*min(m,f));
    }
    printf("%d\n",ans);
    return 0;
}