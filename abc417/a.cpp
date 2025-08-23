#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    S.erase(S.begin(), S.begin() + A);
    S.erase(S.end()-B, S.end());
    cout << S << endl;
}