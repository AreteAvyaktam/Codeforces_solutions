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
#define cd complex<double>
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
#define loop(type,it,init,condition,update) for(type it=init;condition;update)
#define enumerate_subsets(type,submask,mask,equal) loop(type,submask,mask,(equal?submask>=0:submask>0),submask=(submask-1)&mask) 
#define range_look_ahead(type,i,start,end,step,buffer) loop(type,i,start,i+buffer<end,i+=step)
#define inc_look_ahead(type,i,start,end,buffer) range_look_ahead(type,i,start,end,1,buffer)
#define range(type,i,start,end,step) loop(type,i,start,(step>0?i<end:i>=end),i+=step)
#define inc(type,i,start,end) range(type,i,start,end,1)
#define dec(type,i,start,end) range(type,i,start,end,-1)
#define for_each(element,container) for(auto &element:container)
#define iterate_forward(it,container) for(auto it=container.begin();it!=container.end();it++)
#define iterate_reverse(it,container) for(auto it=container.rbegin();it!=container.rend();it++)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr.begin(),arr.end(),greater<auto>())
#define char_index(c,caps) caps?c-'A':c-'a'
#define Input(A,x) A x; cin>>x
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void inputArray(vector<tmp>&arr,int start=0){
    inc(tmp,i,start,arr.size()){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    inc(tmp,i,r,matrix.size()){
        inc(tmp,j,c,matrix[i].size()){
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
    inc(tmp,i,0,matrix.size()){
        inc(tmp,j,0,matrix[i].size()){
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
    Input(int,n);
    vi arr(n);
    inputArray(arr);
    int collected=0,turns=0;
    while(collected<n){
        turns+=(collected<n and collected!=0);
        inc(int,i,0,n){
            if(collected>=arr[i]){
                collected++;
                arr[i]=infinity;
            }
        }
        turns+=(collected<n);
        dec(int,i,n-1,0){
            if(collected>=arr[i]){
                collected++;
                arr[i]=infinity;
            }
        }
    }
    cout<<turns<<endl;
    return 0;
}