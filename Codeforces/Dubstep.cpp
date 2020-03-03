#include <iostream>
#include <string>

using namespace std;
string n,ans;

int main()
{
    cin >> n;
    int k=n.size();
    int f=0;
    int s=0;
    int e=0;
    for (int i=0;i<k;i++){
        if (n[i]=='W' && n[i+1]=='U' && n[i+2]=='B'){
            if (f==1) {
                n.erase(i,3);
                n.insert(i," ");
            }else{
                n.erase(i,3);
                i=i-1;
                continue;
            }
        }else{
            f=1;
        }
    }
    cout << n <<endl;
    return 0;
}
