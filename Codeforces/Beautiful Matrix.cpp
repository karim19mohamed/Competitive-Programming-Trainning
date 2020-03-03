#include <iostream>
#include <cmath>

using namespace std;
int m[5][5];
int ind_i;
int ind_j;
int ans;

int main()
{
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            cin >> m[i][j];
            if (m[i][j]) {
                ind_i=i;
                ind_j=j;
            }
        }
    }
    ans+=abs(2-ind_i)+abs(2-ind_j);
    cout << ans << endl;
    return 0;
}
