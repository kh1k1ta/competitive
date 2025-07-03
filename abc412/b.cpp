/*
まず，Sの条件（先頭でない大文字の直前）に合う文字を集める．
つぎに，それがすべてTに含まれるか調べる．
大文字小文字の判定はASCIIコードで行う
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S, T;
    cin >> S >> T;
    
    // 含まれているか のフラグに変換する
    vector<bool> sflg(0x100);
    vector<bool> tflg(0x100);
    for(int i = 1; i < S.length(); ++i){
        if('A' <= S[i] && S[i] <= 'Z'){ // おれはorとandを間違えがち
            // cout << "S[" << i << "]は大文字でした，その前の文字は:" << S[i-1] << endl; 
            sflg[S[i-1]] = true;
        } 
    }
    
    for(int i = 0; i < T.length(); ++i){
        tflg[T[i]] = true;
    }

    /*
    for(int i = 0; i < 0x100; ++i) cout << sflg[i];
    cout << endl;
    for(int i = 0; i < 0x100; ++i) cout << tflg[i];
    cout << endl;
    */

    // sflgがtflgの部分集合であれば真，そうでなければ偽
    // つまり tflg -> sflg をいえばよい
    for(int i = 0; i < 0x100; ++i){
        if(!sflg[i] || tflg[i]) continue;
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

// 1WA．1WAてどゆことだ? あ! AとZを条件からこぼしていた! おれはよく条件をミスりがちっぽいな...
// AC.