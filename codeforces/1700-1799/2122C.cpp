// Problem: C - Manhattan Pairs
// Platform: codeforces
// Contest: Contest-2122
// Rating/Difficulty: 1700
// Language: C++23 (GCC 14-64, msys2)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2122/submission/392175702
// Solved on: 2026-09-26T14:47:38.129Z

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
#define int long long
//#define double long double
#define TryingToDoBetter   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define IN  freopen("prime_subtractorization_input.txt", "r", stdin);
#define OUT freopen("output.txt", "w", stdout) ;
using namespace std;using ll =  long long ;using ld =  double ;
const ll  N =1e4+5, M=998244353; const double  EPS = 1e-6 ;
using vi = deque<int>;
template<class T> using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dx4[] = {1, 0 , 0 , -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}, dy4[] = {0, 1, -1 ,0 };
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
//find_by_order()returns an iterator to the k-th largest element (counting from zero),
//order_of_key()the number of items in a set that are strictly smaller than our item.
//Erase on multi  ordered set : s.erase(--s.lower_bound(value))

// Before submit check:
// Corner cases
// Conditions

/*
 هناك احتمال آخر لتتويج مسعانا بغير الهزيمة، ما دمنا قررنا أننا لن نموت قبل أن نحاول أن نحيا
 */

bool cmp(deque<int>&v1 , deque<int>&v2){
    return v1.front()<v2.front();
}

void solve() {

int n ;
cin>>n;
deque<deque<int>>r(n),l;
    for (int i = 0; i <n ; ++i) {
        r[i].resize(3);
        for (int j = 0; j <2 ; ++j) {
            cin>>r[i][j];
        }
        r[i][2]=i;
    }
    std::sort(r.begin(), r.end(),cmp);
    while (r.size()>l.size()){
        l.push_back(r.back());
        r.pop_back();
    }
    for (int i = 0; i <l.size() ; ++i) {
        swap(l[i][0],l[i][1]);
        swap(r[i][0],r[i][1]);

    }
    std::sort(l.begin(), l.end(),cmp);
    std::sort(r.begin(), r.end(),cmp);
    while (!l.empty()){
        cout<<l.front()[2]+1<<" "<<r.back()[2]+1<<"\n";
        r.pop_back();
        l.pop_front();
    }

}
int32_t main(){
 TryingToDoBetter
    int t=1;
  cin>>t;
    while (t--){
        solve();
    //   cout<<"\n";

    }

    return 0;
}