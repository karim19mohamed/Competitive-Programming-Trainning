#include <iostream>
#include <queue>

using namespace std;
long long n,a,b,ans,rem,x;
priority_queue <pair <long long,long long> > arr;
priority_queue <pair <long long,long long> > arr1;
priority_queue <pair <long long,long long> > arr2;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        arr.push(make_pair(a-b,a));
        arr1.push(make_pair(-b,a));
        arr2.push(make_pair(a,b));
    }
    rem=0;
    while (!arr.empty()){
        ans+=arr.top().second-rem;
        //cout << ans << endl;
        rem=arr.top().first;
        arr.pop();
    }
    rem=0;
    while (!arr1.empty()){
        x+=arr1.top().second-rem;
        //cout << ans << endl;
        rem=arr1.top().second+arr1.top().first;
        arr1.pop();
    }
    ans=min(ans,x);
    rem=0;
    x=0;
    while (!arr2.empty()){
        x+=arr2.top().first-rem;
        //cout << ans << endl;
        rem=arr2.top().first+arr2.top().second;
        arr2.pop();
    }
    ans=min(ans,x);
    cout << ans << endl;
    return 0;
}
