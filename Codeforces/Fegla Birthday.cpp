#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;
int t;
long long n,c,ans[200009],k=1,p=1;

int main()
{
    //
    while (c<200009){
        c=((k*k)-k)/2;
        c+=k+1;
        for (int i=p;i<=c;i++){
            ans[i]=k;
        }
        //cout << c << endl;
        //char z;cin>>z;
        k++;
        p=c+1;
    }
    ans[1]=0;
    //freopen("cake.in", "r", stdin);
    scanf("%d",&t);
    while (t--){
        scanf("%lld",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}
