#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int n,m,a,b;
int head[10009],nxt[40009],to[40009];
int ne;
bool ves[10009];
void addEdge(int f,int t);
int dfs (int u);

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        addEdge(a-1,b-1);
        addEdge(b-1,a-1);
    }
    if (n-1!=m || dfs(0)!=n){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    return 0;
}
void addEdge(int f,int t){
    nxt[ne]=head[f];
    to[ne]=t;
    head[f]=ne++;
}
int dfs (int u){
    ves[u]=1;
    int ans=1;
    for (int i=head[u];~i;i=nxt[i]){
        if (ves[ to[i] ]==0) ans+=dfs( to[i] );
    }
    return ans;
}
