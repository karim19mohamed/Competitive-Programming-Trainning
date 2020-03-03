#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
long long t;
int n;
vector <int> adj[100];
bool ves[100];
string s1,s2,x;
void dfs (int u);
int ans;
bool w=1;
bool q=1;

int main()
{
    cin >> t;
    for (long long i=0;i<t;i++){
        if (q) getline(std::cin,x);
        if (q) getline(std::cin,x);
        if (w) getline(std::cin,s1);
        w=1;
        q=0;
        n=s1[0]-'A'+1;
        while (getline(std::cin,s2)){
            if (s2.size()==1){
                s1=s2;
                w=0;
                break;
            }
            if (s2.size()==0){
                break;
            }
            adj[s2[0]-'A'].push_back(s2[1]-'A');
            adj[s2[1]-'A'].push_back(s2[0]-'A');
        }
        //cout << s1 << "  " <<n << endl;
        for (int j=0;j<n;j++){
            if (ves[j]==0){
                dfs(j);
                ans++;
            }
        }
        cout << ans << endl;
        if (i!=t-1) cout << endl;
        ans=0;
        memset(ves,0,sizeof ves);
        for (int j=0;j<n;j++) adj[j].erase(adj[j].begin(),adj[j].end());
    }
    return 0;
}
void dfs (int u){
    ves[u]=1;
    for (int i=0;i<adj[u].size();i++){
        if ( ves[adj[u][i]]==0 ) dfs(adj[u][i]);
    }
}


