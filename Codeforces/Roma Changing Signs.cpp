#include <iostream>
#include <algorithm>

using namespace std;
long long n,a,k,sum;
int arr[100009];
bool f;

int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        sum+=arr[i];
    }

    //sort (arr,arr+n);

    while (k!=0){
        if (a==n) a=0;
        if (arr[a]>=0 && f==0) {
            sort (arr,arr+n);
            a=0;
            f=1;
        }
        sum-=arr[a];
        arr[a]*=-1;
        sum+=arr[a];
        k--;
        if (!f) a++;
    }
    cout << sum << endl;
    return 0;
}
