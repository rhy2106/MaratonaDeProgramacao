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
	while( b > 0 ){
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
	int tt; cin >> tt;
	while(tt--){
		int n, x, y; cin >> n >> x >> y;
		vector<int> a(n);
		int g = gcd(x,y);
		for(int &i : a) cin >> i, i %= g;
		int menor = INF;
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()),a.end());
		n = a.size();
		for(int i = 0; i < n; i++)
			menor = min(menor, abs(a[i] - ((i ? g : 0) + a[(n-1 + i)%n])));
		cout << menor << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

