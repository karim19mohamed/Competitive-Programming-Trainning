#include <iostream>
#include <stdio.h>

using namespace std;
int t,n,a,ans;

int main()
{
    scanf("%d",&t);
    while (t--){
        ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            ans+=(a/(i+1));
        }
        if (ans%2) printf("ALICE\n");
        else printf("BOB\n");
    }
    return 0;
}
