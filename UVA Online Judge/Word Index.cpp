#include <iostream>
#include <string>
#include <queue>

using namespace std;
string s;
bool ind;
long long ans=0;
string alp="abcdefghijklmnopqrstuvwxyz";
queue <string> arr;
bool flag[30];
void alphapet(int indx,string word,int num);
long long k;

int main()
{
    while (cin >> s){
        int q=s.size();
        for (int i=1;i<q;i++) {
            if (s[i]<=s[i-1]){
                cout << "0" << endl;
                q=-1;
                break;
            }
        }
        if (q==-1) continue;
        for (int i=0;i<26;i++) {
            string t="a";
            t[0]+=i;
            arr.push(t);
        }

        for (int j=1;j<q;j++){
            k=arr.size();
            for (int i=0;i<k;i++){
                if (arr.front().size()==q){
                    for (int z=0;z<q;z++){
                        if (arr.front()[z]==s[z]){
                            ind=1;
                        }else{
                            ind=0;
                            break;
                        }
                    }
                    if (ind==1) break;
                }
                if (ind==1) break;
                ans++;
                alphapet(1,arr.front(),j+1);
                arr.pop();
            }
            if (ind==1) break;
        }
        if (ind==1){
            cout << ans << endl;
        }else{
            k=arr.size();
            for (int i=0;i<k;i++) {
                ans++;
                for (int z=0;z<q;z++){
                    if (arr.front()[z]==s[z]){
                        ind=1;
                    }else{
                        ind=0;
                        break;
                    }
                }
                if (ind==1) break;
                arr.pop();
            }
        }
        cout << ans << endl;
        ans=0;
        ind=0;
        k=arr.size();
        for (int i=0;i<k;i++) arr.pop();
    }
    return 0;
}
void alphapet(int indx,string word,int num){
    if (indx==0) {
        //cout << word << endl;
        arr.push(word);
        //ans_t++;
        return;
    }
    for (int i=0;i<26;i++){
        if (flag[i]==0){
            flag[i]=1;
            if (alp[i]>word[num-2]){
                alphapet(indx-1,word+alp[i],num);
            }
            flag[i]=0;
        }
    }
}

