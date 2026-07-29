class Solution {
public:
    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    Matrix power(Matrix M, int exp) {
        int n = M.size();
        Matrix result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) result[i][i] = 1; // identity
        while (exp > 0) {
            if (exp % 2 == 1) result = multiply(result, M);
            M = multiply(M, M);
            exp /= 2;
        }
        return result;
    }

    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        Matrix M = {{1,1,1},{1,0,0},{0,1,0}};
        Matrix Mn = power(M, n-2);

        // initial vector [T2, T1, T0] = [1,1,0]
        long long Tn = Mn[0][0]*1 + Mn[0][1]*1 + Mn[0][2]*0;
        return (int)Tn;
    }
};
