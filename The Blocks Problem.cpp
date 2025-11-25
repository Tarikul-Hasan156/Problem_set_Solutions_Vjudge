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
const ll N=25;
ll x;
vector<vector<ll>>vv(N);
pair<ll,ll> find_position_of_value (ll X){
    for (int i=0;i<x;i++){
        for (int j=0;j<vv[i].size();j++){
            if (vv[i][j]==X){
                return {i,j};
            }
        }
    }
    return {0,0};
}
void move_value_ini_position (int vec_num,int position_vec){
    for (int i=position_vec+1;i<vv[vec_num].size();i++){
        ll temp=vv[vec_num][i];
        vv[temp].push_back(temp);
    }
    vv[vec_num].resize(position_vec+1);
}
void move_another_vec (int vec_id,int position,int dest_vec_id){
    for (int i=position;i<vv[vec_id].size();i++){
        ll val=vv[vec_id][i];
        vv[dest_vec_id].push_back(val);
    }
    vv[vec_id].resize(position);
}
void solve ()
{
    cin>>x;
    for (int i=0;i<x;i++){
        vv[i].push_back(i);
    }
    string s1;
    while (cin>>s1 and s1!="quit"){
        ll a,b;string s2;
        cin>>a>>s2>>b;
            auto  [vec_id_a,position_a]=find_position_of_value(a);
            auto [vec_id_b,position_b]=find_position_of_value(b);
            if (vec_id_a==vec_id_b)continue;
        if (s1=="move"){
            if (s2=="onto"){
                move_value_ini_position (vec_id_a,position_a);
                move_value_ini_position (vec_id_b,position_b);
                move_another_vec(vec_id_a,position_a,vec_id_b); 
            }else{
                move_value_ini_position (vec_id_a,position_a);
                move_another_vec(vec_id_a,position_a,vec_id_b);
            }
        }else{
            if (s1=="pile"){
                move_value_ini_position (vec_id_b,position_b);
                move_another_vec(vec_id_a,position_a,vec_id_b);
            }else{
                move_another_vec(vec_id_a,position_a,vec_id_b);
            }
        }
    }
    for (int i=0;i<x;i++){
        cout <<i<<":";
        for (int j=0;j<vv[i].size();j++){
            cout<<sp<<vv[i][j];
        }
        cout<<endl;
    }
    
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