#include <iostream>

using namespace std;
int r,c;
char arr[19][19];
int ans;
bool s_i[19];
bool s_j[19];

int main()
{
    cin >> r >> c;
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            cin >> arr[i][j];
            if (arr[i][j]=='S'){
                s_i[i]=1;
                s_j[j]=1;
            }
        }
    }
    for (int j=0;j<c;j++){
        if (s_j[j]!=1){
            for (int i=0;i<r;i++){
                if (arr[i][j]!='a'){
                    ans++;
                    arr[i][j]='a';
                }
            }
        }
    }
    for (int i=0;i<r;i++){
        if (s_i[i]!=1){
            for (int j=0;j<c;j++){
                if (arr[i][j]!='a'){
                    ans++;
                    arr[i][j]='a';
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
