/*
ID: s-karim1
PROG: ride
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string comit;
string group;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    fin >> comit;
    fin >> group;
    int sum[2]={1,1};
    for (int i=0;i<comit.size();i++){
        sum[0]=sum[0]*(comit[i]-'@');
    }
    for (int i=0;i<group.size();i++){
        sum[1]=sum[1]*(group[i]-'@');
    }
    if ((sum[0]%47) == (sum[1]%47)){
        fout << "GO" << endl;
    }else{
        fout << "STAY" << endl;
    }
    return 0;
}
