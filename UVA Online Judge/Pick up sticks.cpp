/*
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>

using namespace std;
long long n,m,a,b,head[1000009],nxt[4000009],to[4000009],ne;
long long vis[1000009];
bool ans=1;
queue <long long> q;

void init(int N){
    memset(head,-1,N*sizeof(head[0]));
    memset(vis,0,N*sizeof(vis[0]));
    ne=0;
    while (!q.empty()){
        q.pop();
    }
    ans=1;
}
void addEdge(long long f, long long t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}
void dfs(long long u){
    vis[u]=1;
    for (long long k=head[u];~k;k=nxt[k]){
        long long j=to[k];
        if (vis[j]==1){
            ans=0;return;
        }else{
            if (vis[j]==0) dfs(j);
        }
    }
    vis[u]=2;
    q.push(u);
}

int main()
{
    while (1){
        scanf("%lld%lld",&n,&m);
        if (n==0) break;
        init(n);
        for (long long i=0;i<m;i++){
            scanf("%lld%lld",&a,&b);
            addEdge(b-1,a-1);
        }
        for (long long i=0;i<n;i++){
            if (vis[i]==0) dfs(i);
            if (ans==0) break;
        }
        if (ans){
            while (!q.empty()){
                long long u=q.front();
                q.pop();
                printf("%lld\n",u+1);
            }
        }else{
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>

using namespace std;
long long n,m,a,b,head[1000009],nxt[4000009],to[4000009],ne,vid=1,cc=1;
long long vis[1000009],color[1000009];
bool ans=1;
queue <long long> q;

void init(int N){
    memset(head,-1,N*sizeof(head[0]));
    memset(color,0,N*sizeof(color[0]));
    ne=0;
    while (!q.empty()) q.pop();
    ans=1;
    cc=1;
}
void addEdge(long long f, long long t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}
void dfs(long long u){
    vis[u]=vid;
    color[u]=cc;
    for (long long k=head[u];~k;k=nxt[k]){
        long long j=to[k];
        if (color[j]==cc){
            ans=0;return;
        }else{
            if (vis[j]!=vid) dfs(j);
        }
    }
    //cout << u << " " << vis[u] << " " << color[u] << endl;
    q.push(u);
}

int main()
{
    while (1){
        scanf("%lld%lld",&n,&m);
        if (n==0) break;
        init(n);
        for (long long i=0;i<m;i++){
            scanf("%lld%lld",&a,&b);
            addEdge(b-1,a-1);
        }
        for (long long i=0;i<n;i++){
            if (vis[i]!=vid){
                dfs(i);
                cc++;
            }
            if (ans==0) break;
        }
        if (ans){
            while (!q.empty()){
                long long u=q.front();
                q.pop();
                printf("%lld\n",u+1);
            }
        }else{
            printf("IMPOSSIBLE\n");
        }
        vid++;
    }
    return 0;
}
