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
vector< vector<int> > v;
vector<ll> s,s1;
bool visited[55];
ll c[55];
ll value;

void dfs(int node,ll sum){
    bool test=0;
    visited[node]=1;
    ll ret;
    if(node==1){
        if(!visited[value]){
            dfs(value,sum+c[value]);
            test=1;
        }
    }
    else{
    for(auto it=v[node].begin();it!=v[node].end();it++)
        if(!visited[*it]){
                test=1;
                dfs(*it,sum+c[*it]);
        }

        if(!test){
            s.PB(sum);
        }
    }

}
int main(){
    freopen ("gold_mine_chapter_1_input.txt","r",stdin);
    freopen ("gold_mine_chapter_1_output.txt","w",stdout);
    ll tc;
    cin>>tc;
    int n;
    ll  val;
    ll a,b;
    for(int testcase=1;testcase<=tc;testcase++){
        v.clear();
        v.resize(51);
        s.clear();
        s1.clear();
        memset(visited,0,sizeof(visited));
        cin>>n;
        rep(i,n){
            cin>>val;
            c[i+1]=val;
        }
        rep(i,n-1){
            cin>>a>>b;
            v[a].PB(b);
            v[b].PB(a);
        }
        if(n==1){
            cout<<"Case #"<<testcase<<":"<<" ";

            cout<<c[1]<<endl;
            continue;
        }
        for(int i=0;i<v[1].size();i++){
            value=v[1][i];
            dfs(1,c[1]);
            sort(all(s));
            s1.PB(s[s.size()-1]);
            s.clear();
        }
        sort(all(s1));
        cout<<"Case #"<<testcase<<":"<<" ";

        if(s1.size()>1)
            cout<<s1[s1.size()-1]+s1[s1.size()-2]-c[1]<<endl;
        else
            cout<<s1[s1.size()-1]<<endl;

    }




}
