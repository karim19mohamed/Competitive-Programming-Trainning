#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
vector <int> adj[10000];
queue <int> q;
long long dis[10000];
int m,a,b,s,tl;
int c=1;
int ans;
void bfs (int u,int t);

int main()
{
    while (1){
        cin >> m;
        if (m==0) break;
        for (int i=0;i<m;i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        while (1){
            memset(dis,-1,sizeof dis);
            cin >> s >> tl;
            if (tl==0) break;
            bfs(s,tl);
            cout <<"Case "<<c<<": "<<ans<<" nodes not reachable from node "<<s<<" with TTL = "<<tl<<"."<<endl;
            c++;
            ans=0;
            while (!q.empty()) q.pop();
        }
        for (int i=0;i<39;i++) adj[i].erase(adj[i].begin(),adj[i].end());
    }
    return 0;
}
void bfs (int u,int t){
    dis[u]=0;
    q.push(u);
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int i=0;i<adj[x].size();i++){
            if (dis[adj[x][i]]==-1){
                dis[adj[x][i]]=dis[x]+1;
                q.push(adj[x][i]);
                if (dis[adj[x][i]]>=t) {
                    ans++;
                    //cout << adj[x][i] << endl;
                }
            }
        }
    }
}


