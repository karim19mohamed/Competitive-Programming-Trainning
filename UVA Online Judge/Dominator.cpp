#include <iostream>
#include <vector>

using namespace std;
int t,n;
bool arr[109][109];
bool ans[109][109];
bool disjoint[109];
vector <int> adj[109];
bool ves[109];
void dfs (int u);

int main()
{
    cin >> t;
    for (int k=0;k<t;k++){
        cin >> n;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin >> arr[i][j];
                if (arr[i][j]) adj[i].push_back(j);
            }
        }
        if (adj[0].size()==0){
            ans[0][0]=1;
        }else{
            dfs(0);
            for (int i=0;i<n;i++){
                if (ves[i]==0) {
                    disjoint[i]=1;
                }
            }
            for(int i=0;i<n;i++){
                for (int j=0;j<n;j++) ves[j]=0;
                ves[i]=1;
                if (disjoint[i]!=1){
                    dfs(0);
                    ves[i]=0;
                    for (int j=0;j<n;j++) {
                        if (ves[j]==0 && disjoint[j]!=1) ans[i][j]=1;
                    }
                }
            }
        }
        cout << "Case " << k+1 << ":" << endl;
        for(int i=0;i<n;i++){
            cout << "+";
            for (int j=0;j<2*n-1;j++) cout << "-";
            cout << "+" << endl;
            for(int j=0;j<n;j++){
                if (ans[i][j]) cout << "|Y";
                else cout << "|N";
                ans[i][j]=0;
            }
            cout << "|" << endl;
        }
        cout << "+";
        for (int j=0;j<2*n-1;j++) cout << "-";
        cout << "+" << endl;
        for (int j=0;j<n;j++){
            ves[j]=0;
            disjoint[j]=0;
            int q=adj[j].size();
            adj[j].erase(adj[j].begin(),adj[j].begin()+q);
        }

    }
    cout << endl;
    return 0;
}
void dfs (int u){
    if (ves[u]==1) return;
    ves[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if (ves[adj[u][i]]==0) dfs(adj[u][i]);
    }
    return;
}

