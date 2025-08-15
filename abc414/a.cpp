/*
単純にAとBの比較を繰り返せばよい．
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
    int ans = 0;
    for(int i = 0; i < N; ++i){
        if(X[i] <= L && R <= Y[i]){
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

// AC.
