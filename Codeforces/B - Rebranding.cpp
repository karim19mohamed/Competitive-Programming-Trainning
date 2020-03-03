#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
long long n,m;
string s,k="abcdefghijklmnopqrstuvwxyz";
char a,b;

int main()
{
    scanf("%lld%lld",&n,&m);
    cin >> s;
    for (long long i=0;i<m;++i){
        cin >> a >> b;
        for (int j=0;j<k.size();++j){
            if (k[j]==a) k[j]=b;
            else if (k[j]==b) k[j]=a;
        }
    }
    for (long long i=0;i<n;++i){
        s[i]=k[s[i]-'a'];
    }
    cout << s << endl;
    return 0;
}
