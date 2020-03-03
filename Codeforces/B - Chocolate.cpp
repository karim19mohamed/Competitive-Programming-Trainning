#include <iostream>
#include <stdio.h>

using namespace std;
int n,arr[109],f,e;
long long ans=1,c[109];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);
    c[arr[0]]++;
    for (int i=1;i<n;i++){
        arr[i]+=arr[i-1];
        c[arr[i]]++;

        e=arr[i];
    }
    //for (int i=0;i<n;i++) cout << "  " << arr[i] << endl;
    for (int i=1;i<e;i++){
        ans*=c[i];
    }
    if (c[0]==n) ans=0;
    printf("%lld\n",ans);
    return 0;
}