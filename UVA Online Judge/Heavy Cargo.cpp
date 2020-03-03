#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <stdio.h>
#include <queue>

using namespace std;
int n,r,head[209],nxt[40009],to[40009],cost[40009],ne,ii=1,c,sc=1;
string a,b;
map <string,long long> arr;
priority_queue <pair<int,pair<int,int> > > q;
int dist[209],ans[209];

void addEdge (int f,int t,int d){
    nxt[ne]=head[f];
    to[ne]=t;
    cost[ne]=d;
    head[f]=ne++;
}
void ini(int N){
    memset(head,-1,N*sizeof(head[0]));
    memset(dist,0,N*sizeof(dist[0]));
    memset(ans,0x3f,N*sizeof(ans[0]));
    ne=0;
    arr.erase(arr.begin(),arr.end());
    ii=1;
}
void prim(int u){
    dist[u]=0;
    q.push({0,{-1,u}});
    while (!q.empty()){
        int w=q.top().first,pre=q.top().second.first,v=q.top().second.second;
        q.pop();
        //cout << w << " " << pre << " " << v << endl;
        if (w!=dist[v]) continue;
        if (pre!=-1) ans[v]=min(w,ans[pre]);
        for (int k=head[v];~k;k=nxt[k]){
            int j=to[k],z=cost[k];
            //cout << j << " " << z << endl;
            if (dist[j]<z){
                dist[j]=z;
                q.push({z,{v,j}});
            }
        }
    }
}

int main()
{
    while (1){
        scanf("%d%d",&n,&r);
        if (n==0) break;
        ini(209);
        for (int i=0;i<r;i++){
            cin >> a >> b >> c;
            if (arr[a]==0){
                arr[a]=ii;
                ii++;
            }
            if (arr[b]==0){
                arr[b]=ii;
                ii++;
            }
            //cout << arr[a] << " " << arr[b] << " " << c << endl;
            addEdge(arr[a],arr[b],c);
            addEdge(arr[b],arr[a],c);
        }
        cin >> a >> b;
        prim(arr[a]);
        printf("Scenario #%d\n%d tons\n\n",sc++,ans[arr[b]]);
    }
    return 0;
}
