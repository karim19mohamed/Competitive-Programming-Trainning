#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
string s;
stack <char> x;
queue <char> res;
bool ans=1;
long long a,b,d,c;

int main()
{
    cin >> s;
    long long k=s.size();
    for (long long i=0;i<k;i++){
        if (s[i]=='(') a++;
        else if (s[i]==')') b++;
        else d++;
    }
    c=a-b;
    if (c>0){
        b=c;
        a=0;
    }else if (c<0){
        b=0;
        a=c;
    }else{
        if (d%2!=1){
            a=d/2;
            b=d/2;
        }else{
            ans=0;
        }
    }
    for (long long i=0;i<k;i++){
        if (ans==0) break;
        if (s[i]=='('){
            x.push(s[i]);
            res.push(s[i]);
        }else if (s[i]==')'){
            if (!x.empty()){
                x.pop();
                res.push(s[i]);
            }else{
                //cout << "asd" << endl;
                ans=0;
                break;
            }
        }else{
            if (!x.empty()){
                if (a==0){
                    x.pop();
                    res.push(')');
                }else if (b==0){
                    x.push('(');
                    res.push('(');
                }else if (a!=0 && b!=0){
                    a--;
                    x.push('(');
                    res.push('(');
                    //cout << "asd" << endl;
                }
            }else {
                a--;
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
