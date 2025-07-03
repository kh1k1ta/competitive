/*
単純にAとBの比較を繰り返せばよい．
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; ++i) cin >> A[i] >> B[i];

    int ans = 0;
    for(int i = 0; i < N; ++i) if(A[i] < B[i]) ans++;

    cout << ans << endl;
    return 0;
}

// AC.