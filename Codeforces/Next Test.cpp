#include <iostream>
#include <algorithm>

using namespace std;
int n;
int q;
int arr[3009];

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        q=max(q,arr[i]);
    }
    sort(arr,arr+n);
    int k=0;
    for (int i=1;i<=q+1;i++){
        if (arr[k]!=i){
            cout << i << endl;
            break;
        }else{
            k++;
        }
    }
    return 0;
}
