/*
** TASKS TO DO
** ___VECTORS___
** 1. constructors __DONE
** 2. + __DONE
** 3. - __DONE
** 4. dot __DONE
** 5. * int __DONE
** 6. / int __DONE
** 7. cross __DONE
** 8. vector len __DONE
** 9. normalize __DONE
** 10. equals __DONE
** ___MATRICES___
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
        Vec() : data(std::vector<float>()) {}

        template<typename... Args>
        Vec(Args... args) : data(std::vector<float>()) {
            add(args...);
        }

        const float& operator[](int pos) const{
            return data[pos];
        }

        friend Vec operator+(Vec& l, Vec& r) {
            Vec result;
            int min_dimension = std::min(l.length(), r.length());
            for (int i = 0; i < min_dimension; i++) {
                result.add(l[i] + r[i]);
            }
            return result;
        }

        friend Vec operator-(Vec& l, Vec& r) {
            Vec result;
            int min_dimension = std::min(l.length(), r.length());
            for (int i = 0; i < min_dimension; i++) {
                result.add(l[i] - r[i]);
            }
            return result;
        }

        Vec operator*(float num) const {
            Vec result;
            for (int i = 0; i < length(); i++) {
                result.add(data[i] * num);
            }
            return result;
        }

        Vec operator/(float num) const {
            Vec result;
            for (int i = 0; i < length(); i++) {
                result.add(data[i] / num);
            }
            return result;
        }

        const int length() const {
            return data.size();
        }

        const bool operator==(Vec& other) {
            if (this->length() != other.length())
                return false;
            for (int i = 0; i < this->length(); i++) {
                if (data[i] != other[i])
                    return false;
            }
            return true;
        }

        const bool operator!=(Vec& other) {
            return !(*this == other);
        }

        auto begin() {
            return data.begin();
        }

        auto end() {
            return data.end();
        }

     private:
        std::vector<float> data;

        void add(float num) {
            data.push_back(num);
        }

        template<typename... Args>
        void add(float num, Args... args) {
            add(num);
            add(args...);
        }
    };

    //
    const float length(const Vec& vec) {
        float pow2 = 0;
        for (auto el : vec.data) {
            pow2 += el * el;
        }
        return sqrt(pow2);
    }

    //
    const float dot(const Vec& v1, const Vec& v2) {
        float result = 0;
        int min_dimension = std::min(v1.length(), v2.length());
        for (int i = 0; i < min_dimension; i++) {
            result += v1[i] * v2[i];
        }
        return result;
    }

    //
    Vec normalize(const Vec& vec) {
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
    Vec cross(const Vec& a, const Vec& b) {
        float x = a[1] * b[2] - a[2] * b[1];
        float y = a[2] * b[0] - a[0] * b[2];
        float z = a[0] * b[1] - a[1] * b[0];
        return Vec(x, y, z);
    }
}

#endif // namespace cm
