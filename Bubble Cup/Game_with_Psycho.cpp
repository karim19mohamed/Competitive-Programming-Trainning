#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;
int t;
long long n,ans,a,aa,sz;
stack <long long> x;
queue <long long> arr;
bool change;

int main()
{
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n;
        for (long long j=0;j<n;j++){
            cin >> a;
            x.push(a);
        }
        while (!x.empty()){
            arr.push(x.top());
            x.pop();
        }
        change=1;
        while(change){
            change=0;
            sz=arr.size();
            for(long long j=1;j<sz;j++){
                aa=arr.front();
                arr.pop();
                if (aa>arr.front()){
                    arr.push(aa);
                    //cout << aa << endl;
                }else{
                    change=1;
                }
            }
            aa=arr.front();
            arr.pop();
            arr.push(aa);
            //cout << endl;
            if (change) ans++;
        }
        cout << ans << endl;
        while (!arr.empty()) arr.pop();
        ans=0;
    }
    return 0;
}
