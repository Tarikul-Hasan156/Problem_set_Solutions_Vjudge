    //بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
    #include <bits/stdc++.h>
    #define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #define ll int64_t
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
    const int mod=1e9+7;
    int a[N];
    ll pw[N]; 
    ll pre[N];
    void solve ()
    {
        int n;cin>>n;
        for (int i=1;i<=n;i++)cin>>a[i];
        ll tot=0;
        pre[0]=0;
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++){
            pre[i]=(pre[i-1]+a[i]);
            tot+=a[i];
        }
        // if (n<2){
        //     cout<<a[0]<<endl;return;
        // }
        //
        ll ans=0;
        for (int i=1;i<=n;i++){
            // for (int j=i+1;j<=n;j++){
                // int val=abs(a[i]-a[j]);
                ll val=(pre[n]-pre[i])-1LL*(n-i)*a[i];
                val%=mod;
                if (val<0)val+=mod;
                ans+=1LL*pw[n-2]*val%mod;
                // ans+=1LL*pw[n-2]*val%mod;
                ans%=mod;
                // cout<<val<<sp<<ans<<endl;
            // }
        }
        cout<<ans<<endl;
    }

    int main ()
    {

        speed;
        pw[0]=1;
        for (int i=1;i<N;i++){
            pw[i]=pw[i-1]*2%mod;
        }
        // for (int i=0;i<5;i++)cout<<pw[i]<<sp;cout<<endl;/
        solve();
        return 0;
    }