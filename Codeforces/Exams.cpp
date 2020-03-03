#include <iostream>

using namespace std;
int n,m;
int d[10009];
int a[10009];
int ans;

int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> d[i];
    }
    for (int i=0;i<m;i++){
        int k;
        cin >>k;
        a[k+1]++;
    }
    int num=1;
    for (int i=0;i<n;i++){
        if (d[i]==0) {
            num++;
        }else{
            cout << "sasda    " <<a[num] << "sasda    "<<m << endl;
            if (a[num]>0){
                a[num]--;
                m--;
                ans+=num;
                num=1;
            }else{
                num++;
            }
        }
    }
    //cout << m << endl;
    if (m==0) cout << ans << endl;
    else cout << "-1" << endl;
    return 0;
}
