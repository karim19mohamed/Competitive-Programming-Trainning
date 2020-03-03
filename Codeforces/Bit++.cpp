#include <iostream>
#include <string>

using namespace std;
int n;
string s1;
int ans;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s1;
        if (s1[0]=='+' || s1[1]=='+' || s1[2]=='+') ans++;
        else if (s1[0]=='-' || s1[1]=='-' || s1[2]=='-') ans--;
    }
    cout << ans << endl;
    return 0;
}
