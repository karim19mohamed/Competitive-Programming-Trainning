#include <iostream>
#include <vector>

using namespace std;
int n,m,k,a,b;
vector <int> adj[109];
vector <int> dis[109];
bool ves[109];
void dfs(int u);
int ans;
bool f;

int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> k;
        if (k==0){
            ans++;
            ves[i]=1;
        }
        for (int j=0;j<k;j++){
            cin >> a;
            dis[a-1].push_back(i);
        }
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<dis[i].size();j++){
            int c=dis[i][j];
            for (int k=0;k<dis[i].size();k++){
                if (dis[i][k]!=c) adj[dis[i][k]].push_back(c);
            }
        }
    }
    for (int i=0;i<n;i++){
        if (ves[i]==0){
            //cout << i << endl;
            dfs(i);
            if (f==1) ans++;
            f=1;
        }
    }
    cout << ans << endl;
    return 0;
}
void dfs(int u){
    ves[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if (ves[adj[u][i]]==0) dfs(adj[u][i]);
    }
    return;
}



