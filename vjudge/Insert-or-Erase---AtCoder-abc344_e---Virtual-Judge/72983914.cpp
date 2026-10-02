// Problem: problem
// Platform: vjudge
// Contest: Insert or Erase - AtCoder abc344_e - Virtual Judge
// Language: C++23 (GCC 15.2.0)
// Verdict: Accepted
// URL: https://vjudge.net/problem/AtCoder-abc344_e
// Solved on: 2026-10-02T11:23:49.685Z

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
     int n,q,t,x,y;
     cin>>n;
     map<int,int>p,ch;
     vi vs(n);
     for (int i = 0; i < n; ++i) {
        cin>>vs[i];
     }
     for (int i = 0; i < n; ++i) {
         if (i-1>=0)
            p[vs[i]]=vs[i-1];
         else p[vs[i]]=vs[i];
         if (i+1<n)
            ch[vs[i]]=vs[i+1];
         else ch[vs[i]]=vs[i];
     }
     int firstElm=vs.front();

     cin>>q;
     while (q--) {
        cin>>t>>x;
         int parent=p[x],child=ch[x];
         if (t==1) {
             cin>>y;
           if (ch[x]==x) {
                ch[x]=y; //im the last
                p[y]=x;
                ch[y]=y;
             }else {
                 ch[x]=y;
                 p[y]=x;
                 ch[y]=child;
                 p[child]=y;
             }
         }else {

             if (p[x]==x) {
                 p[child]=child;//im the first;
                 firstElm=child;
             }else if (ch[x]==x) {
                 ch[parent]=parent; //im the last
             }else {
                 ch[parent]=child;
                 p[child]=parent;
             }
         }
     }
     while (true) {
         cout<<firstElm<<" ";
         int tem=firstElm;
         firstElm=ch[firstElm];
         if (tem==firstElm)
             break;
     }
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