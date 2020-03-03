#include <iostream>

using namespace std;
long long n,m,boxs,q;
long long arr[100009];
long long s_position[100009];
long long t[100009];
long long ans;

int main()
{
    cin >> n >> m;
    for (long long i=0;i<n;i++) {
        cin >> arr[i];
        boxs+=arr[i];
    }
    if (boxs!=0){
        s_position[0]=m;
        ans=1;
        q=1;
        while (boxs!=0){
            for (long long j=0;j<n;j++) {
                s_position[j]+=t[j];
                t[j]=0;
            }
            for (long long j=0;j<n;j++){
                //cout << s_position[j] << "  " << arr[j] << "  " << boxs << endl;
                //char z;cin>>z;
                if (s_position[j]-arr[j]>0){
                    t[j+1]+=s_position[j]-arr[j];
                    s_position[j]-=t[j+1];
                }
                if(arr[j]!=0){
                    if (s_position[j]<=arr[j]){
                        arr[j]=arr[j]-s_position[j];
                        boxs-=s_position[j];
                    }else{
                        boxs-=arr[j];
                        arr[j]=0;
                    }
                }
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
