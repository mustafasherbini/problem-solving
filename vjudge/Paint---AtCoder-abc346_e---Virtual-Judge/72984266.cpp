// Problem: problem
// Platform: vjudge
// Contest: Paint - AtCoder abc346_e - Virtual Judge
// Language: C++23 (GCC 15.2.0)
// Verdict: Accepted
// URL: https://vjudge.net/problem/AtCoder-abc346_e
// Solved on: 2026-10-02T11:22:29.633Z

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
     int r,c,k,totalCels=0;
     cin>>r>>c>>k;
     vector all(k,vector<int>(3));
     set<int>drawnR,drawnC;
     map<int,int>colors;
     for (int i = 0; i < k; ++i) {
         for (int j = 0; j < 3; ++j) {
             cin>>all[i][j];
         }
     }

     for (int i = k-1; i >=0; --i) {
        int t=all[i][0],idx=all[i][1],co=all[i][2];
         if (t==1) {//row

             if (drawnR.find(idx)!=drawnR.end())
                 continue;
             colors[co]+=c-drawnC.size();
             totalCels+=c-drawnC.size();
             drawnR.insert(idx);
         }else {//col
             if (drawnC.find(idx)!=drawnC.end())
                 continue;
             colors[co]+=r-drawnR.size();
             totalCels+=r-drawnR.size();
             drawnC.insert(idx);
         }
     }
     deque<pair<int,int>>res;
     colors[0]+=c*r-totalCels;
     int sz=0;
     for (auto p : colors)
         if (p.s>0)
             sz++;

     cout<<sz<<"\n";
     for (auto p : colors)
         if (p.s>0)
            cout<<p.f<<" "<<p.s<<"\n";

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