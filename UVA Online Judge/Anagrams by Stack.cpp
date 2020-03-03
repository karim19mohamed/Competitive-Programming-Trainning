#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;
string s1,s2,game,res;
vector <string> ans;
stack <char> a;

int main()
{
    while (cin >> s1 >> s2){
        cout << "[" << endl;
        int n=s1.size();
        for (int i=0;i<s1.size();i++) game=game+'i';
        for (int i=0;i<s1.size();i++) game=game+'o';
        do{
            int ind=0;
            bool k=0;
            for (int i=0;i<2*n;i++){
                if (game[i]=='i') ind++;
                else ind--;
                if (ind<0){
                    k=1;
                    break;
                }
            }
            if (k) continue;
            int z=0;
            int p=0;
            for (int i=0;i<game.size();i++){
                if (game[i]=='i'){
                    a.push(s1[z]);
                    z++;
                }else{
                    if (a.top()!=s2[p]) break;
                    res=res+a.top();
                    a.pop();
                    p++;
                }
            }
            if (res==s2){
                cout << game << endl;
            }
            res="";
        }while (next_permutation(game.begin(),game.end()));
        game="";
        cout << "]" << endl;
    }
    return 0;
}
