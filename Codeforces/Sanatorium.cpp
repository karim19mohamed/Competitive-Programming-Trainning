#include <iostream>
#include <cmath>

using namespace std;
long long arr[3];
long long ans=1e18;
long long k;
long long num;
int indx;
int no_zero;
int sim;

int main()
{
    cin >> arr[0] >> arr[1] >> arr[2];
    num=arr[0];
    num=min(num,arr[1]);
    num=min(num,arr[2]);
    for (int i=0;i<3;i++){
        if (arr[i]==num) continue;
        if (arr[0]-arr[i]<0) k=k-(arr[0]-arr[i]);
        if (arr[0]-arr[i]==0) no_zero++;
        if (arr[1]-arr[i]<0) k=k-(arr[1]-arr[i]);
        if (arr[1]-arr[i]==0) no_zero++;
        if (arr[2]-arr[i]<0) k=k-(arr[2]-arr[i]);
        if (arr[2]-arr[i]==0) no_zero++;
        //cout <<"sada   " << k <<endl;
        if (no_zero==2) k--;
        ans=min(ans,k);
        k=0;
        no_zero=0;
        indx=1;
    }

    if (arr[0]+arr[1]+arr[2]!=3*arr[0] && arr[0]!=0){
        if (arr[0]+arr[1]==0) sim=1;
        if (arr[1]+arr[2]==0) sim=1;
        if (arr[0]+arr[3]==0) sim=1;
    }
    if (sim==1) ans-=2;
    if (indx) cout << ans << endl;
    else cout <<"0"<< endl;
    return 0;
}
