//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e5+9;
int a[N], t[4*N];
void build_tree (int node, int b, int e) {
    if (b == e) {
        t[node] = a[b];
        return;
    }
    int mid = (b + e) >> 1;
    int l = 2*node, r= 2*node + 1;
    build_tree(l, b, mid);
    build_tree (r, mid+1, e);
    t[node] = min (t[l], t[r]);
}
int query (int node, int b, int e, int i, int j) {
    if (i > e or j < b) return N;
    if (b >= i and e <= j) return t[node];
    int mid = (b+e) >> 1;
    int l = 2*node, r = 2*node + 1;
    return min (query (l, b, mid, i, j), query (r, mid+1, e, i, j));
}
int ca = 0;
void solve ()
{
    int n; cin >> n;
    int q; cin >> q;
    for (int i = 1; i < N; i++) {
        t[i] = N;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build_tree(1, 1, n);
    cout << "Case " << ++ca <<": " << endl;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << query (1, 1, n, l, r) << endl;
    }
}

int main ()
{
    speed;
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}