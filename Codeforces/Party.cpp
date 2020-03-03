#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>

using namespace std;
int n,a,head[2009],nxt[2009],to[2009],ne,ans;
queue <int> q;
int vis[2009],vid=1;

void addEdge (int f,int t){
    nxt[ne]=head[f];
    to[ne]=t;
    head[f]=ne++;
}
void dfs (int u,int w){
    vis[u]=vid;
    ans=max(ans,w);
    for (int k=head[u];~k;k=nxt[k]){
        int j=to[k];
        if (vis[j]!=vid){
            dfs(j,w+1);
        }
    }
}

int main()
{
    scanf("%d",&n);
    memset(head,-1,n*sizeof(head[0]));
    for (int i=0;i<n;i++){
        scanf("%d",&a);
        if (a==-1) q.push(i);
        else addEdge(a-1,i);
    }
    while (!q.empty()){
        int k=q.front();
        q.pop();
        dfs(k,1);
    }
    printf("%d\n",ans);
    return 0;
}
