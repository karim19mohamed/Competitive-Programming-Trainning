#include <iostream>
#include <stdio.h>

using namespace std;
int n,m,ri,ci,re,ce,a[509][509],b[509][509];
long long q,ans;
char arr[509][509];
bool w;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> arr[i][j];
    for (int i=0;i<n;i++){
        w=0;
        for (int j=0;j<m;j++){
            if (w && arr[i][j]=='.'){
                a[i][j]=a[i][j-1]+1;
            }else if (arr[i][j]=='.'){
                if (j!=0){
                    a[i][j]=a[i][j-1];
                }
                w=1;
            }else if (arr[i][j]=='#'){
                w=0;
                if (j!=0){
                    a[i][j]=a[i][j-1];
                }
            }
        }
    }
    for (int i=0;i<m;i++){
        w=0;
        for (int j=0;j<n;j++){
            if (w && arr[j][i]=='.'){
                b[j][i]=b[j-1][i]+1;
            }else if (arr[j][i]=='.'){
                if (j!=0){
                    b[j][i]=b[j-1][i];
                }
                w=1;
            }else if (arr[j][i]=='#'){
                w=0;
                if (j!=0){
                    b[j][i]=b[j-1][i];
                }
            }
            //cout << b[j][i] << " ";
        }
        //cout << endl;
    }
    scanf("%lld",&q);
    for (long long i=0;i<q;i++){
        scanf("%d%d%d%d",&ri,&ci,&re,&ce);
        ri--;ci--;re--;ce--;
        ans=0;
        for (int j=ri;j<=re;j++){
            ans+=a[j][ce]-a[j][ci];
        }
        for (int j=ci;j<=ce;j++){
            ans+=b[re][j]-b[ri][j];
        }
        printf("%lld\n",ans);
    }
    return 0;
}