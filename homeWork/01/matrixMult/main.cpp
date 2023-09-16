#include <iostream>
#include <vector>

using namespace std;


void printMatrix(vector<vector<int>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}

void readMatrix(vector<vector<int>>& v, int n, int m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
}

void multMatrix(vector<vector<int>>& v1, vector<vector<int>>& v2,
    vector<vector<int>>& res) {

    for (size_t i = 0; i < v1.size(); ++i) {
        for (size_t j = 0; j < v2[0].size(); ++j) {
            res[i][j] = 0;
            for (size_t k = 0; k < v2.size(); ++k) {
                res[i][j] += v1[i][k] * v2[k][j];
            }
        }
    }
}

void func() {
    int a, b;
    int n, m, l;

    std::cin >> n >> m >> l;
    vector<vector<int>> v1(n);
    readMatrix(v1, n, m);

    vector<vector<int>> v2(m);
    readMatrix(v2, m, l);

    vector<vector<int>> v3(n);
    for (size_t i = 0; i < n; i++)
        v3[i] = vector<int>(l);

    multMatrix(v1, v2, v3);

    printMatrix(v3);
}

int main() {
    func();
    //execDynamic();
    return 0;
}
