#include <iostream>
#include <algorithm>

using namespace std;
int tap,n;
int cd[29];
int arr[29];
int ans,num,ind_1,ind_2;
bool in_out;

int main()
{
    cin >> tap >> n;
    for (int i=1;i<n+1;i++) {
        cin >> cd[i];
        arr[i]=cd[i];
        cd[i]=cd[i]+cd[i-1];
        //cout << cd[i] << endl;
    }
    sort (cd,cd+n+1);
    for (int i=1;i<n+1;i++){
        for (int j=0;j<i;j++){
            //cout << cd[i] << "  " <<cd[j] << "  " << cd[n]-cd[j]+cd[i] << "  " << ans << endl;
            if (cd[i]-cd[j]<=tap){
                if (cd[i]-cd[j]>ans){
                    ans=cd[i]-cd[j];
                    num=i-j;
                    in_out=0;
                    ind_1=i;
                    ind_2=j;
                }else if (cd[i]-cd[j]==ans){
                    num=max(num,i-j);
                    in_out=0;
                    ind_1=i;
                    ind_2=j;
                }
            }
            if (cd[n]-cd[i]+cd[j]<=tap){
                if (cd[n]-cd[i]+cd[j]>ans){
                    ans=cd[n]-cd[i]+cd[j];
                    num=n+j-i;
                    in_out=1;
                    ind_1=i;
                    ind_2=j;
                }else if (cd[n]-cd[i]+cd[j]==ans){
                    num=max(num,n+j-i);
                    in_out=1;
                    ind_1=i;
                    ind_2=j;
                }
            }
        }
    }
    //cout << ind_1 << "  " << ind_2 << endl;
    if (in_out==0){
        for (int i=ind_2+1;i<=ind_1;i++) cout << arr[i] << " ";

    }else{
        for (int i=1;i<=ind_2;i++) cout << arr[i] << " ";
        for (int j=ind_1+1;j<=n;j++) cout << arr[j] << " ";
    }
    //cout << in_out << endl;
    cout << "sum:" << ans << endl;
    return 0;
}
