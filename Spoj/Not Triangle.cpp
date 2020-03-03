#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int n;
long long L[2005];
long long sum[2005][2005];
long long ans[2005][2005];
int i_min;
int j_min;
int min_i;
int max_i;
int min_j;
int max_j;
int iter;
int x;
void tri (int i,int j,int indx_i,int indx_j,long long third);

int main()
{
    while (cin>>n){
        if (n==0) break;
        for (int i=0;i<n;i++){
            cin >> L[i];
        }
        sort(L,L+n);
        long long num=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i<j){
                    sum[i][j]=L[i]+L[j];
                    num=num+1;
                    ans[i][j]=num;
                }else{
                    sum[i][j]=2*1e10;
                    ans[i][j]=num;
                }
            }
        }

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout << sum[i][j] << "   ";
            }
            cout << endl;
        }

        long long res=0;
        for (int i=2;i<n;i++){
            int min_i=0;
            int max_i=n-1;
            int min_j=0;
            int max_j=n-1;
            iter=0;
            x=0;
            tri (n/2,n-1,floor((float)((max_i-min_i)/2)),floor((float)((max_j-min_j)/2)),L[i]);
            res=res+ans[i_min][j_min];
            i_min=0;
            j_min=0;
        }
        cout << res << endl;
    }
    return 0;
}

void tri (int i,int j,int indx_i,int indx_j,long long third){
    cout <<i<<"  "<<j<<"  "<<indx_i<<"  "<<indx_j<<"  "<<third<<"  "<<sum[i][j]<<"  "<<x<<endl;
    //cout << i <<"  " <<indx_i<<"  "<<ceil((float)(indx_i)/2) << endl;
    int zzz;
    //cin >>  zzz;
    if (indx_j==0) {
        //j_min=j;
        return;
    }

    if (indx_i==0){
        if(!iter){
            i_min=i;
            if (sum[i_min][n-1]<third){
                x=i_min+1;
            }else{
                x=i_min;
            }
            j=n/2;
            iter++;
        }
        if (sum[x][j]<third){
            j_min=j;
            min_j=j;
            tri(x,j+ceil((float)(indx_j)/2),0,floor((float)(max_j-min_j)/2),third);
        }else{
            max_j=j;
            tri(x,j-ceil((float)(indx_j)/2),0,ceil((float)(max_j-min_j)/2),third);
        }
    }
    //cout << iter << endl;
    if (iter==0){
        //cout << i <<"  " << ceil((float)((indx_i)/2)) << endl;
        if (sum[i][n-1]<third){
            min_i=i;
            tri(i+ceil((float)(indx_i)/2),n-1,floor((float)(max_i-min_i)/2),indx_j,third);
        }else{
            max_i=i;
            tri(i-ceil((float)(indx_i)/2),n-1,floor((float)(max_i-min_i)/2),indx_j,third);
        }
    }

}
