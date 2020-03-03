#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
string s;
bool ch;

int main()
{
    cin >> s;
    for (long long i=0;i<s.size();++i){
        if (s[i]=='0'){
            s.erase(s.begin()+i);
            ch=1;
            break;
        }
    }
    if (ch) cout << s << endl;
    else{
        s.erase(s.begin());
        cout << s << endl;
    }
    return 0;
}
