/*
Выпонил Жуков В. Ю.
Группа АВТ-219
*/
#include <iostream>
#include <ctime> 
#include <time.h>

using namespace std;

int main() {
    clock_t start1, end1, start2, end2, startall, endall;
    srand(time(NULL));
    int n = 0;
    double tmp, d;
    cout << "Enter a matrix size:\n";
    cout << "n = ";
    cin >> n;
    startall = clock();
    double** a = new double* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = -100 + (double)rand() / RAND_MAX * (100 - (-100));
            cout.width(10);
            cout << fixed << a[i][j] << " ";
            cout.precision(2);
        }
        cout << endl;
    }
    start1 = clock();
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = -a[i][k] / a[k][k];
            for (int j = 0; j < n; j++) {
                a[i][j] += a[k][j] * tmp;
            }
        }
    }
    end1 = clock();
    double duration1 = ((end1 - start1) / (double)CLOCKS_PER_SEC);

    cout << "\nTarget matrix (Gauss method):\n\n";
    cout.precision(2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(10);
            cout << fixed << a[i][j] << " ";
        }
        cout << "\n";
    }
    start2 = clock();
    d = 1;
    for (int i = 0; i < n; i++) {
        d *= a[i][i];
    }
    end2 = clock();
    double duration2 = ((end2 - start2) / (double)CLOCKS_PER_SEC);

    cout << fixed << "\nMatrix determinant: " << d << "\n";
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    printf("Determinant calculation time = %.10f second(s)\n", (duration2 + duration1));
    endall = clock();
    double durationall = ((endall - startall) / (double)CLOCKS_PER_SEC);
    printf("Total execution time = %.10f second(s) \n", durationall);
    return 0;
}
