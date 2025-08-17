#include <bits/stdc++.h>
using namespace std;

int main(void){
  int Q;
  cin >> Q;
  vector<int> isin(101);
  for(int i=0; i<Q; ++i){
    int type;
    cin >> type;
    if(type == 1){
      int x;
      cin >> x;
      isin[x]++;
    }
    else{
      for(int i=0; i<101; ++i){
        if(isin[i] != 0){
          isin[i]--;
          cout << i << endl;
          break;
        }
      }
    }
  }
  
  return 0;
}


