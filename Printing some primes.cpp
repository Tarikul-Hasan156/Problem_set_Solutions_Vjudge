        //بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
        #include <bits/stdc++.h>
        #define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        #define ll long long
        #define sp ' '
        #define endl '\n'
        using namespace std;
        const int N=1e8+9;

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
        // bool is_prime[N];
        void solve ()
        {
            int n=N-9;
            for (int i=2;i<=n;i++)is_prime[i]=true;
            is_prime[1]=false;
            for (int i=2;i*i<=n;i++){
                if (is_prime[i]){
                for (int j=i*i;j<=n;j+=i){
                    is_prime[j]=false;
                }
            }
            }
            // for (int i=0;i<10;i++){  
            //     if (is_prime[i])cout<<i<<sp;
            // }cout<<endl;
            vector<int>v;v.push_back(0);
            for (int i=2;i<=n;i++){
                if (is_prime[i])v.push_back(i);
            }
            int i=0;
            for (int i=1;i<(int)v.size();i+=100){
                cout<<v[i]<<endl;
            }
        }

        int main ()
        {
            speed;
            solve();
            return 0;
        }