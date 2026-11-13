#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
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
const ld eps = 1e-9;
const ld PI = 3.14159265359;

using namespace std;

int n;
char matriz[4][4];
int ans = 0;

bool ver(iPair pos, vector<iPair> torres){
	if(matriz[pos.f][pos.s] == 'X') return false;
	for(auto [x,y] : torres){
		if( pos.f == x && pos.s == y) return false;
		if( pos.f == x ){
			bool parede = false;;
			for(int i = min(pos.s,y); i <= max(pos.s, y); i++)
				if( matriz[x][i] == 'X' ) parede = true;
			if(!parede) return false;
		}
		if( pos.s == y){
			bool parede = false;
			for(int i = min(pos.f,x); i <= max(pos.f, x); i++)
				if( matriz[i][y] == 'X' ) parede = true;
			if(!parede) return false;
		}
	}
	return true;
}

void f(vector<iPair> torres){
	if(torres.size() > ans) ans = torres.size();
	for(int k = 0; k < n*n; k++){
		int i = k / n, j = k % n;
		if( !ver({i,j},torres) ) continue;
		vector<iPair> ntorres = torres;
		ntorres.pb({i,j});
		f(ntorres);
	}
}

void solve(){
	ans = 0;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> matriz[i][j];

	vector<iPair> torres;
	f(torres);
	cout << ans << endl;

}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	while(cin >> n, n != 0) solve();
    return 0;
}

