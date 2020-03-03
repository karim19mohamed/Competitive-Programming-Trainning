#include <iostream>

using namespace std;
long long n;
long long arr[100009];
long long l,r=0;
long long num=1;
long long ans=1;

int main()
{
    cin >> n;
    if (n>1) ans=2;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        r=i;
        //cout << r << "  " << l << endl;
        if (r==0) continue;
        if (r-l>1 && arr[r]==arr[r-1]+arr[r-2]){
            if (r-l==2) num=2;
            num++;
        }else{
            l=r-1;
            num=1;
        }
        ans=max(ans,num);
    }
    cout << ans << endl;
    return 0;
}
