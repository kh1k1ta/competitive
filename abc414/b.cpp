#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<char> c(N);
    vector<long long> l(N);
    for(int i = 0; i < N; ++i){
        cin >> c[i] >> l[i];
    }

    string ans = {};
    long long length = 0;

    for(int i = 0; i < N; ++i){
        length += l[i];
        if(length > 100){
            cout << "Too Long" << endl;
            return 0;
        }
    }
    
    ans.reserve(length);
    for(int i = 0; i < N; ++i){
        ans.append(l[i], c[i]);
    }
    cout << ans << endl;
    
    return 0;
}
