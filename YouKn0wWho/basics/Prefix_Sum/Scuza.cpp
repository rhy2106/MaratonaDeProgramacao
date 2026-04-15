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

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		int n, q; cin >> n >> q;
		ll a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		iPair b[q];
		for(int i = 0; i < q; i++){
			cin >> b[i].f;
			b[i].s = i;
		}
		sort(b, b+q);
		ll ans[q];
		int j = 0;
		for(int i = 0; i < q; i++){
			ans[b[i].s] = 0;
			while(j < n && b[i].f >= a[j]){
				if(j > 0) a[j] = a[j-1] + a[j];
				j++;
			}
			ans[b[i].s] = (j == 0 ? 0 : a[j-1]);
		}
		for(int i = 0; i < q; i++) cout << ans[i] << " ";
		cout << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

