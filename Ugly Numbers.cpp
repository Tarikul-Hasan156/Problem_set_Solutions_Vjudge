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
    #define i128 __int128
    ll MAX=1e18;
    void solve ()
    {
        vector<ll>v;
        v.push_back(0);
        ll p2=1;
        for (int i=0;p2<MAX;i++,p2*=2){
            ll p3=1;
            for (int j=0;p2*p3<MAX;j++,p3*=3){
                ll p5=1;
                for (int k=0;p2*p3*p5<MAX;k++,p5*=5){
                    v.push_back(p3*p2*p5);
                }
            }
        }
        sort(v.begin(),v.end());
        cout<<"The 1500'th ugly number is "<<v[1500]<<"."<<endl;
    }

    int main ()
    {
        speed;
        solve();
        return 0;
    }