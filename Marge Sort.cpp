    //بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
    #include <bits/stdc++.h>
    #define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #define ll int64_t
    #define sp ' '
    #define endl '\n'
    using namespace std;

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
    const ll N=1e5+9;
    vector<ll>vv;
    ll x;
        vector<ll> marge(vector<ll>a,vector<ll>b){
            ll i=0,j=0;
            vector<ll>ans;
            while (i<a.size() and j<b.size()){
                if (a[i]<b[j]){
                    ans.push_back(a[i]);
                    i++;
                }else{
                    ans.push_back(b[j]);
                    j++;
                }
            }
            while (i<a.size()){
                ans.push_back(a[i]);
                i++;
            }
            while (j<b.size()){
                ans.push_back(b[j]);
                j++;
            }
            return ans;
        }



    vector<ll> divide (ll l,ll r){
        if (l==r){
            return vector<ll>{vv[l]};
        }
        ll mid=(l+r)/2;
        auto L=divide(l,mid);
        auto R=divide(mid+1,r);
        return marge(L,R);
    }


    
    void solve ()
    {
        // cin>>x;
        ll temp;
        while (cin>>temp){
            vv.push_back(temp);
        }
        x=vv.size();
        auto ans=divide (0,x-1);
        for (auto &x:ans)cout<<x<<sp;cout<<endl;
    }

    int main ()
    {
        speed;
        // int tt;
        // cin >> tt;
        // while (tt--)
        // {
            solve();
        // }
        return 0;
    }