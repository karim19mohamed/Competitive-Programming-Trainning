#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
long long n,m,a,b;
bool ans=1;
vector <long long> adj[209];
int c[209];
queue <long long> q;
void bfs(long long x);

int main()
{
    while (1){
        cin >> n ;
        if (n==0) break;
        cin >> m ;
        for (int i=0;i<m;i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        memset(c,-1,sizeof c);
        for (int i=0;i<n;i++) if (c[i]==-1) bfs(i);
        if (ans) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
        ans=1;
        while (!q.empty()) q.pop();
        for (int i=0;i<n;i++) adj[i].erase(adj[i].begin(),adj[i].end());
    }
    return 0;
}
void bfs(long long x){
    c[x]=0;
    q.push(x);
    while (!q.empty()){
        long long u=q.front();
        q.pop();
        for (int i=0;i<adj[u].size();i++){
            if (c[adj[u][i]]==-1){
                c[adj[u][i]]=1-c[u];
                q.push(adj[u][i]);
            }else if (c[adj[u][i]]==c[u]){
                ans=0;
            }
        }
    }
}



