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
		int n, k; cin >> n >> k;
		int a[n+1]; a[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			a[i] = a[i] + a[i-1];
		}
		if( a[n] < k ){
			cout << -1 << endl;
			continue;
		}
		int ans = INF;
		for(int i = 1; i <= n; i++){
			int l = i, r = n, pos = -1;
			while(l <= r){
				int mid = (l + r) / 2;

				if(a[mid] - a[i-1] <= k){
					pos = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			if( pos == -1 || a[pos] - a[i-1] != k) continue;
			ans = min(ans, n-(pos-i+1));
		}
		cout << ans << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

