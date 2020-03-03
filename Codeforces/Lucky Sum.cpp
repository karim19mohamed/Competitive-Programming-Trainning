#include <iostream>
#include <algorithm>

using namespace std;
long long n,m;
long long ans;
long long arr[10000];
int i=0;

void perm(long long num,int indx,long long d);

int main()
{
    cin >> n >> m;
    int f=0,e=1;

    long long k=n;
    while (k!=0){
        k/=10;
        f++;
    }
    k=m;
    while (k!=0){
        k/=10;
        e++;
    }
    //cout << f << " " << e <<endl;
    for (int j=f;j<=e;j++){
        perm(0,j,1);
    }
    sort(arr,arr+i);
    n--;
    for (int j=0;j<i;j++){
        if (arr[j]>=n && arr[j]<m){
            ans+=arr[j]*(arr[j]-n);
            n=arr[j];
        }else if (arr[j]>=m){
            ans+=arr[j]*(m-n);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
void perm(long long num,int indx,long long d){
    if (indx==0) {
        arr[i]=num;
        //cout << num << endl;
        i++;
        return;
    }
    perm (num+4*d,indx-1,d*10);
    perm (num+7*d,indx-1,d*10);
}
