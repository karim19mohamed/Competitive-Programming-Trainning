#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;
int n;
long long L[2005];
long long ans[2005];
int min_i;
int max_i;
int out;
int tri(int i,int indx,long long third);

int main()
{
    while(cin>>n){
        if (n==0) break;
        for (int i=0;i<n;i++){
                scanf("%lld",&L[i]);
                ans[i]=1;
            }
        sort(L,L+n);
        int k=n*(n-1)/2;
        long long sum[k];
        int num=0;
        int res=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i<j){
                    sum[num]=L[i]+L[j];
                    min_i=0;
                    max_i=n-1;
                    out=n;
                    res+=(n-1-tri(min_i+(max_i-min_i)/2,(max_i-min_i)/2,sum[num]));
                    num=num+1;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
int tri(int i,int indx,long long third){
    if (indx==0){
        if (L[i]<=third) out=i;
        return out;
    }

    if (L[i]>third){
        max_i=i;
        tri(i-(indx+1)/2,(max_i-min_i)/2,third);
    }else{
        min_i=i;
        out=i;
        tri(i+(indx+1)/2,(max_i-min_i)/2,third);
    }
}
