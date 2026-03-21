#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<ll> seg;

// constrói a árvore
void build(const vector<ll>& a, int node, int l, int r) {
    if (r - l == 1) {
        seg[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(a, 2 * node, l, mid);
    build(a, 2 * node + 1, mid, r);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

// atualização pontual: a[idx] = val
void update(int node, int l, int r, int idx, ll val) {
    if (r - l == 1) {
        seg[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx < mid)
        update(2 * node, l, mid, idx, val);
    else
        update(2 * node + 1, mid, r, idx, val);

    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

// soma no intervalo [ql, qr)
ll query(int node, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql)
        return 0;
    if (ql <= l && r <= qr)
        return seg[node];

    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr)
         + query(2 * node + 1, mid, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    seg.assign(4 * n, 0);
    build(a, 1, 0, n);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            ll v;
            cin >> i >> v;
            update(1, 0, n, i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n, l, r) << '\n';
        }
    }

    return 0;
}

