#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;
string n;
map <string,bool> vis;
map <string,bool> ans;
void dfs(string u,bool indx);
bool checker(string s);

int main()
{
    dfs(".........",1);
    while (1){
        cin >> n;
        if (n=="end") break;
        if (ans[n]){
            printf("valid\n");
        }else if(vis[n]){
            bool q=1;
            for (int i=0;i<9;i++){
                if (n[i]=='.') q=0;
            }
            if (q){
                printf("valid\n");
            }else{
                printf("invalid\n");
            }
        }else{
            printf("invalid\n");
        }
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
    }else{
        ans[u]=1;
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



