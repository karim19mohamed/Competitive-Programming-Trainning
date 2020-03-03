#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
bool c[3600];
int n,m,ans;

int main()
{
    scanf("%d %d",&n,&m);
    c[0]=c[1]=1;
    for (int i=2;i<60;++i){
        for (int j=2;j<60;++j){
            c[i*j]=1;
        }
    }

    if (!c[n]){
        for (int i=n+1;i<60;++i){
            if (!c[i]){
                ans=i;
                break;
            }
        }
    }
    (ans==m) ? printf("YES\n") : printf("NO\n") ;
    return 0;
}

