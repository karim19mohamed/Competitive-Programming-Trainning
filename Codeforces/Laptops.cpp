#include <iostream>
#include <queue>

using namespace std;
int n;
priority_queue < pair<int,int> > arr;
pair <int,int> x;
int a,b;
int ans;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        x=make_pair(-1*a,b);
        arr.push(x);
    }
    ans=arr.top().second;
    arr.pop();
    while (arr.empty()!=1){
        if (arr.top().second<ans){
            ans=-1;
            break;
        }else{
            ans=arr.top().second;
        }
        arr.pop();
    }
    if (ans==-1) cout << "Happy Alex" << endl;
    else cout << "Poor Alex" << endl;
    return 0;
}
