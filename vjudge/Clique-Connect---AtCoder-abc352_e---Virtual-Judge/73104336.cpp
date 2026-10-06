// Problem: problem
// Platform: vjudge
// Contest: Clique Connect - AtCoder abc352_e - Virtual Judge
// Language: C++23 (GCC 15.2.0)
// Verdict: Accepted
// URL: https://vjudge.net/problem/AtCoder-abc352_e
// Solved on: 2026-10-06T20:37:14.815Z

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
#define int ll
//#define double long double
#define TryingToDoBetter   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define IN  freopen("prime_subtractorization_input.txt", "r", stdin);
#define OUT freopen("output.txt", "w", stdout) ;
using namespace std;
using ll = long long;
using ld = double;
using vi = deque<int>;
const int N=2e5+5, M=1e3+5, MOD=1e9+7,OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T> >;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dx4[] = {1, 0, 0, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}, dy4[] = {0, 1, -1, 0};
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//find_by_order()returns an iterator to the k-th largest element (counting from zero),
//order_of_key()the number of items in a set that are strictly smaller than our item.
//Erase on multi  ordered set : s.erase(--s.lower_bound(value))

// Before submit check:
// Corner cases
// Conditions

class DSU{
public:

    int p[N],sz[N],ncmp,mx=0;
    void  inti(int nodes){
        iota(p,p+nodes,0); // increase the first val
        fill(sz,sz+nodes,1);
        ncmp=nodes;
    }
    int find (int u){
        return p[u]==u ? u :p[u]= find(p[u]);

    }
    bool  operator () (int u , int v){
        u= find(u);
        v= find(v);
        if (u== v) return false;
        if(sz[u]>sz[v])swap(u,v);
        p[u]=v;
        sz[v]+=sz[u];
        mx= max(mx,sz[v]);
        ncmp--;
        return true;
    }


} dsu;
void solve() {
    int n , m,res=0,sz,in;
    cin>>n>>m;
    dsu.inti(n);
    vector<vector<int>>all(m);
    vector<pair<int,int>>costPerVec(m);
    for (int i = 0; i < m; ++i) {
        cin>>sz>>costPerVec[i].f;
        costPerVec[i].s=i;
        for (int j = 0; j < sz; ++j) {
            cin>>in;
            all[i].push_back(in);
        }
    }
    sort(costPerVec.begin(), costPerVec.end());

    for (int i = 0; i < m; ++i) {
        int idx=costPerVec[i].s,co=costPerVec[i].f;
        for (int j = 0; j+1 < all[idx].size(); ++j) {
            if (dsu(all[idx][j],all[idx][j+1]))
                res+=co;
        }
    }
    if (dsu.ncmp==1)
        cout<<res;
    else cout<<-1;

}


int32_t main() {
TryingToDoBetter
    int t = 1;
//  cin >> t;

    while (t--) {
        solve();
    cout << "\n";
    }

        return 0;
}