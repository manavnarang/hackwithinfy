#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define arr_watch(arr, n) for(int i=0;i<n;++i) cout<<arr[i]<<" \n"[i==n-1]
using namespace std;
const int maxn = 1e5;
vector<int> graph[maxn + 5];
int order[maxn + 5], A[maxn + 5];
list<int> colors[maxn + 5];
int the_end;
 
void dfs(int u, int p){
    colors[A[u]].push_back(u);
    for (int child: graph[u]){
        if(child == p) continue;
        dfs(child, u);
    }
    order[u] = the_end++;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
 
    // freopen("D:/TestFiles/input.txt","r",stdin);
 
    #endif
    /*********************** CODE IS HERE *****************************************/
 
    //number of nodes...
    int n; cin >> n;
    for(int i = 1, x, y; i < n; ++i){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //colors input...
    for (int i = 1; i <= n; ++i)
        cin >> A[i];    
 
    the_end = 1;
    dfs(1, 0);        //here we go....
 
    int ans = 0;
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int col = A[x];   //color of that x node...
        auto it1 = colors[col].begin();
        auto it2 = it1;
        bool flag = false;
 
        //iterate over subtree with same color(end_time of those nodes <= xth node)
        while(it1 != colors[col].end()){
            if(order[*it1] > order[x] and flag)
                break;
            it2++;
            if(*it1 == x)
                flag = true;
 
            if(order[*it1] <= order[x] and flag){
                ans++;
                colors[col].erase(it1);  //found that node, then remove it
            }
            it1 = it2;
        }
        cout << ans << endl;
 
    }
 
 
    return 0;
}

INPUT:
5
3 1
3 2
2 4
2 5
1 1 2 2 1
4
2
4
5
1

OUTPUT:
2
3
3
4
 
