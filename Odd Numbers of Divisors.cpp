//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const int N=1e5+9;
const ll MX = 1e10;
int spf[N];
vector<ll> v[N];
void solve ()
{
    int d;
    ll l, r; cin >> d >> l >> r;
    int ans = 0;
    ans = upper_bound (v[d].begin(), v[d].end(), r)- lower_bound(v[d].begin(), v[d].end(), l);
    cout << ans << endl;
}

int main ()
{
    speed;
    for (int i = 2; i < N; i++) spf[i] = i;
    for (int i = 2; i < N; i++) {
        if (spf[i] == i) {
        for (int j = i; j < N; j += i) {
            spf[j] = min (spf[j], i);
        }
      }
    }
    for (int i = 2; i < N; i++) { 
        int x = i;
        int numbers_of_divisors = 1;
        while (x > 1) {
            int e = 0, p = spf[x];
            while (x % p == 0) {
                e++;
                x /= p;
            }
            numbers_of_divisors *= (2 * e + 1);
        }
        v[numbers_of_divisors].push_back (1LL*i*i);
    }
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}