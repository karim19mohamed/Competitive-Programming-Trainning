#include <iostream>
#include <stdio.h>

using namespace std;
int n,ans;
char c;
bool arr[109][109],ch[109];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            cin >> c;
            if (c=='0') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (!arr[i][j]) ch[j]=1;
        }
        int b=0;
        for (int j=0;j<n;++j){
            bool a=1;
            for (int k=0;k<n;++k){
                if (!(arr[j][k]^ch[k])) a=0;
            }
            if (a) b++;
        }
        ans=max(ans,b);
        for (int j=0;j<n;++j){
            if (!arr[i][j]) ch[j]=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}
