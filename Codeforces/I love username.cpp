#include <iostream>

using namespace std;
int n;
int arr[1009];

int main()
{
    cin >> n;
    int min_num=20000;
    int max_num=-1;
    int ans=0;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        if (i==0){
            min_num=arr[i];
            max_num=arr[i];
        }else{
            if (arr[i]>max_num){
                ans++;
                max_num=arr[i];
            }else if (arr[i]<min_num){
                ans++;
                min_num=arr[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
