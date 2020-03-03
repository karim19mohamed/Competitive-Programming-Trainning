#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
long long x,y;
priority_queue <long long> arr;
long long ans;
long long cost;

int main()
{
    while (1){
        cin >> n;
        if (n==0) break;
        for (int i=0;i<n;i++){
            cin >> x;
            arr.push(-1*x);
        }
        while (arr.size()!=1){
            x=arr.top();
            arr.pop();
            y=arr.top();
            arr.pop();
            arr.push(x+y);
            cost+=x+y;
        }
        arr.pop();
        cout << -1*cost << endl;
        ans=0;
        cost=0;
    }
    return 0;
}
