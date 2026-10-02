// Problem: problem
// Platform: vjudge
// Contest: Minimize Sum of Distances - AtCoder abc348_e - Virtual Judge
// Language: C++23 (GCC 15.2.0)
// Verdict: Accepted
// URL: https://vjudge.net/problem/AtCoder-abc348_e
// Solved on: 2026-10-02T23:35:52.523Z

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
    class PresentationFile;
    class Spreadsheet;
    class TextFile;
    class IDocument;
    using namespace std;
    using ll = long long;
    using ld = double;
    const ll N = 10, M = 998244353 ;
    const double EPS = 1e-6;
    using vi = deque<int>;
    template<class T>
    using min_heap = priority_queue<T, std::vector<T>, std::greater<T> >;
    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dx4[] = {1, 0, 0, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}, dy4[] = {0, 1, -1, 0};
   using namespace __gnu_pbds;
   template<class T> using ordered_set =tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
    //find_by_order()returns an iterator to the k-th largest element (counting from zero),
    //order_of_key()the number of items in a set that are strictly smaller than our item.
    //Erase on multi  ordered set : s.erase(--s.lower_bound(value))

    // Before submit check:
    // Corner cases
    // Conditions



vector<vector<int>>gra;
vector<vector<pair<int,int>>>costs;
vector<pair<int,int>>chCosts;
vi c;
int res;
pair<int,int> dfs1(int idx ,int p) {
        auto & r = chCosts[idx];
    //  sum of c , distance ;
         r = {c[idx],0};
        for (int i =0 ; i < gra[idx].size(); i++) {

            if (gra[idx][i]==p)
                continue;

           auto pairR= dfs1(gra[idx][i],idx);

            costs[idx][i]=pairR;

            r.f+=pairR.f; // Cs
            r.s+=pairR.s+pairR.f; // move to me

        }
        return r;
}
void dfs2(int idx ,int p,int lstCs =0 , int lstCosts=0) {

    res = min(res, chCosts[idx].s + lstCosts);
    for (int i =0 ; i < gra[idx].size(); i++) {

        if (gra[idx][i]==p)
            continue;

        dfs2(gra[idx][i], idx,
            lstCs + chCosts[idx].f - costs[idx][i].f,
            lstCosts
                + lstCs
                + chCosts[idx].s
                - costs[idx][i].s
                + chCosts[idx].f
                - costs[idx][i].f
                - costs[idx][i].f);    }

}
 void solve()
 {
     int n,u,v;
     cin>>n;
     c.resize(n);
     gra.resize(n);
    costs.resize(n);
    chCosts.resize(n);
    res=INT64_MAX;
     for (int i = 0; i < n-1; ++i)
     {
         cin>>u>>v;
         --v,u--;
         gra[u].push_back(v);
         gra[v].push_back(u);
         costs[u].emplace_back(0,0);
         costs[v].emplace_back(0,0);
     }
     for (int i = 0; i < n; ++i)
         cin>>c[i];

        dfs1(0,-1);
        dfs2(0,-1);
     cout<<res;
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