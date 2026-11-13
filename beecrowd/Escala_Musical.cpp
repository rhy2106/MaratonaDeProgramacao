#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

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

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

void solve(){
	string a[13];

	a[0] = "do";
	a[1] = "do#";
	a[2] = "re";
	a[3] = "re#";
	a[4] = "mi";
	a[5] = "fa";
	a[6] = "fa#";
	a[7] = "sol";
	a[8] = "sol#";
	a[9] = "la";
	a[10] = "la#";
	a[11] = "si";

	set<int> escala_maior;
	escala_maior.insert( 0 );
	escala_maior.insert( 2 );
	escala_maior.insert( 4 );
	escala_maior.insert( 5 );
	escala_maior.insert( 7 );
	escala_maior.insert( 9 );
	escala_maior.insert( 11 );

	int n; cin >> n;
	set<int> notas;
	for( int i = 0; i < n; i++){
		int x; cin >> x; x--; x %= 12;
		notas.insert(x);
		// cout << a[x] << " ";
	}
	// cout << endl;

	int tom = -1;
	for(int i = 0; i < 12; i++){
		// cout << "Escala: " << a[i] << endl;
		for(int j : notas){
			int nota_escala = (j - i + 12) % 12;
			// cout << a[nota_escala] << " ";
			if( !escala_maior.count( nota_escala ) ) break;
			if( j == *prev(notas.end()) ) tom = i;
		}
		// cout << endl;
		if( tom != -1 ) break;
	}
	cout << (tom != -1 ? a[tom] : "desafinado") << endl;
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

