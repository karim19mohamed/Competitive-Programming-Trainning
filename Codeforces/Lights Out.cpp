#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int c[3][3];

int main()
{
    for (int i=0;i<3;++i) for (int j=0;j<3;++j) scanf("%i",&c[i][j]);
    for (int i=0;i<3;++i){
        for (int j=0;j<3;++j){
            int x=c[i][j];
            if (i+1<3){ x+=c[i+1][j]; }
            if(i-1>=0){ x+=c[i-1][j]; }
            if (j+1<3){ x+=c[i][j+1]; }
            if (j-1>=0){ x+=c[i][j-1]; }
            if (x%2){ printf("0"); }else{ printf("1");}
        }
        printf("\n");
    }
    return 0;
}

