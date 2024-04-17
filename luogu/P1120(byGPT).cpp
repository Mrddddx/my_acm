#include <bits/stdc++.h>
using namespace std;

bool dfs(int index, int num, int target, vector<int>& sticks) {
    if (index == sticks.size()) return true;
    if (target == 0) return dfs(index + 1, 0, sticks[0], sticks);
    
    for (int j = num; j < sticks.size(); ++j) {
        if (sticks[j] <= target) {
            int temp = sticks[j];
            sticks.erase(sticks.begin() + j);
            if (dfs(index, j, target - temp, sticks)) return true;
            sticks.insert(sticks.begin() + j, temp);
            if (target == temp || target == sticks[0]) break;
            while (j < sticks.size() - 1 && sticks[j] == sticks[j + 1]) ++j;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> sticks(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> sticks[i];
        sum += sticks[i];
    }
    sort(sticks.rbegin(), sticks.rend());

    vector<int> possible_lengths;
    for (int i = sticks[0]; i <= sum; ++i)
        if (sum % i == 0) possible_lengths.push_back(i);
    
    for (int length : possible_lengths) {
        if (dfs(0, 0, length, sticks)) {
            cout << length << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    system("pause");
    return 0;
}

