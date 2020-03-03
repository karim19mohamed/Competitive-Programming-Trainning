#include <iostream>
#include <stdio.h>

using namespace std;
int n,s,ans,a,b[1009],c;

int main()
{
    scanf("%d%d",&n,&s);
    for (int i=0;i<n;++i){
        scanf("%d",&a);
        scanf("%d",&c);
        b[a]=max(b[a],c);
    }
    for (int i=s;i>0;--i){
        if (b[i]-ans>0){;
            ans=b[i]+1;
        }else{
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
