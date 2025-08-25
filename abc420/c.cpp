#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
#define pb push_back
#define sz(a) ((int)a.size())

using ll=long long;
using u32=unsigned int;
using u64=unsigned long long;
using i128=__int128;
using u128=unsigned __int128;
using f128=__float128;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<typename T> using vc=vector<T>;
template<typename T> using vvc=vc<vc<T>>;
template<typename T> using vvvc=vc<vvc<T>>;
using vi=vc<int>;
using vll=vc<ll>;
using vvi=vc<vi>;
using vvll=vc<vll>;

template<typename T>
ostream& operator<<(ostream& os, const vc<T>& vec) {
    for (const auto& val : vec) {
        os << val << " ";
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vvc<T>& mat) {
    for (const auto& row : mat) {
        os << row << "\n";
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vvvc<T>& tensor) {
    for (const auto& mat : tensor) {
        os << mat << "\n";
    }
    return os;
}  


ll dig_sum(ll r, ll n){
    ll count = 0;
    while(n>0){
        count += n%r;
        n /= r;
    }
    return count;
}

#define int long long

struct query{
    char c;
    ll x;
    ll v;
};
int main(void){
    ll N, Q;
    cin >> N >> Q;
    vi A(N), B(N);
    vc<query> qr(Q);
    ll min_sum = 0;
    for(ll i=0; i<N; ++i){
        cin >> A[i];
    }
    for(ll i=0; i<N; ++i){
        cin >> B[i];
    }
    for(auto& q : qr){
        cin >> q.c >> q.x >> q.v;
        q.x--;
    }
    
    for(ll i=0; i<N; ++i){
        if(A[i] < B[i]){
            min_sum += A[i];
        }
        else{
            min_sum += B[i];
        }
    }
    // cout << "A: " << A << endl;
    // cout << "B: " << B << endl;
    // cout << "min_sum: " << min_sum << endl;
    for(auto& q : qr){
        if(q.c == 'A'){
            if(A[q.x] < B[q.x]){
                if(q.v < A[q.x] && A[q.x] < B[q.x]){
                    min_sum -= A[q.x] - q.v;
                }
                else if(A[q.x] < q.v && q.v < B[q.x]){
                    min_sum += q.v - A[q.x];
                }
                else if(B[q.x] < q.v){
                    min_sum += B[q.x] - A[q.x];
                }
            }
            else{
                if(q.v < A[q.x] && q.v < B[q.x]){
                    min_sum -= A[q.x] - q.v;
                }
            }
            A[q.x] = q.v;
        }
        else{
            if(B[q.x] < A[q.x]){
                if(q.v < B[q.x] && B[q.x] < A[q.x]){
                    min_sum -= B[q.x] - q.v;
                }
                else if(B[q.x] < q.v && q.v < A[q.x]){
                    min_sum += q.v - B[q.x];
                }
                else if(A[q.x] < q.v){
                    min_sum += A[q.x] - B[q.x];
                }
            }
            else{
                if(q.v < B[q.x] && q.v < A[q.x]){
                    min_sum -= B[q.x] - q.v;
                }
            }
            B[q.x] = q.v;
        }
        cout << min_sum << endl;
    }

    return 0;
}