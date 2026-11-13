#include <bits/stdc++.h>
#include <cassert>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl '\n'

using namespace std;

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a%b);
}

void case1(ll n, ll k){
	vector<ll> dp(n);
	ll ans = 0;
	for(int i = 0; i < k; i++){
		ll x; cin >> x;
		for(int j = 0; j * x < n; j++){
			if( dp[j*x] ) continue;
			ans++;
			dp[j*x]++;
		}
	}
	cout << n - ans << endl;
}

void case2(ll n, ll k){
	int m = (1<<k); n--;
	vector<ll> a(k);
	vector<ll> dp(m,0);
	for(int i = 0; i < k; i++) cin >> a[i];
	for(int mask = 0; mask < m; mask++){
		ll tmp = 1, c = 0;
		for(int i = 0; i < k; i++)
			if( mask & (1<<i) ){
				tmp = tmp * a[i] / gcd(tmp, a[i]);
				c++;
			}
		dp[mask] = ((c & 1) ? 1 : -1) * (n / tmp);
	}
	ll ans = 0;
	for(int mask = 1; mask < m; mask++) ans += dp[mask];
	cout << n-ans << endl;
}

void solve(){
	ll n, k; cin >> n >> k;
	if( n <= 1e6 ) case1(n,k);
	else case2(n,k);
}

int main(){
	fastio;
	int tt = 1;
	while(tt--) solve();
	return 0;
}

