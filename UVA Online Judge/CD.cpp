#include <iostream>
#include <queue>

using namespace std;
long long tap,n;
long long cd[29];
bool flag[29];
priority_queue <pair <int,long long> > arr;
pair <int,int> foo;
long long ans,k;
int num,x;
void music (long long indx,long long sum,int s);

int main()
{
    cin >> tap >> n;
    for (int i=0;i<n;i++) cin >> cd[i];
    music (n,0,0);
    k=ans;
    for (int i=0;i<n;i++){
        k-=cd[i];
        x++;
        foo=make_pair(-1*i,cd[i]);
        arr.push(foo);
        for (int j=0;j<n;j++){
            if (cd[j]<=k && j!=i){
                k-=cd[j];
                foo=make_pair(-1*j,cd[j]);
                arr.push(foo);
                x++;
            }
        }
        cout << x << " " << num << " " << k << endl;
        if (x==num){
            if (k==0) {
                while (arr.empty()!=1) {
                    cout << arr.top().second << " ";
                    arr.pop();
                }
                break;
            }
        }
        x=0;
        k=ans;
        while (arr.empty()!=1) arr.pop();
    }
    cout << "sum:" << ans << endl;
    return 0;
}
void music (long long indx,long long sum,int s){
    if (indx+1==0) return;
    if (sum<=tap){
        if (sum>ans) num=s;
        else if (sum==ans) num=max(num,s);
        ans=max(ans,sum);
    }
    if (sum>tap){
        return;
    }

    for (int i=0;i<n;i++){
        if (flag[i]==0){
            flag[i]=1;
            music (indx-1,sum+cd[i],s+1);
            flag[i]=0;
        }
    }
}
/*
ans=0;
k=0;
num=0;
x=0;
*/
