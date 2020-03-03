#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;
int t,n,a,p,r;
long long c;
string nam,x,y;
map <string,int> arr;
int head[10009],nxt[100000009],to[100000009];
long long cost[100000009];
int ne;
priority_queue < pair<long long,int> > q;
long long dis[10009];
void addEdge (int f,int t,long long e);
void dijkstra (int u);

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d",&n);
        memset(head,-1,n*sizeof(head[0]));
        memset(nxt,0,ne*sizeof(nxt[0]));
        memset(to,0,ne*sizeof(to[0]));
        memset(cost,0,ne*sizeof(cost[0]));
        ne=0;
        for (int j=0;j<n;j++){
            cin >> nam ;
            scanf("%d",&p);
            arr[nam]=j;
            //cout << nam << "  " << p << endl;
            for (int k=0;k<p;k++){
                scanf("%d%lld",&a,&c);
                addEdge(j,a-1,c);
                //cout << a << "  " << c << endl;
            }
        }
        scanf("%d",&r);
        for (int j=0;j<r;j++){
            cin >> x >> y;
            memset(dis,1,n*sizeof(dis[0]));
            dijkstra (arr[x]);
            printf("%lld\n",dis[arr[y]]);
        }
    }
    return 0;
}
void addEdge (int f,int t,long long e){
    nxt[ne]=head[f];
    to[ne]=t;
    cost[ne]=e;
    head[f]=ne++;
}
void dijkstra (int u){
    dis[u]=0;
    q.push(make_pair(0,u));
    while (!q.empty()){
        long long w=q.top().first;
        int v=q.top().second;
        q.pop();
        if (-1*w>dis[v]) continue;
        for (int i=head[v];~i;i=nxt[i]){
            int j=to[i];
            long long k=cost[i];
            if (dis[v]+k<dis[j]){
                dis[j]=dis[v]+k;
                q.push(make_pair(-1*dis[j],j));
            }
        }
    }
}




