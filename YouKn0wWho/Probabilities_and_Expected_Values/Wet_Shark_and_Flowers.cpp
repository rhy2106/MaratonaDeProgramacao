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

int f(int l, int r, int p){
	return r/p - (l-1)/p;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n, p; cin >> n >> p;
	vector<iPair> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].f >> a[i].s;
	ld ans = 0;
	for(int i = 0; i < n; i++){
		int j = (i+1)%n;
		int pi = f(a[i].f,a[i].s,p);
		int pj = f(a[j].f,a[j].s,p);
		ld x = (a[i].s - a[i].f + 1.0 - pi) / (a[i].s - a[i].f + 1.0);
		ld y = (a[j].s - a[j].f + 1.0 - pj) / (a[j].s - a[j].f + 1.0);
		ans += 1.0 - x*y;
	}
	cout << fixed << setprecision(9) << ans*2000.0 << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

