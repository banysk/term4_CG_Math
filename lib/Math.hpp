/*
** TASKS TO DO
** ___VEC___
** 1. constructors __DONE
** 2. + __DONE
** 3. - __DONE
** 4. dot __DONE
** 5. * num __DONE
** 6. / num __DONE
** 7. cross __DONE
** 8. vector len __DONE
** 9. normalize __DONE
** 10. comparisons __DONE
** ___MAT___
** 1. constructors __DONE
** 2. + __DONE
** 3. - __DONE
** 4. * __DONE
** 5. * num __DONE
** 6. / num __DONE
** 7. + num __DONE
** 8. - num __DONE
** 9. * VEC __DONE
** 10. E __DONE
** 11. -1 __DONE
** 12. T __DONE
** 13. comparisons __DONE
** 14. offset __
** 15. rotate __
** 16. scale __
*/

#ifndef CM
#define CM

#include <vector>
#include <algorithm>
#include <cmath>

namespace cm { 
    class Vec {
        friend const float length(const Vec& vec);
        friend Vec normalize(const Vec& vec);

    public:
        Vec() : data(std::vector<float>()) {} // TESTED
        //
        Vec(int dim, float num) : data(std::vector<float>()) {
            for (int i = 0; i < dim; i++) {
                data.push_back(num);
            }
        }
        //
        template<typename... Args>
        Vec(Args... args) : data(std::vector<float>()) { // TESTED
            add(args...);
        }
        //
        float& operator[](int pos) { // TESTED
            return data[pos];
        }
        //
        friend Vec operator+(Vec& l, Vec& r) { // TESTED
            Vec result;
            int min_dimension = std::min(l.length(), r.length());
            for (int i = 0; i < min_dimension; i++) {
                result.add(l[i] + r[i]);
            }
            return result;
        }
        //
        friend Vec operator-(Vec& l, Vec& r) { // TESTED
            Vec result;
            int min_dimension = std::min(l.length(), r.length());
            for (int i = 0; i < min_dimension; i++) {
                result.add(l[i] - r[i]);
            }
            return result;
        }
        //
        Vec operator*(float num) const { // TESTED
            Vec result;
            for (int i = 0; i < length(); i++) {
                result.add(data[i] * num);
            }
            return result;
        }
        //
        Vec operator/(float num) const { // TESTED
            Vec result;
            for (int i = 0; i < length(); i++) {
                result.add(data[i] / num);
            }
            return result;
        }
        //
        const bool operator==(Vec& other) { // TESTED
            if (this->length() != other.length())
                return false;
            for (int i = 0; i < this->length(); i++) {
                if (data[i] != other[i])
                    return false;
            }
            return true;
        }
        //
        const bool operator!=(Vec& other) { // TESTED
            return !(*this == other);
        }
        //
        const int length() const { // TESTED
            return data.size();
        }

    private:
        std::vector<float> data;
        //
        void add(float num) { // TESTED
            data.push_back(num);
        }
        //
        template<typename... Args>
        void add(float num, Args... args) { // TESTED
            add(num);
            add(args...);
        }
    };
    //
    const float length(const Vec& vec) { // TESTED
        float pow2 = 0;
        for (auto el : vec.data) {
            pow2 += el * el;
        }
        return sqrt(pow2);
    }
    //
    const float dot(Vec& v1, Vec& v2) { // TESTED
        float result = 0;
        int min_dimension = std::min(v1.length(), v2.length());
        for (int i = 0; i < min_dimension; i++) {
            result += v1[i] * v2[i];
        }
        return result;
    }
    //
    Vec normalize(const Vec& vec) { // TESTED
        float len = length(vec);
        Vec result;
        if (len != 0) {
            for (auto el : vec.data) {
                result.add(el / len);
            }
        }
        return result;
    }
    //
    // 0 1 2
    // x y z
    Vec cross(Vec& a, Vec& b) { // TESTED
        float x = a[1] * b[2] - a[2] * b[1];
        float y = a[2] * b[0] - a[0] * b[2];
        float z = a[0] * b[1] - a[1] * b[0];
        return Vec(x, y, z);
    }

    class Mat {
     public:
         Mat() : data(std::vector<std::vector<float>>()) {}
         //
         Mat(int dim) : data(std::vector<std::vector<float>>()) {
             for (int i = 0; i < dim; i++) {
                 data.push_back(std::vector<float>(dim, 0.0f));
             }
         }
         //
         template<typename... Args>
         Mat(std::initializer_list<std::initializer_list<float>> list) : data(std::vector<std::vector<float>>()) {
             for (auto line : list) {
                 std::vector<float> buf = std::vector<float>();
                 for (auto num : line) {
                     buf.push_back(num);
                 }
                 data.push_back(buf);
             }
         }
         //
         std::vector<float>& operator[](int pos) { // TESTED
             return data[pos];
         }
         //
         friend Mat operator+(Mat& l, Mat& r) { // TESTED
             int min_dimension = std::min(l.dim(), r.dim());
             Mat result(min_dimension);
             for (int i = 0; i < min_dimension; i++) {
                 for (int j = 0; j < min_dimension; j++) {
                     result[i][j] = l[i][j] + r[i][j];
                 }
             }
             return result;
         }
         //
         friend Mat operator-(Mat& l, Mat& r) { // TESTED
             int min_dimension = std::min(l.dim(), r.dim());
             Mat result(min_dimension);
             for (int i = 0; i < min_dimension; i++) {
                 for (int j = 0; j < min_dimension; j++) {
                     result[i][j] = l[i][j] - r[i][j];
                 }
             }
             return result;
         }
         //
         friend Mat operator*(Mat& l, Mat& r) { // TESTED
             int min_dimension = std::min(l.dim(), r.dim());
             Mat result(min_dimension);
             for (int i = 0; i < min_dimension; i++) {
                 for (int j = 0; j < min_dimension; j++) {
                     for (int k = 0; k < min_dimension; k++) {
                         result[i][j] += r[i][k] * l[k][j];
                     }
                 }
             }
             return result;
         }
         //
         friend Mat operator*(Mat& l, float num) {
             int min_dimension = l.dim();
             Mat result(min_dimension);
             for (int i = 0; i < min_dimension; i++) {
                 for (int j = 0; j < min_dimension; j++) {
                     result[i][j] = l[i][j] * num;
                 }
             }
             return result;
         }
         //
         friend Mat operator/(Mat& l, float num) {
             int min_dimension = l.dim();
             Mat result(min_dimension);
             for (int i = 0; i < min_dimension; i++) {
                 for (int j = 0; j < min_dimension; j++) {
                     result[i][j] = l[i][j] / num;
                 }
             }
             return result;
         }
         //
         friend Mat operator+(Mat& l, float num) {
             int min_dimension = l.dim();
             Mat result(min_dimension);
             for (int i = 0; i < min_dimension; i++) {
                 for (int j = 0; j < min_dimension; j++) {
                     result[i][j] = l[i][j] + num;
                 }
             }
             return result;
         }
         //
         friend Mat operator-(Mat& l, float num) {
             int min_dimension = l.dim();
             Mat result(min_dimension);
             for (int i = 0; i < min_dimension; i++) {
                 for (int j = 0; j < min_dimension; j++) {
                     result[i][j] = l[i][j] - num;
                 }
             }
             return result;
         }
         //
         friend Vec operator*(Mat& l, Vec& v) {
             int min_dimension = l.dim();
             Vec result(min_dimension, 0.0f);
             for (int row = 0; row < min_dimension; row++){
                 for (int col = 0; col < min_dimension; col++) {
                     result[col] += v[row] * l[row][col];
                 }
             }
             return result;
         }
         //
         const bool operator==(Mat& other) { // TESTED
             if (this->dim() != other.dim())
                 return false;
             for (int i = 0; i < this->dim(); i++) {
                 for (int j = 0; j < this->dim(); j++) {
                     if (data[i][j] != other[i][j])
                         return false;
                 }
             }
             return true;
         }
         //
         const bool operator!=(Mat& other) { // TESTED
             return !(*this == other);
         }
         //
         const int dim() {
             return data.size();
         }

     private:
        std::vector<std::vector<float>> data;
    };

    Mat identity(int dim) {
        Mat result(dim);
        for (int i = 0; i < dim; i++) {
            result[i][i] = 1.0f;
        }
        return result;
    }

    Mat transpose(Mat& mat) {
        int dim = mat.dim();
        Mat result(dim);
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                result[i][j] = mat[j][i];
            }
        }
        return result;
    }

    int sign(int i) {
        int sgn;
        i % 2 == 0 ? sgn = 1 : sgn = -1;
        return sgn;
    }

    Mat sub(Mat& mat, int ex_row, int ex_col) {
        int dim = mat.dim();
        Mat result(dim - 1);
        int r = 0;
        for (int row = 0; row < dim; row++) {
            if (row == ex_row)
                continue;
            int c = 0;
            for (int col = 0; col < dim; col++) {
                if (col == ex_col)
                    continue;
                result[r][c] = mat[row][col];
                c++;
            }
            r++;
        }
        return result;
    }

    float det(Mat& mat) {
        if (mat.dim() == 1)
            return mat[0][0];
        if (mat.dim() == 2)
            return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
        int dim = mat.dim();
        float result = 0;
        for (int i = 0; i < dim; i++) {
            result += sign(i) * mat[0][i] * det(sub(mat, 0, i));
        }
        return result;
    }

    Mat ac(Mat& mat) {
        int dim = mat.dim();
        Mat result(dim);
        for (int row = 0; row < dim; row++) {
            for (int col = 0; col < dim; col++) {
                result[row][col] = sign(row) * sign(col) * det(sub(mat, row, col));
            }
        }
        return result;
    }

    Mat inverse(Mat& mat) {
        return transpose(ac(mat) * float(1.0f / det(mat)));
    }
}

#endif // namespace cm
