#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>

using namespace std;
int n,t,a,b,head[50009],nxt[100009],to[100009],ne,vid=1,checker;
long long cst[100009],c,ans;
int vis[50009];
string s;

void addEdge(int i,int j,long long k){
    nxt[ne]=head[i];
    to[ne]=j;
    cst[ne]=k;
    head[i]=ne++;
}
void dfs(int u,long long w){
    if (ans<w){
        ans=w;checker=u;
    }
    vis[u]=vid;
    for (int k=head[u];~k;k=nxt[k]){
        int j=to[k];
        if (vis[j]!=vid) dfs(j,w+cst[k]);
    }
}

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d",&n);
        memset(head,-1,n*sizeof(head[0]));
        memset(nxt,0,n*sizeof(nxt[0]));
        memset(to,0,n*sizeof(to[0]));
        memset(cst,0,n*sizeof(cst[0]));
        ne=0;ans=0;checker=0;
        //if (n==50000) n=43;
        for (int j=0;j<n-1;j++){
            scanf("%d%d%lld",&a,&b,&c);
            addEdge(a-1,b-1,c);
            addEdge(b-1,a-1,c);
        }
        dfs(0,0);
        vid++;
        ans=0;
        dfs(checker,0);
        vid++;
        printf("%lld\n",ans);
    }
    return 0;
}
