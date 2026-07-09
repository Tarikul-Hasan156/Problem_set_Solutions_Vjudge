//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e5+9;
int a[N], t[4*N];
int marge (int a, int b) {
    return a+b;
}
void build (int n, int b, int e) {
    if (b == e) {
        t[n] = a[b];
        return;
    }
    int mid = (b + e) >> 1, l = 2*n, r = 2*n + 1;
    build (l, b, mid);
    build (r, mid + 1, e);
    t[n] = marge (t[l], t[r]);
}
void update (int n, int b, int e, int i, int val) {
    if (i > e or i < b) return;
    if (b == e and e == i) {
        t[n] += val;
        return;
    }
    int mid = (b + e) >> 1, l = 2*n, r = 2*n + 1;
    update (l, b, mid, i, val);
    update (r, mid+1, e, i, val);
    t[n] = marge (t[l], t[r]);
}
void update1 (int n, int b, int e, int i) {
    if (i > e or i < b) return;
    if (b == e and e == i) {
        t[n] = 0;
        return;
    }
    int mid = (b + e) >> 1, l = 2*n, r = 2*n + 1;
    update1 (l, b, mid, i);
    update1 (r, mid+1, e, i);
    t[n] = marge (t[l], t[r]);
}
int query1 (int n, int b, int e, int i) {
    if (i < b or i > e) return 0;
    if (b == e and e == i) {
        int ans = t[n];
        return ans;
    }
    int mid =  (b + e) >> 1, l = 2*n, r = 2*n + 1;
    return query1(l, b, mid, i) + query1(r, mid+1, e, i);
}
int query2 (int n, int b, int e, int i, int j) {
    if (b > j or e < i) return 0;
    if (b >= i and e <= j) {
        return t[n];
    }
    int mid = (b + e) >> 1, l = 2*n, r = 2*n + 1;
    return query2 (l, b, mid, i, j) + query2 (r, mid+1, e, i, j);
}
int ca = 0;
void solve ()
{
    int n, q; cin >> n >> q;
    cout <<"Case " << ++ca <<":" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build (1, 1, n);
    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int i; cin >> i;
            cout << query1 (1, 1, n, ++i) << endl;
            update1 (1, 1, n, i);
        }else if (ty == 2) {
            int i, val; cin >> i >> val;
            update (1, 1, n, ++i, val);
        }else {
            int i, j; cin >> i >> j;
            cout << query2 (1, 1, n, ++i, ++j) << endl;
        }
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