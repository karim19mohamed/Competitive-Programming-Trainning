#include <iostream>
#include <string>
#include <stack>

using namespace std;
string x;
stack <char> arr;
bool ans=1;
long long n;
int k;

int main()
{
    cin >> n;
    getline(cin,x);
    for (int i=0;i<n;i++){
        getline(cin,x);
        k=x.size();
        for (int j=0;j<k;j++){
            if (x[j]=='(' || x[j]=='['){
                arr.push(x[j]);
            }else {
                if (arr.empty()) {
                    ans=0;
                    break;
                } else if (x[j]==arr.top()+1 || x[j]==arr.top()+2) {
                    arr.pop();
                }else{
                    ans=0;
                    break;
                }
            }
        }
        if (arr.size()!=0) ans=0;
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
        ans=1;
        while (arr.empty()!=1) arr.pop();
    }
    return 0;
}
