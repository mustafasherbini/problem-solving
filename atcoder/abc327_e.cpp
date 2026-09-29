// Problem: Maximize Rating
// Platform: atcoder
// Language: C++17
// Verdict: Accepted
// URL: https://atcoder.jp/contests/abc327/tasks/abc327_e?lang=en
// Solved on: 2026-09-29T07:17:49.139Z

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
    const ll N = 2e12 + 2, M = 998244353 ;
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



 void solve()
 {
    int n;cin>>n;
    vi vs(n);
     vector<double>last(n,0),cur(n),powers(n+1);
     double sumPows=0,res=-N;
    for (int i = 0; i < n; ++i) {
        cin>>vs[i];
    }
    for (int i = 0; i <= n; ++i) {
        powers[i]=powl(0.9,i);
    }
    for (int k = 1; k <= n; ++k) {

        for (int idx = n-1; idx >=0; --idx) {
            cur[idx]=vs[idx]*powers[k-1];
            if (idx+1<n) {
                cur[idx]+=last[idx+1];
                cur[idx]=max(cur[idx],cur[idx+1]);
            }
        }
        swap(last,cur);
        sumPows+=powers[k-1];
        res=max(res, (last.front()/sumPows )-(1200.0/sqrtf(k)));
    }

    std::cout << std::fixed << std::setprecision(15) << res << std::endl;
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
