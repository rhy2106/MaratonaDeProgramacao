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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int &i : a) cin >> i;
	map<int,int> m;
	set<int> mex;

	for(int i = 0; i <= k; i++)
		mex.insert(i);
	for(int i = 0; i < k; i++){
		mex.erase(a[i]);
		m[a[i]]++;
	}

	cout << *mex.begin() << " ";

	for(int i = k; i < n; i++){
		m[a[i-k]]--;
		if(m[a[i-k]] == 0){
			mex.insert(a[i-k]);
			m.erase(a[i-k]);
		}
		m[a[i]]++;
		mex.erase(a[i]);
		cout << *mex.begin() << " ";
	}
	cout << endl;

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

