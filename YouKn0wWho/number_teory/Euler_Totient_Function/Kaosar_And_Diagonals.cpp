#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 5;
ll phi[MAXN];

int main(){
    _;
	for(int i = 0; i < MAXN; i++) phi[i] = i;
	for(int i = 2; i < MAXN; i++){
		if(phi[i] != i) continue;
		for(int j = i; j < MAXN; j += i)
			phi[j] -= phi[j] / i;
	}

	for(int i = 1; i < MAXN; i++)
		phi[i] += phi[i-1];

	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		cout << phi[n] - n - 1  << endl;
		
	}
    return 0;
}

