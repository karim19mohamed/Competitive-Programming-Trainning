#include <iostream>
#include <string>

using namespace std;
string x,y,x_new,y_new;
string z_1,z_2;
bool z=0;

int main()
{
    cin >> x;
    cin >> y;
    for (std::string::reverse_iterator x_new=x.rbegin(); x_new!=x.rend(); ++x_new) z_1+=*x_new;
    for (std::string::reverse_iterator y_new=y.rbegin(); y_new!=y.rend(); ++y_new) z_2+=*y_new;
    int k=x.size();
    int q=y.size();
    int ans=1;
    int rem=0;

    if ((k>q && z_1[q]=='0' && z_1[q-1]+z_2[q-1]-'0'-'0'+(z_1[q-2]+z_2[q-2]-'0'-'0')/10>9) || (z_1[q-1]+z_2[q-1]-'0'-'0'+(z_1[q-2]+z_2[q-2]-'0'-'0')/10==10)){
        ans=0;
    }else if ((q>k && z_2[k]=='0' && z_1[k-1]+z_2[k-1]-'0'-'0'+(z_1[q-2]+z_2[q-2]-'0'-'0')/10>9) || (z_1[k-1]+z_2[k-1]-'0'-'0'+(z_1[q-2]+z_2[q-2]-'0'-'0')/10==10)){
        ans=0;
    }else if (z_1[0]+z_2[0]-'0'-'0'==10){
        ans=0;
    }else{

        for (int i=0;i<min(k,q)-1;i++){
            if ((z_1[0]=='0' && z_2[0]!='0')||(z_2[0]=='0' && z_1[0]!='0')){
                ans=0;
                break;
            }
            if (i>0) rem=(z_1[i-1]+z_2[i-1]-'0'-'0')/10;
            //cout << rem << endl;
            if (z_1[i]+z_2[i]-'0'-'0'+rem==10){
                ans=0;
                break;
            }
            rem=0;
            if (z_1[i+1]=='0' && z_2[i+1]=='0'){
                if (i>1) rem=(z_1[i-2]+z_2[i-2]-'0'-'0')/10;
                if (z_1[i]+z_2[i]-'0'-'0'+rem>9){
                    ans=0;
                    break;
                }
                rem=0;
            }else if (z_1[i+1]=='0' || z_2[i+1]=='0'){
                ans=0;
                break;
            }
        }
    }
    if (ans==1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
