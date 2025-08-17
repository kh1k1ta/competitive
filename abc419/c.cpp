#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void){
  // チェビシェフ距離 max(x, y)を用いる
  int N;
  cin >> N;
  vector<ll> R(N), C(N);
  ll R_max = 0, C_max = 0, R_min = 0x7FFFFFFFFFFFFFFF, C_min = 0x7FFFFFFFFFFFFFFF;
  for(int i=0; i<N; ++i){
    cin >> R[i] >> C[i];
    if(R_max < R[i]) R_max = R[i];
    if(C_max < C[i]) C_max = C[i];
    if(R_min > R[i]) R_min = R[i];
    if(C_min > C[i]) C_min = C[i];
  }
  ll R_dis, C_dis, distance, ans;
  R_dis = R_max - R_min;
  C_dis = C_max - C_min;
  R_dis > C_dis ? distance = R_dis : distance = C_dis;
   
  ans = distance /2 + distance%2;
  cout << ans;
  return 0;
}


