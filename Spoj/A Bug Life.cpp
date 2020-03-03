#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;
long long t,m,c,ne;
int n,a,b;
int head[2009],nxt[2000009],to[2000009];
bool ans=1;
int color[2009];
queue <int> q;
void addEdge(int x,int y);
void bfs (int u);

int main()
{
    scanf("%lld",&t);
    while (t--){
        scanf("%d%lld",&n,&m);
        ans=1;
        ne=0;
        memset(head,-1,n*sizeof(head[0]));
        memset(color,-1,n*sizeof(color[0]));
        memset(nxt,0,m*sizeof(nxt[0]));
        memset(to,0,m*sizeof(to[0]));
        for (long long i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            addEdge(a-1,b-1);
            addEdge(b-1,a-1);
        }
        for (int i=0;i<n;i++) {
            if (color[i]==-1){
                while (!q.empty()) q.pop();
                bfs(i);
            }
        }
        printf("Scenario #%lld:\n",++c);
        if (ans) printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");

    }
    return 0;
}
void addEdge(int x,int y){
    nxt[ne]=head[x];
    to[ne]=y;
    head[x]=ne++;
}
void bfs (int u){
    color[u]=0;
    q.push(u);
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (int i=head[v];~i;i=nxt[i]){
            int j=to[i];
            //cout << color[j]<<"  "<<color[v] << endl;
            if (color[j]==-1){
                color[j]=1-color[v];
                q.push(j);
            }else if (color[j]==color[v]){
                ans=0;
                break;
            }
        }
    }
}


