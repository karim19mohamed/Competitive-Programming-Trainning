#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int n,ind;
queue <int> arr;
stack <int> jar;
int fi=1;
bool ans=1;

int main()
{
    while(1){
        cin >> n;
        if (n==0) break;
        while (1){
            cin >> ind;
            if (ind==0) break;
            arr.push(ind);
            for (int i=1;i<n;i++) {
                cin >> ind;
                arr.push(ind);
            }
            jar.push(fi);
            while (arr.empty()!=1){
                while (jar.top()!=arr.front()){
                    fi++;
                    if (fi>n){
                        ans=0;
                        break;
                    }
                    jar.push(fi);
                }
                while(jar.empty()!=1 &&jar.top()==arr.front()){
                    jar.pop();
                    arr.pop();
                }
                if (arr.empty()!=1) {
                    fi++;
                    if (fi>n){
                        ans=0;
                        break;
                    }
                    jar.push(fi);
                }
                if (fi>n) break;

            }
            if (ans==1) cout << "Yes" << endl;
            else cout << "No" << endl;
            ans=1;
            fi=1;
            while (!jar.empty()) jar.pop();
            while (!arr.empty())arr.pop();
        }
        cout << endl;
    }
    return 0;
}
