//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;

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

void solve ()
{
    // map<int,string>mp;
    // vector<pair<int,string>>vv;
    priority_queue<ll>pq;
    unordered_map<ll,string,custom_hash>mp;
     ll x;cin>>x;
     cin.ignore();
    for (int i=0;i<x;i++){
       string temp;
       getline(cin,temp);
    //    cout<<temp<<endl;
       string name="";
       vector<string>temp2;
       ll age=0;
        stringstream ss(temp);
        string word;
        while (ss>>word){
            temp2.push_back(word);
        }
        ll size=temp2.size();
        for (int i=0;i<size-1;i++){
            name+=temp2[i];
        }
        age=stoi(temp2[size-1]);
        pq.push(age);
        mp.insert({age,name});
    }
    while (!pq.empty()){
        cout<<mp[pq.top()]<<endl;
        pq.pop();
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