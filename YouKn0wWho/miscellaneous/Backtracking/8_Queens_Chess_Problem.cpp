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

vector<vector<iPair>> ans;

bool ver(iPair pos, vector<iPair> rainhas){
	for(auto [x,y] : rainhas){
		if( pos.f == x ) return false;
		if( pos.s == y ) return false;
		if( abs( x - pos.f ) == abs( y - pos.s ) ) return false;
	}
	return true;
}

void f(vector<iPair> rainhas, int col){
	if(col == rainhas[0].f) col++;
	if( rainhas.size() == 8 ){
		sort(rainhas.begin(),rainhas.end());
		ans.pb(rainhas);
		return;
	}
	int i = 0; // POSICAO = ( COLUNA, LINHA )
	while( i < 8 ){
		if(ver({col,i},rainhas)){
			rainhas.pb({col,i});
			f(rainhas,col+1);
			rainhas.pop_back();
		}
		i++;
	}
}

void solve(){
	cout << "SOLN       COLUMN" << endl;
	cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
	ans.clear();
	int x, y; cin >> x >> y;
	x--; y--;
	vector<iPair> rainhas(1,{y,x});

	int col = ( y == 0 ? 1 : 0 );
	f(rainhas, col);

	for(int i = 0; i < ans.size(); i++){
		cout << setw(2) << i + 1 << "      ";
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j].s + 1 << ( j != ans[i].size()-1 ? " " : "" );
		cout << endl;
	}
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	cin >> tt;
	for(int i = 0; i < tt; i++){
		solve();
		if( i != tt-1 ) cout << endl;
	}
    return 0;
}

