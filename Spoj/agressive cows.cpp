#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int t;
int n;
int c;
long long x[100000];
int start_x;
int end_x;
long long final_ans=1e9;
long long min_dis(int i,long long dis_m,int s,int e,int indx);

int main()
{
    cin >> t;
    for (int j=0;j<t;j++){
        cin >> n >> c;
        for (int i=0;i<n;i++){
            cin >> x[i];
        }
        sort(x,x+n);
        c=c-2;
        long long ans=0;
        start_x=n-1;
        end_x=0;
        ans=min_dis(n/2,min( abs(x[end_x]-x[n/2]) , abs(x[start_x]-x[n/2]) ),start_x,end_x,n/2);
        cout << ans << endl;
        final_ans=1e9;
    }
    return 0;
}
long long min_dis(int i,long long dis_m,int s,int e,int indx){
    //cout << dis_m << "  c " << c << "final " << final_ans << "indx  " << indx << endl;
    if (c==0) return final_ans;
    //int zzz;
    //cin >> zzz;

    if ( dis_m > min( abs(x[e]-x[i-indx/2]) , abs(x[s]-x[i-indx/2]) ) || indx==0 ){
        if ( dis_m > min( abs(x[e]-x[i+indx/2]) , abs(x[s]-x[i+indx/2]) ) || indx==0 ){
            c--;
            final_ans=min(final_ans,dis_m);
            //cout << "asdas   " << final_ans << endl;
            dis_m=1e9;
            if (abs(i-e)>=abs(i-s)){
                start_x=i;
            }else{
                end_x=i;
            }
            indx=(abs(end_x-start_x))/2;
            min_dis(indx,min( abs(x[end_x]-x[indx]) , abs(x[start_x]-x[indx]) ),start_x,end_x,indx);
        }else{
            min_dis(i+indx/2,min( abs(x[e]-x[i+indx/2]) , abs(x[s]-x[i+indx/2]) ),start_x,end_x,indx/2);
        }
    }else{
        min_dis(i-indx/2,min( abs(x[e]-x[i-indx/2]) , abs(x[s]-x[i-indx/2]) ),start_x,end_x,indx/2);
    }

}


/*
1
5 3
1
2
8
4
9
*/

