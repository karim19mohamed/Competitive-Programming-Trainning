#include <iostream>

using namespace std;
long long n;
long long a[100009];

int main()
{
    cin >> n ;
    for (int i=0;i<n;i++){
        cin >> a[i] ;
    }
    long long t=0;
    for (int i=0;i<n;i++){
        t+=a[i]*a[n-1-i];
        //cout << a[i] << "  " << a[n-1-i] << endl;
    }
    cout << t << endl;
    return 0;
}
