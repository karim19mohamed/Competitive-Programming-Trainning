#include <iostream>
#include <queue>
#include <cstring>
#include <stdio.h>

using namespace std;
int n,m,a,b;
double c,ans[109],cst[10009],dis[109];
priority_queue < pair<double,int > > q;
int head[109],nxt[10009],to[10009],ne;

void addEdge(int i,int j,double k){
    nxt[ne]=head[i];
    to[ne]=j;
    cst[ne]=k;
    head[i]=ne++;
}

void dijikstra(int u){
    dis[u]=0;
    ans[u]=1;
    q.push({0,u});
    while (!q.empty()){
        int v=q.top().second;
        int w=-q.top().first;
        q.pop();
        if (w>dis[v]) continue;
        for (int k=head[v];~k;k=nxt[k]){
            int j=to[k];
            double i=cst[k]+dis[v];
            if (dis[j]>i){
                dis[j]=i;
                ans[j]=ans[v]*(100-cst[k])/100;
                q.push({-dis[j],j});
            }
        }
    }
}
int main()
{
    while (1){
        scanf("%d",&n);
        if (n==0) break;
        memset(head,-1,n*sizeof(head[0]));
        ne=0;
        for (int i=0;i<n;i++){
            ans[i]=1;dis[i]=100000000;
        }
        scanf("%d",&m);
        for (int i=0;i<m;i++){
            scanf("%d%d%lf",&a,&b,&c);
            addEdge(a-1,b-1,100-c);
            addEdge(b-1,a-1,100-c);
        }
        dijikstra(0);
        ans[n-1]*=100;
        printf("%.6lf percent\n",ans[n-1]);
    }
    return 0;
}




