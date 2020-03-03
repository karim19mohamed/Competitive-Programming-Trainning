#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>

using namespace std;
int t,n,m,head[1009],nxt[2009],to[2009],a,b,ne,vid,qid[1009];
long long c,cost[2009],dist[1009];
queue <int> q;

void addEdge(int i,int j,long long k){
    nxt[ne]=head[i];
    to[ne]=j;
    cost[ne]=k;
    head[i]=ne++;
}
bool bellman(int u){
    memset(dist,0x3f,n*sizeof(dist[0]));
    vid++;
    q.push(u);
    dist[u]=0;qid[u]=vid;
    int nn=n;
    while (!q.empty()){
        nn--;
        int sz=q.size();
        while (sz--){
            int f=q.front();
            q.pop();qid[f]=0;
            for (int k=head[f];~k;k=nxt[k]){
                int j=to[k];long long nd=cost[k];
                if (nd+dist[f]<dist[j]){
                    dist[j]=nd+dist[f];
                    if (nn==0) return 1;
                    if (qid[j]!=vid){
                        qid[j]!=vid;q.push(j);
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d%d",&n,&m);
        memset(head,-1,n*sizeof(head[0]));
        memset(nxt,0,m*sizeof(nxt[0]));
        memset(to,0,m*sizeof(to[0]));
        memset(cost,0,m*sizeof(cost[0]));
        ne=0;
        for (int j=0;j<m;j++){
            scanf("%d%d%lld",&a,&b,&c);
            addEdge(a,b,c);
        }
        bool res=bellman(0);
        if (res) printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}
