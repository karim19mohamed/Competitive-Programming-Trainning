#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
long long t;
int n,m,a;
vector <pair <int,int> > adj[1000009];
int arr[1009][1009];
priority_queue <pair <int,int> > q;
long long dis[1000009];
void dijkstra (int x);

int main()
{
    cin >> t;
    for (int k=0;k<t;k++){
        cin >> n >> m;
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> arr[i][j];
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (i-1>=0){
                    adj[a].push_back(make_pair(arr[i-1][j],a-m));
                    adj[a-m].push_back(make_pair(arr[i][j],a));
                }
                if (i+1<n){
                    adj[a].push_back(make_pair(arr[i+1][j],a+m));
                    adj[a+m].push_back(make_pair(arr[i][j],a));
                }
                if (j-1>=0){
                    adj[a].push_back(make_pair(arr[i][j-1],a-1));
                    adj[a-1].push_back(make_pair(arr[i][j],a));
                }
                if (j+1<m){
                    adj[a].push_back(make_pair(arr[i][j+1],a+1));
                    adj[a+1].push_back(make_pair(arr[i][j],a));
                }
                a++;
            }
        }
        for (int i=0;i<n*m;i++) dis[i]=90000009;
        dijkstra (0);
        cout << dis[n*m-1]+arr[0][0] << endl;
        for (int i=0;i<n*m;i++) adj[i].erase(adj[i].begin(),adj[i].end());
        a=0;
    }
    return 0;
}
void dijkstra (int x){
    q.push(make_pair(0,x));
    dis[x]=0;
    while (!q.empty()) {
        int w = -1*q.top().first;
        int u=q.top().second;
        q.pop();
        if (-1*w>dis[u]) continue;
        for (int i=0;i<adj[u].size();i++){
            if (dis[adj[u][i].second]>dis[u]+adj[u][i].first){
                dis[adj[u][i].second]=dis[u]+adj[u][i].first;
                q.push(make_pair(-1*dis[adj[u][i].second],adj[u][i].second));
            }
        }
    }
}







