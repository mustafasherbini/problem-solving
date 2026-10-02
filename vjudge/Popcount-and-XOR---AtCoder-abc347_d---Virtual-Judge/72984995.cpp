// Problem: problem
// Platform: vjudge
// Contest: Popcount and XOR - AtCoder abc347_d - Virtual Judge
// Language: C++23 (GCC 15.2.0)
// Verdict: Accepted
// URL: https://vjudge.net/problem/AtCoder-abc347_d
// Solved on: 2026-10-02T11:31:12.849Z

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




 void solve()
 {
     int a ,b ,c,x=0,y=0,ca,cb;
     cin>>a>>b>>c;
        ca=a,cb=b;
     for (int i = 0; i <= 60  ; ++i) {
         int sh=1ll<<i;
            if (c&sh) {
                if (ca>cb ) {
                    x|=sh;
                    ca--;
                }else {
                    y|=sh;
                    cb--;
                }
            }
     }
     for (int i = 0; i <=60  and ca>0 and cb>0; ++i) {
         int sh=1ll<<i;
         if (!(c&sh)){
                 x|=sh;
                 ca--;
                 y|=sh;
                 cb--;
                    }
     }
    if (ca==0 and cb==0 and (x^y)==c)
        cout<<x<<" "<<y;
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