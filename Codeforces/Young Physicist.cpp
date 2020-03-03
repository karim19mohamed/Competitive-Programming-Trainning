#include <iostream>

using namespace std;
int n;
int arr[109][3];
int ans_x,ans_y,ans_z;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            cin >> arr[i][j];
            ans_x+=arr[i][0];
            ans_y+=arr[i][1];
            ans_z+=arr[i][2];
        }
    }
    if (ans_x==0 && ans_y==0 && ans_z==0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
