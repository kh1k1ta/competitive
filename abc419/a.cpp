#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S, ans;
    cin >> S;
    if(S == "red"){
      ans = "SSS";
    }
    else if(S == "blue"){
      ans = "FFF";
    }
    else if(S == "green"){
      ans = "MMM";
    }
    else{
      ans = "Unknown";
    }

    cout << ans << endl;
    return 0;
}


