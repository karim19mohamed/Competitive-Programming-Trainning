#include <iostream>
#include <queue>

using namespace std;
long long s,n;
long long x;
long long y;
bool ans=1;
priority_queue < pair<long long,long long> > arr;
pair <long long,long long> in;

int main()
{
    cin >> s >> n;
    for (int i=0;i<n;i++){
        cin >> x >> y;
        in=make_pair(-1*x,y);
        arr.push(in);
    }
    int k=arr.size();
    for (int i=0;i<k;i++){
        if (s+arr.top().first>0){
            s+=arr.top().second;
            arr.pop();
        }else{
            ans=0;
            break;
        }
    }
    if (ans==1) cout <<"YES"<<endl;
    else cout <<"No"<<endl;
    return 0;
}
