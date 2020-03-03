#include <iostream>

using namespace std;
int n;
int ans[1000][1000];

int main()
{
    cin >> n;
    //int i=2*n+100;
    //int j=2*n+100;


    //ans[n+1][0]=0;
    //ans[n+1][j-1]=0;
    //ans[0][n+1]=0;
    //ans[i][n+1]=0;
    for (int a=0;a<n+1;a++){
        int num=0;
        for (int b=0;b<=n-1-a;b++){
            ans[a][b]=-1;
            cout << "  ";
        }
        for (int b=n-1-a;b<=n-1;b++){
            ans[a][b]=num;
            cout << ans[a][b];
            if (a!=0 && b!=n+1) cout << " ";
            num++;
        }
        num--;
        for (int b=n;b<=n-1+a;b++){
            num--;
            ans[a][b]=num;
            cout << ans[a][b];
            if (b!=n-1+a) cout << " ";
        }
        cout << endl;
    }
    for (int a=n-1;a>=0;a--){
        cout << "  ";
        for (int b=0;b<=n-1+a;b++){
            if (ans[a][b]==-1) {
                cout << "  ";
                continue;
            }
            cout << ans[a][b] ;
            if (b!=n-1+a) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
