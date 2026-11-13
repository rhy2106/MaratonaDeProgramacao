#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ld long long double
#define ll long long
#define f first
#define s second
#define endl '\n'
#define pb push_back

using namespace std;

struct AhoCorasick{
	struct Trie{
		Trie* links[26];
		Trie* fail;
		bool vis;
		Trie(){
			for(int i = 0; i < 26; i++)
				links[i] = nullptr;
			fail = nullptr;
			vis = false;
		}
	};

	Trie* root;
	vector<Trie*> end, bfs;

	Trie* createTrie(){
		return new Trie();
	}

	void init(int n){
		root = createTrie();
		end.resize(n);
	}

	void insert(string s, int idx){
		Trie* p = root;
		for( char c : s ){
			int i = c - 'a';
			if( p->links[i] == nullptr )
				p->links[i] = createTrie();
			p = p->links[i];
		}
		end[idx] = p;
	}

	void build(){
		queue<Trie*> q;
		Trie* p = root;
		for(int i = 0; i < 26; i++){
			if(p->links[i] != nullptr){
				q.push(p->links[i]);
				p->links[i]->fail = root;
			} else {
				p->links[i] = p;
			}
		}

		while( !q.empty() ){
			Trie* u = q.front(); q.pop();
			bfs.pb(u);
			for(int i = 0; i < 26; i++){
				if( u->links[i] != nullptr ){
					u->links[i]->fail = u->fail->links[i];
					q.push(u->links[i]);
				}
				else u->links[i] = u->fail->links[i];
			}
		}

	}

	void query(string s){
		Trie* p = root;
		for(char c : s){
			int i = c - 'a';
			p = p->links[i];
			p->vis = true;
		}
		for(int i = bfs.size() - 1; i >= 0; i--){
			Trie* u = bfs[i];
			if( u->vis && u->fail != nullptr ){
				u->fail->vis = true;
			}
		}
		for(Trie* u : end)
			cout << (u->vis ? "YES" : "NO") << endl;
	}
};

void solve(int testCase){
	string s; cin >> s;
	int n; cin >> n;
	AhoCorasick ac;
	ac.init(n);
	for(int i = 0; i < n; i++){
		string t; cin >> t;
		ac.insert(t, i);
	}
	ac.build();
	ac.query(s);
}

int main(){
	// fastio;
	int tt = 1;
	for(int t = 1; t <= tt; t++) solve(t);
	return 0;
}

