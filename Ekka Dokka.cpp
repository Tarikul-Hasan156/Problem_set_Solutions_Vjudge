//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e5+9;

// struct custom_hash {
//   static uint64_t splitmix64(uint64_t x) {
//       x += 0x9e3779b97f4a7c15ULL;
//       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
//       x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
//       return x ^ (x >> 31);
//   }
//
//   size_t operator()(uint64_t x) const {
//       static const uint64_t FIXED_RANDOM =
//           chrono::steady_clock::now().time_since_epoch().count();
//       return splitmix64(x + FIXED_RANDOM);
//   }
// };
int ca = 0;
ll power (ll n, ll a){
    ll ans=1;
    while (a){
        if (a&1){
            ans=1LL*ans*n;
        }
        n=1LL*n*n;
        a>>=1;
    }
    return ans;
}
// ll count_power (ll &n) {
//     int cnt = 0;
//     while (n % 2 == 0) {
//         cnt++;
//         n = (n >> 1);
//     }
//     return power (2, cnt);
// }
void solve ()
{
     ll n; cin >> n;
     int cnt = 0;
     if (n & 1) {
        cout <<"Case " << ++ca << ": " << "Impossible" << endl;
     }else {
        while (n % 2 == 0) {
            cnt++;
            n = (n >> 1);
        }
        cout << "Case " << ++ca << ": " << n << sp << power (2, cnt) << endl;
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