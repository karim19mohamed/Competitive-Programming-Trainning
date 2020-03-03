#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;
string s,p;
long long n,a,ans;
int k;
map <string,bool> m;

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;++i){
        scanf("%lld",&a);
        if (a) s=s+"1";
        else s=s+"0";
    }
    while (1){
        p=s;
        m[s]=1;
        k=0;
        for (long long i=1;i<n-1;++i){
            k=p[i-1]+p[i]+p[i+1]-'0'-'0'-'0';
            if (k>1) s[i]='1';
            else s[i]='0';
        }
        if (s==p){
            printf("%lld\n",ans);
            cout << s[0];
            for (long long i=1;i<n;++i){
                cout << " " << s[i];
            }
            cout << endl;
            break;
        }else if (m[s]){
            printf("-1\n");
            break;
        }
        ans++;
    }
    return 0;
}
