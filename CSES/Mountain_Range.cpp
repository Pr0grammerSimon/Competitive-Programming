#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>


using namespace std;
using ll = long long;
using vi = vector<int>;
using vpii = vector<pair<int, int>>;

const int MAXN = 2 * 1e5 + 7;

int left_s[MAXN];
int right_s[MAXN];

const int base = 1 << 18;

int tree[base * 2];

int query(int l, int r) {
    l += base - 1;
    r += base + 1;

    int ans = 0;
    while (l / 2 != r / 2){
        if (l % 2 == 0) ans = max(ans, tree[l + 1]);
        if (r % 2 == 1) ans = max(ans, tree[r - 1]);
        l /= 2;
        r /= 2;
    }

    return ans;
}

void edit(int v, int val) {
    v += base;
    tree[v] = val;
    v /= 2;
    while (v) {
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        v /= 2;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> mono_stack;
    vi tab(n);
    vpii order;

    for (int i = 0; i < n; i++) {
        cin >> tab[i];
        order.push_back({tab[i], i});
    }

    sort(order.begin(), order.end());

    for (int i = 0; i < n; i ++) {
        while (mono_stack.size() && tab[mono_stack.top()] < tab[i]) mono_stack.pop();
        if (mono_stack.size() == 0) left_s[i] = 0;
        else left_s[i] = mono_stack.top() + 1;

        mono_stack.push(i);
    }

    while (mono_stack.size()) mono_stack.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (mono_stack.size() && tab[mono_stack.top()] < tab[i]) mono_stack.pop();
        if (mono_stack.size() == 0) right_s[i] = n - 1;
        else right_s[i] = mono_stack.top() - 1;

        mono_stack.push(i);
    }

    int act_ptr = 0;

    while (act_ptr < n) {
        int act_number = order[act_ptr].first;
        vi pos;

        while (act_ptr < n && order[act_ptr].first == act_number) {
            pos.push_back(order[act_ptr].second);
            act_ptr++;
        }

        vi ans;
        for (int idx : pos) ans.push_back(query(left_s[idx], right_s[idx]) + 1);
        for (int i = 0; i < ans.size(); i++) edit(pos[i], ans[i]); 

    }

    cout << query(0, n - 1) << '\n';

    
    
    return 0;
}