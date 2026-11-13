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

using namespace std;

void solve(){
	int n; cin >> n;
	vector<iPair> a(n);
	for(int i = 0 ; i < n; i++)
		cin >> a[i].f >> a[i].s;

	sort(a.begin(), a.end(), [](const iPair a, const iPair b){
		if( a.s == b.s )
			return a.f < b.f;
		return a.s < b.s;
	});
	
	int cnt = 0;
	int t = 0;
	for(iPair i : a){
		if( i.f < t ) continue;
		cnt++;
		t = i.s;
	}
	cout << cnt << endl;
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

