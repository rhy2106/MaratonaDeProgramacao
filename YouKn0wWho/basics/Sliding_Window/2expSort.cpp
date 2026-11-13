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

void solve(){
	int n, k; cin >> n >> k; k++;
	int v[n];
	for(int &i : v) cin >> i;
	int l = 0, r = 1;
	int ans = 0;
	while( r < n ){
		while( r < n && r - l + 1 < k ){
			if(v[r-1] >= v[r] * 2) l = r;
			r++;
		}
		if( r >= n ) break;
		if(r - l + 1 == k && v[r-1] < v[r]*2)
			ans++;
		l++;
	}
	cout << ans << endl;
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

