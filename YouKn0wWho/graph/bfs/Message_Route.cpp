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

vector<vector<int>> grafo;
vector<int> visitados;
map<int,int> pai;

void bfs(){
	queue<int> fila;
	fila.push(0);
	visitados[0] = 1;
	while(!fila.empty()){
		int pacote = fila.front();
		fila.pop();
		for(int i : grafo[pacote]){
			if(!visitados[i]){
				pai[i] = pacote;
				fila.push(i);
				visitados[i] = 1;
			}
		}
	}
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n, m; cin >> n >> m;
	grafo.assign(n,vector<int>());
	visitados.assign(n,0);
	pai.clear();
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		grafo[x].pb(y);
		grafo[y].pb(x);
	}

	bfs();

	if( pai.count(n-1) ){
		vector<int> caminho;
		int tmp = n-1;
		while( tmp != 0 ){
			caminho.pb(tmp);
			tmp = pai[tmp];
		}
		caminho.pb(0);
		cout << caminho.size() << endl;
		for(int i = 0; i < caminho.size(); i++){
			cout << caminho[caminho.size()-i-1] + 1 << " ";
		}

	} else cout << "IMPOSSIBLE" << endl;
	
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

