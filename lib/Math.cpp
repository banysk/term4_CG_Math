#include "Math.h"

cm::Vec::Vec() : data(std::vector<float>()) {}

cm::Vec::Vec(int dim, float num) : data(std::vector<float>()) {
    for (int i = 0; i < dim; i++) {
        data.push_back(num);
    }
}

float& cm::Vec::operator[](int pos) {
    return data[pos];
}

cm::Vec cm::operator+(Vec& l, Vec& r) {
    Vec result;
    int min_dimension = std::min(l.length(), r.length());
    for (int i = 0; i < min_dimension; i++) {
        result.add(l[i] + r[i]);
    }
    return result;
}

cm::Vec cm::operator-(Vec& l, Vec& r) {
    Vec result;
    int min_dimension = std::min(l.length(), r.length());
    for (int i = 0; i < min_dimension; i++) {
        result.add(l[i] - r[i]);
    }
    return result;
}

cm::Vec cm::Vec::operator*(float num) const {
    Vec result;
    for (int i = 0; i < length(); i++) {
        result.add(data[i] * num);
    }
    return result;
}

cm::Vec cm::Vec::operator/(float num) const {
    Vec result;
    for (int i = 0; i < length(); i++) {
        result.add(data[i] / num);
    }
    return result;
}

const bool cm::Vec::operator==(Vec& other) {
    if (this->length() != other.length())
        return false;
    for (int i = 0; i < this->length(); i++) {
        if (data[i] != other[i])
            return false;
    }
    return true;
}

const int cm::Vec::length() const {
    return data.size();
}

const bool cm::Vec::operator!=(Vec& other) {
    return !(*this == other);
}

void cm::Vec::add(float num) {
    data.push_back(num);
}

const float cm::length(const Vec& vec) {
    float pow2 = 0;
    for (auto el : vec.data) {
        pow2 += el * el;
    }
    return sqrt(pow2);
}

const float cm::dot(Vec& v1, Vec& v2) {
    float result = 0;
    int min_dimension = std::min(v1.length(), v2.length());
    for (int i = 0; i < min_dimension; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

cm::Vec cm::normalize(const Vec& vec) {
    float len = length(vec);
    Vec result;
    if (len != 0) {
        for (auto el : vec.data) {
            result.add(el / len);
        }
    }
    return result;
}

cm::Vec cm::cross(Vec& a, Vec& b) {
    float x = a[1] * b[2] - a[2] * b[1];
    float y = a[2] * b[0] - a[0] * b[2];
    float z = a[0] * b[1] - a[1] * b[0];
    return Vec(x, y, z);
}

cm::Mat::Mat() : data(std::vector<std::vector<float>>()) {}

cm::Mat::Mat(int dim) : data(std::vector<std::vector<float>>()) {
    for (int i = 0; i < dim; i++) {
        data.push_back(std::vector<float>(dim, 0.0f));
    }
}

template<typename... Args>
cm::Mat::Mat(std::initializer_list<std::initializer_list<float>> list) : data(std::vector<std::vector<float>>()) {
    for (auto line : list) {
        std::vector<float> buf = std::vector<float>();
        for (auto num : line) {
            buf.push_back(num);
        }
        data.push_back(buf);
    }
}

std::vector<float>& cm::Mat::operator[](int pos) {
    return data[pos];
}

cm::Mat cm::operator+(Mat& l, Mat& r) {
    int min_dimension = std::min(l.dim(), r.dim());
    Mat result(min_dimension);
    for (int i = 0; i < min_dimension; i++) {
        for (int j = 0; j < min_dimension; j++) {
            result[i][j] = l[i][j] + r[i][j];
        }
    }
    return result;
}

cm::Mat cm::operator-(Mat& l, Mat& r) {
    int min_dimension = std::min(l.dim(), r.dim());
    Mat result(min_dimension);
    for (int i = 0; i < min_dimension; i++) {
        for (int j = 0; j < min_dimension; j++) {
            result[i][j] = l[i][j] - r[i][j];
        }
    }
    return result;
}

cm::Mat cm::operator*(Mat& l, Mat& r) {
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

cm::Mat cm::operator*(Mat& l, float num) {
    int min_dimension = l.dim();
    Mat result(min_dimension);
    for (int i = 0; i < min_dimension; i++) {
        for (int j = 0; j < min_dimension; j++) {
            result[i][j] = l[i][j] * num;
        }
    }
    return result;
}

cm::Mat cm::operator/(Mat& l, float num) {
    int min_dimension = l.dim();
    Mat result(min_dimension);
    for (int i = 0; i < min_dimension; i++) {
        for (int j = 0; j < min_dimension; j++) {
            result[i][j] = l[i][j] / num;
        }
    }
    return result;
}

cm::Mat cm::operator+(Mat& l, float num) {
    int min_dimension = l.dim();
    Mat result(min_dimension);
    for (int i = 0; i < min_dimension; i++) {
        for (int j = 0; j < min_dimension; j++) {
            result[i][j] = l[i][j] + num;
        }
    }
    return result;
}

cm::Mat cm::operator-(Mat& l, float num) {
    int min_dimension = l.dim();
    Mat result(min_dimension);
    for (int i = 0; i < min_dimension; i++) {
        for (int j = 0; j < min_dimension; j++) {
            result[i][j] = l[i][j] - num;
        }
    }
    return result;
}

cm::Vec cm::operator*(Mat& l, Vec& v) {
    int min_dimension = l.dim();
    Vec result(min_dimension, 0.0f);
    for (int row = 0; row < min_dimension; row++) {
        for (int col = 0; col < min_dimension; col++) {
            result[col] += v[row] * l[row][col];
        }
    }
    return result;
}

const bool cm::Mat::operator==(Mat& other) {
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

const bool cm::Mat::operator!=(Mat& other) {
    return !(*this == other);
}

const int cm::Mat::dim() {
    return data.size();
}

cm::Mat cm::identity(int dim) {
    Mat result(dim);
    for (int i = 0; i < dim; i++) {
        result[i][i] = 1.0f;
    }
    return result;
}

cm::Mat cm::transpose(Mat& mat) {
    int dim = mat.dim();
    Mat result(dim);
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            result[i][j] = mat[j][i];
        }
    }
    return result;
}

int cm::sign(int i) {
    int sgn;
    i % 2 == 0 ? sgn = 1 : sgn = -1;
    return sgn;
}

cm::Mat cm::sub(Mat& mat, int ex_row, int ex_col) {
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

float cm::det(Mat& mat) {
    if (mat.dim() == 1)
        return mat[0][0];
    if (mat.dim() == 2)
        return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
    int dim = mat.dim();
    float result = 0;
    for (int i = 0; i < dim; i++) {
        auto buf = sub(mat, 0, i);
        result += sign(i) * mat[0][i] * det(buf);
    }
    return result;
}

cm::Mat cm::ac(Mat& mat) {
    int dim = mat.dim();
    Mat result(dim);
    for (int row = 0; row < dim; row++) {
        for (int col = 0; col < dim; col++) {
            auto buf = sub(mat, row, col);
            result[row][col] = sign(row) * sign(col) * det(buf);
        }
    }
    return result;
}

cm::Mat cm::inverse(Mat& mat) {
    Mat buf = ac(mat);
    float d = float(1.0f / det(mat));
    buf = buf * d;
    return transpose(buf);
}

cm::Mat cm::translate(Mat& mat, Vec& vec) {
    Mat result = mat;
    result[3][0] = vec[0];
    result[3][1] = vec[1];
    result[3][2] = vec[2];
    return result;
}

cm::Mat cm::scale(Mat& mat, Vec& vec) {
    Mat result = mat;
    result[0][0] = vec[0];
    result[1][1] = vec[1];
    result[2][2] = vec[2];
    return result;
}

cm::Mat cm::rotateX(float deg) {
    Mat result = cm::identity(4);
    result[1][1] = cos(deg);
    result[1][2] = -sin(deg);
    result[2][1] = sin(deg);
    result[2][2] = cos(deg);
    return result;
}

cm::Mat cm::rotateY(float deg) {
    Mat result = cm::identity(4);
    result[0][0] = cos(deg);
    result[0][2] = sin(deg);
    result[2][0] = -sin(deg);
    result[2][2] = cos(deg);
    return result;
}

cm::Mat cm::rotateZ(float deg) {
    Mat result = cm::identity(4);
    result[0][0] = cos(deg);
    result[0][1] = -sin(deg);
    result[1][0] = sin(deg);
    result[1][1] = cos(deg);
    return result;
}
