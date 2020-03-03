#include <iostream>
#include <stdio.h>

using namespace std;
int n,m,num,b;
long long k,a,r[5009][2],c[5009][2];

int main()
{
    scanf("%d%d%lld",&n,&m,&k);
    for (long long i=1;i<=k;i++){
        scanf("%d%d%lld",&num,&b,&a);
        if (num==1){
            r[b-1][0]=a;
            r[b-1][1]=i;
        }else{
            c[b-1][0]=a;
            c[b-1][1]=i;
        }
    }
    //cout << r[0][0] << " " << c[1][0] << endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (r[i][1]>c[j][1]){
                printf("%lld",r[i][0]);
            }else if (r[i][1]<=c[j][1]){
                printf("%lld",c[j][0]);
            }
            if (j!=m-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}