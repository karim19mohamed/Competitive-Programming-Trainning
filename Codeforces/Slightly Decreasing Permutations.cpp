#include <iostream>

using namespace std;
int n;
int k;

int main()
{
    cin >> n;
    cin >> k;
    for (int i=0;i<k;i++){
        cout << n;
        if (n!=1) cout <<" ";
        n--;
    }
    for (int i=0;i<n;i++){
        cout << i+1;
        if ((i+1)!=n) cout << " ";
    }
    cout << endl;
    return 0;
}
