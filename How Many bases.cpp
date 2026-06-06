//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e5+9;
const int mod = 100000007;
int power (int n, int a){
    int ans=1%mod;
    while (a){
        if (a&1){
            ans=1LL*ans*n%mod;
        }
        n=1LL*n*n%mod;
        a>>=1;
    }
    return ans;
}
int ca = 0;
int solve_greater_then_or_equal_t (vector<int> &e, int t) {
    int ans = 1;
    for (int i =  0; i < e.size(); i++) {
        ans = 1LL*ans*(e[i]/t + 1) % mod;
    }
    return ans;
}
int solve_equal_to_t (vector<int> &e, int t) {
    return (solve_greater_then_or_equal_t(e, t) - solve_greater_then_or_equal_t(e, t+1) + mod) % mod;
}
void solve ()
{
    int n, m , t;
    while (cin >> n >> m >> t) {
        if (n == 0 and m == 0 and t == 0)return;
        vector<int> v;
        for (int i = 2; 1LL*i*i <= n; i++) {
            if (n % i == 0) {
               int cnt = 0;
               while (n % i == 0) {
                    cnt++;
                    n /= i;
               }
               v.push_back(cnt*m);
            }
        }
        if (n > 1) v.push_back(m);
        cout << "Case " << ++ca << ": " << solve_equal_to_t(v, t) << endl;

    }
}

int main ()
{
    speed;
    solve();
    return 0;
}