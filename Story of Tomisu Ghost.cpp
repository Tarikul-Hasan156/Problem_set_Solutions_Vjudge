//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e5+9;
vector<int>primes;
bitset<N>is_prime;
const int mod = 10000019;
int ca = 0;
void sieve () {
    for (int i = 2; i < N; i++) is_prime[i] = true;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            for (int j = i+i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}
int Legendre(int n, int p) {
    int ans = 0;
    while (n) {
        ans += n / p;
        n /= p;
    }
    return ans;
}
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
void solve ()
{
    int n, t; cin >> n >> t;
    int ans = 1;
    for (auto p: primes) {    
        if (p > n) break;
        int f = Legendre (n, p);
        int e = f / t;
        ans = 1LL* ans * power(p, e) % mod;
    }
    cout << "Case " << ++ ca <<":"<< sp;
    if (ans == 1) {
        cout << -1 << endl;
    }else {
        cout << ans << endl;
    }
}

int main ()
{
    speed;
    sieve();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}