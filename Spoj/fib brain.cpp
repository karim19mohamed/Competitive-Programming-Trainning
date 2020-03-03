#include <iostream>
#include <cmath>

using namespace std;
long long fib (int n);
long long arr[100000000];

int main()
{
    int t;
    cin >> t;
    int n[t];
    for (int i=0;i<t;i++){
        cin >> n[i] ;
    }
    for (int i=0;i<t;i++){
        long long ans[i];
        ans[i]=fib (n[i]);
        cout << ans[i] << endl;
    }
    return 0;
}

long long fib (int n){
    arr[0]=0;
    arr[1]=1;
    if (n<=2){
        return n-1;
    }else{
        long long ans_1=1;
        long long ans_2=0;
        long long ans;
        for (int i=2;i<n;i++){
            if (arr[i]!=0){
                continue;
            }else{
                ans_1=arr[i-1];
                ans_2=arr[i-2];
            }
            ans=(ans_2+ans_1)%100000000;
            ans_2=ans_1;
            ans_1=ans;
            arr[i]=ans;
        }
        return ans%10;
    }

}
