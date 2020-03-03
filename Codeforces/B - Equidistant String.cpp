#include <iostream>
#include <string>

using namespace std;
string s,t;
long long d;

int main()
{
    cin >> s >> t;
    for (int i=0;i<s.size();i++){
        if (s[i]!=t[i]) d++;
    }
    if (d%2==0){
        d=d/2;
        for (int i=0;d>0;i++){
            if (s[i]!=t[i]){
                d--;
                s[i]=t[i];
            }
        }
        cout << s << endl;
    }else{
        cout << "impossible" << endl;
    }
    return 0;
}