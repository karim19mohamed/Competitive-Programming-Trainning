#include <iostream>
#include <string>

using namespace std;
int n,m,x,y,d;
char p;
string s1;
string in="NESW";
bool lost=0;
bool ves[100][100];

int main()
{
    cin >> n >> m;
    while (cin >> x >> y >> p){
        cin >> s1;
        for (int i=0;i<4;i++) if (p==in[i]) d=i;
        for (int i=0;i<s1.size();i++){
            if (s1[i]=='F'){
                if (p=='N') y++;
                else if (p=='S') y--;
                else if (p=='E') x++;
                else if (p=='W') x--;
                //cout << x << " " << y << " " << p << endl;
                if (y>m){
                    y--;
                    if (ves[x][y]) continue;
                    lost=1;
                    ves[x][y]=1;
                    break;
                }else if (y<0){
                    y++;
                    if (ves[x][y]) continue;
                    lost=1;
                    ves[x][y]=1;
                    break;
                }
                if (x>n){
                    x--;
                    if (ves[x][y]) continue;
                    lost=1;
                    ves[x][y]=1;
                    break;
                }else if (x<0){
                    x++;
                    if (ves[x][y]) continue;
                    ves[x][y]=1;
                    lost=1;
                    break;
                }
            }else if (s1[i]=='R'){
                if (d==3){
                    d=0;
                    p=in[d];
                }else{
                    d++;
                    p=in[d];
                }
            }else if (s1[i]=='L'){
                if (d==0){
                    d=3;
                    p=in[d];
                }else{
                    d--;
                    p=in[d];
                }
            }
        }
        if (!lost) cout << x << " " << y << " " << p << endl;
        else cout << x << " " << y << " " << p << " " << "LOST" << endl;
        lost=0;
    }
    return 0;
}
