#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
int q,d,u,r,l,ans;
string s;


int main()
{
    scanf("%d",&q);
    for (int i=0;i<q;++i){
        cin >> s;
        for(int j=0;j<s.length();++j){
            if (s[j]=='D') ++d;
            else if (s[j]=='U') ++u;
            else if (s[j]=='L') ++l;
            else ++r;
        }
        int a =min(d,u),b=min(r,l);
        if (a==0) b=1;
        if (b==0) a=1;
        if ((d==0 && u==0 && l==0) || (d==0 && u==0 && r==0) || (d==0 && l==0 && r==0) || (u==0 && l==0 && r==0)){
            a=0;
            b=0;
        }
        if (d==0 || u==0) a=0;
        if (r==0 || l==0) b=0;
        ans=2*a+2*b;
        printf("%d\n",ans);
        if (ans!=0){
            for (int j=0;j<a;++j) printf("D");
            for (int j=0;j<b;++j) printf("R");
            for (int j=0;j<a;++j) printf("U");
            for (int j=0;j<b;++j) printf("L");
        }
        printf("\n");
        d=0;
        u=0;
        r=0;
        l=0;
    }
    return 0;
}
