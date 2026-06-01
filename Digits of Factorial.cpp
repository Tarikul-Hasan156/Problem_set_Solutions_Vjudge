//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e6+9;
int ca = 0;
vector<double> v(N);
void calculate () {
    for (int i = 1; i < N; i++) {
        v[i] = log2 (i);
    }
    for (int i = 1; i < N; i++) {
        v[i] = v[i] + v[i-1];
    }
}
void solve ()
{
    int n, b; cin >> n >> b;
    double ans = 0;
    // for (int i = 1; i <= n; i++) {
        // ans += calculate(i, b);
        ans += v[n];
    // }
    ans /= log2(b);
    cout <<"Case " << ++ca << ": " <<((n == 0) ? 1:(ll)(ans) + 1) << endl;
}


int main ()
{
    speed;
    calculate ();
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}