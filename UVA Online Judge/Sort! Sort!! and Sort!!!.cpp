#include <iostream>
#include <queue>

using namespace std;
long long n,m;
long long arr[100009];
priority_queue < pair <long long,long long> > so;
pair <long long,long long> foo;
long long x;

int main()
{
    while (1){
        cin >> n >> m;
        if (n==0 && m==0) break;
        for (int i=0;i<n;i++){
            cin >> arr[i];
            x=(arr[i]%m)*(-1);
            if (arr[i]%2==0) arr[i]*=-1;
            foo=make_pair(x,arr[i]);
            so.push(foo);
        }
        cout << n << " " << m << endl;
        while (so.empty()!=1){
            if (so.top().second%2!=0) cout << so.top().second << endl;
            else cout << -1*so.top().second << endl;
            so.pop();
        }
    }
    cout << n << " " << m << endl;
    return 0;
}
