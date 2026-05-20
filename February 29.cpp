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
int count_leaf_day_in_year (int year) {
    int ans = year / 4;
    ans += year / 400;
    ans-= year / 100;
    return ans;
}
int leaf_day (int start, int end) {
    return count_leaf_day_in_year (start) - count_leaf_day_in_year (end);
}
void solve ()
{
    string first, second;
    getline(cin, first);
    getline(cin, second);
    first.erase(first.find(','), 1);
    second.erase(second.find(','), 1);
    vector<string>s1,s2;
    stringstream ss(first);
    string temp;
    while(ss>>temp){
        s1.push_back(temp);
    }
    stringstream sss(second);
    while (sss >> temp){
        s2.push_back(temp);
    }
    vector<string>v({"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"});
    map<string, int>mp;
    int i=0;
    for (auto val:v){
        mp[val] = i++;
    }
    int first_year = stoi(s1[2]);
    int second_year = stoi(s2[2]);
    if (mp[s1[0]] <= mp["February"]) {

    }else {
        first_year++;
    }
    if (mp[s2[0]] > mp["February"] or (mp[s2[0]] == mp["February"] and stoi(s2[1]) >= stoi("29"))){

    }else {
        second_year--;
    }
    cout << "Case " << ++ca << ": " << leaf_day(second_year, first_year-1) <<endl;
}

int main ()
{
    speed;
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--)
    {
        solve();
    }
    return 0;
}