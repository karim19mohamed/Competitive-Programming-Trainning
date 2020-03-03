#include <iostream>
#include <map>
#include <vector>

using namespace std;
long long n;
map <long long,long long> arr;
vector <long long> x;
long long k;

int main()
{
    while (cin >> n){
        arr[n]++;
        x.push_back(n);
    }
    while(x.empty()!=1){
        if (arr[x[k]]!=0) {
            cout << x[k] << " " << arr[x[k]] << endl;
            arr[x[k]]=0;
        }
        k++;
    }
    return 0;
}
