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

int m;
vector<int> a;

void get_sum(vector<int> &s, int l, int r){
	int tam = r - l + 1;
	for(int mask = 0; mask < (1<<tam); mask++){
		int total = 0;
		for(int i = 0; i < tam; i++)
			if(mask & (1<<i)) total = (total + a[l + i]) % m;
		s.pb(total);
	}
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n >> m;
	a.assign(n,0);
	for(int &i : a) cin >> i;

	vector<int> l, r;
	get_sum(l, 0, n/2-1);
	get_sum(r, n/2, n-1);
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
	l.erase(unique(l.begin(),l.end()), l.end());
	r.erase( unique(r.begin(),r.end()), r.end());
	int ans = 0;
	for(int i : l){
		auto b = lower_bound(r.begin(),r.end(),m-i);
		if(b != r.begin()){
			b--;
			ans = max(ans,(i + *b)%m);
		}

		ans = max(ans,(i+r.back())%m);	
	}
	cout << ans << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

