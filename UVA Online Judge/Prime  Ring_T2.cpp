#include <iostream>
#include <string>

using namespace std;
int n;
bool prime[34]={0  ,0  ,1  ,1  ,0  ,1  ,0  ,1  ,0  ,0  ,0   ,1   ,0   ,1   ,0   ,0   ,0   ,1   ,0   ,1   ,0   ,0   ,0   ,1   ,0   ,0   ,0   ,0   ,0   ,1   ,0   ,1   ,0   ,0   };
string num[34]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33"};
bool flag[34];
void ring (int indx,string ans,int e,int f);
int y=1;
bool q;

int main()
{

    while (cin >> n){
        if (q==1) cout << endl;
        cout << "Case " << y << ":" << endl;
        if (n!=1) ring(n-1,"1 ",1,0);
        else cout << "1" << endl;
        q=1;
        y++;
    }
    return 0;
}
void ring (int indx,string ans,int e,int f){
    if (ans.size()>2){
        if (prime[f+e]!=1) return;
    }
    if (indx==0){
        if (prime[e+1]==1){
            int k=ans.size();
            ans.erase(ans.begin()+k-1);
            cout << ans << endl;
        }
        return;
    }

    for (int i=2;i<=n;i++){
        if (flag[i]==0){
            flag[i]=1;
            ring(indx-1,ans+num[i]+" ",i,e);
            flag[i]=0;
        }
    }
}
