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


int gcd(int a, int b){
	while(b > 0){
		int c = b;
		b = a%b;
		a = c;
	}
	return a;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	int a[n];
	bool freq[101], v[n][101];
	memset(a, 0, sizeof(a));
	memset(freq, 0, sizeof(freq));
	memset(v, 0, sizeof(v));
	for(int i = 0; i < n; i++) cin >> a[i];
	int cnt = 1;
	freq[a[0]] = 1; v[0][a[0]] = 1;
	for(int i = 1; i < n; i++){
		if(!freq[a[i]]) cnt++;
		freq[a[i]] = 1;
		v[i][a[i]] = 1;
		for(int j = 1; j <= 100; j++){
			if(v[i-1][j]){
				int g = gcd(j,a[i]);
				if(!freq[g]) cnt++;
				freq[g] = 1;
				v[i][g] = 1;
			}
		}
	}
	cout << cnt << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

