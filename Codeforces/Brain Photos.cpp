#include <iostream>

using namespace std;
int n,m;

int main()
{
    cin >> n >> m;
    char arr[n][m];
    int ind=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> arr[i][j];
            if (arr[i][j]=='C' || arr[i][j]=='M' || arr[i][j]=='Y'){
                ind=1;
            }
        }
    }
    if (ind==1){
        cout << "#Color" << endl;
    }else{
        cout << "#Black&White" << endl;
    }
    return 0;
}
