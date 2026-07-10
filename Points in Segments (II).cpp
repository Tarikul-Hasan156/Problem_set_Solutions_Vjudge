//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const int N=50000+9;
int a[N], b[N], Q[N], ans[3*N];
int ca = 0;
void solve ()
{
    int n, q; cin >> n >> q;
    set<int> se;
    cout << "Case " << ++ca <<":\n";
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        se.insert(a[i]);
        se.insert(b[i]);
    }
    for (int i = 1; i <= q; i++) {
        cin >> Q[i];
        se.insert(Q[i]);
    }
    int id = 0;
    map<int, int> mp;
    for (auto x: se) {
        mp[x] = ++id;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
        b[i] = mp[b[i]];
    }
    for (int i = 1; i <= q; i++) {
        Q[i] = mp[Q[i]];
    }
    for (int i = 1; i <= n; i++) {
        ++ans[a[i]];
        --ans[b[i]+1];
    }
    for (int i = 1; i < 3*N; i++) {
        ans[i] = ans[i] + ans[i-1];
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[Q[i]] << endl;
    }
    for (int i = 1; i <= id; i++) {
        ans[i] = 0;
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