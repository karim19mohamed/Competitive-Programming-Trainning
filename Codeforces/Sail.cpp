#include <iostream>
#include <string>

using namespace std;
long long t,sx,sy,ex,ey;
long long ans=-1;
string x;

int main()
{
    cin >> t >> sx >> sy >> ex >> ey;
    cin >> x;
    int k=x.size();
    for (int i=0;i<k;i++){
        if (x[i]=='E' && ex-sx>0) {
            sx++;
        }else if (x[i]=='S' && ey-sy<0) {
            sy--;
        }else if (x[i]=='W' && ex-sx<0) {
            sx--;
        }else {
            if (x[i]=='N' && ey-sy>0) sy++;
        }
        if (sx==ex && sy==ey){
            ans=i+1;
            break;
        }
        //cout << sx << "  " << sy << endl;
    }
    cout << ans << endl;
    return 0;
}
