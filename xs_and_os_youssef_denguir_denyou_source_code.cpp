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

int mini;
int ans;
int column_X[55],column_O[55],row_X[55],row_O[55];
char t[55][55];

int main(){
    freopen ("xs_and_os_input.txt","r",stdin);
    freopen ("xs_and_os_output.txt","w",stdout);
    int tc;
    cin>>tc;
    int n;
    string s;
    for(int testcase=1;testcase<=tc;testcase++){
        cin>>n;
        memset(column_X,0,sizeof(column_X));
        memset(column_O,0,sizeof(column_O));
        memset(row_X,0,sizeof(row_X));
        memset(row_O,0,sizeof(row_O));
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<n;j++){
                t[i][j]=s[j];
                if(t[i][j]=='X')
                    row_X[i]++;
                else if(t[i][j]=='O')
                    row_O[i]++;
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(t[i][j]=='X')
                    column_X[j]++;
                else if(t[i][j]=='O')
                    column_O[j]++;
            }
        }
        mini=INT_MAX;
        ans=0;

        for(int i=0;i<n;i++){
            if(column_O[i]==0)
                mini=min(n-column_X[i],mini);
            if(row_O[i]==0)
                mini=min(n-row_X[i],mini);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(((n-column_X[j])==1)&&((n-row_X[i])==1)&&row_O[i]==0&&column_O[j]==0&&t[i][j]=='.'){

                    ans--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(column_O[i]==0){
                if(n-column_X[i]==mini)
                    ans++;
            }
            if(row_O[i]==0){
                   if(n-row_X[i]==mini)
                        ans++;
            }
        }
        cout<<"Case #"<<testcase<<":"<<" ";

        if(mini==INT_MAX)
            cout<<"Impossible"<<endl;
        else
            cout<<mini<<" "<<ans<<endl;


    }





}
