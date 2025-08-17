#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, M;
  cin >> N >> M;
  vector<int> L(M), R(M);
  vector<bool> swapped(N);
  string S, T;
  cin >> S >> T;

  for(int i=0; i<M; ++i){
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--; 
  }
  
  for(int i=0; i<N; ++i){
    if(swapped[i] == true) S[i] = T[i];
  }
  cout << S << endl;
  return 0;
}


