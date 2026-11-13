#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define ld long double
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;
const ll A = 911382323;
const ll B = 972663749;
const ld eps = 1e-9;
const ld PI = 3.14159265359;

using namespace std;

vector<string> ans;
vector<string> a;

void f(int pos, string word, string res){
	if(pos == word.size()){
		ans.pb(res);
		return;
	}
	if( word[pos] == '#' )
		for(string s : a)
			f(pos+1, word, res + s);
	else if( '0' <= word[pos] && word[pos] <= '9' )
		for(int i = (int)word[pos]; i <= (int)'9'; i++)
			f(pos+1, word, res + (char)i);
	else if( 'A' <= word[pos] && word[pos] <= 'Z' )
		for(int i = (int)word[pos]; i <= (int)'Z'; i++)
			f(pos+1, word, res+(char)i);
	else if( 'a' <= word[pos] && word[pos] <= 'z' )
		for(int i = (int)word[pos]; i <= (int)'z'; i++)
			f(pos+1, word, res+(char)i);
}

void solve(){
	int n; 
	while( cin >> n ){
		cout << "--" << endl;
		ans.clear();
		a.assign(n,"");
		for(int i = 0; i < n; i++) cin >> a[i];
		int m; cin >> m;
		vector<string> b(m);
		for(int i = 0; i < m; i++) cin >> b[i];
		for(int i = 0; i < m; i++) f(0,b[i],"");
		for(string i : ans)
			cout << i << endl;
	}
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
    return 0;
}

