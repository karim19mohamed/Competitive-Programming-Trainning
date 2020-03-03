#include <iostream>
#include <string>
#include <sstream>

using namespace std;
long long tap,n;
long long cd[29];
bool flag[29];
long long ans,k;
long long num;
string x;
void music (long long indx,long long sum,long long s,std::string w);

int main()
{
    cin >> tap >> n;
    for (long long i=0;i<n;i++) cin >> cd[i];
    music (n,0,0,"");
    k=ans;
    //cout << "sasda";
    cout << x;
    cout << "sum:" << ans << endl;
    return 0;
}
void music (long long indx,long long sum,long long s,std::string w){
    if (indx+1==0) return;
    if (sum<=tap){
        if (sum>ans){
            num=s;
            ans=sum;
            x=w;
        }else if (sum==ans){
            if (s>num){
                num=s;
                x=w;
            }
        }
    }
    if (sum>tap){
        return;
    }

    for (int i=0;i<n;i++){
        if (flag[i]==0){
            flag[i]=1;
            stringstream ss;
            ss << cd[i];
            string p=ss.str();
            music (indx-1,sum+cd[i],s+1,w+p+" ");
            flag[i]=0;
        }
    }
}
/*
ans=0;
k=0;
num=0;
x=0;
*/
