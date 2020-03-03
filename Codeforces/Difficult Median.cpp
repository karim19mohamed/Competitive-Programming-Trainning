#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
int t;
long long n,N,arr[100009],ans[100009],m,moved_m,k=0,new_indx=0;

int main()
{
    //freopen("difficult.in", "r", stdin);
    scanf("%d",&t);
    while (t--){
        scanf("%lld",&n);
        for (long long i=0;i<n;i++){
            scanf("%lld",&arr[i]);
            m+=arr[i];
        }
        N=m;
        m=(m+1)/2;
        long long w=0;
        for (long long i=0;i<n;i++){
            w+=arr[i];
            long long indx=w;
            if (indx<m){
                k=abs(m-indx);
                //indx=m;
                moved_m=(N-k+1)/2;
                if (moved_m<indx){
                    //indx--;
                    //k--;
                    k=k-(indx-moved_m);
                }else if (moved_m>indx){
                    //indx++;
                    //k++;
                    k=k+(moved_m-indx);
                }
                ans[i]=k;
            }else if (indx-arr[i]+1>m){
                indx=indx-arr[i]+1;
                k=abs(m-indx);
                indx=m;
                moved_m=(N-k+1)/2;
                if (moved_m<indx){
                    k=k+(indx-moved_m);
                    indx--;
                    //k++;
                }else if (moved_m>indx){
                    k=k-(moved_m-indx);
                    indx++;
                    //k--;
                }
                ans[i]=k;
            }else{
                ans[i]=0;
            }
        }
        for (long long i=0;i<n;i++){
            printf("%lld",ans[i]);
            if (i!=n-1) printf(" ");
        }
        printf("\n");
        k=0,new_indx=0;m=0;N=0;
    }
    return 0;
}
