#include <iostream>
#include <string>

using namespace std;
int n,m;
string arr[109];
bool x;

int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> arr[i];
    for (int i=0;i<n;i++){
        if (i%2==1) x=1;
        else x=0;
        for (int j=0;j<m;j++){
            if (arr[i][j]=='-'){
                cout << arr[i][j];
            }else if (x){
                cout << 'B';
            }else{
                cout << 'W';
            }
            x=(x^1);
        }
        cout << endl;
    }
    return 0;
}
