#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
const int N=109,M=10009*2;
int n,s,t,a,b;
long long c,ans,cost;
int head[N],nxt[M],to[M],ne;
long long cap[M];
void init(int n){
    memset(head,-1,n*sizeof(head[0]));
    ne=0;
}
void addEdge (int f,int t,long long c){
    nxt[ne]=head[f];
    to[ne]=t;
    cap[ne]=c;
    head[f]=ne++;
}
int vis[N],vid,src,snk;
long long dfs(int i,long long flow){
    if (!flow) return 0;
    if (vis[i]==vid) return 0;
    if (i==snk) return flow;
    vis[i]=vid;
    for (int k=head[i];~k;k=nxt[k]){
        int j=to[k];long long c=cap[k];
        long long f=dfs(j,min(flow,c));
        if (f){
            cap[k]-=f;
            cap[k^1]+=f;
            return f;
        }
    }
    return 0;
}
long long maxFlow(){
    long long flow=0,f;
    while (vid++,(f=dfs(src,1e10))){
        flow+=f;
    }
    return flow;
}

int main()
{
    int tc=0;
    while (scanf("%d",&n),n){
        init(n);
        scanf("%d%d%lld",&s,&t,&c);
        src=s-1;snk=t-1;
        for (long long i=0;i<c;i++){
            scanf("%d%d%lld",&a,&b,&cost);
            addEdge(a-1,b-1,cost);
            addEdge(b-1,a-1,0);
            addEdge(b-1,a-1,cost);
            addEdge(a-1,b-1,0);

        }
        ans=maxFlow();
        printf("Network %d\nThe bandwidth is %lld.\n\n",++tc,ans);
    }
    return 0;
}
