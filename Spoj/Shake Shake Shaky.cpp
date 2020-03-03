#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int t;
int n;
long long k;
long long arr[50000];
long long max_i;
long long min_i;
long long res;
long long final_res;

long long distrib (long long i,long long indx);
int cal(long long x);

int main()
{
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n >> k;

        for (int j=0;j<n;j++){
            cin >> arr[j];
        }
        sort(arr,arr+n);
        min_i=0;
        max_i=arr[n-1];
        final_res=0;
        long long ans=0;
        ans=distrib(max_i/2,(max_i+1)/2);
        cout << ans << endl;
    }
    return 0;
}
long long distrib (long long i,long long indx){
    cout << "fgxdx   "  << i << "    " << indx << "    " << cal(i) << "   "<<min_i<<"   "<<max_i<< endl;
    int zzz;
    cin >> zzz;
    if (cal(i)==1){
        if (indx==0) return final_res;
        //max_i=i+indx;
        cout << "yes" << endl;
        min_i=i;
        distrib(i+ceil((float)(indx)/2),floor( (float)((max_i-min_i)/2) ) );
    }else if (cal(i)==2){
        return final_res;
    }else if (cal(i)==0){
        cout << "no" << endl;
        if (indx==0) return final_res;
        max_i=i;
        //min_i=i-indx;
        distrib(i-ceil((float)(indx+1)/2),ceil( (float)((max_i-min_i)/2) ) );
    }
}
int cal(long long x){
    long long ans=0;
    if (x==0) {
        res=x;
        return 1;
    }
    for (int j=0;j<n;j++){
        //if (x<100){
        //int zzz;
        //cin >> zzz;
        ans=ans+floor( (float)(arr[j]/x) );
        cout << x << "    " << arr[j] << "   " << ans << endl;
        //}
        if (ans>=k){
            res=x;
            final_res=max(final_res,res);
            if (res!=final_res) return 2;
            return 1;
        }
    }
    if (ans<k) return 0;
}
