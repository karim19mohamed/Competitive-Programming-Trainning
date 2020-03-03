#include <iostream>
#include <string>
#include <cstring>

using namespace std;
long long c,n,m,x,y;
string s,q;
bool arr[69][69];
string in="NESW";
char dir='N';
int w=0;

int main()
{
    cin >> c;
    for (long long i=0;i<c;i++){
        getline(std::cin,q);
        cin >> n >> m;
        getline(std::cin,q);
        for (int j=0;j<n;j++){
            getline(std::cin,s);
            for (int k=0;k<m;k++) {
                (s[k]=='*')? arr[j][k]=0 : arr[j][k]=1;
            }
        }
        /*for (int j=0;j<n;j++){
            for (int k=0;k<m;k++) cout << arr[n-1-j][k];
            cout << endl;
        }*/
        getline(std::cin,s);
        x=s[0]-'0'-1;
        y=s[2]-'0'-1;
        //cout << arr[x][y];
        while (1){
            cin >> s;
            //cout << s << endl;
            for (int j=0;j<s.size();j++){
                if (s[j]=='R'){
                    if (w==3){
                        dir=in[0];
                        w=0;
                    }else{
                        dir=in[w+1];
                        w++;
                    }
                }else if (s[j]=='L'){
                    if (w==0){
                        dir=in[3];
                        w=3;
                    }else{
                        dir=in[w-1];
                        w--;
                    }
                }else if (s[j]=='F'){
                    if (dir=='N' && arr[x-1][y] && x-1>=0) x--;
                    else if (dir=='S' && arr[x+1][y] && x+1<=n-1) x++;
                    else if (dir=='E' && arr[x][y+1] && y+1<=m-1) y++;
                    else if (dir=='W' && arr[x][y-1] && y-1>=0) y--;
                }
                //cout << dir << " " << x << " " << y << endl;
            }
            if (s[s.size()-1]=='Q'){
                cout << x+1 << " " << y+1 << " " << dir << endl;
                cout << endl;
                break;
            }
        }
        dir='N';
        w=0;
        for (int j=0;j<m;j++) for (int k=0;k<n;k++) arr[j][k]=0;
    }
    return 0;
}
