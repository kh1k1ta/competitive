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



tuple<vc<pii>, int> simu(int N, vc<pii> ip, vvc<bool> vog, vvc<bool> hog, vvc<bool> cleaned, vc<char> button){
    vc<pii> next_ip;
    int score = 0;
    for(int i=0; auto& [x, y] : ip){
        switch(button[i]){
            case 'U':
                if(y == 0){
                    next_ip[i] = make_pair(x, y);
                    break;
                } 
                if(hog[x][y-1]){
                    next_ip[i] = make_pair(x, y);
                    break;
                }
                next_ip[i] = make_pair(x, y-1);
                break;
            case 'D':
                if(y == N-1){
                    next_ip[i] = make_pair(x, y);
                    break;
                } 
                if(hog[x][y]){
                    next_ip[i] = make_pair(x, y);
                    break;
                }
                else next_ip[i] = make_pair(x, y+1);
                break;
            case 'L':
                if(x == 0){
                    next_ip[i] = make_pair(x, y);
                    break;
                } 
                if(hog[x-1][y]){
                    next_ip[i] = make_pair(x, y);
                    break;
                }    
                next_ip[i] = make_pair(x-1, y);
                break;
            case 'R':
                if(x == N-1){
                    next_ip[i] = make_pair(x, y);
                    break;
                } 
                if(hog[x][y]){
                    next_ip[i] = make_pair(x, y);
                    break;
                }
                next_ip[i] = make_pair(x+1, y);
                break;
            case 'S':
                next_ip[i] = make_pair(x, y);
                break;
        }
        if(!cleaned[next_ip[i].first][next_ip[i].second]) score++;
        i++;
    }
    return {next_ip, score};
}

int main(void){
    int N, M, K;
    cin >> N >> M >> K;
    vc<pii> ip(M);
    vvc<bool> vog(N, vc<bool>(N-1));
    vvc<bool> hog(N-1, vc<bool>(N));
    vi ops;
    for(int i=0; i<M; ++i){
        int x, y;
        cin >> x >> y;
        ip.at(i) = make_pair(x, y);
    }
    for(int i=0; i<N; ++i){
        string S;
        cin >> S;
        for(int j=0; j<N-1; ++j){
            if(S[j] == '1') vog[i][j] = true;
            else vog[i][j] = false;
        }
    }
    for(int i=0; i<N-1; ++i){
        string S;
        cin >> S;
        for(int j=0; j<N; ++j){
            if(S[j] == '1') hog[i][j] = true;
            else hog[i][j] = false;
        }
    }

    vvc<char> bts(K, vc<char>(M));
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    for(int i=0; i<M; ++i){
        vc<char> bt = {'U', 'U', 'D', 'D', 'L', 'L', 'R', 'R', 'S', 'S'};
        shuffle(bt.begin(), bt.end(), engine);
        for(int j=0; j<K; ++j){
            bts[j][i] = bt[j];
        }
    }
    cout << bts;
        
    vvc<bool> cleaned(N, vc<bool>(N));
    
    vi times_set = {1, 2, 3, 5, 6, 9, 10};
    int score = 10;
    uniform_int_distribution<int> tdist(0, 6);
    uniform_int_distribution<int> opdist(0, K-1);
    for(int i=0; i<300; ++i){
        int op = opdist(seed_gen);
        for(int j=0; j<times_set[tdist(seed_gen)]; ++j){
            ops.pb(op);
            // auto [ignore, dscore] = simu(N, ip, vog, hog, cleaned, bts[op]);
            // score += dscore;
        }
        // if(score == N*N) break;
    }
    cout << ops << endl;
    
    return 0;
    
}