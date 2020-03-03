#include <iostream>
#include <stdio.h>
#include <map>
#include <set>

using namespace std;
int t,n;
long long a,ans,num;
set <long long> s;
set<long long>::iterator it;
map <long long,long long> m;

int main()
{
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        ans=0;
        for (int i=0;i<n;++i){
            scanf("%d",&a);
            while (a!=1){
                num=a/2;
                a=a-num;
                cout << num << "  " << a << endl;
                ans^=num;
            }
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
