// Problem: problem
// Platform: vjudge
// Contest: Socks 2 - AtCoder abc334_c - Virtual Judge
// Language: C++23 (GCC 15.2.0)
// Verdict: Accepted
// URL: https://vjudge.net/problem/AtCoder-abc334_c
// Solved on: 2026-10-04T21:09:00.951Z

    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #define f first
    #define s second
    #define int ll
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
    const ll N = 1e11, M = 998244353 ;
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

vi all;
int rec(int i,bool skip , vector<vector<int>>&dp) {
    if (skip && i+1==all.size())
        return N;
    if (i>=all.size())
        return skip?0:N;
    int &ret=dp[i][skip];
    if (~ret)
        return ret;
    ret=all[i+1]-all[i] + rec(i+2,skip,dp);
    if (!skip)
        ret=min(ret,rec(i+1,true,dp));
    return ret;
}

 void solve()
 {

     map<int,int>show;
     int n,k,res=0,in;
     cin>>n>>k;
     for (int i = 0; i < k; ++i) {
         cin>>in;
         show[in]++;
     }
    all.clear();
     for (int i = 1; i <= n; ++i) {
         in=show[i];
         if (in<2)all.push_back(i);
         if (in<1)all.push_back(i);
     }
     for (int i = 0; i < all.size() and i+1<all.size(); i+=2) {
        res+=all[i+1]-all[i];
     }
     if (all.size()%2==0) {
         cout<<res;
         return;
     }
    vector dp(all.size(),vector<int>(2,-1));

        cout<<rec(0,false,dp);

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