#include <iostream>
#include <string>

using namespace std;
string s1;

int main()
{
    cin >> s1;
    int k=s1.size();
    bool ans=0;
    for (int i=0;i<k;i++){
        if (s1[i]=='H' || s1[i]=='Q' ||s1[i]=='9'){
            ans=1;
            break;
        }
    }
    if (ans==1) cout << "YES" << endl;
    if (ans==0) cout << "NO" << endl;
    return 0;
}
