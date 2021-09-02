#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define MP make_pair
#define PB push_back
#define all(x) x.begin(),x.end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define repinv(i,n) for(ll i=n-1;i>-1;i--)
#define MOD 998244353
#define endl '\n'
typedef long long ll;
vector<string> v;
int mini;
int nb;
inline bool is_vowel(char c){
    return (c=='O'||c=='I'||c=='E'||c=='A'||c=='U');
}
void generate_strings(int n){
    string ch;
    for(char i='A';i<='Z';i++){
        ch="";
        for(int j=0;j<n;j++)
            ch+=i;
        v.PB(ch);


    }
}

int main(){
    freopen ("consistency_chapter_1_input.txt","r",stdin);
    freopen ("consistency_chapter_1_output.txt","w",stdout);


    int tc;
    cin>>tc;
    string s;
    for(int k=1;k<=tc;k++){
        cin>>s;
        v.clear();
        generate_strings(s.size());
        mini=INT_MAX;

        for(int i=0;i<v.size();i++){
            nb=0;
            for(int j=0;j<s.size();j++)
                if(v[i][j]!=s[j]&&is_vowel(v[i][j])&&is_vowel(s[j]))
                    nb+=2;
                else if(v[i][j]!=s[j]&&!is_vowel(v[i][j])&&!is_vowel(s[j]))
                    nb+=2;
                else if(v[i][j]!=s[j])
                    nb++;
            mini=min(mini,nb);


        }
        cout<<"Case #"<<k<<":"<<" ";
        cout<<mini<<endl;




    }




}
