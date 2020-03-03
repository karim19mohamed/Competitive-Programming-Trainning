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
void tri (int i,int j,int indx_i,long long third);

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
                    sum[i][j]=0;
                    ans[i][j]=0;
                    num=0;
                }
            }
        }
        /*
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout << sum[i][j] << "   ";
            }
            cout << endl;
        }
        */
        long long res=0;
        int x=0;
        for (int i=2;i<n;i++){
            x=0;
            for (int j=0;j<n;j++){
                x++;
                min_j=x;
                max_j=n-1;
                if (L[i]<=sum[i][x]) continue;
                tri (j,min_j+(max_j-min_j)/2,floor((float)((max_j-min_j)/2)),L[i]);
                res=res+ans[j][j_min];
                //cout << res << endl;
                j_min=0;
            }
        }
        cout << res << endl;
    }
    return 0;
}

void tri (int i,int j,int indx_j,long long third){
    //cout <<i<<"  "<<j<<"  "<<indx_j<<"  dascx  "<<third<<"  "<<sum[i][j]<<"  "<<x<<"  sdafsd  "<<max_j<<"   "<<min_j<<endl;
    //cout << i <<"  " <<indx_i<<"  "<<ceil((float)(indx_i)/2) << endl;
    //int zzz;
    //cin >>  zzz;
    if (indx_j==0) {
        if (sum[i][j]<third) j_min=j;
        return;
    }


    if (sum[i][j]<third){
        j_min=j;
        min_j=j;
        tri(i,j+ceil((float)(indx_j)/2),floor((float)(max_j-min_j)/2),third);
    }else{
        max_j=j;
        tri(i,j-ceil((float)(indx_j)/2),floor((float)(max_j-min_j)/2),third);
    }
}
