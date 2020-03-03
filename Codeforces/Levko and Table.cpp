#include <iostream>

using namespace std;
int n,k;
int arr[109][109];

int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i==j) cout << k;
            else cout << "0";
            if (j!=n-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
