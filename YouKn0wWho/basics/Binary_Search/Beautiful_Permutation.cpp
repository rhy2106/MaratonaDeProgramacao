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
		int k, x;
		cout << 1 << " " << 1 << " " << n << endl;
		cout.flush();
		cin >> k;
		cout << 2 << " " << 1 << " " << n << endl;
		cout.flush();
		cin >> x;
		int h = x - k;
		int l = 1, r = n;
		while(r - l > 1){
			int mid = ( l + r ) / 2;
			cout << 1 << " " << l << " " << mid << endl;
			cout.flush();
			cin >> k;
			cout << 2 << " " << l << " " << mid << endl;
			cout.flush();
			cin >> x;
			if( x - k > 0 ) r = mid;
			else l = mid;
		}
		if(l == 1){
			cout << 1 << " " << l << " " << 1 << endl;
			cout.flush();
			cin >> k;
			cout << 2 << " " << l << " " << 1 << endl;
			cout.flush();
			cin >> x;
			if( x - k > 0 ) l--;
		}
		cout << "! " << l + 1 << " " << l + h << endl;
		cout.flush();
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

