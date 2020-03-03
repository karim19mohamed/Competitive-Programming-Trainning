#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;
const int N=20+1009,M=N*N;
int n,m,head[N],nxt[M],to[M],cap[M],ne,a,b,src,snk;
vector <int> arr[29];

void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
}
void addEdge(int f, int t,int c) {
	nxt[ne] = head[f];
	to[ne] = t;
	cap[ne]=c;
	head[f] = ne++;
}
void addAugEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, 0);
}
int vid,vis[N];
int dfsFlow (int i,int FLOW){
    if (i==snk) return FLOW;
    if (!FLOW) return 0;
    if (vis[i]==vid) return 0;

    vis[i]=vid;
    for (int k=head[i];~k;k=nxt[k]){
        int j=to[k];
        int c=cap[k];
        int f=dfsFlow(j,min(FLOW,c));
        if (f){
            cap[k]-=f;
            cap[k^1]+=f;
            return f;
        }
    }
    return 0;
}
int maxflow(){
    if (src==snk) return 1e4;
    int flow=0,f;
    while (vid++,f=dfsFlow(src,50000)){
        flow+=f;
    }
    return flow;
}
#define cn(ID) ID
#define cm(ID) ID+n

void dfs(){
    for (int i=0;i<m;i++){
        for (int k=head[cm(i)];~k;k=nxt[k]){
            int j=to[k];
            int c=cap[k];
            if (c==0) continue;
            if (j!=snk){
                arr[j].push_back(i+1);
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m),n){
        init(n+m+2);
        src=n+m+2-1;
        snk=n+m+2-2;
        int re=0;
        for (int i=0;i<n;i++){
            scanf("%d",&a);
            addAugEdge(src,cn(i),a);
            re+=a;
        }
        for (int i=0;i<m;i++){
            scanf("%d",&a);
            for (int j=0;j<a;j++){
                scanf("%d",&b);
                addAugEdge(cn(b-1),cm(i),1);
            }
            addAugEdge(cm(i),snk,1);
        }
        int res=maxflow();
        if (res==re){
            printf("1\n");
            dfs();
            for (int i=0;i<n;i++){
                for (int j=0;j<arr[i].size();j++){
                    printf("%d",arr[i][j]);
                    if (j!=arr[i].size()-1) printf(" ");
                }
                printf("\n");
            }
        }else{
            printf("0\n");
        }
        for(int i=0;i<n;i++){
            arr[i].erase(arr[i].begin(),arr[i].end());
        }
    }
    return 0;
}
