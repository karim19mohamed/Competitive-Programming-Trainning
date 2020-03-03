#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;
int n,p,t;
long long arr[59][59],arrano[59][59],arrao[59][59],res,ans;
double grad[59],a,b,up,down;
ofstream answer;

int main()
{
    answer.open("answer.txt");
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        memset(arr,0,sizeof(arr));
        memset(arrano,0,sizeof(arrano));
        memset(arrao,0,sizeof(arrao));
        memset(grad,0,sizeof(grad));
        scanf("%d%d",&n,&p);
        for (int j=0;j<n;j++){
            scanf("%lf",&grad[j]);
        }
        for (int j=0;j<n;j++){
            for (int k=0;k<p;k++){
                scanf("%lf",&a);
                b=a/grad[j];
                down=floor(b);up=ceil(b);
                if (a>=down*grad[j]*0.9 && a<=down*grad[j]*1.1) arr[j][k]+=(int)(down);
                if (a>=up*grad[j]*0.9 && a<=up*grad[j]*1.1 && up!=down) arr[j][k]+=(int)(up);
                if (up==down){
                    up++;
                    if(a>=up*grad[j]*0.9 && a<=up*grad[j]*1.1) arrano[j][k]+=(int)(up);
                    up--;up--;
                    if(a>=up*grad[j]*0.9 && a<=up*grad[j]*1.1) arrao[j][k]+=(int)(up);
                }
            }
        }
        for (int j=0;j<n;j++){
            for (int k=0;k<p;k++){
                bool jj=1;
                for (int w=j+1;w<n;w++){
                    for (int ww=0;ww<p;ww++){
                        if (arr[j][k]!=0&&(arr[j][k]==arr[w][ww] || arr[j][k]==arrano[w][ww] || arr[j][k]==arrao[w][ww])){
                            ans++;arr[j][k]=arrano[j][k]=arrao[j][k]=arr[w][ww]=arrano[w][ww]=arrao[w][ww]=0;
                            jj=0;break;
                        }else if (arrano[j][k]!=0 && (arrano[j][k]==arr[w][ww] || arrano[j][k]==arrano[w][ww] || arrano[j][k]==arrao[w][ww])){
                            ans++;arr[j][k]=arrano[j][k]=arrao[j][k]=arr[w][ww]=arrano[w][ww]=arrao[w][ww]=0;
                            jj=0;break;
                        }else if (arrao[j][k]!=0 && (arrao[j][k]==arr[w][ww] || arrao[j][k]==arrano[w][ww] || arrao[j][k]==arrao[w][ww])){
                            ans++;arr[j][k]=arrano[j][k]=arrao[j][k]=arr[w][ww]=arrano[w][ww]=arrao[w][ww]=0;
                            jj=0;break;
                        }
                    }
                    if (jj==0) break;
                }
                if (n==1 && arr[j][k]!=0) ans++;
                arr[j][k]=0;
            }
        }
        answer<<"Case #"<<i+1<<": "<< ans <<endl;
        ans=0;
    }
    return 0;
}
