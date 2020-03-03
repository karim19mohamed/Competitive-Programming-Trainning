#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
int n;
long long arr[4009],di[1000009],ans,a,c,d;
int b;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        if (i>0){
            if (b==0 && arr[i-1]<=arr[i]){
                a=arr[i-1];
                d=arr[i];
                b=1;
                c=2;
            }else if (b==1){
                if (a==arr[i] && d==arr[i-1]){
                    c++;
                    b=3;
                }else{
                    b=2;
                }
            }else if (b==3){
                if (d==arr[i] && a==arr[i-1]){
                    c++;
                    b=1;
                }else{
                    b=2;
                }
            }else if (b==2){
                ans=max(ans,c);
                b=0;
                c=0;
            }
        }
    }
    ans=max(ans,c);
    printf("%lld\n",ans);
    return 0;
}
