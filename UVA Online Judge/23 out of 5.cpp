#include <iostream>
#include <stdio.h>

using namespace std;
int a[5];
int s=1;
bool flag[5];
int ans;
void check(int indx,int sum);

int main()
{

    while(s!=0){
        for (int i=0;i<5;i++){
            cin >> a[i];
        }
        s=a[0]+a[1]+a[2]+a[3]+a[4];
        if (s==0) break;
        //cout << s << endl;
        for (int j=0;j<5;j++){
            flag[j]=1;
            check(3,a[j]);
            flag[j]=0;
        }
        //cout << ans << endl;
        if (ans!=0){
            cout << "Possible" << endl;
        }else{
            cout << "Impossible" << endl;
        }
        ans=0;
    }
    return 0;
}
void check(int indx,int sum){
    if (indx==-1){
        //cout << sum << endl;
        if(sum==23) {
            //cout << sum << endl;
            ans=1;
            return ;
            }
        if(sum!=23) return;
    }

    for (int i=0;i<5;i++){
        if (flag[i]==0){
            flag[i]=1;
            check(indx-1,sum+a[i]);
            check(indx-1,sum-a[i]);
            check(indx-1,sum*a[i]);
            flag[i]=0;
        }
    }
}
