#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n,a,b,k,c,ans;
vector <int> adj[109];
bool ves[109];
void dfs (int u);

int main()
{
    while (1){
        cin >> n;
        if (n==0) break;
        while (1){
            cin >> a;
            if (a==0) break;
            while (1){
                cin >> b;
                if (b==0) break;
                adj[a-1].push_back(b-1);
            }
        }
        cin >> k;
        for (int i=0;i<k;i++){
            cin >> c;
            dfs(c-1);
            for (int j=0;j<n;j++) if (ves[j]==0) ans++;
            cout << ans;
            for (int j=0;j<n;j++) if (ves[j]==0) cout << " " << j+1;
            cout << endl;
            memset(ves,0,sizeof ves);
            ans=0;
        }
        for (int i=0;i<n;i++) adj[i].erase(adj[i].begin(),adj[i].end());
    }
    return 0;
}
void dfs (int u){

    for (int i=0;i<adj[u].size();i++){
        if (ves[ adj[u][i] ]==0) {
            ves[adj[u][i]]=1;
            dfs(adj[u][i]);
        }
    }
    return;
}




