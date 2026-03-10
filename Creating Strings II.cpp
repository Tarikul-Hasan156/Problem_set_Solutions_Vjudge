//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;
const int N=1e6+9;
const int mod=1e9+7;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
      x += 0x9e3779b97f4a7c15ULL;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
      x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
      return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM =
          chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
  }
};
int power (int n, int a){
    n%=mod;
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
int fac[N],ifac[N];
void fact(){
    fac[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=1LL*fac[i-1]*i%mod;
    }
    ifac[N-1]=power(fac[N-1],mod-2);
    for (int i=N-2;i>=0;i--){
        ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
    }

}
void solve ()
{
    string s;cin>>s;
    int n=s.size();
    unordered_map<char,int,custom_hash>mp;
    for (auto ch:s){
        mp[ch]++;
    }
    int res=fac[n];
    for (auto [ch,val]:mp){
        res=1LL*res*ifac[val]%mod;
    }
    cout<<res<<endl;
}

int main ()
{
    speed;
    fact();
    solve();
    return 0;
}