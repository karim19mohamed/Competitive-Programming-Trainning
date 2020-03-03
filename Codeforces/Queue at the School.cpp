#include <iostream>
#include <string>

using namespace std;
int n,t;
string s1;

int main()
{
    cin >> n >> t;
    cin >> s1;
    int k=s1.size();
    for (int i=0;i<t;i++){
        for (int j=1;j<k;j++){
            if(s1[j]=='G' && s1[j-1]=='B'){
                s1[j-1]='G';
                s1[j]='B';
                j++;
            }
        }
    }
    cout << s1 << endl;
    return 0;
}
