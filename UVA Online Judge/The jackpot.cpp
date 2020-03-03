#include <iostream>
#include <cmath>

using namespace std;
int n;
long long arr[10009];

int main()
{
    while (1){
        long long ans=0;
        cin >> n;
        if (n==0) break;
        for (int i=1;i<=n;i++){
            cin >> arr[i];
            arr[i]=arr[i]+arr[i-1];
            ans=max(ans,arr[i]);
            if (arr[i]<0) arr[i]=0;
        }
        if (ans!=0){
            cout << "The maximum winning streak is " <<ans << "." << endl;
        }else{
            cout << "Losing streak." << endl;
        }
    }
    return 0;
}
