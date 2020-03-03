#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
const int N=26+19,M=N*N;
int n,m,head[N],nxt[M],to[M],cap[M],ne,src,snk;
vector <char> arr[10];

void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
}
void addEdge(int f, int t,int c) {
	nxt[ne] = head[f];
	to[ne] = t;
	cap[ne]=c;
	head[f] = ne++;
}
void addAugEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, 0);
}
int vid,vis[N];
int dfsFlow (int i,int FLOW){
    if (i==snk) return FLOW;
    if (!FLOW) return 0;
    if (vis[i]==vid) return 0;

    vis[i]=vid;
    for (int k=head[i];~k;k=nxt[k]){
        int j=to[k];
        int c=cap[k];
        int f=dfsFlow(j,min(FLOW,c));
        if (f){
            cap[k]-=f;
            cap[k^1]+=f;
            return f;
        }
    }
    return 0;
}
int maxflow(){
    if (src==snk) return 1e4;
    int flow=0,f;
    while (vid++,f=dfsFlow(src,50000)){
        flow+=f;
    }
    return flow;
}
#define cn(ID) ID
#define cm(ID) ID+n

void dfs(){
    for (int i=0;i<m;i++){
        for (int k=head[cm(i)];~k;k=nxt[k]){
            int j=to[k];
            int c=cap[k];
            if (c==0) continue;
            if (j!=snk){
                char aa='A'+j;
                //cout << j << endl;
                arr[i].push_back(aa);
            }
        }
    }
}


char s[15];
char in[12],a;
int b;
int main()
{
    while(gets(s)){
        if (strcmp(s, "")==0) break;
        n=26;
        m=10;
        init(n+m+2);
        src=n+m+2-1;
        snk=n+m+2-2;
        int re=0;
        do{
            if (strcmp(s, "")==0) break;
            if (s=="") break;
            sscanf(s,"%c%d %s", &a, &b, in);
            int xx=a-'A';
            int indx=0;
            addAugEdge(src,cn(xx),b);
            re+=b;
            while (in[indx]!=';'){
                int zz=in[indx]-'0';
                addAugEdge(cn(xx),cm(zz),1);
                indx++;
            }
        }while(gets(s));
        for (int i=0;i<m;i++) addAugEdge(cm(i),snk,1);

        int res=maxflow();
        if (res==re){
            dfs();
            for (int i=0;i<m;i++){
                if (arr[i].size()==0) printf("_");
                for (int j=0;j<arr[i].size();j++){
                    printf("%c",arr[i][j]);
                }
            }
            printf("\n");
        }else{
            printf("!\n");
        }
        for(int i=0;i<m;i++){
            arr[i].erase(arr[i].begin(),arr[i].end());
        }
    }
    return 0;
}
