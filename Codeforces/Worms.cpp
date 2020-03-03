#include <iostream>
#include <cmath>

using namespace std;
int n;
int a[100009];
int m;
int q[100009];
int pie1[100009];
int pie2[100009];
int place(int i,int indx,int x);


int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    pie1[0]=1;
    pie2[0]=a[0];
    for (int i=1;i<n;i++){
        pie1[i]=pie2[i-1]+1;
        pie2[i]=pie2[i-1]+a[i];
    }
    cin >> m;
    for (int i=0;i<m;i++){
        cin >> q[i];
    }
    for (int i=0;i<m;i++){
        int ans;
        ans=place(n/2,n/2,q[i])+1;
        cout << ans << endl;
    }
    return 0;
}
int place(int i,int indx,int x){
    //cout << "i=" <<i << "   indx="<<indx << "   pie1="<<pie1[i] << "   pie2="<<pie2[i] << "   x="<<x <<endl;
    if (x>=pie1[i] && x<=pie2[i]) return i;
    //int asas;
    //cin >> asas;
    if(x<pie1[i] && x<pie2[i]){
        place(i-ceil((float)(indx+1)/2),indx/2,x);
    }else{
        place(i+ceil((float)(indx)/2),indx/2,x);
    }
}
