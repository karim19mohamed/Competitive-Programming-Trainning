#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
int n,arr[109],res=10000,a,b;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",&arr[i]);
    for (int i=0;i<n;++i) {
        if (i<n-1){
            if (abs(arr[i]-arr[i+1])<res){
                res=abs(arr[i]-arr[i+1]);
                a=i;b=i+1;
            }
        }else{
            if (abs(arr[i]-arr[0])<res){
                res=abs(arr[i]-arr[0]);
                a=i;b=0;
            }
        }
    }
    printf("%d %d\n",a+1,b+1);
    return 0;
}
