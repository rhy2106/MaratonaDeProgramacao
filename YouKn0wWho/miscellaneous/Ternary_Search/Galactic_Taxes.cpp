#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define ld long double
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<double,int>
#define iTuple tuple<int,double,double>
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

vector<vector<iTuple>> grafo;
int n, m;

ld f(double t){
	vector<double> visitados(n,1e10);
	priority_queue<iPair,vector<iPair>, greater<iPair>> fila;
	fila.push({0,0});
	visitados[0] = 0;
	while(!fila.empty()){
		iPair pacote = fila.top();
		fila.pop();
		for(auto [filho, a ,b] : grafo[pacote.s]){
			double cost = a * t + b + visitados[pacote.s];
			if(cost < visitados[filho]){
				visitados[filho] = cost;
				fila.push({cost,filho});
			}
		}
	}
	return visitados[n-1];
}

void solve(){
	while( cin >> n >> m ){
		grafo.assign(n,vector<iTuple>());

		for(int i = 0; i < m; i++){
			int x, y;
			double a, b;
			cin >> x >> y >> a >> b;
			x--; y--;
			grafo[x].emplace_back(y,a,b);
			grafo[y].emplace_back(x,a,b);
		}

		double l = 0, r = 24 * 60;
		for(int i = 0; i < 80; i++){
			double m1 = l + (r-l)/3.0;
			double m2 = r - (r-l)/3.0;
			if( f(m1) < f(m2) ) l = m1;
			else r = m2;
		}

		cout << fixed << setprecision(5);
		cout << f(l) << endl;
	}
	
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	while(tt--) solve();
    return 0;
}

