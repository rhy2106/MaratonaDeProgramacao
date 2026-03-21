#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
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

const int logn = 17, logq = 18, high = 6;
const int maxn = (1<<logn), maxq = (1<<logq);

int a[maxn], x[maxq], y[maxq], vivo[maxn], ans[maxq+1];
ll f[maxn];
vector<int> tempo[maxq];

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n, q; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> x[i] >> y[i];
		x[i] &= (maxn-1);
	}
	memset(vivo, -1, sizeof(vivo));
	for(int i = logq-1; i >= 0; i--){
		memset(f, 0, sizeof(f));
		for(int j = 0; j < n; j++) tempo[vivo[j] + (1<<i)].pb(j);
		for(int j = 0; j < q; j++){
			int hi = x[j] >> (logn - high);
			for(int mask = hi; ; mask = (mask-1) & hi){
				f[x[j] ^ ((hi ^ mask) << (logn - high))] += y[j];
				if(mask == 0) break;
			}
			for(int k : tempo[j]){
				int lo = ~k & ((1<<(logn-high))-1);
				ll sum = 0;
				for(int mask = lo; ; mask = (mask-1) & lo){
					sum += f[k ^ mask];
					if(mask == 0) break;
				}
				
				if(a[k] > sum){
					vivo[k] = j;
					if(q == maxq && j == q-2 && a[k] > sum + ((x[q-1] & k) == k ? y[q-1] : 0))
						vivo[k] = q-1;
				}
			}
			tempo[j].clear();
		}
	}
	ans[0] = n;
	for(int i = 0; i < n; i++) ans[vivo[i]+1]--;
	partial_sum(ans, ans+q, ans);
	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}


