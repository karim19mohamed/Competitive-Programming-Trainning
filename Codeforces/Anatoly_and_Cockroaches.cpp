#include <iostream>
#include <cmath>

using namespace std;
int n;
char a[100009];
char x[2]={'r','b'};
char op_1[100009];
char op_2[100009];
int ans_1=0;
int ans_2=0;
int ans=0;

int main()
{
    cin >> n ;

    for (int i=0;i<n;i++){
        cin >> a[i];
        //cout << a[i];
        op_1[i]=x[i%2];
        //cout << op_1[i];
        ans_1=ans_1+abs(a[i]-op_1[i]);
        op_2[i]=x[(i+1)%2];
        ans_2=ans_2+abs(a[i]-op_2[i]);
    }
    if (ans_1<=ans_2){
        /*if (ans_1==0){
            cout << ans << endl;
            break;
        }*/
        for (int i=0;i<n;i++){
            if (a[i]!=op_1[i]){
                if (a[i+1]!=op_1[i+1] && i+1<n){
                    ans++;
                    if (a[i+1]=='r'){
                        a[i+1]='b';
                    }else if (a[i+1]=='b'){
                        a[i+1]='r';
                    }
                }else{
                    ans++;
                }
            }
        }
    }else{
        /*if (ans_2==0){
            cout << ans << endl;
            break;
        }*/
        for (int i=0;i<n;i++){
            if (a[i]!=op_2[i]){
                if (a[i+1]!=op_2[i+1] && i+1<n){
                    ans++;
                    if (a[i+1]=='r') a[i+1]='b';
                    if (a[i+1]=='b') a[i+1]='r';
                }else{
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
