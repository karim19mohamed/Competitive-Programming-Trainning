#include <iostream>
#include <string>

using namespace std;
int t;
int m;
int n;
char arr[10][10];
int s,e;
char nam[7]={'I','E','H','O','V','A','#'};
void path(int i,int j,int indx);

int main()
{
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> m >> n;
        for (int j=0;j<m;j++){
            for (int k=0;k<n;k++){
                cin >> arr[j][k];
                //cout << arr[i][j];
                if (arr[j][k]=='@') s=k;
                if (arr[j][k]=='#') e=k;
            }
        }
        //cout << s << "  " << e << endl;
        path(m-1,s,0);
        cout << endl;
    }
    return 0;
}

void path(int i,int j,int indx){
    if (indx==7) return;

    //cout <<arr[i-1][j]<<"  "<<nam[indx] <<endl;
    if (arr[i-1][j]==nam[indx]){
        cout << "forth";
        if (indx!=6) cout << " ";
        path(i-1,j,indx+1);
    }else if (arr[i][j+1]==nam[indx]){
        cout << "right";
        if (indx!=6) cout << " ";
        path(i,j+1,indx+1);
    }else if (arr[i][j-1]==nam[indx]){
        cout << "left";
        if (indx!=6) cout << " ";
        path(i,j-1,indx+1);
    }

}

