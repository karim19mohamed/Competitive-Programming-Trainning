#include <iostream>
#include <cmath>

using namespace std;
int t;
int n;
int ans;
int arr[50];
void tower(int num,int i);

int main()
{
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n;
        for (int j=0;j<n;j++){
            arr[j]=0;
        }
        ans=0;
        tower(1,0);

        cout << ans << endl;
    }
    return 0;
}
void tower(int num,int i){

    while (1){
        if (i==n) return;
        //cout << num << "   " <<arr[0]<< "   "<<arr[1]<< "   "<<arr[2]<< "   "<<arr[3] << endl;
        if ((int)(sqrt(arr[i]+num))*(int)(sqrt(arr[i]+num)) != arr[i]+num && arr[i]!=0){
            i++;
        }else{
            arr[i]=num;
            ans=num;
            tower(num+1,0);
            break;
        }
    }
}
