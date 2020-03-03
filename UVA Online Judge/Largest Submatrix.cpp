#include <iostream>
#include <string>

using namespace std;
int t;
int arr[35][35];
string inp;
int ans=0;
int res[10000000];
int iter=0;

int main()
{
    cin >> t;
    string q;
    for (int qqq=0;qqq<t;qqq++){
        getline(std::cin,q);
        //if (inp.empty()==1) t--;
        cin >> inp;
        int k=inp.size();
        for (int i=0;i<k;i++){
            if (inp[i]-'0'==1) arr[1][i+1]=1+arr[0][i+1]+arr[1][i]-arr[0][i];
            if (inp[i]-'0'==0) arr[1][i+1]=-1+arr[0][i+1]+arr[1][i]-arr[0][i];
        }
        for (int i=1;i<k;i++){
            cin >> inp;
            for (int j=0;j<k;j++){
                if (inp[j]-'0'==1) arr[i+1][j+1]=1+arr[i][j+1]+arr[i+1][j]-arr[i][j];
                if (inp[j]-'0'==0) arr[i+1][j+1]=arr[i][j+1]+arr[i+1][j]-arr[i][j];
            }
        }
        /*for (int i=0;i<=k;i++){
            for (int j=0;j<=k;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }*/
        int num=0;
        for (int i=1;i<=k;i++){
            for (int j=1;j<=k;j++){
                for (int a=i;a<=k;a++){
                    for (int w=j;w<=k;w++){
                        num=arr[a][w]-arr[i-1][w]-arr[a][j-1]+arr[i-1][j-1];
                        if (num==(a-i+1)*(w-j+1)) ans=max(ans,num);
                    }
                }
            }
        }
        //res[iter]=ans;
        cout << ans << endl;
        if (qqq!=t-1) cout << endl;
        ans=0;
        //iter++;
    }
    /*for (int i=0;i<iter;i++){
        cout << res[i] << endl;
        if (i!=iter-1) cout << endl;
    }*/
    return 0;
}
