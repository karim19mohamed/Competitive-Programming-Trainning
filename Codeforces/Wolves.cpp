#include <iostream>

using namespace std;
int n,m;
char arr[19][19];
int ans;

int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> arr[i][j];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (arr[i][j]=='W'){
                if (j!=0) {
                    if (arr[i][j-1]=='P'){
                        ans++;
                        arr[i][j-1]='0';
                        arr[i][j]='0';
                    }
                }
                if (j!=m-1 && arr[i][j]=='W'){
                    if (arr[i][j+1]=='P'){
                        ans++;
                        arr[i][j+1]='0';
                        arr[i][j]='0';
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (arr[i][j]=='W'){
                if (i!=0) {
                    if (arr[i-1][j]=='P'){
                        ans++;
                        arr[i-1][j]='0';
                        arr[i][j]='0';
                    }
                }
                if (i!=n-1 && arr[i][j]=='W'){
                    if (arr[i+1][j]=='P'){
                        ans++;
                        arr[i+1][j]='0';
                        arr[i][j]='0';
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

