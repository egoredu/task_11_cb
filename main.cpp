#include <iostream>
#include <vector>
#include <fstream>
#include<algorithm>
using namespace std;


struct diag{
    int length;
    int sum;
    int maximum;
    int number;
};

bool comp(diag a, diag b){
    // логика сравнения диагоналей
    if (a.length > b.length) return false;
    else if (a.length < b.length) return true;
    else{
        if (a.sum > b.sum) return false;
        else if (a.sum < b.sum) return true;
        else{
            if (a.maximum > b.maximum) return false;
            else if (a.maximum < b.maximum) return true;
        }
    }
    return true; // если доходим, то все 3 параметра равны и порядок не важен
}

int main() {
    int m, n, el;
    vector<vector<int> > matrix;
    vector<int> row;
    char *filename;

    //cout << "Enter the input file path:\n";
    //cin >> filename;
    freopen("input.txt", "r", stdin);
    cin >> m >> n;
    // вводим матрицу
    for (int i = 0; i < m; ++i) {
        row.clear();
        for (int j = 0; j < n; ++j) {
            cin >> el;
            cout << el << ' ';
            row.push_back(el);
        }
        cout << '\n';
        matrix.push_back(row);
    }
    cout << "\n\n";
    struct diag diagonals[n + m - 1]; // каждый элемент – diag, в котором длина диагонали, сумма, максимум, номер
    struct diag d{};
    int maximum, sum;
    vector<int> diagonal_elems;
    for (int k = 0; k < n + m - 1; ++k) {
        diagonal_elems.clear();
        // если сумма индексов константа – элементы относятся к одной диагонали
        // записываем элементы в k-ю диагональ
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (i + j == k) diagonal_elems.push_back(matrix[i][j]);
        // считаем максимум диагонали
        maximum = *max_element(diagonal_elems.begin(), diagonal_elems.end());
        // считаем сумму
        sum = 0;
        for (vector<int>::iterator it = diagonal_elems.begin(); it != diagonal_elems.end(); ++it) sum += *it;
        // записываем
        d.length = diagonal_elems.size();
        d.sum = sum;
        d.maximum = maximum;
        d.number = k + 1;
        diagonals[k] = d;
    }
    // сортируем
    sort(diagonals, diagonals + (n+m-1), comp);
    // выводим
    for (int l = 0; l < n + m - 1; ++l) {
        d = diagonals[l];
        cout << d.number << ") length: " << d.length << ", sum: " << d.sum << ", max: " << d.maximum <<'\n';
    }
}
