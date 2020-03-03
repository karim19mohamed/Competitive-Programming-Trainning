#include <iostream>
#include <string>

using namespace std;
string s;
long long ans,cnt;

int main()
{
    cin >> s;
    for (int i=s.size()-1;i>=4;i--){
        if (s[i]=='l' && s[i-1]=='a' && s[i-2]=='t' && s[i-3]=='e' && s[i-4]=='m') cnt++;
        else if (s[i]=='y' && s[i-1]=='v' && s[i-2]=='a' && s[i-3]=='e' && s[i-4]=='h') ans+=cnt;
    }
    cout << ans << endl;
    return 0;
}