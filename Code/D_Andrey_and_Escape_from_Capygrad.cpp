#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define see(statement) cout << statement << endl
#define YY see("YES")
#define NN see("NO")
#define yy see("Yes")
#define nn see("No")
#define is ==
#define isnt !=
#define fi first
#define sc second
#define Aa see("Alice")
#define AA see("ALICE")
#define Bb see("Bob")
#define BB see("BOB")
#define pb(value) push_back(value)
#define pf(value) push_front(value)
#define rb() pop_back()
#define rf() pop_front()
#define this (*this)
#define sz() size()
#define vt(type) vector<type>
#define ins(element) insert(element)
#define bg() begin()
#define bk() back()
#define fr() front()
#define ed() end()
#define mp(value1,value2) make_pair(value1,value2)
#define br() cout << endl
#define cast(element,type) static_cast<type>(element)
#define ll long long
#define cd complex<double>
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vb vector<bool>
#define vvb vector<vb>
#define vld vector<ld>
#define pair(t1,t2) pair<t1,t2>
#define pii pair(int,int)
#define pll pair(ll,ll)
#define pld pair(ll,ld)
#define vpii vector<pii>
#define vpll vector<pll>
#define debug(statement) cout<<"**************Debug: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
#define max_heap(tmp) priority_queue<tmp>
#define min_heap(tmp) priority_queue<tmp,vector<tmp>,greater<tmp> >
#define map(type1,type2) map<type1,type2>
#define umap(type1,type2) unordered_map<type1,type2>
#define mmap(type1,type2) multimap<type1,type2>
#define ummap(type1,type2) unordered_multimap<type1,type2>
#define set(type) set<type>
#define uset(type) unordered_set<type>
#define mset(type) multiset<type>
#define umset(type) unordered_multiset<type>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define elif else if
#define loop(type,it,init,condition,update) for(type it = init;condition;update)
#define list(first,second,container) for(auto &[first,second]: container)
#define enumerate(first,second,container) list(first,second,enumerated(container))
#define zip(first,second,container1,container2) list(first,second,zipped(container1,container2))
#define enum_sub_type(type,submask,mask,equal) loop(type,submask,mask,(equal ? submask >= 0 : submask > 0),submask = (submask - 1) & mask)
#define enum_sub(submask,mask,equal) enum_sub_type(int,submask,mask,equal)
#define rng_la(type,i,start,end,step,buffer) loop(type,i,start,i + buffer < end,i += step)
#define inc_la(i,start,end,buffer) rng_la(int,i,start,end,1,buffer)
#define slid_win(left,right,size,end) for(int left = 1, right = size; right < end; left++,right++)
#define rng_type(type,i,start,end,step) loop(type,i,start,(step > 0 ? i < end : i >= end),i += step)
#define rng(i,start,end,step) rng_type(int,i,start,end,step)
#define inc(i,start,end) rng(i,start,end,1)
#define dec(i,start,end) rng(i,start,end,-1)
#define inc_type(type,i,start,end) rng_type(type,i,start,end,1)
#define dec_type(type,i,start,end) rng_type(type,i,start,end,-1)
#define inc_la_type(type,i,start,end,buffer) rng_la(type,i,start,end,1,buffer)
#define each_key(element,container) for(const auto &element:container)
#define each(element,container) for(auto &element:container)
#define iter_for(it,container) for(auto it = container.begin();it != container.end();it++)
#define iter_rev(it,container) for(auto it = container.rbegin();it != container.rend();it++)
#define until(condition) while(!(condition))
#define sorted(arr) sort(all(arr))
#define custSort(container,comparator) sort(all(container),comparator)
#define cnt(container,value) count(all(container),value)
#define isSorted(container) is_sorted(all(container))
#define rev(arr) reverse(all(arr))
#define rsort(arr) sort(rall(arr));
#define slice(start,end) substr(start,end - (start) + 1)
#define char_index(c) (c >= 'A' and c <= 'Z' ? c - 'A' : c - 'a')
inline ll llmax(ll a,ll b){
    return a > b ? a : b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp1,typename tmp2>
vector<pair<tmp1,tmp2> >zipped(vector<tmp1>&arr1,vector<tmp2>&arr2){
    vector<pair<tmp1,tmp2> >ans;
    inc(i,0,arr1.sz()){
        ans.pb(make_pair(arr1[i],arr2[i]));
    }
    return ans;
}
template<typename tmp>
vt(tmp)uniqueConsec(vector<tmp>&arr){
    vt(tmp)ans;
    inc(i,0,arr.sz()){
        if(ans.sz() is 0 or ans.back() isnt arr[i]){
            ans.pb(arr[i]);
        }
    }
    return ans;
}
template<typename tmp>
vector<pair<int,tmp> >enumerated(vt(tmp)&arr){
    vector<pair<int,tmp> >ans;
    inc(i,0,arr.sz()){
        ans.pb(make_pair(i,arr[i]));
    }
    return ans;
}
template<typename tmp>
inline void readArray(vt(tmp)&arr,int start = 0){
    inc(i,start,arr.size()){
        cin >> arr[i];
    }
}
template<typename tmp>
inline void readMatrix(vt(tmp)&matrix,int r = 0,int c = 0){
    inc(i,r,matrix.size()){
        inc(j,c,matrix[i].size()){
            cin >> matrix[i][j];
        }
    }
}
template<typename tmp>
inline void writeArray(vt(tmp)&arr,int start = 0){
    inc(i,start,arr.size()){
        cout << arr[i] << " ";
    }
    br();
}
template<typename tmp>
inline tmp findMaxIndex(vt(tmp)&arr,int start = 0){
    tmp ans = start;
    inc(i,start,arr.sz()){
        ans = (arr[ans] > arr[i] ? ans : i);
    }
    return ans;
}
template<typename tmp>
inline tmp findMinIndex(vt(tmp)&arr,int start = 0){
    tmp ans = start;
    inc(i,start,arr.sz()){
        ans = (arr[ans] < arr[i] ? ans : i);
    }
    return ans;
}
template<typename tmp>
inline void writeMatrix(vt(vt(tmp))&matrix,int r = 0,int c = 0){
    inc(i,r,matrix.size()){
        inc(j,c,matrix[i].size()){
            cout << matrix[i][j] << " ";
        }
        br();
    }
}
template<typename tmp> tmp power(tmp base,tmp exponent){
    if(exponent is 0){
        return 1;
    } else {
        vt(tmp)dp(log2(exponent) + 1,0);
        dp[0] = base;
        inc(i,1,dp.sz()){
            dp[i] = dp[i - 1] * dp[i - 1];
        }
        tmp ans = 1;
        while(exponent){
            int pos = log2(exponent & (-exponent));
            exponent ^= (1 << pos);
            ans *= dp[pos];
        }
        return ans;
    }
}
template<typename tmp>
void coordinateCompressInplace(vt(tmp)&arr){
    map(tmp,int)pos;
    inc(i,0,arr.sz()){
        pos[arr[i]] = 0;
    }
    int index = 0;
    each(entry,pos){
        entry.sc = index++;
    }
    inc(i,0,arr.sz()){
        arr[i] = pos[arr[i]];
    }
}
template<typename tmp>
vt(tmp) coordinateCompress(vt(tmp)&arr){
    vt(tmp)ans = arr;
    map(tmp,int)pos;
    inc(i,0,ans.sz()){
        pos[ans[i]] = i;
    }
    int index = 0;
    each(entry,pos){
        entry.sc = index++;
    }
    inc(i,0,ans.sz()){
        ans[i] = pos[ans[i]];
    }
    return ans;
}
template<typename tmp> tmp mod(tmp number,tmp base){
    while(number < 0){
        number += base;
    }
    return number % base;
}
template<typename tmp> inline tmp manhattanDist(pair(tmp,tmp) &first,pair(tmp,tmp) &second){
    return abs(first.fi - second.fi) + abs(first.sc - second.sc);
}
template<typename tmp> tmp gcd(tmp a, tmp b){
    if (a is 0)
        return b;
    return gcd(b % a, a);
}
template<typename tmp> tmp lcm(tmp a,tmp b){
    return (a * b) / gcd(a,b);
}
template<typename tmp> tmp ceil(tmp num,tmp den){
    return (num / den) + (num % den != 0);
}
template<typename tmp>
inline bool inBetween(tmp left,tmp mid,tmp right,bool incLeft = true,bool incRight = true){
    return (incLeft ? mid >= left : mid > left) and (incRight ? mid <= right : mid < right);
}
const int inf = 2e9;
const ll linf = 2e18;
class DSU {
    public:  
    vi ranks,parents;

    private:  
    void _merge(int large,int small){
        this.parents[small] = large;
        this.ranks[large] += this.ranks[small];
    }

    public:  
    DSU(int n){
        this.ranks = vi(n,1);
        this.parents = vi(n,1);
        inc(i,0,n){
            this.parents[i] = i;
        }
    }
    int find(int x){
        if(x is this.parents[x]){
            return x;
        } else {
            return this.parents[x] = this.find(this.parents[x]);
        }
    }
    void findUnion(int x,int y){
        int parx = this.find(x),pary = this.find(y);
        if(parx isnt pary){
            if(this.ranks[parx] >= this.ranks[pary]){
                this._merge(parx,pary);
            } else {
                this._merge(pary,parx);
            }
        }
    }
};
class Node {
    public:  
    int start,end,maxi;
    Node *left,*right;
    Node(int start,int end,int maxi){
        this.start = start;
        this.end = end;
        this.maxi = maxi;
        this.left = nullptr;
        this.right = nullptr;
    }
};
class SegmentTree{
    private:  
    Node *root;
    Node* _build(int start,int end,DSU &dsu,map(int,int)&teleport){
        if(start is end){
            Node *node = new Node(start,end,teleport[dsu.find(start)]);
            return node;
        } else {
            int mid = (start + end) >> 1;
            Node *left = this._build(start,mid,dsu,teleport);
            Node *right = this._build(mid + 1,end,dsu,teleport);
            Node *node = new Node(start,end,max(left->maxi,right->maxi));
            node->left = left;
            node->right = right;
            return node;
        }
    }
    int _query(Node *node,int start,int end){
        if(!node or start > node->end or end < node->start){
            return -inf;
        } elif(node->start >= start and node->end <= end){
            return node->maxi;
        } else {
            return max(this._query(node->left,start,end),this._query(node->right,start,end));
        }
    }

    public:  
    SegmentTree(DSU &dsu,map(int,int)&teleport,int end){
        this.root = this._build(0,end,dsu,teleport);
    }
    int query(int start,int end){
        return this._query(this.root,start,end);
    }
};
void testcase();
int main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        testcase();
    }
    return 0;
}
void testcase(){
    int n;
    cin >> n;
    vpii input(n);
    inc(i,0,n){
        int l,r,a,b;
        cin >> l >> r >> a >> b;
        input[i] = mp(l,b);
    }
    sorted(input);
    int index = 0,left = input[0].fi,right = input[0].sc;
    DSU dsu(n);
    inc(i,1,n){
        if(input[i].fi > right){
            index = i;
            left = input[i].fi,right = input[i].sc;
        } else {
            dsu.findUnion(index,i);
            right = max(right,input[i].sc);
        }
    }
    map(int,int)teleport;
    inc(i,0,n){
        teleport[dsu.find(i)] = max(teleport[dsu.find(i)],input[i].sc);
    }
    SegmentTree tree(dsu,teleport,n - 1);
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        int left = (input[0].fi <= x) ? 0 : n + 1,right = -1,start = 0,end = n - 1;
        while(start <= end){
            int mid = (start + end) >> 1;
            if(input[mid].fi <= x){
                right = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        cout << max(x,tree.query(left,right)) << " ";
    }
    br();
    return;
}
#pragma GCC diagnostic pop