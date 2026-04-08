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
    int ca=1;  
    void solve ()
    {
        int p,l;cin>>p>>l;
        int remain=p-l;
        if (remain<=l){
            cout<<"Case "<<ca++<<":"<<sp;
            cout<<"impossible"<<endl;
        }else{
            vector<int>se;
            for (int i=1;1LL*i*i<=remain;i++){
                if (remain%i==0){
                    se.push_back(i);
                    if (i!=remain/i)
                    se.push_back(remain/i);
                }
            }
            sort(se.begin(),se.end());
                cout<<"Case "<<ca++<<":"<<sp;
                for (auto x:se){
                    if (x>l)cout<<x<<sp;
                }cout<<endl;
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