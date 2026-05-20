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
int ca = 0;
void solve ()
{
    string s1, s2; cin >> s1 >> s2;
    for (int i=0;i<s1.size();i++) {
        if (s1[i]=='.')s1[i]=' ';
    }
    for (auto &ch:s2) {
        if (ch == '.') ch = ' ';
    }
    stringstream sss(s1);
    vector<int>v, v1;
    string temp;
    while (sss >> temp) {
        v.push_back(stoi(temp));
    }
   stringstream ss(s2);
   while (ss >> temp) {
        bitset<8>bs (temp);
        unsigned long long val = bs.to_ullong();
        v1.push_back(val);
   }
   bool ok = true;
   for (int i = 0; i < v.size(); i++) {
        if (v[i] != v1[i]) {
            ok = false;break;
        }
   }
   if (ok) {
    cout << "Case " << ++ca <<": "<<"Yes" <<endl;
   }else {
    cout << "Case " << ++ca <<": "<<"No" <<endl;
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