#include <iostream>
#include <stdio.h>

using namespace std;
long long n,le[100009],m,indx,a,ans;

int main()
{
    scanf("%lld",&n);
    for (int i=0;i<n;i++){
        scanf("%lld",&le[i]);
        if (m<le[i]){
            m=le[i];
            indx=i;
        }
    }
    for (int i=0;i<n;i++){
        if (indx!=i) a+=le[i];
    }
    ans=le[indx]-a+1;
    printf("%lld\n",ans);
    return 0;
}
