#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;
string s;
stack <char> x;
queue <char> res;
bool ans=1;

int main()
{
    cin >> s;
    long long k=s.size();
    for (long long i;i<k;i++){
        cout << s << endl;
        if (s[i]=='('){
            x.push(s[i]);
            res.push(s[i]);
        }else if (s[i]==')'){
            if (x.top()=='('){
                x.pop();
                res.push(s[i]);
            }else if (x.empty()){
                ans=0;
                break;
            }
        }else if (s[i]=='?'){
            if (x.top()=='('){
                x.pop();
                res.push(')');
            }else if (x.empty()){
                x.push('(');
                res.push('(');
            }
        }
    }
    if (ans==1 && x.empty()==1){
        while (!res.empty()){
            cout << res.front();
            res.pop();
        }
        cout << endl;
    }else {
        cout << "Impossible" << endl;
    }
    return 0;
}
