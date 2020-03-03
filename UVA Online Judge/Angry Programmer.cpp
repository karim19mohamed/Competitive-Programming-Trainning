#include <iostream>
#include <cstring>
#include <stdio.h>

#define LN(i) i*2-1-1
#define RN(i) i*2-1

using namespace std;
//const int N=59*2,M=1009*2*2+N*2;
const int N=50000,M=50000;
int n,m,a,b,BB,DD;
long long c,ans;
bool zeros[N];

int head[N],nxt[M],to[M],ne;
long long cap[M];
void init(int n){
    n*=2;
    memset(head,-1,n*sizeof(head[0]));
    memset(zeros,0,n*sizeof(zeros[0]));
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
        //cout << i << "  " << j << "  " << c << endl;
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
    while (scanf("%d%d",&n,&m),n){
        init(n*2);
        for (int i=0;i<n-2;i++){
            scanf("%d%lld",&a,&c);
            addEdge(LN(a),RN(a),c);
            addEdge(RN(a),LN(a),0);
            addEdge(RN(a),LN(a),c);
            addEdge(LN(a),RN(a),0);
            if (c==0){
                zeros[LN(a)]=zeros[RN(a)]=1;
            }
        }
        for (int i=0;i<m;i++){
            scanf("%d%d%lld",&a,&b,&c);
            if (zeros[LN(a)] || zeros[RN(a)] || zeros[LN(b)] || zeros[RN(b)]) continue;
            addEdge(RN(a),LN(b),c);
            addEdge(LN(b),RN(a),0);
            addEdge(LN(b),RN(a),c);
            addEdge(RN(a),LN(b),0);
            //cout << RN(a) << "  " << LN(b) << endl;
        }
        src=RN(1);snk=LN(n);

        ans=maxFlow();
        printf("%lld\n",ans);
    }
    return 0;
}
