#include <iostream>
#include <queue>

using namespace std;
int n;
queue <int> arr;
int k;

int main()
{
    while (1){
        cin >> n;
        if (n==0) break;
        for (int i=1;i<=n;i++) arr.push(i);
        cout << "Discarded cards:";
        if (arr.size()>1) cout << " ";
        while (arr.size()!=1){
            cout << arr.front();
            if (arr.size()!=2) cout << ", ";
            arr.pop();
            k=arr.front();
            arr.pop();
            arr.push(k);
        }
        cout << endl;
        cout << "Remaining card: " << arr.front() << endl;
        arr.pop();
    }
    return 0;
}
