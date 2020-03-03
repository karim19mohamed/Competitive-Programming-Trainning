#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;
int n;
string a,b,c;
map <string,bool> vis;
void dfs(string u,bool indx);
bool checker(string s);

int main()
{
    scanf("%d",&n);
    dfs(".........",1);
    for (int i=0;i<n;i++){
        cin >> a >> b >> c;
        if (vis[a+b+c]) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
void dfs(string u,bool indx){
    vis[u]=1;
    if (!checker(u)){
        for (int i=0;i<9;i++){
            if (u[i]=='.'){
                if (indx){
                    u[i]='X';
                    if (vis[u]==0) dfs(u,0);
                    u[i]='.';
                }else{
                    u[i]='O';
                    if (vis[u]==0) dfs(u,1);
                    u[i]='.';
                }
            }
        }
    }
}
bool checker(string s){
    string w="";
    w=w+s[0]+s[1]+s[2]; if (w=="XXX" || w=="OOO") return 1;
    w="";
    w=w+s[3]+s[4]+s[5]; if (w=="XXX" || w=="OOO") return 1;
    w="";
    w=w+s[6]+s[7]+s[8]; if (w=="XXX" || w=="OOO") return 1;
    w="";
    w=w+s[0]+s[3]+s[6]; if (w=="XXX" || w=="OOO") return 1;
    w="";
    w=w+s[1]+s[4]+s[7]; if (w=="XXX" || w=="OOO") return 1;
    w="";
    w=w+s[2]+s[5]+s[8]; if (w=="XXX" || w=="OOO") return 1;
    w="";
    w=w+s[0]+s[4]+s[8]; if (w=="XXX" || w=="OOO") return 1;
    w="";
    w=w+s[2]+s[4]+s[6]; if (w=="XXX" || w=="OOO") return 1;
    w="";
    return 0;
}



