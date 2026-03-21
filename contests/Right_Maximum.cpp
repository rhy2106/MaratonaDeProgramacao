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
		vector<iPair> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i].f;
			a[i].s = i;
		}
		sort(a.begin(),a.end(), [](const iPair a, const iPair b){
			if(a.f == b.f) return a.s > b.s;
			return a.f > b.f;
		});
		int idx = n;
		int cont = 0;
		for(int i = 0; i < n; i++){
			if(a[i].s > idx) continue;
			cont ++;
			idx = a[i].s;
			if(idx == 0) break;
		}
		cout << cont << endl;
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

