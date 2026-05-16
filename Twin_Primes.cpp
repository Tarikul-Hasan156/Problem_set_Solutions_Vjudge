//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=20000000+7;

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
bitset<N>is_prime;
vector<int>primes;
vector<pair<int,int>>pr;
void sieve (){
    for (int i=2;1LL*i*i<N;i++){
        if (!is_prime[i]){
            for (int j=i*i;j<=N;j+=i){
                is_prime[j]=1;
            }
        }
    }
    for (int i=2;i<N;i++){
        if (!is_prime[i])primes.push_back(i);
    }
    for (int i=0;i<(int)primes.size()-1;i++){
        if (primes[i]+2==primes[i+1]){
            pr.push_back({primes[i],primes[i+1]});
        }
    }
}
void solve ()
{
    int n;
    while (cin>>n){
        auto [val1,val2]=pr[n-1];
        cout<<"("<<val1<<", "<<val2<<")"<<endl;
    }
}

int main ()
{
    speed;
    sieve();
    // cout<<primes.size()<<endl;
    // cout<<pr.size()<<endl;
    // for (int i=0;i<5;i++){
    //     auto [val1,val2]=pr[i];
    //     cout<<val1<<sp<<val2<<endl;
    // }
    solve();
    return 0;
}