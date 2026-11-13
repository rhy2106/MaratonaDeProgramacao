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

using namespace std;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(a > b) swap(a,b);
		if(a > c) swap(a,c);
		if(a > d) swap(a,d);
		if(b > c) swap(b,c);
		if(b > d) swap(b,d);
		if(c > d) swap(c,d);
		
		int erro = 0;
		if( a >= b + c + d ) erro = 1;
		if( b >= a + c + d ) erro = 1;
		if( c >= b + a + d ) erro = 1;
		if( d >= b + c + a ) erro = 1;

		if( a == b && b == c && c == d) cout << "square" << endl;
		else if(a == b && c == d) cout << "rectangle" << endl;
		else if( !erro ) cout << "quadrangle" << endl;
		else cout << "banana" << endl;
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

