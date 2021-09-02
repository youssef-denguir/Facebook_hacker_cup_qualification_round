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
vector< char > exist;
ll mini;
ll nb;
int k;
unordered_map<char,unordered_map<char,int>> dist;
bool check,check_ans;
unordered_map<char,int> level;
unordered_map<char, vector<char> > g;
unordered_map<char,bool> visited;

void bfs(char u,char u1) {
	queue<char> s;
	visited[u] = 1;
	s.push(u);
    dist[u1][u]=0;
    level[u]=0;
	while (!s.empty()) {
		char c = s.front();
		s.pop();

		for (auto i = g[c].begin(); i != g[c].end(); i++)
			if (!visited[*i]) {
				visited[*i] = 1;
				level[*i]=level[c]+1;
				dist[u1][*i]=level[c]+1;
				s.push(*i);
			}
	}
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
    freopen ("consistency_chapter_2_input.txt","r",stdin);
    freopen ("consistency_chapter_2_output.txt","w",stdout);

    FAST;
    int tc;
    cin>>tc;
    string s;
    string str;
    for(int test=1;test<=tc;test++){
        cin>>s;
        v.clear();
        g.clear();
        exist.clear();
        generate_strings(s.size());
        dist.clear();
        mini=1e18;
        cin>>k;

        for(int i=0;i<k;i++){
            cin>>str;
            g[str[0]].PB(str[1]);
            exist.PB(str[0]);
        }
        for(int i=0;i<exist.size();i++){
                visited.clear();
                level.clear();
                bfs(exist[i],exist[i]);
        }
        check_ans=0;
        check=1;
        for(int i=0;i<v.size();i++){
            nb=0;
            check=1;
            for(int j=0;j<s.size();j++){
                if(v[i][j]!=s[j]&&dist[s[j]][v[i][j]])
                    nb+=dist[s[j]][v[i][j]];
                else if(v[i][j]!=s[j]&&!dist[s[j]][v[i][j]]){
                    check=0;
                    break;
                }
            }
            if(check){
                check_ans=1;
                mini=min(mini,nb);
            }



        }


        cout<<"Case #"<<test<<":"<<" ";

        if(check_ans)
            cout<<mini<<endl;
        else
            cout<<-1<<endl;




    }




}
