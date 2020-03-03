#include <iostream>
#include <vector>

using namespace std;
long long n,m,a,b,c;
long long sum=2000000;
vector <long long> adj[200009];
bool ves[200009];
bool ans[200009];
long long cone[200009];
void dfs (long long u);

int main()
{
    cin >> n >> m;
    for (long long i=0;i<m;i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        cone[a-1]++;
        cone[b-1]++;
    }
    for (long long i=0;i<n;i++){
        if (sum > cone[i]){
            c=i;
            sum=cone[i];
        }
    }
    for (long long i=0;i<adj[c].size();i++){
        ves[adj[c][i]]=1;
    }
    ves[c]=1;
    for (long long i=0;i<n;i++){
        cout << !ves[i];
        if (i!=n-1) cout << " ";
    }
    cout << endl;
    return 0;
}
void dfs (long long u){
    ves[u]=1;
    for (long long i=0;i<adj[u].size();i++){
        if (ves[ adj[u][i] ]==0) dfs(adj[u][i]);
    }
    return;
}



