//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e5+9;
int ca = 0;
void solve ()
{
    int n, q; cin >> n >> q;
    int a[n];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += 1LL*(a[i])*(n-2*i-1);
    }
    cout <<"Case " <<++ca <<":"<<endl;
    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            cout << ans << endl;
        }else {
            int x, v; cin >> x >> v;
            ans -= 1LL*a[x]*(n-2*x-1);
            a[x] = v;
            ans += 1LL*a[x]*(n-2*x-1);
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