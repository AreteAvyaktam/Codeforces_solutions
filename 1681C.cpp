#include <bits/stdc++.h>
using namespace std;
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define YY cout<<"YES"<<endl
#define NN cout<<"NO"<<endl
#define yy cout<<"Yes"<<endl
#define nn cout<<"No"<<endl
#define endl "\n"
#define typecast static_cast
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ll,ld>
#define vpii vector<pii>
#define vpll vector<pll>
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
#define PQ priority_queue
#define loop(it,init,condition,update) for(auto it=init;condition;update)
#define range(i,start,end,step) loop(i,start,i<end,i+=step)
#define increment(i,start,end) range(i,start,end,1)
#define decrement(i,start,end) range(i,start,end,-1)
#define for_each(element,container) for(auto &element:container)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr.begin(),arr.end(),greater<auto>())
#define char_index(c,caps) caps?c-'A':c-'a'
#define Input(A,x) A x; cin>>x
#define Init(B,x,value) B x; x=value
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void inputArray(vector<tmp>&arr,int start=0){
    increment(i,start,arr.size()){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    increment(i,r,matrix.size()){
        increment(j,c,matrix[i].size()){
            cin>>matrix[i][j];
        }
    }
}
template<typename tmp> 
inline void printArray(vector<tmp>&arr){
    for_each(element,arr){
        cout<<element<<" ";
    }
    cout<<endl;
}
template<typename tmp>
inline void printMatrix(vector<vector<tmp>>&matrix){
    increment(i,0,matrix.size()){
        increment(j,0,matrix[i].size()){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
const int infinity=1e9+7;
const ll linf=1e18+7;
const ll llzero=typecast<ll>(0);
int main(){
    ios;
    Input(int,t);
    while(t--){
        Input(int,n);
        vi a(n),b(n);
        inputArray(a);
        inputArray(b);
        set<vi>elements;
        vpii moves;
        increment(i,0,n){
            elements.insert({a[i],b[i],i});
        }
        increment(i,0,n){
            vi element=*elements.begin();
            elements.erase(elements.begin());
            if(element.back()!=i){
                int src=element.back(),target=i;
                elements.erase({a[target],b[target],target});
                swap(a[target],a[src]);
                swap(b[target],b[src]);
                moves.push_back({target+1,src+1});
                elements.insert({a[src],b[src],src});
            }
        }
        if(is_sorted(a.begin(),a.end()) and is_sorted(b.begin(),b.end())){
            cout<<moves.size()<<endl;
            for_each(move,moves){
                cout<<move.first<<" "<<move.second<<endl;
            }
        } else {
            cout<<-1<<endl;
        }
    }
    return 0;
}