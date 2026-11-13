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

vector<int> primos;
vector<vector<int>> ans;
int n;

void prebuild(){
	vector<int> p(40,0);
	for(int i = 2; i < 40; i++){
		if( p[i] ) continue;
		primos.pb(i);
		for(int j = i; j < 40; j+=i)
			p[j]++;
	}
}

bool dentro( vector<int> roda, int x){
	for(int i = 0; i < roda.size(); i++)
		if(roda[i] == x) return true;
	return false;
}

void f(vector<int> roda){
	if(roda.size() == n){
		if( dentro( primos, roda[n-1]+ 1 ) )
			ans.pb(roda);
		return;
	}

	for(int j = 0; j < primos.size(); j++){
		int x = primos[j] - roda.back();
		if( x <= 0 ) continue;
		if( x > n ) break;
		if( dentro(roda,x) ) continue;
		vector<int> nroda = roda;
		nroda.pb(x);
		f(nroda);
	}
}

void solve(){
	int cont = 0;
	while(cin >> n){
		cont++;
		if(cont > 1) cout << endl;
		cout << "Case " << cont << ":" << endl;
		ans.clear();

		vector<int> roda;
		roda.pb(1);
		f(roda);

		for(int i = 0; i < ans.size(); i++){
			for(int j = 0; j < ans[i].size(); j++){
				cout << ans[i][j] << ( j == ans[i].size() - 1 ? "" : " " );
			}
			cout << endl;
		}
	}
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	prebuild();
	int tt = 1;
	while(tt--) solve();
    return 0;
}

