//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e6+9;

// struct custom_hash {
//   static uint64_t splitmix64(uint64_t x) {
//       x += 0x9e3779b97f4a7c15ULL;
//       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
//       x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
//       return x ^ (x >> 31);
//   }

//   size_t operator()(uint64_t x) const {
//       static const uint64_t FIXED_RANDOM =
//           chrono::steady_clock::now().time_since_epoch().count();
//       return splitmix64(x + FIXED_RANDOM);
//   }
// };
// unordered_map<ll,int,custom_hash>mp;
int ca=1;
// void calculate (){
//     for (int i=2;1LL*i*i<=N;i++){
//         for (ll j=i;j<N;j+=i){
//             mp[j]++;
//         }
//     }
// }
bitset<N>is_prime;
vector<int>primes;
void sieve (){
    for (int i=2;1LL*i*i<N;i++){
        if (!is_prime[i]){
            for (int j=i*i;j<N;j+=i){
                is_prime[j]=1;
            }
        }
    }
    for (int i=2;i<N;i++){
        if (!is_prime[i])primes.push_back(i);
    }
}
void solve ()
{
    ll n;cin>>n;
    int ans=1;
    for (auto p:primes){
        int divs=0;
        if (1LL*p*p>n)break;
        while (n%p==0){
            divs++;
            n/=p;
        }
        ans=ans*(divs+1); 
    }
    if (n>1){
        ans=ans*2;
    }
    cout << "Case "<<ca++<<": "<<ans-1<<endl;
}

int main ()
{
    speed;
    sieve();
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}