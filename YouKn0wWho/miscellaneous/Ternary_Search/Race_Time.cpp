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

using namespace std;

double f(vector<iPair>& a, ld t){
	ld maior = 0;
	ld menor = INF;

	for(iPair carro : a){
		ld pos = carro.f * t + carro.s;
		maior = max(maior, pos);
		menor = min(menor, pos);
	}

	return maior - menor;
}

void solve(){
	int n, k; cin >> n >> k;
	vector<iPair> a(n,{0,0});
	for(int i = 0; i < n; i++)
		cin >> a[i].f >> a[i].s;

	ld l = 0, r = k;

	while(r - l > eps){
		ld m1 = l + (r-l)/3;
		ld m2 = r - (r-l)/3;
		ld f1 = f(a,m1);
		ld f2 = f(a,m2);
		if( f1 > f2 ) l = m1;
		else r = m2;
	}

	cout << fixed << setprecision(6);
	cout << f(a,l) << endl;

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

