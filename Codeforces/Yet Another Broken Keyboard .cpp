#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
int n,k,l;
long long a,ans;
string s;
map<char,bool> arr;
char c;


int main()
{
    scanf("%d %d",&n,&k);
    cin >> s;
    scanf("%c",&c);
    for (int i=0;i<k;++i){
        scanf("%c",&c);
        //cout << c << endl;
        arr[c]=1;
        if (i!=k-1) scanf("%c",&c);
    }
    //cout << arr['a'] << " " << arr['b'] << endl;
    for (int i=0;i<s.length();++i){
        char tmp=s[i];

        if (arr[tmp]){
            ++a;
        }else{
            ans+=(a*(a+1)/2);
            a=0;
        }
        //cout << tmp << "  " << arr[tmp] << "  " << a << endl;
    }
    if (a!=0) ans+=(a*(a+1)/2);
    printf("%lld\n",ans);
    return 0;
}
