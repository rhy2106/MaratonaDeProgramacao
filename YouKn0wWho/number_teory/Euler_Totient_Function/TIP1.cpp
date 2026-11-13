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

const int MAXN = 1e7 + 5;
int phi[MAXN], ans[MAXN];

int check(int x, int y){
	int digitos[10] = {0};
	memset(digitos,0,sizeof(digitos));

	while( x > 0 ){
		digitos[x % 10]++;
		x /= 10;
	}

	while( y > 0 ){
		digitos[y % 10]--;
		y /= 10;
	}

	for(int i = 0; i < 10; i++)
		if(digitos[i] != 0)
			return 0;
	return 1;
}

void build(){

	for(int i = 1; i < MAXN; i++) phi[i] = i;
	for(int i = 2; i < MAXN; i++){
		if(phi[i] != i) continue;
		for(int j = i; j < MAXN; j += i)
			phi[j] -= phi[j]/i;
	}

	ans[0] = ans[1] = -1;
	int cur_phi = 0, cur = -1;

	for(int i = 2; i < MAXN; i++){
		if( check(phi[i],i) ){
			if( cur == -1 ){
				cur = i;
				cur_phi = phi[i];
			} else{
				if( (ll) i * cur_phi < (ll) cur*phi[i] ){
					cur = i;
					cur_phi = phi[i]; 
				} else if( (ll) i * cur_phi == (ll) cur*phi[i] && i > cur){
					cur = i;
					cur_phi = phi[i]; 
				}
			}
		}
		ans[i] = cur;
	}
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	build();
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		cout << (ans[n-1] == -1 ? "No solution." : to_string(ans[n-1])) << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

