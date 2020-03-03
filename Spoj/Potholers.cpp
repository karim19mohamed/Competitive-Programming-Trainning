#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
const int N=209,M=N*N*2;
int t,n,m,a,b;
long long c,ans;

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
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init(n);
        for (int i=0;i<n-1;i++){
            scanf("%d",&a);
            for (int j=0;j<a;j++){
                scanf("%d",&b);
                addEdge(i,b-1,(i==0 || b-1==n-1)? 1 : 100000000);
                addEdge(b-1,i,0);
            }
        }
        src=0;snk=n-1;
        ans=maxFlow();
        printf("%lld\n",ans);
    }
    return 0;
}
