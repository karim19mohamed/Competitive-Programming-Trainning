#include <iostream>
#include <string>

using namespace std;
int n;
bool flag[34];
//char num[17]={'0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16'};
bool prime[34]={0  ,0  ,1  ,1  ,0  ,1  ,0  ,1  ,0  ,0  ,0   ,1   ,0   ,1   ,0   ,0   ,0   ,1   ,0   ,1   ,0   ,0   ,0   ,1   ,0   ,0   ,0   ,0   ,0   ,1   ,0   ,1   ,0   ,0   };
string num[34]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33"};
void ring (int indx,string ans,int q,int pre_q);
int y=1;

int main()
{
    while (cin >> n){
        cout << "Case " << y << ":" << endl;
        if (n!=1) ring (n-1,"1 ",0,0);
        //else cout << "1" << endl;
        cout << endl;
        y++;
    }
    return 0;
}
void ring (int indx,string ans,int q,int pre_q){
    if (ans.size()>3){
        int k=ans.size();
        if (prime[q+pre_q]!=1) return;
    }
    if (indx==0){
        int k=ans.size();
        if (prime[q+1]==1){
            ans.erase(ans.begin()+k-1);
            cout << ans << endl;
        }
        return;
    }

    for (int i=2;i<=n;i++){
        if (flag[i]==0){
            flag[i]=1;
            cout << ans << " " << indx << endl;
            char z;cin >> z;
            ring(indx-1,ans+num[i]+" ",i,q);
            flag[i]=0;
        }
    }
    return;
}
