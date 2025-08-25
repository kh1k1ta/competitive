#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 完全平方数かどうかを判定
bool is_perfect_square(ll n) {
    if (n < 0) return false;
    ll root = sqrtl(n);
    // 浮動小数点誤差を考慮して前後もチェック
    for (ll r = max(0LL, root - 2); r <= root + 2; r++) {
        if (r * r == n) return true;
    }
    return false;
}

vector<ll> find_n_values(ll X) {
    vector<ll> results;
    set<ll> found; // 重複を避けるため
    
    // より広い範囲でkを探索
    // n² + n + X = k² から、n ≈ k の場合を考慮
    // また、n² + n + X ≈ n² なので k ≈ |n|
    
    // Xが正の場合、k ≥ sqrt(X)程度から始める
    ll k_start = 1;
    if (X > 0) {
        k_start = max(1LL, (ll)sqrtl(X) - 1000);
    }
    
    // 探索範囲を大幅に拡大
    for (ll k = k_start; k <= abs(X) + 100000; k++) {
        ll discriminant = 4LL * k * k - 4LL * X + 1LL;
        
        if (discriminant < 0) continue;
        
        if (is_perfect_square(discriminant)) {
            ll sqrt_d = sqrtl(discriminant);
            
            // 浮動小数点誤差対策でsqrt_dを再確認
            bool found_sqrt = false;
            for (ll sd = max(0LL, sqrt_d - 2); sd <= sqrt_d + 2; sd++) {
                if (sd * sd == discriminant) {
                    sqrt_d = sd;
                    found_sqrt = true;
                    break;
                }
            }
            
            if (!found_sqrt) continue;
            
            // n = (-1 ± √discriminant) / 2
            ll n1 = (-1 + sqrt_d) / 2;
            ll n2 = (-1 - sqrt_d) / 2;
            
            // 整数解かどうかチェック
            if ((-1 + sqrt_d) % 2 == 0) {
                // 検証
                ll check1 = n1 * n1 + n1 + X;
                if (check1 == k * k && found.find(n1) == found.end()) {
                    results.push_back(n1);
                    found.insert(n1);
                }
            }
            
            if ((-1 - sqrt_d) % 2 == 0) {
                // 検証  
                ll check2 = n2 * n2 + n2 + X;
                if (check2 == k * k && found.find(n2) == found.end()) {
                    results.push_back(n2);
                    found.insert(n2);
                }
            }
        }
    }
    
    sort(results.begin(), results.end());
    return results;
}

int main() {
    ll X;
    cin >> X;
    
    vector<ll> n_values = find_n_values(X);
    
    cout << n_values.size() << endl;
    for (size_t i = 0; i < n_values.size(); i++) {
        if (i > 0) cout << " ";
        cout << n_values[i];
    }
    cout << endl;
    
    return 0;
}