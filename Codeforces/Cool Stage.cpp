#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;
int t,n,ans;

int main()
{
    freopen("paint.in", "r", stdin);
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        ans=n*2;
        /*for (int i=0;i<n;i++){
            ans+=2;
        }*/
        printf("%d\n",ans);
    }
    return 0;
}
