#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
long long t,n,m,a,b,c,s,e;
vector <pair<long long,long long> > adj[200009];
priority_queue <pair<long long,long long> > q;
long long dis[200009];
void dijkstra (long long x);

int main()
{
    cin >> t;
    for (int k=0;k<t;k++){
        cin >> n >> m >> s >> e;
        for (int i=0;i<m;i++){
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(c,b));
            adj[b].push_back(make_pair(c,a));
        }
        for (int i=0;i<n;i++) dis[i]=1000000;
        //memset(dis,1,sizeof dis);
        dijkstra (s);
        if (dis[e]<100000) cout <<"Case #"<<k+1<<": "<<dis[e]<< endl;
        else cout <<"Case #"<<k+1<<": unreachable"<< endl;
        for (int i=0;i<n;i++) adj[i].erase(adj[i].begin(),adj[i].end());
    }
    return 0;
}
void dijkstra (long long x){
    q.push(make_pair(0,x));
    dis[x]=0;
    while (!q.empty()){
        long long w=-1*q.top().first;
        long long u=q.top().second;
        q.pop();
        if (w > dis[u]) continue;
        for (int i=0;i<adj[u].size();i++){
            if (dis[ adj[u][i].second ]>dis[u]+adj[u][i].first){
                dis[ adj[u][i].second ]=dis[u]+adj[u][i].first;
                q.push(make_pair(-1*dis[ adj[u][i].second ],adj[u][i].second));
            }
        }
    }
}




