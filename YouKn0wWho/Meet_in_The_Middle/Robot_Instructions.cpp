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

vector<iPair> a;

iPair add(iPair a, iPair b){
	return {a.f+b.f,a.s+b.s};
}

iPair sub(iPair a, iPair b){
	return {a.f-b.f,a.s-b.s};
}

void get_sum(vector<vector<iPair>> &m, int l, int r){
	int tam = r - l + 1;
	for(int mask = 0; mask < (1<<tam); mask++){
		iPair total = {0,0};
		int cnt = 0;
		for(int i = 0; i < tam; i++){
			if(mask & (1<<i)){
				total = add(total,a[l+i]);
				cnt++;
			}
		}
		m[cnt].pb(total);
	}
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	iPair fim; cin >> fim.f >> fim.s;
	a.assign(n,{0,0});
	for(int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
	vector<vector<iPair>> l(n+1);
	vector<vector<iPair>> r(n+1);
	get_sum(l, 0, n/2-1);
	get_sum(r, n/2, n-1);
	for(int i = 0; i < n; i++){
		sort(l[i].begin(),l[i].end());
		sort(r[i].begin(),r[i].end());
	}

	for(int i = 1; i <= n; i++){
		ll ans = 0;
		for(int j = 0; j <= i; j++){
			for(iPair k : l[j]){
				auto lo = lower_bound(r[i-j].begin(),r[i-j].end(),sub(fim,k));
				auto hi = upper_bound(r[i-j].begin(),r[i-j].end(),sub(fim,k));
				ans += hi - lo;
			}
		}
		cout << ans << endl;
	}

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

