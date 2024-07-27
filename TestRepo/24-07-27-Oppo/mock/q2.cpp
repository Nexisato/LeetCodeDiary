/**
 * @Description:
 * 小红有一个大小为 2×2 的矩阵，如果对于每一行，第一个数小于第二个数，
 * 对于每一列，第一个数小于第二个数，那么这个矩阵就是美丽的。
 * 现在小红可以对矩阵顺时针旋转，她想知道，经过若干次旋转，能否得到美丽的矩阵。
 */
#include <iostream>
#include <functional>
using namespace std;


int main() {
    int T;
    cin >> T;

    int mat[4] = {0};
    function<bool(int*)> is_beautiful = [&](int *mat) {
        return mat[0] < mat[1] && mat[2] < mat[3] && mat[0] < mat[2] && mat[1] < mat[3];
    };

    for (int _i = 0; _i < T; ++_i) {
        for (int _j = 0; _j < 4; ++_j)
            cin >> mat[_j];
        bool is_success = false;
        for (int _k = 0; _k < 4; ++_k) {
            if (is_beautiful(mat)) {
                is_success = true;
                break;
            }
            swap(mat[0], mat[2]);
            swap(mat[1], mat[2]);
            swap(mat[2], mat[3]);
        }
        cout << (is_success ? "Yes" : "No") << endl;
    }


    return 0;
}