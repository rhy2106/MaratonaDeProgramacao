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
		int n; cin >> n;
		int x[n], t[n];
		for(int &i : x) cin >> i, i*=2;
		for(int &i : t) cin >> i, i*=2;

		int l = -1, r = INF;
		while(r - l > 1){
			int mid = (l + r) / 2.0;
			int lx = 0, rx = INF;
			for(int i = 0; i < n; i++){
				if(t[i] > mid){
					lx = INF;
					rx = 0;
					break;
				} else{
					lx = max( lx, x[i] - (mid - t[i]) );
					rx = min( rx, x[i] + (mid - t[i]) );
				}
			}
			(lx <= rx ? r : l) = mid;
		}

		int lx = 0, rx = INF;
		for(int i = 0; i < n; i++){
			lx = max( lx, x[i] - (r - t[i]) );
			rx = min( rx, x[i] + (r - t[i]) );
		}
		cout << rx / 2;
		if( rx % 2 != 0 ) cout << ".5" << endl;
		else cout << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

