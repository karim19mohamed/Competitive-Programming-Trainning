#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <fstream>

using namespace std;
const long long N=1009,M=1000009;
int t,n,ans;
int a,chk[1009],res[1009],dd;
bool forbed[10][10];
ofstream answer;

long long head[N], nxt[M], to[M], ne;
long long vis[N],vid;
void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;ans=0;dd=0;
	vid++;
}
void addEdge(long long f, long long t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}
void dfs(long long u){
    vis[u]=vid;ans++;
    for (long long k=head[u];~k;k=nxt[k]){
        long long j=to[k];
        if (vis[j]!=vid && chk[j]!=chk[u]){
            dfs(j);res[dd++]=j;
        }
    }

}


int main()
{
    answer.open("answer.txt");
    scanf("%d",&t);
    forbed[0][1]=1;forbed[2][1]=1;forbed[0][5]=1;forbed[4][5]=1;forbed[2][3]=1;forbed[3][4]=1;
    forbed[1][0]=1;forbed[1][2]=1;forbed[5][0]=1;forbed[5][4]=1;forbed[3][2]=1;forbed[4][3]=1;
    for (int i=0;i<t;i++){
        scanf("%d",&n);
        init(n);
        int indx=0;
        for (int j=0;j<6;j++){
            scanf("%d",&a);
            for (int k=0;k<a;k++){
                chk[indx++]=j;
                //cout << indx-1 << "    " << chk[indx-1] << endl;
            }
        }
        for (int j=0;j<n;j++){
            for (int k=j+1;k<n;k++){
                int a=chk[j],b=chk[k];
                if (!forbed[a][b] && a!=b){
                    addEdge(j,k);
                    addEdge(k,j);
                    //cout << j << "  " << k << endl;
                }
            }
        }
        res[dd++]=0;
        dfs(0);
        for (int j=0;j<dd-1;j++){
            cout << res[j] << endl;
        }
        if (ans==n){
            int a=chk[res[0]],b=chk[res[dd-1]];
            if (forbed[a][b]){
                answer<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;
            }else{
                answer<<"Case #"<<i+1<<": ";
                for (int j=0;j<dd;j++){
                    if(chk[res[j]]==0) answer << "R";
                    else if (chk[res[j]]==1) answer << "O";
                    else if (chk[res[j]]==2) answer << "Y";
                    else if (chk[res[j]]==3) answer << "G";
                    else if (chk[res[j]]==4) answer << "B";
                    else if (chk[res[j]]==5) answer << "V";
                }
                answer << endl;
            }
        }else{
            answer<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
