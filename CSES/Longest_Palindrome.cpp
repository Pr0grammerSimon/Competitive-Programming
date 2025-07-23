#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    string s2;
    s2.push_back('!');
    s2.push_back('#');
    for (char c : s) {
        s2.push_back(c);
        s2.push_back('#');
    }
    s2.push_back('&');


    int n = s2.size();
    vector<int> results(n, 0);

    int left = 0, right = 0;

    int pos_result = 2;

    for (int i = 1; i < n; i++) {
        int mirror = left + (right - i);
        int act_result = min(right - i, results[mirror]);

        while (s2[i + act_result + 1] == s2[i - act_result - 1]) act_result++;
        results[i] = act_result;

        if (i + results[i] > right) {
            left = i - results[i];
            right = i + results[i];
        }

        if (results[i] > results[pos_result]) pos_result = i;
    }

    int l = pos_result - results[pos_result];
    int r = pos_result + results[pos_result];

    for (int i = l; i <= r; i++) {
        if (s2[i] != '#') cout << s2[i];
    }

    return 0;
}