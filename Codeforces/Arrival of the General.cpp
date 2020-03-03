#include <iostream>

using namespace std;
int n;
int a[109];
int max_a=0;
int min_a=150;
int max_indx;
int min_indx;
int ans;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (a[i]>max_a){
            max_a=a[i];
            max_indx=i;
        }
        if (a[i]<=min_a){
            min_a=a[i];
            min_indx=i;
        }
    }
    if (max_indx!=0){
        if (max_indx>min_indx){
            ans=ans+max_indx;
            min_indx++;
        }else{
            ans=ans+max_indx;
        }
    }
    if (min_indx!=n-1){
        ans=ans+(n-1-min_indx);
    }
    cout << ans << endl;
    return 0;
}
