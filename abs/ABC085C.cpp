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

#define rep1(n) for(ll i=0; i<(ll)(n); ++i)

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


int main(void){
    ll N, Y;
    cin >> N >> Y;
    Y /= 1000;
    int A=0, B=0, C=0;
    string ans;
    // cout << (Y >= N) << endl;
    // cout << (N >= Y / 10 + Y%10/5 + Y%5) << endl;
    for(int i=0; i<=N; ++i){
        for(int j=0; j<=N; ++j){
            int k = N - i - j;
            if(k >= 0){
                if(10*i + 5*j + k == Y){
                    cout << i << " " << j << " " << k << endl;
                    return 0;
                }
            }
            
        }
    }
    cout << "-1 -1 -1" << endl;

    
    
    return 0;
}