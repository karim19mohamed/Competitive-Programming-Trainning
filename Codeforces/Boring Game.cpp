#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int t;
long long n,x,y,ans;

int main()
{
    freopen("boring.in", "r", stdin);
    scanf("%d",&t);
    while (t--){
        scanf("%lld%lld%lld",&n,&x,&y);
        for (long long i=1;i<=n;i++){
            if (i+1<=n){
                if (i%x==0 && (i+1)%y==0){
                    ans++;//cout << i << " " << i+1 << endl;
                }
            }
            if (i-1>0){
                if (i%x==0 && (i-1)%y==0){
                    ans++;//cout << i << " " << i-1 << endl;
                }
            }
            if (i%x==0 && i%y==0){
                ans++;//cout << i << " " << i << endl;
            }
        }
        printf("%lld\n",ans);
        ans=0;
    }
    return 0;
}
