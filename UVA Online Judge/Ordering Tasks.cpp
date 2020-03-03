#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;
int n,m,head[109],nxt[100009],to[100009],a,b,ne,vis[109];
queue <int> q;

void addEdge (int i,int j){
    nxt[ne]=head[i];
    to[ne]=j;
    head[i]=ne++;
}
void dfs(int u){
    vis[u]=1;
    for (int k=head[u];~k;k=nxt[k]){
        int j=to[k];
        if (vis[j]==0) dfs(j);
    }
    q.push(u+1);
}

int main()
{
    while (1){
        scanf("%d%d",&n,&m);
        if (n==0) break;
        memset(head,-1,n*sizeof(head[0]));
        memset(nxt,0,m*sizeof(nxt[0]));
        memset(to,0,m*sizeof(to[0]));
        memset(vis,0,n*sizeof(vis[0]));
        ne=0;
        for (int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            addEdge(b-1,a-1);
        }
        for (int i=0;i<n;i++) if (vis[i]==0) dfs(i);
        while (!q.empty()){
            int j=q.front();
            q.pop();
            printf("%d",j);
            if (q.size()!=0) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
