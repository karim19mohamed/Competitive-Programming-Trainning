#include <iostream>

using namespace std;
int t;
int arr[189];

int main()
{
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> arr[i];
        if (360%(180-arr[i])==0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
