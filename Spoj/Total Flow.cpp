#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
const int N=139,M=10009*2;
char a,b,dumy;
int n,s,t;
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
        //cout << "asda" << endl;
        flow+=f;
    }
    return flow;
}

int main()
{
    scanf("%d",&n);
    init(130);
    src=0;snk='Z'-'A';
    for (int i=0;i<n;i++){
        scanf(" %c %c",&a,&b);
        scanf("%lld",&cost);
        //cout << dumy << "  " << b << endl;
        addEdge(a-'A',b-'A',cost);
        addEdge(b-'A',a-'A',0);
        //addEdge(b-1,a-1,cost);
        //addEdge(a-1,b-1,0);

    }
    ans=maxFlow();
    printf("%lld\n",ans);
    return 0;
}
