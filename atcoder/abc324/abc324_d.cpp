// Problem: D - Square Permutation
// Platform: atcoder
// Contest: abc324
// Language: C++23 (GCC 15.2.0)
// Verdict: AC
// URL: https://atcoder.jp/contests/abc324/submissions/79573822
// Solved on: 2026-09-26T21:24:30.111Z

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
     int n ,res=0,mx=9999999999999;
     string in;cin>>n>>in;
     vi frq(10,0);

     for (int i = 0; i < n; ++i)
         frq[in[i]-'0']++;

     for (int i = 0; i*i <= mx; ++i) {
         vi frq2(10,0);
            int v=i*i;

            while (v) {
                frq2[v%10]++;
                v/=10;
            }

         bool can=true;

         for (int j = 1; j <= 9; ++j) {
             if (frq2[j]!=frq[j])
                    can=false;
         }

         can&=frq2[0]<=frq[0];
         res+=can;
         }

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