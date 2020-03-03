#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>

using namespace std;
long long n,m,a,b,c,head[10009],nxt[10009],to[10009],cost[10009],ne,sc=1,an;
long long dis[10009],ans[10009];
priority_queue <pair<long long,pair<long long,long long> > > q;

void addEdge (long long f,long long t, long long d){
    nxt[ne]=head[f];
    to[ne]=t;
    cost[ne]=d;
    head[f]=ne++;
}
void init(long long k){
    for (long long i=0;i<k;i++){
        head[i]=-1;to[i]=0;cost[i]=0;
        dis[i]=0;
        ans[i]=6000000000;
    }
    ne=0;
}
void prim(long long u){
    dis[u]=0;
    q.push({0,{-1,u}});
    while (!q.empty()){
        long long w=q.top().first,v=q.top().second.second,pre=q.top().second.first;
        q.pop();
        if (w!=dis[v]) continue;
        if (pre!=-1){
            ans[v]=min(ans[pre],w);
        }
        for (long long k=head[v];~k;k=nxt[k]){
            long long j=to[k],h=cost[k];
            if (dis[j]<h){
                dis[j]=h;
                q.push({h,{v,j}});
            }
        }
    }
}

int main()
{
    while (1){
        scanf("%lld%lld",&n,&m);
        if (n==0) break;
        init(n);
        for (long long i=0;i<m;i++){
            scanf("%lld%lld%lld",&a,&b,&c);
            addEdge(a-1,b-1,c);
            addEdge(b-1,a-1,c);
        }
        scanf("%lld%lld%lld",&a,&b,&c);
        prim(b-1);
        for (long long i=0;i<n;i++) if (ans[i]==6000000000) prim(i);
        ans[a-1]--;
        an=(c+ans[a-1]-1)/(ans[a-1]);
        if (a!=b) printf("Scenario #%lld\nMinimum Number of Trips = %lld\n\n",sc,an);
        else printf("Scenario #%lld\nMinimum Number of Trips = 0\n\n",sc);
        sc++;
    }
    return 0;
}
