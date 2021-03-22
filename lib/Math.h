#ifndef CM
#define CM
#include <vector>

namespace cm {
    // Vector
    class Vec {
        friend const float length(const Vec& vec);
        friend Vec normalize(const Vec& vec);

    public:
        Vec();

        Vec(int dim, float num);

        template<typename... Args>
        Vec(Args... args) : data(std::vector<float>()) {
            add(args...);
        }

        float& operator[](int pos);

        friend Vec operator+(Vec& l, Vec& r);

        friend Vec operator-(Vec& l, Vec& r);

        Vec operator*(float num) const;

        Vec operator/(float num) const;

        const bool operator==(Vec& other);

        const bool operator!=(Vec& other);

        const int length() const;

    //private:
        std::vector<float> data;

        void add(float num);

        template<typename... Args>
        void add(float num, Args... args) {
            add(num);
            add(args...);
        }
    };
    const float length(const Vec& vec);

    const float dot(Vec& v1, Vec& v2);

    Vec normalize(const Vec& vec);

    Vec cross(Vec& a, Vec& b);

    // Matrix
    class Mat {
    public:
        Mat();

        Mat(int dim);

        template<typename... Args>
        Mat(std::initializer_list<std::initializer_list<float>> list);

        std::vector<float>& operator[](int pos);

        friend Mat operator+(Mat& l, Mat& r);

        friend Mat operator-(Mat& l, Mat& r);

        friend Mat operator*(Mat& l, Mat& r);

        friend Mat operator*(Mat& l, float num);

        friend Mat operator/(Mat& l, float num);

        friend Mat operator+(Mat& l, float num);

        friend Mat operator-(Mat& l, float num);

        friend Vec operator*(Mat& l, Vec& v);

        const bool operator==(Mat& other);

        const bool operator!=(Mat& other);

        const int dim();

    private:
        std::vector<std::vector<float>> data;
    };

    Mat identity(int dim);

    Mat transpose(Mat& mat);

    int sign(int i);

    Mat sub(Mat& mat, int ex_row, int ex_col);

    float det(Mat& mat);

    Mat ac(Mat& mat);

    Mat inverse(Mat& mat);

    Mat translate(Mat& mat, Vec& vec);

    Mat scale(Mat& mat, Vec& vec);

    Mat rotateX(float deg);

    Mat rotateY(float deg);

    Mat rotateZ(float deg);
}

#endif // namespace cm
