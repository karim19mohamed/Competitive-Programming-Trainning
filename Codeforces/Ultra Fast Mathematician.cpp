#include <iostream>
#include <string>

using namespace std;
string s1;
string s2;
string ans;

int main()
{
    cin >> s1;
    cin >> s2;
    ans="";
    int k=s1.size();
    //cout << k << endl;
    for (int i=0;i<k;i++){
        if (s1[i]!=s2[i]) ans+='1';
        if (s1[i]==s2[i]) ans+='0';
    }
    cout << ans << endl;
    return 0;
}
