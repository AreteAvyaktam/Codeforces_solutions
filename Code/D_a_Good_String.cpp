#include <bits/stdc++.h>    
using namespace std;
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define see(statement) cout<<statement<<endl
#define YY see("YES")
#define NN see("NO")
#define yy see("Yes")
#define nn see("No")
#define endl "\n"
#define f first
#define Aa see("Alice")
#define AA see("ALICE")
#define Bb see("Bob")
#define BB see("BOB")
#define s second
#define pb push_back
#define rb pop_back
#define gcd(a,b) __gcd(a,b)
#define sz() size()
#define ins(element) insert(element)
#define br() cout<<endl
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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ll,ld>
#define vpii vector<pii>
#define vpll vector<pll>
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
#define PQ priority_queue
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define loop(type,it,init,condition,update) for(type it = init;condition;update)
#define enum_sub_type(type,submask,mask,equal) loop(type,submask,mask,(equal ? submask >= 0 : submask > 0),submask = (submask - 1) & mask)
#define enum_sub(submask,mask,equal) enum_sub_type(int,submask,mask,equal) 
#define range_la(type,i,start,end,step,buffer) loop(type,i,start,i + buffer < end,i += step)
#define inc_la(i,start,end,buffer) range_la(int,i,start,end,1,buffer)
#define slid_win(left,right,size,end) for(int left = 1, right = size; right < end; left++,right++)
#define range_type(type,i,start,end,step) loop(type,i,start,(step > 0 ? i < end : i >= end),i += step)
#define range(i,start,end,step) range_type(int,i,start,end,step)
#define inc(i,start,end) range(i,start,end,1)
#define dec(i,start,end) range(i,start,end,-1)
#define inc_type(type,i,start,end) range_type(type,i,start,end,1)
#define dec_type(type,i,start,end) range_type(type,i,start,end,-1)
#define inc_la_type(type,i,start,end,buffer) range_la(type,i,start,end,1,buffer)
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
#define rsort(arr) sort(arr); rev(all(arr));
#define slice(start,end) substr(start,end - (start) + 1)
#define char_index(c) (c >= 'A' and c <= 'Z' ? c - 'A' : c - 'a')
inline ll llmax(ll a,ll b){
    return a > b ? a : b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void readArray(vector<tmp>&arr,int start = 0){
    inc(i,start,arr.size()){
        cin >> arr[i];
    }
}
template<typename tmp>
inline void readMatrix(vector<vector<tmp>>&matrix,int r = 0,int c = 0){
    inc(i,r,matrix.size()){
        inc(j,c,matrix[i].size()){
            cin >> matrix[i][j];
        }
    }
}
template<typename tmp> 
inline void writeArray(vector<tmp>&arr,int start = 0){
    inc(i,start,arr.size()){
        cout << arr[i] << " ";
    }
    br();
}
template<typename tmp>
inline void writeMatrix(vector<vector<tmp>>&matrix,int r = 0,int c = 0){
    inc(i,r,matrix.size()){
        inc(j,c,matrix[i].size()){
            cout << matrix[i][j] << " ";
        }
        br();
    }
}
template<typename tmp> tmp mod(tmp number,tmp base){
    while(number < 0){
        number += base;
    }
    return number % base;
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
constexpr int inf = 1e9 + 10;
constexpr ll linf = 1e18 + 10;
const ll llzero=cast(0,ll);
void testcase();
int goodString(string &str,map<char,vi>&prefix,char ch,int start,int end);
int main(){
    // ios;
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
    string str;
    cin >> str;
    map<char,vi>prefix;
    inc_type(char,ch,'a','z' + 1){
        prefix[ch].resize(n + 1,0);
    }
    inc(i,0,n){
        inc_type(char,ch,'a','z' + 1){
            prefix[ch][i + 1] = prefix[ch][i] + ch == str[i];
        }
    }
    int ans = inf;
    inc_type(char,ch,'a','z' + 1){
        ans = min(ans,goodString(str,prefix,ch,0,n - 1));
    }
    see(ans);
    return;
}
int goodString(string&str,map<char,vi>&prefix,char ch,int start,int end){
    if(start > end){
        return 0;
    } else if(start == end){
        return str[start] != ch;
    } else {
        int mid = (start + end) /2 ;
        int number = mid - start + 1;
        int leftCnt = 0;
        int rightCnt = 0;
        inc(i,start,mid + 1){
            leftCnt += str[i] == ch;
        }
        dec(i,end,mid){
            rightCnt += str[i] == ch;
        }
        char nextChar = ch == 'z' ? 'a' : ch + 1;
        if(leftCnt != rightCnt){
            if(leftCnt < rightCnt){
                return number - rightCnt + goodString(str,prefix,nextChar,start,mid);
            } else {
                return number - leftCnt + goodString(str,prefix,nextChar,mid + 1,end);
            }
        } else {
            int ans1 = goodString(str,prefix,nextChar,start,mid);
            int ans2 = goodString(str,prefix,nextChar,mid + 1,end);
            return number - leftCnt + min(ans1,ans2);
        }
    }
}