#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;
int n,head[209],vis[209],nxt[10009],ne;
char arr[10000][29],to[10009];
string s;
queue <char> in;
stack <char> q;

void addEdge (char i,char j){
    in.push(i);
    in.push(j);
    nxt[ne]=head[i];
    to[ne]=j;
    head[i]=ne++;
}
void dfs(char u){
    vis[u]=1;
    for (int k=head[u];~k;k=nxt[k]){
        char j=to[k];
        if (vis[j]==0) dfs(j);
    }
    if (u!='0') q.push(u);
}

int main()
{
    while (1){
        cin >> s;
        if (s=="#") break;
        for (int i=0;i<s.size();i++) {
            arr[n][i]=s[i];

        }
        for (int i=s.size();i<20;i++) arr[n][i]='0';
        n++;
    }
    memset(head,-1,sizeof(head));
    for (int i=0;i<20;i++){
        for (int j=1;j<n;j++){
            if (i==0 && arr[j-1][i]!=arr[j][i] && arr[j][i]!='0' && arr[j-1][i]!='0'){
                addEdge(arr[j-1][i],arr[j][i]);
                continue;
            }
            if (arr[j-1][i-1]==arr[j][i-1] && arr[j-1][i]!=arr[j][i]){
                if (arr[j][i]!='0' && arr[j-1][i]!='0') addEdge(arr[j-1][i],arr[j][i]);
                else if (arr[j][i]!='0' && arr[j-1][i]=='0'){
                    addEdge(arr[j-1][i],arr[j][i]);
                    in.push('0');
                }
            }
        }
    }
    while (!in.empty()){
        char i=in.front();
        in.pop();
        if (vis[i]==0) dfs(i);
    }
    while (!q.empty()){
        char i=q.top();
        cout << i;
        q.pop();
    }
    cout << endl;
    return 0;
}
