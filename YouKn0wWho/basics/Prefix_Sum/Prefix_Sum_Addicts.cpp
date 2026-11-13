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
		vector<ll> s(n + 1);
		vector<ll> a(n + 1);
		for(int i = n - k + 1; i <= n; i++) cin >> s[i];
		if( k == 1 ){
			cout << "YES" << endl;
			continue;
		}
		for(int i = n - k + 2 ; i <= n; i++) a[i] = s[i] - s[i-1];
		if(!is_sorted(a.begin() + n - k + 2, a.end())){
			cout << "NO" << endl;
			continue;
		}
		if(s[n - k + 1] > a[n - k + 2] * (n - k + 1)){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

