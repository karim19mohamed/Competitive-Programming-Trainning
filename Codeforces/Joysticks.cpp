#include <iostream>
#include <stdio.h>

using namespace std;
int a,b,ans;

int main()
{
    scanf("%d%d",&a,&b);
    while(a>0 && b>0){
        if (a==1 && b==1) break;
        if (a<=b){
            a++;
            b-=2;
        }else{
            b++;
            a-=2;
        }
        ans++;

    }

    printf("%d\n",ans);
    return 0;
}
