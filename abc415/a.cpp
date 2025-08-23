#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  string S, ans;
  
  cin >> N >> S;
  S.erase(S.begin(), S.end()-3);
  
  if (S == "tea"){
    ans = "Yes"; 
  }
  else ans = "No";
  cout << ans << endl;
  return 0;
}


