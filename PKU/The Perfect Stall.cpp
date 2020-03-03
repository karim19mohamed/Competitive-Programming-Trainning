#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
const int N=200+200+2,M=(200+200+200*200)<<1;
int head[N],to[M],nxt[M],cap[M],ne,n,m,a,b,src,snk;
int vis[N],vid;

void init (int n){
    memset(head,-1,n*sizeof(head[0]));
    ne=0;
}
void addEdge (int f,int t,int c){
    nxt[ne]=head[f];
    to[ne]=t;
    cap[ne]=c;
    head[f]=ne++;
}
void addAugEdge(int f,int t,int c){
    addEdge(f,t,c);
    addEdge(t,f,0);
}
int dfs (int i,int Flow){
    if (i==snk) return Flow;
    if (!Flow) return 0;
    if (vis[i]==vid) return 0;
    vis[i]=vid;
    for (int k=head[i];~k;k=nxt[k]){
        int j=to[k],c=cap[k];
        int f=dfs(j,min(c,Flow));
        if (f){
            cap[k]-=f;
            cap[k^1]+=f;
            return f;
        }
    }
    return 0;
}
int MaxFlow(){
    if (snk==src) return 1e5;
    int flow=0,f;
    while (vid++,f=dfs(src,1e5)){
        flow+=f;
    }
    return flow;
}

#define c(ID) (ID)
#define s(ID) (ID+n)

int main()
{
    while (cin >>n >>m){
    init(n+m+2);
    src=n+m+2-2;
    snk=n+m+2-1;
    for (int i=0;i<n;i++){
        scanf("%d",&a);
        addAugEdge(src,c(i),1);
        for (int j=0;j<a;j++){
            scanf("%d",&b);
            addAugEdge(c(i),s(b-1),1e5);
        }
    }
    for (int i=0;i<m;i++) addAugEdge(s(i),snk,1);
    printf("%d\n",MaxFlow());
    }
    return 0;
}
