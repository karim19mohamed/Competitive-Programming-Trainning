#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
int n,a,b,head[10009],nxt[10009],to[10009],ne,ans,node;
int vis[10009],vid=1;

void addEdge(int f,int t){
    nxt[ne]=head[f];
    to[ne]=t;
    head[f]=ne++;
}
int dfs(int u,int w){
    if (w>ans) {
        ans=w;node=u;
    }
    vis[u]=vid;
    for (int k=head[u];~k;k=nxt[k]){
        int j=to[k];
        if (vis[j]!=vid) dfs(j,w+1);
    }
}

int main()
{
    scanf("%d",&n);
    memset(head,-1,n*sizeof(head[0]));
    for (int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        addEdge(a-1,b-1);
        addEdge(b-1,a-1);
    }
    dfs(0,0);
    vid++;ans=0;
    dfs(node,0);
    printf("%d\n",ans);
    return 0;
}
