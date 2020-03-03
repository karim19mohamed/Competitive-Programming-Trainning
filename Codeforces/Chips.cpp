#include <iostream>

using namespace std;
int n,m;

int main()
{
    cin >> n >> m;
    int i=1;
    while (m!=0){
        if (i>n) i=1;
        if (m-i>=0){
            m=m-i;
            i++;
        }else{
            break;
        }
    }
    cout << m << endl;
    return 0;
}
