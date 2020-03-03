#include <iostream>
#include <string>

using namespace std;
string s1;
string s2;
int ans;

int main()
{
    cin >> s1;
    cin >> s2;
    int k=s1.size();
    for (int i=0;i<k;i++){
        if (s1[i]>90) s1[i]-=32;
        if (s2[i]>90) s2[i]-=32;
        if (s1[i]==s2[i]) ans=0;
        if (s1[i]<s2[i]) {
            ans=-1;
            break;
        }
        if (s1[i]>s2[i]) {
            ans=1;
            break;
        }
    }
    cout << ans <<endl;
    return 0;
}
