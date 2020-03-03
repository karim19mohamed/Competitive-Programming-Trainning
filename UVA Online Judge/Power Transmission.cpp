#include <iostream>
#include <cstring>
#include <stdio.h>

#define LN(i) i*2-1
#define RN(i) i*2

using namespace std;
const int N=109*2+2,M=N*N*2;
int n,a,b,BB,DD;
long long c,m,ans;

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
    while (cin>>n){
        init(n*2+2);
        for (int i=1;i<=n;i++){
            scanf("%lld",&c);
            addEdge(RN(i),LN(i),c);
            addEdge(LN(i),RN(i),0);
            //cout << RN(i) << "  " << LN(i) << "  " << c << endl;
        }

        scanf("%lld",&m);
        for (long long i=0;i<m;i++){
            scanf("%d%d%lld",&a,&b,&c);
            addEdge(LN(a),RN(b),c);
            addEdge(RN(b),LN(a),0);
        }
        scanf("%d%d",&BB,&DD);
        for (int i=0;i<BB;i++){
            scanf("%d",&a);
            addEdge(0,RN(a),1000000000);
            addEdge(RN(a),0,0);
        }
        for (int i=0;i<DD;i++){
            scanf("%d",&a);
            addEdge(LN(a),(n*2)+1,1000000000);
            addEdge((n*2)+1,LN(a),0);
        }
        src=0;snk=(n*2)+1;
        ans=maxFlow();
        printf("%lld\n",ans);
    }
    return 0;
}
