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
		int a[n+1]; a[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			a[i] += a[i-1];
		}
		int l = 0, r = n;
		while(r - l > 1){
			int mid = (l + r) / 2;
			cout << "? " << mid - l << " ";
			for(int i = l+1; i <= mid; i++)
				cout << i << " ";
			cout.flush();
			int x; cin >> x;
			if(x > a[mid] - a[l]) r = mid;
			else l = mid;
		}
		cout << "! ";
		cout << r << endl;
		cout.flush();
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

