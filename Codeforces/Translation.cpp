#include <iostream>
#include <string>

using namespace std;
string s,t;
int ans=1;

int main()
{
    cin >> s;
    cin >> t;
    int k=s.size();
    for (int i=0;i<k;i++){
        if (s[i]!=t[k-i-1]){
            ans=0;
            break;
        }
    }
    if (ans==1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
