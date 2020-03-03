#include <iostream>
#include <stdio.h>

using namespace std;
long long a,b,c,ans,n,m;

int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    if (a==b && b==c){
        printf("%lld\n",a);
    }else if (a==0 || b==0 || c==0){
        ans+=a/3; a%=3;
        ans+=b/3; b%=3;
        ans+=c/3; c%=3;
        printf("%lld\n",ans);
    }else{
        ans+=a/3; a%=3;
        ans+=b/3; b%=3;
        ans+=c/3; c%=3;
        if (a==1) n++; else if (a==2) m++;
        if (b==1) n++; else if (b==2) m++;
        if (c==1) n++; else if (c==2) m++;
        if ((n==2 && m==1) || n==3) ans++;
        else if (m==3) ans+=2;
        else if (m==2) ans++;
        printf("%lld\n",ans);
    }
    return 0;
}