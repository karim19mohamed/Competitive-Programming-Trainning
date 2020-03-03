#include <iostream>
#include <string>

using namespace std;
string s[2];
long long arr[30][2];
bool ans=1;
long long diff;

int main()
{
    cin >> s[0] >> s[1];
    for (int i=0;i<2;i++) for (int j=0;j<s[i].size();j++) arr[s[i][j]-'a'][i]++;
    for (int i=0;i<29;i++) if (arr[i][0]!=arr[i][1]) ans=0;
    if (ans) for (int i=0;i<s[0].size();i++) if (s[0][i]!=s[1][i]) diff++;
    if (ans && diff<=2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
