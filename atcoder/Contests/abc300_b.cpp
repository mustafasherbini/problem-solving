// Problem: Same Map in the RPG World
// Platform: atcoder
// Language: C++17
// Verdict: Accepted
// URL: https://atcoder.jp/contests/abc300/submissions/78909472
// Solved on: 2026-09-26T14:56:04.346Z

    #include <bits/stdc++.h>
    //#include <ext/pb_ds/assoc_container.hpp>
    //#include <ext/pb_ds/tree_policy.hpp>
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
    const ll N = 1e5 + 2, M = 1e9 + 7;
    const double EPS = 1e-6;
    using vi = deque<int>;
    template<class T>
    using min_heap = priority_queue<T, std::vector<T>, std::greater<T> >;
    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dx4[] = {1, 0, 0, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}, dy4[] = {0, 1, -1, 0};
    //using namespace __gnu_pbds;
    //template<class T> using ordered_set =tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
    //find_by_order()returns an iterator to the k-th largest element (counting from zero),
    //order_of_key()the number of items in a set that are strictly smaller than our item.
    //Erase on multi  ordered set : s.erase(--s.lower_bound(value))

    // Before submit check:
    // Corner cases
    // Conditions

int val(int i , int v) {
    return ((i%v)+v)%v;
}
    void solve() {
        int n , m;
        cin>>n>>m;

        map<pair<int,int>,int>tri;
        vector<deque<char>>grid1(n,deque<char>(m)),grid2(n,deque<char>(m));

        vi v1,v2;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin>>grid1[i][j];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin>>grid2[i][j];

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                bool can=true;
                for (int i = 0; i < n and can; ++i) {
                    for (int j = 0; j < m and can; ++j) {
                        if (grid2[i][j]!=grid1[val(row+i,n)][val(col+j,m)])
                            can=false;
                    }
                }
                if (can) {
                    cout<<"Yes";
                    return;
                }
            }
        }

    cout<<"No";
    }

    int32_t main() {
       TryingToDoBetter
        int t = 1;
    //   cin >> t;

        while (t--) {
            solve();
        cout << "\n";
        }

        return 0;
    }