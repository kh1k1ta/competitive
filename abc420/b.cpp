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

int main(void){
    int N, M;
    cin >> N >> M;
    vc<string> S(N);
    vi score(N);
    vi ans;
    for(auto& s : S) cin >> s;
    for(int i=0; i<M; ++i){
        int sum = 0;
        for(int j=0; j<N; ++j){
            sum += int(S[j][i] - '0');
        }
        // cout << "sum: " << sum << endl;

        if(sum == 0 || sum == N){
            for(auto& s : score) s++;
        } 
        else if(sum > N/2){
            for(int j=0; j<N; ++j){
                if(S[j][i] == '0'){
                    score[j]++;
                    // cout << "0, minority: " << j << endl;
                }
            }
        } 
        else {
            for(int j=0; j<N; ++j){
                if(S[j][i] == '1'){
                    score[j]++;
                    // cout << "1, minority: " << j << endl;
                } 
            }    
        }
        
    }

    int max = 0;
    for(auto& s : score) if(s > max) max = s;
    for(int i=0; i<N; ++i){
        if(score[i] == max) ans.pb(i+1);
    }
    // cout << "score: " << score << endl;
    cout << ans << endl;

    return 0;
}