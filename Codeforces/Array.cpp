#include <iostream>
#include <queue>

using namespace std;
int n;
int arr[109];
int neg[2];
queue <int> cat_1;
queue <int> cat_2;
queue <int> cat_3;

int main()
{
    cin >> n;
    int z=0;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        if (arr[i]<0 && cat_1.empty()!=1 && neg[1]==0){
            neg[z]=arr[i];
            z++;
            continue;
        }

        if (cat_1.empty()==1 && arr[i]<0){
            cat_1.push(arr[i]);
        }else if (arr[i]<=0){
            cat_3.push(arr[i]);
        }else if (arr[i]>0){
            cat_2.push(arr[i]);
        }
    }
    if (cat_2.empty()==1){
        cat_2.push(neg[0]);
        cat_2.push(neg[1]);
    }else if (neg[0]!=0){
        cat_3.push(neg[0]);
        if (neg[1]!=0) cat_3.push(neg[1]);
    }

    int k=cat_1.size();
    cout << cat_1.size() << " ";
    for (int i=0;i<k;i++){
        cout << cat_1.front();
        cat_1.pop();
        if (i!=k-1) cout << " ";
    }
    cout << endl;

    k=cat_2.size();
    cout << cat_2.size() << " ";
    for (int i=0;i<k;i++){
        cout << cat_2.front();
        cat_2.pop();
        if (i!=k-1) cout << " ";
    }
    cout << endl;

    k=cat_3.size();
    cout << cat_3.size() << " ";
    for (int i=0;i<k;i++){
        cout << cat_3.front();
        cat_3.pop();
        if (i!=k-1) cout << " ";
    }
    cout << endl;
    return 0;
}
