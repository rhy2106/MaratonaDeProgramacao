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

int matriz[8][8];
int ans = 0;

bool ver(iPair pos, vector<iPair> rainhas){
	for(auto [x,y] : rainhas){
		if( pos.f == x ) return false;
		if( pos.s == y ) return false;
		if( abs(pos.f - x) == abs(pos.s - y) ) return false;
	}
	return true;
}

void f(vector<iPair> rainhas, int col){
	if( rainhas.size() == 8 ){
		int total = 0;
		for(auto [i, j] : rainhas)
			total += matriz[i][j];
		ans = max(ans, total);
		return;
	}	
	for(int i = 0; i < 8; i++){
		if(ver({i,col},rainhas)){
			vector<iPair> nrainhas = rainhas;
			nrainhas.pb({i,col});
			f(nrainhas, col+1);
		}
	}
}

void solve(){
	ans = 0;
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			cin >> matriz[i][j];
	vector<iPair> rainhas;
	f(rainhas, 0);
	cout << setw(5) << ans << endl;
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	cin >> tt;
	while(tt--) solve();
    return 0;
}

