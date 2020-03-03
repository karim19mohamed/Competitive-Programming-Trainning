#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;
const int N=1000+1000+5000+2,M=1000000;
int n,m,p,head[N],nxt[M],to[M],cap[M],ne,src,snk;
vector <int> arr[1009];

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
#define cp(ID) ID+n+m

void dfs(){
    for (int i=0;i<m;i++){
        for (int k=head[cm(i)];~k;k=nxt[k]){
            int j=to[k];
            int c=cap[k];
            if (c==0){
                continue;
            }
            if (j!=snk){
                //cout << i << "  " << w << endl;
                arr[j].push_back(i);
            }
        }
    }
}

int t;
map <string,int> inperson;
map <string,int> inparty;
map <string,int> inclub;
map <int,string> outperson;
map <int,string> outclub;

string s[1009],ss,name,party,club;
int indxn,indxm,indxp,po[1000];
vector<int> L[1000];

int main()
{
    scanf ("%d",&t);
    getline(std::cin,ss);
    getline(std::cin,ss);
    while(t--){
        int indx=0;
        int re=0;
        n=m=p=0;
        while (getline(std::cin,ss)){
            if(ss.empty()) break;
            s[indx]=ss;
            indx++;
            istringstream is(ss);

            is>>name>>party;
            inperson[name] = n;
            outperson[n]=name;

            if(inparty.find(party)==inparty.end())
                inparty[party] = p++;
            po[n] = inparty[party];
            //cout << "sdas" << endl;
            while(is>>club){
                //cout << club << endl;
                if(inclub.find(club)==inclub.end()){
                    inclub[club] = m;
                    outclub[m] = club;
                    ++m;
                }
                L[n].push_back(inclub[club]);
            }
            ++n;
        }
        init(n+m+p+2);
        src=n+m+p+2-1;
        snk=n+m+p+2-2;
        int threshold;
        (m%2==0)? threshold=(m/2)-1 : threshold=(m/2);
        for (int i=0;i<p;i++) addAugEdge(src,cp(i),threshold);
        for (int i=0;i<m;i++) addAugEdge(cm(i),snk,1);
        for (int i=0;i<n;i++) addAugEdge(cp(po[i]),cn(i),1);
        for(int i = 0;i<n;++i){
            for(int j = 0;j<L[i].size();j++){
                int c = L[i][j];
                addAugEdge(cn(i),cm(c),1);
            }
        }
        re=m;
        //cout << re << endl;
        int res=maxflow();
        //cout << res << endl;
        if (res==re){
            dfs();
            for (int i=0;i<n;i++){
                for (int j=0;j<arr[i].size();j++){
                    cout << outperson[i] << " " << outclub[arr[i][j]] << endl;
                }
            }
        }else{
            printf("Impossible.\n");
        }
        if (t!=0) printf("\n");
        for(int i=0;i<n;i++){
            arr[i].erase(arr[i].begin(),arr[i].end());
            L[i].erase(L[i].begin(),L[i].end());
        }
        inperson.erase(inperson.begin(),inperson.end());
        outperson.erase(outperson.begin(),outperson.end());
        inclub.erase(inclub.begin(),inclub.end());
        outclub.erase(outclub.begin(),outclub.end());
        inparty.erase(inparty.begin(),inparty.end());
    }
    return 0;
}
