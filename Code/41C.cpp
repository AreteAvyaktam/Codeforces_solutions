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
#define loop(it,init,condition,update) for(auto it=init;condition;update)
#define enumerate_subsets(submask,mask,equal) loop(submask,mask,(equal?submask>=0:submask>0),submask=(submask-1)&mask) 
#define range_look_ahead(i,start,end,step,buffer) loop(i,start,i+buffer<end,i+=step)
#define increment_look_ahead(i,start,end,buffer) range_look_ahead(i,start,end,1,buffer)
#define range(i,start,end,step) loop(i,start,(step>0?i<end:i>=end),i+=step)
#define increment(i,start,end) range(i,start,end,1)
#define decrement(i,start,end) range(i,start,end,-1)
#define for_each(element,container) for(auto &element:container)
#define iterate_forward(it,container) for(auto it=container.begin();it!=container.end();it++)
#define iterate_reverse(it,container) for(auto it=container.rbegin();it!=container.rend();it++)
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
    Input(string,email);
    int left=0,right=email.size()-1;
    if(email.size()>=3){
        if(email.substr(0,3)=="dot"){
            left+=3;
        }
        if(email.substr(email.size()-3,3)=="dot"){
            right-=3;
        }
    }
    if(email.size()>=2){
        if(email.substr(email.size()-2,2)=="at"){
            right-=2;
        }
        if(email.substr(0,2)=="at"){
            left+=2;
        }
    }
    set<int>dot;
    int atPos=-1;
    increment(i,left,right){
        if(i+2<email.size() and email.substr(i,3)=="dot"){
            dot.insert(i);
        }
        if(atPos==-1 and i+1<email.size() and email.substr(i,2)=="at"){
            atPos=i;
        }
    }
    string ans;
    increment(i,0,left){
        ans+=email[i];
    }
    loop(i,left,i<=right,i){
        if(dot.count(i)){
            ans+='.';
            i+=3;
        } else if(i==atPos){
            ans+="@";
            i+=2;
        }else {
            ans+=email[i++];
        }
    }
    increment(i,right+1,email.size()){
        ans+=email[i];
    }
    cout<<ans<<endl;
    return 0;
}