#include <iostream>
#include <cmath>
#include <string>

using namespace std;
int x;
int r,c,m,n;
char arr[30][30];
int counter[30];
int m_ans,ans;

int main()
{
    cin >> x;
    for (int i=0;i<x;i++){
        cin >> r >> c >> m >> n;
        for (int j=0;j<r;j++){
            for (int k=0;k<c;k++){
                cin >> arr[j][k];
                counter[arr[j][k]-'A']++;
                m_ans=max(m_ans,counter[arr[j][k]-'A']);
            }
        }
        for (int j=0;j<27;j++){
            if (counter[j]==m_ans) ans+=counter[j]*m;
            else ans+=counter[j]*n;
            counter[j]=0;
        }
        cout << "Case " << i+1 << ": " << ans << endl;
        ans=0;
        m_ans=0;
    }
    return 0;
}
