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

int n, m;
char matriz[20][20];
int visitados[20][20];

int bfs(iPair inicio){
	iPair mov[4] = {{1,0},{-1,0},{0,1},{0,-1}};
	queue<iPair> fila;
	fila.push(inicio);
	int ans = 0;
	while(!fila.empty()){
		iPair pos = fila.front();
		fila.pop();
		if(visitados[pos.f][pos.s]) continue;
		visitados[pos.f][pos.s] = 1;
		ans++;
		for(auto [i, j] : mov){
			if( pos.f + i >= n ) continue;
			if( pos.s + j >= m ) continue;
			if( pos.f + i < 0 ) continue;
			if( pos.s + j < 0 ) continue;
			if( matriz[pos.f + i][pos.s + j] == '#') continue;
			if( visitados[pos.f + i][pos.s + j] ) continue;
			fila.push({pos.f + i, pos.s + j});
		}
	}
	return ans;
}

void solve(){
	while(cin >> m >> n, m != 0 && n != 0){
		iPair inicio;
		for(int i = 0; i < 20; i++)
			for(int j = 0; j < 20; j++)
				matriz[i][j] = '#';

		for(int i = 0; i < 20; i++)
			for(int j = 0; j < 20; j++)
				visitados[i][j] = 0;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matriz[i][j];
				if(matriz[i][j] == '@')
					inicio = {i,j};
			}
		}
		int ans = bfs(inicio);
		cout << ans << endl;
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

