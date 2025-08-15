#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<string> S(N);
    set<string> appeared = {};
    for(int i=0; i<N; ++i){
        cin >> S[i];
    }
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(i == j) continue;
            else{
                appeared.insert(S[i]+S[j]);
            }
        }
    }

    cout << appeared.size() << endl;

    return 0;
}

// AC.
