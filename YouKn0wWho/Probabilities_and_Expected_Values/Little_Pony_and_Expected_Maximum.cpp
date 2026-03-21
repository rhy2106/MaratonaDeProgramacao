#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

using namespace std;
ld fastexp(ld b, ll e){
	ld r = 1;
	while(e>0){
		if(e&1) r *= b;
		b *= b;
		e >>= 1;
	}
	return r;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ld n, m; cin >> n >> m;
	ld ans = 0;
	for(int i = 1; i <= n; i++){
		ans += (ld)i*(fastexp((ld)i/n,m) - fastexp((ld)(i-1)/n,m));
	}

	cout << fixed << setprecision(9) << ans << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

