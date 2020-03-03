#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
int n,a[109],cnt[1009];
priority_queue <int> q;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        ++cnt[a[i]];
    }
    for (int i=0;i<1009;++i) if (cnt[i]!=0) q.push(cnt[i]);
    int t=q.top(),s=0;
    q.pop();
    while(!q.empty()){
        s+=q.top();
        q.pop();
    }
    (t>s+1) ? printf("NO\n"):printf("YES\n");
    return 0;
}
