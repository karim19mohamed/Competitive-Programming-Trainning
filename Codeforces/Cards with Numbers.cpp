#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
long long n;
int a[600009];
priority_queue < pair<int,long long> > q;
map <int,long long> m;
bool ans=1;

int main()
{
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    scanf("%lld",&n);
    for (long long i=0;i<2*n;++i){
        scanf("%d",&a[i]);
        ++m[a[i]];
        q.push(make_pair(a[i],i+1));
    }
    for (long long i=0;i<2*n;++i){
        if (m[a[i]]%2!=0){
            ans=0;
            break;
        }
    }
    if (ans==1){
        while (!q.empty()){
            printf("%lld",q.top().second);
            q.pop();
            printf(" %lld\n",q.top().second);
            q.pop();
        }
    }else{
        printf("-1\n");
    }
    return 0;
}
