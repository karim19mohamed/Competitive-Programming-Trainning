#include <iostream>
#include <string>

using namespace std;
int n;
string arr;
int ans;

int main()
{
    cin >> n;
    cin >> arr;
    for (int i=1;i<n;i++){
        if (arr[i]==arr[i-1]) ans++;
    }
    cout << ans << endl;
    return 0;
}
