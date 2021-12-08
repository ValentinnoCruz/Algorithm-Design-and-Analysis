

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int len;

void maxtrix(int p[], vector<vector<int>> &m, vector<vector<int>> &s, int len_adj)
{
    for (int i = 1; i < len_adj; i++) {
        m[i][i] = 0;
    }
    for (int l = 2; l < len_adj; l++) {
        for (int i = 1; i < len_adj - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = 10000000;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j]);
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
void print(vector<vector<int>> s, int i, int j) {
    if (i == j) cout << "A" << (i - 1);
    else {
        cout << "(";
        print(s, i, s[i][j]);
        cout << ".";
        print(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    cin >> len;
    int values[len];
    /*Take in Array Values*/
    for (int i = 0; i <= len; i++) {
        cin >> values[i];
    }

    vector<vector<int>> m;
    vector<vector<int>> s;

    m.resize(len+1, std::vector<int>(len+1, 0));
    s.resize(len+1, std::vector<int>(len+1, 0));
    
    maxtrix(values, m, s, len+1);
    cout << m[1][len] << "\n";
    print(s, 1, len);
    cout << "\n";
    return 0;
}