#include <iostream>
#include <string>

using namespace std;
int n;
string clock1;

int main()
{
    cin >> n;
    cin >> clock1;
    if (n==12){
        if (clock1[1]>'2'){
            clock1[0]='0';
        }else if (clock1[1]>'0'){
            if (clock1[0]>'1') clock1[0]='0';
        }else if (clock1[1]=='0'){
            if (clock1[0]>'1' || clock1[0]=='0') clock1[0]='1';
        }
    }else{
        if (clock1[0]>'2') {
            clock1[0]='0';
        }else if (clock1[0]=='2'){
            if(clock1[1]>'3') clock1[1]='3';
        }
    }
    if (clock1[3]>'5') clock1[3]='0';
    cout << clock1 << endl;
    return 0;
}
