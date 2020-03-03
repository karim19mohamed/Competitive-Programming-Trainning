#include <iostream>

using namespace std;
int b;
int s;
long long arr[20009];

int main()
{
    cin >> b;
    for (int k=0;k<b;k++){
        cin >> s;
        long long num;
        int i_max=1;
        int iter=1;
        int j_max=1;
        long long ans=0;
        for (int i=1;i<s;i++){
            cin >> num;
            arr[i]=arr[i-1]+num;
            if (ans<arr[i]){
                i_max=iter;
                j_max=i+1;
                ans=arr[i];
            }else if (ans==arr[i]){
                if (j_max-i_max < i+1-iter){
                    i_max=iter;
                    j_max=i+1;
                    ans=arr[i];
                }
            }
            if (arr[i]<0){
                iter=i+1;
                arr[i]=0;
            }
            //cout << "asddfsd   " << ans << endl;
        }
        if (ans>0){
            cout << "The nicest part of route " << k+1 << " is between stops " << i_max << " and " << j_max << endl;
        }else {
            cout << "Route " << k+1 << " has no nice parts" << endl;
        }
    }

    return 0;
}
