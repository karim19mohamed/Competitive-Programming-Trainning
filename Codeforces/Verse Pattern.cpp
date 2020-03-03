#include <iostream>
#include <string>

using namespace std;
int n;
int arr[109];
string x;
string q;
int alp[125];

int main()
{
    alp[97]=97;
    alp[101]=101;
    alp[105]=105;
    alp[111]=111;
    alp[117]=117;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    getline(std::cin,q);
    int k=0;
    bool ans=0;
    for (int i=0;i<n;i++){
        getline(std::cin,x);
        int ite=x.size();
        int num=0;
        //cout << x << endl;
        for (int j=0;j<ite;j++){
            //cout << x[j] << endl;
            if (x[j]=='a') num++;
            if (x[j]=='e') num++;
            if (x[j]=='i') num++;
            if (x[j]=='o') num++;
            if (x[j]=='u') num++;
            if (x[j]=='y') num++;
        }
        //cout << ite << endl;
        if (num==arr[i] && k==0){
            ans=1;
        }else{
            ans=0;
            k=1;
            //break;
        }
    }
    if (ans==0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}
