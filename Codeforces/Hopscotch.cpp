#include <iostream>

using namespace std;
long long a ,x,y,level;
long long ans,k;
double cor_x,cor_y;

int main()
{
    cin >> a >> x >> y;

    level=1;
    if (y%a>0 || (y>0 && y<a)){
        while (level*a<y) level++;
        cout << level << endl;
        if (level==1 || level%2==0){
            cor_x=-1*(double)(a)/2;
            cor_y=(double)(a)/2;
            //if (x<0) k=1;
        }else{
            if (x==0) ans=-1;
            cor_x=-a;
            cor_y=a;
            if (x<0) k=1;
        }

        if (ans==0){
            if (x>cor_x && x<cor_y) {
                for (int i=1;i<level+1;i++){
                    if (i==1) ans=1;
                    else if (i%2==0) ans++;
                    else ans+=2;
                }
            }else {
                ans=-1;
                k=0;
            }
        }
    }else{
        ans=-1;
    }
    cout << ans-k << endl;
    return 0;
}
