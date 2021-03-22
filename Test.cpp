#include "pch.h"
#include "CppUnitTest.h"
#include "lib/Math.hpp"
#include "glm/glm.hpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CG_MATH
{
    // Functions 1
    bool CheckOperation(glm::vec2 glmv, cm::Vec cmv) {
        for (int i = 0; i < 2; i++) {
            if (glmv[i] != cmv[i])
                return false;
        }
        return true;
    }
    bool CheckOperation(glm::vec3 glmv, cm::Vec cmv) {
        for (int i = 0; i < 3; i++) {
            if (glmv[i] != cmv[i])
                return false;
        }
        return true;
    }
    bool CheckOperation(glm::vec4 glmv, cm::Vec cmv) {
        for (int i = 0; i < 4; i++) {
            if (glmv[i] != cmv[i])
                return false;
        }
        return true;
    }

    // Functions 2
    bool CheckOperation(glm::mat2 glm, cm::Mat cm) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (glm[i][j] != cm[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool CheckOperation(glm::mat3 glm, cm::Mat cm) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                if (glm[i][j] != cm[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool CheckOperation(glm::mat4 glm, cm::Mat cm) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                if (glm[i][j] != cm[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    // Main
    TEST_CLASS(Mat) {
    public:
        TEST_METHOD(Constructor) {
            cm::Mat mat;
            cm::Mat mat1({ {1.0f} }), mat2({ {1.0f, 2.0f}, {3.0f, 4.0f} });
            Assert::AreEqual(mat1[0][0], 1.0f);
            Assert::AreEqual(mat2[0][0], 1.0f);
            Assert::AreEqual(mat2[0][1], 2.0f);
            Assert::AreEqual(mat2[1][0], 3.0f);
            Assert::AreEqual(mat2[1][1], 4.0f);
        }

        TEST_METHOD(Addition) { // TESTED
            glm::mat2 glm2_1(1.0f, 3.0f, 2.0f, 4.0f),
                glm2_2(-1.0f, 1.0f, -1.0f, 1.0f);
            cm::Mat cm2_1({ { 1.0f, 3.0f }, { 2.0f, 4.0f } }),
                cm2_2({ {-1.0f, 1.0f}, {-1.0f, 1.0f} });

            glm::mat3 glm3_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f),
                glm3_2(9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
            cm::Mat cm3_1({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} }),
                cm3_2({ {9.0f, 8.0f, 7.0f}, {6.0f, 5.0f, 4.0f}, {3.0f, 2.0f, 1.0f} });

            glm::mat4 glm4_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f),
                glm4_2(16.0f, 15.0f, 14.0f, 13.0f, 12.0f, 11.0f, 10.0f, 9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
            cm::Mat cm4_1({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} }),
                cm4_2({ {16.0f, 15.0f, 14.0f, 13.0f},{12.0f, 11.0f, 10.0f, 9.0f},{8.0f, 7.0f, 6.0f, 5.0f},{4.0f, 3.0f, 2.0f, 1.0f} });


            Assert::IsTrue(CheckOperation(glm2_1 + glm2_2, cm2_1 + cm2_2));
            Assert::IsTrue(CheckOperation(glm3_1 + glm3_2, cm3_1 + cm3_2));
            Assert::IsTrue(CheckOperation(glm4_1 + glm4_2, cm4_1 + cm4_2));
        }

        TEST_METHOD(Subtraction) { // TESTED
            glm::mat2 glm2_1(1.0f, 3.0f, 2.0f, 4.0f),
                glm2_2(-1.0f, 1.0f, -1.0f, 1.0f);
            cm::Mat cm2_1({ { 1.0f, 3.0f }, { 2.0f, 4.0f } }),
                cm2_2({ {-1.0f, 1.0f}, {-1.0f, 1.0f} });

            glm::mat3 glm3_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f),
                glm3_2(9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
            cm::Mat cm3_1({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} }),
                cm3_2({ {9.0f, 8.0f, 7.0f}, {6.0f, 5.0f, 4.0f}, {3.0f, 2.0f, 1.0f} });

            glm::mat4 glm4_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f),
                glm4_2(16.0f, 15.0f, 14.0f, 13.0f, 12.0f, 11.0f, 10.0f, 9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
            cm::Mat cm4_1({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} }),
                cm4_2({ {16.0f, 15.0f, 14.0f, 13.0f},{12.0f, 11.0f, 10.0f, 9.0f},{8.0f, 7.0f, 6.0f, 5.0f},{4.0f, 3.0f, 2.0f, 1.0f} });


            Assert::IsTrue(CheckOperation(glm2_1 - glm2_2, cm2_1 - cm2_2));
            Assert::IsTrue(CheckOperation(glm3_1 - glm3_2, cm3_1 - cm3_2));
            Assert::IsTrue(CheckOperation(glm4_1 - glm4_2, cm4_1 - cm4_2));
        }

        TEST_METHOD(Multiplication) { // TESTED
            glm::mat2 glm2_1(1.0f, 3.0f, 2.0f, 4.0f),
                glm2_2(-1.0f, 1.0f, -1.0f, 1.0f);
            cm::Mat cm2_1({ { 1.0f, 3.0f }, { 2.0f, 4.0f } }),
                cm2_2({ {-1.0f, 1.0f}, {-1.0f, 1.0f} });

            glm::mat3 glm3_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f),
                glm3_2(9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
            cm::Mat cm3_1({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} }),
                cm3_2({ {9.0f, 8.0f, 7.0f}, {6.0f, 5.0f, 4.0f}, {3.0f, 2.0f, 1.0f} });

            glm::mat4 glm4_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f),
                glm4_2(16.0f, 15.0f, 14.0f, 13.0f, 12.0f, 11.0f, 10.0f, 9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
            cm::Mat cm4_1({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} }),
                cm4_2({ {16.0f, 15.0f, 14.0f, 13.0f},{12.0f, 11.0f, 10.0f, 9.0f},{8.0f, 7.0f, 6.0f, 5.0f},{4.0f, 3.0f, 2.0f, 1.0f} });


            Assert::IsTrue(CheckOperation(glm2_1 * glm2_2, cm2_1 * cm2_2));
            Assert::IsTrue(CheckOperation(glm3_1 * glm3_2, cm3_1 * cm3_2));
            Assert::IsTrue(CheckOperation(glm4_1 * glm4_2, cm4_1 * cm4_2));
        }

        TEST_METHOD(MultiplicationByNum) { // TESTED
            glm::mat2 glm2_1(1.0f, 3.0f, 2.0f, 4.0f);
            cm::Mat cm2_1({ { 1.0f, 3.0f }, { 2.0f, 4.0f } });

            glm::mat3 glm3_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
            cm::Mat cm3_1({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} });

            glm::mat4 glm4_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
            cm::Mat cm4_1({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} });


            Assert::IsTrue(CheckOperation(glm2_1 * 2.0f, cm2_1 * 2.0f));
            Assert::IsTrue(CheckOperation(glm3_1 * 3.0f, cm3_1 * 3.0f));
            Assert::IsTrue(CheckOperation(glm4_1 * 4.0f, cm4_1 * 4.0f));
        }

        TEST_METHOD(DivisionByNum) { // TESTED
            glm::mat2 glm2_1(1.0f, 3.0f, 2.0f, 4.0f);
            cm::Mat cm2_1({ { 1.0f, 3.0f }, { 2.0f, 4.0f } });

            glm::mat3 glm3_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
            cm::Mat cm3_1({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} });

            glm::mat4 glm4_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
            cm::Mat cm4_1({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} });


            Assert::IsTrue(CheckOperation(glm2_1 / 2.0f, cm2_1 / 2.0f));
            Assert::IsTrue(CheckOperation(glm3_1 / 3.0f, cm3_1 / 3.0f));
            Assert::IsTrue(CheckOperation(glm4_1 / 4.0f, cm4_1 / 4.0f));
        }

        TEST_METHOD(AddNum) { // TESTED
            glm::mat2 glm2_1(1.0f, 3.0f, 2.0f, 4.0f);
            cm::Mat cm2_1({ { 1.0f, 3.0f }, { 2.0f, 4.0f } });

            glm::mat3 glm3_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
            cm::Mat cm3_1({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} });

            glm::mat4 glm4_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
            cm::Mat cm4_1({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} });


            Assert::IsTrue(CheckOperation(glm2_1 + 2.0f, cm2_1 + 2.0f));
            Assert::IsTrue(CheckOperation(glm3_1 + 3.0f, cm3_1 + 3.0f));
            Assert::IsTrue(CheckOperation(glm4_1 + 4.0f, cm4_1 + 4.0f));
        }

        TEST_METHOD(SubtractNum) { // TESTED
            glm::mat2 glm2_1(1.0f, 3.0f, 2.0f, 4.0f);
            cm::Mat cm2_1({ { 1.0f, 3.0f }, { 2.0f, 4.0f } });

            glm::mat3 glm3_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
            cm::Mat cm3_1({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} });

            glm::mat4 glm4_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
            cm::Mat cm4_1({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} });


            Assert::IsTrue(CheckOperation(glm2_1 - 2.0f, cm2_1 - 2.0f));
            Assert::IsTrue(CheckOperation(glm3_1 - 3.0f, cm3_1 - 3.0f));
            Assert::IsTrue(CheckOperation(glm4_1 - 4.0f, cm4_1 - 4.0f));
        }

        TEST_METHOD(MultiplicationByVec) { // TESTED
            glm::mat2 glm2m(1.0f, 3.0f, 2.0f, 4.0f);
            cm::Mat cm2m({ { 1.0f, 3.0f }, { 2.0f, 4.0f } });

            glm::mat3 glm3m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
            cm::Mat cm3m({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} });

            glm::mat4 glm4m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
            cm::Mat cm4m({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} });

            glm::vec2 glm2v(0.0f, 1.0f);
            glm::vec3 glm3v(0.0f, 1.0f, 2.0f);
            glm::vec4 glm4v(0.0f, 1.0f, 2.0f, 3.0f);

            cm::Vec cm2v(0.0f, 1.0f);
            cm::Vec cm3v(0.0f, 1.0f, 2.0f);
            cm::Vec cm4v(0.0f, 1.0f, 2.0f, 3.0f);

            Assert::IsTrue(CheckOperation(glm2m * glm2v, cm2m * cm2v));
            Assert::IsTrue(CheckOperation(glm3m * glm3v, cm3m * cm3v));
            Assert::IsTrue(CheckOperation(glm4m * glm4v, cm4m * cm4v));
        }

        TEST_METHOD(IdentityMatrix) { // TESTED
            Assert::IsTrue(CheckOperation(glm::mat2(1.0f), cm::identity(2)));
            Assert::IsTrue(CheckOperation(glm::mat3(1.0f), cm::identity(3)));
            Assert::IsTrue(CheckOperation(glm::mat4(1.0f), cm::identity(4)));
        }

        TEST_METHOD(Det) { // TESTED
            glm::mat2 glm2m(1.0f, 3.0f, 2.0f, 4.0f);
            cm::Mat cm2m({ { 1.0f, 3.0f }, { 2.0f, 4.0f } });

            glm::mat3 glm3m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
            cm::Mat cm3m({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} });

            glm::mat4 glm4m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
            cm::Mat cm4m({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} });

            Assert::AreEqual(glm::determinant(glm2m), cm::det(cm2m));
            Assert::AreEqual(glm::determinant(glm3m), cm::det(cm3m));
            Assert::AreEqual(glm::determinant(glm4m), cm::det(cm4m));
        }

        TEST_METHOD(Inverse) { // TESTED
            glm::mat2 glm2m(1.0f, 3.0f, 2.0f, 4.0f);
            cm::Mat cm2m({ { 1.0f, 3.0f }, { 2.0f, 4.0f } });

            glm::mat3 glm3m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
            cm::Mat cm3m({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} });

            glm::mat4 glm4m(0.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 17.0f);
            cm::Mat cm4m({ {0.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 17.0f} });

            Assert::IsTrue(CheckOperation(glm::inverse(glm2m), cm::inverse(cm2m)));
            Assert::IsTrue(CheckOperation(glm::inverse(glm3m), cm::inverse(cm3m)));
            Assert::IsTrue(CheckOperation(glm::inverse(glm4m), cm::inverse(cm4m)));
        }

        TEST_METHOD(TransposedMatrix) { // TESTED
            glm::mat2 glm2m(1.0f, 3.0f, 2.0f, 4.0f);
            cm::Mat cm2m({ { 1.0f, 3.0f }, { 2.0f, 4.0f } });

            glm::mat3 glm3m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
            cm::Mat cm3m({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} });

            glm::mat4 glm4m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
            cm::Mat cm4m({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} });

            Assert::IsTrue(CheckOperation(glm::transpose(glm2m), cm::transpose(cm2m)));
            Assert::IsTrue(CheckOperation(glm::transpose(glm3m), cm::transpose(cm3m)));
            Assert::IsTrue(CheckOperation(glm::transpose(glm4m), cm::transpose(cm4m)));
        }

        TEST_METHOD(Comparisons) { // TESTED
            glm::mat2 glm2_1(1.0f, 3.0f, 2.0f, 4.0f),
                glm2_2(-1.0f, 1.0f, -1.0f, 1.0f);
            cm::Mat cm2_1({ { 1.0f, 3.0f }, { 2.0f, 4.0f } }),
                cm2_2({ {-1.0f, 1.0f}, {-1.0f, 1.0f} });

            glm::mat3 glm3_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f),
                glm3_2(9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
            cm::Mat cm3_1({ { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, {7.0f, 8.0f, 9.0f} }),
                cm3_2({ {9.0f, 8.0f, 7.0f}, {6.0f, 5.0f, 4.0f}, {3.0f, 2.0f, 1.0f} });

            glm::mat4 glm4_1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f),
                glm4_2(16.0f, 15.0f, 14.0f, 13.0f, 12.0f, 11.0f, 10.0f, 9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
            cm::Mat cm4_1({ {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f},{9.0f, 10.0f, 11.0f, 12.0f},{13.0f, 14.0f, 15.0f, 16.0f} }),
                cm4_2({ {16.0f, 15.0f, 14.0f, 13.0f},{12.0f, 11.0f, 10.0f, 9.0f},{8.0f, 7.0f, 6.0f, 5.0f},{4.0f, 3.0f, 2.0f, 1.0f} });

            Assert::AreEqual(glm2_1 != glm2_2, cm2_1 != cm2_2);
            Assert::AreEqual(glm3_1 != glm3_2, cm3_1 != cm3_2);
            Assert::AreEqual(glm4_1 != glm4_2, cm4_1 != cm4_2);

            Assert::AreEqual(!(glm2_1 != glm2_2), !(cm2_1 != cm2_2));
            Assert::AreEqual(!(glm3_1 != glm3_2), !(cm3_1 != cm3_2));
            Assert::AreEqual(!(glm4_1 != glm4_2), !(cm4_1 != cm4_2));
        }

        TEST_METHOD(Sub) { // TESTED
            
        }

    };
    
    TEST_CLASS(Vec)
    {
    public:
        TEST_METHOD(Constructor) // TESTED
        {
            cm::Vec cm;
            cm::Vec cm2(0.0f, 1.0f), cm3(0.0f, 1.0f, 2.0f), cm4(0.0f, 1.0f, 2.0f, 3.0f);
        }

        TEST_METHOD(Addition) { // TESTED
            glm::vec2 glm2_1(0.0f, 1.0f), glm2_2(1.0f, 0.0f);
            glm::vec3 glm3_1(0.0f, 1.0f, 2.0f), glm3_2(2.0f, 1.0f, 0.0f);
            glm::vec4 glm4_1(0.0f, 1.0f, 2.0f, 3.0f), glm4_2(3.0f, 2.0f, 1.0f, 0.0f);

            cm::Vec cm2_1(0.0f, 1.0f), cm2_2(1.0f, 0.0f);
            cm::Vec cm3_1(0.0f, 1.0f, 2.0f), cm3_2(2.0f, 1.0f, 0.0f);
            cm::Vec cm4_1(0.0f, 1.0f, 2.0f, 3.0f), cm4_2(3.0f, 2.0f, 1.0f, 0.0f);

            Assert::IsTrue(CheckOperation(glm2_1 + glm2_2, cm2_1 + cm2_2));
            Assert::IsTrue(CheckOperation(glm3_1 + glm3_2, cm3_1 + cm3_2));
            Assert::IsTrue(CheckOperation(glm4_1 + glm4_2, cm4_1 + cm4_2));
        }

        TEST_METHOD(Subtraction) { // TESTED
            glm::vec2 glm2_1(0.0f, 1.0f), glm2_2(1.0f, 0.0f);
            glm::vec3 glm3_1(0.0f, 1.0f, 2.0f), glm3_2(2.0f, 1.0f, 0.0f);
            glm::vec4 glm4_1(0.0f, 1.0f, 2.0f, 3.0f), glm4_2(3.0f, 2.0f, 1.0f, 0.0f);

            cm::Vec cm2_1(0.0f, 1.0f), cm2_2(1.0f, 0.0f);
            cm::Vec cm3_1(0.0f, 1.0f, 2.0f), cm3_2(2.0f, 1.0f, 0.0f);
            cm::Vec cm4_1(0.0f, 1.0f, 2.0f, 3.0f), cm4_2(3.0f, 2.0f, 1.0f, 0.0f);

            Assert::IsTrue(CheckOperation(glm2_1 - glm2_2, cm2_1 - cm2_2));
            Assert::IsTrue(CheckOperation(glm3_1 - glm3_2, cm3_1 - cm3_2));
            Assert::IsTrue(CheckOperation(glm4_1 - glm4_2, cm4_1 - cm4_2));
        }

        TEST_METHOD(Dot) { // TESTED
            glm::vec2 glm2_1(0.0f, 1.0f), glm2_2(1.0f, 0.0f);
            glm::vec3 glm3_1(0.0f, 1.0f, 2.0f), glm3_2(2.0f, 1.0f, 0.0f);
            glm::vec4 glm4_1(0.0f, 1.0f, 2.0f, 3.0f), glm4_2(3.0f, 2.0f, 1.0f, 0.0f);

            cm::Vec cm2_1(0.0f, 1.0f), cm2_2(1.0f, 0.0f);
            cm::Vec cm3_1(0.0f, 1.0f, 2.0f), cm3_2(2.0f, 1.0f, 0.0f);
            cm::Vec cm4_1(0.0f, 1.0f, 2.0f, 3.0f), cm4_2(3.0f, 2.0f, 1.0f, 0.0f);

            Assert::AreEqual(glm::dot(glm2_1, glm2_2), cm::dot(cm2_1, cm2_2));
            Assert::AreEqual(glm::dot(glm3_1, glm3_2), cm::dot(cm3_1, cm3_2));
            Assert::AreEqual(glm::dot(glm4_1, glm4_2), cm::dot(cm4_1, cm4_2));
        }

        TEST_METHOD(MultiplicationByNum) { // TESTED
            glm::vec2 glm2_1(0.0f, 1.0f);
            glm::vec3 glm3_1(0.0f, 1.0f, 2.0f);
            glm::vec4 glm4_1(0.0f, 1.0f, 2.0f, 3.0f);

            cm::Vec cm2_1(0.0f, 1.0f);
            cm::Vec cm3_1(0.0f, 1.0f, 2.0f);
            cm::Vec cm4_1(0.0f, 1.0f, 2.0f, 3.0f);

            Assert::IsTrue(CheckOperation(glm2_1 * float(1.0 / 2.0), cm2_1 * float(1.0 / 2.0)));
            Assert::IsTrue(CheckOperation(glm3_1 * float(1.0 / 3.0), cm3_1 * float(1.0 / 3.0)));
            Assert::IsTrue(CheckOperation(glm4_1 * float(1.0 / 4.0), cm4_1 * float(1.0 / 4.0)));
        }

        TEST_METHOD(DivisionByNum) { // TESTED
            glm::vec2 glm2_1(0.0f, 1.0f);
            glm::vec3 glm3_1(0.0f, 1.0f, 2.0f);
            glm::vec4 glm4_1(0.0f, 1.0f, 2.0f, 3.0f);

            cm::Vec cm2_1(0.0f, 1.0f);
            cm::Vec cm3_1(0.0f, 1.0f, 2.0f);
            cm::Vec cm4_1(0.0f, 1.0f, 2.0f, 3.0f);

            Assert::IsTrue(CheckOperation(glm2_1 / float(1.0 / 2.0), cm2_1 / float(1.0 / 2.0)));
            Assert::IsTrue(CheckOperation(glm3_1 / float(1.0 / 3.0), cm3_1 / float(1.0 / 3.0)));
            Assert::IsTrue(CheckOperation(glm4_1 / float(1.0 / 4.0), cm4_1 / float(1.0 / 4.0)));
        }

        TEST_METHOD(Length) { // TESTED
            glm::vec2 glm2_1(0.0f, 1.0f);
            glm::vec3 glm3_1(0.0f, 1.0f, 2.0f);
            glm::vec4 glm4_1(0.0f, 1.0f, 2.0f, 3.0f);

            cm::Vec cm2_1(0.0f, 1.0f);
            cm::Vec cm3_1(0.0f, 1.0f, 2.0f);
            cm::Vec cm4_1(0.0f, 1.0f, 2.0f, 3.0f);

            Assert::AreEqual(glm::length(glm2_1), cm::length(cm2_1));
            Assert::AreEqual(glm::length(glm3_1), cm::length(cm3_1));
            Assert::AreEqual(glm::length(glm4_1), cm::length(cm4_1));
        }

        TEST_METHOD(Normalize) { // TESTED
            glm::vec2 glm2_1(0.0f, 1.0f);
            glm::vec3 glm3_1(0.0f, 1.0f, 2.0f);
            glm::vec4 glm4_1(0.0f, 1.0f, 2.0f, 3.0f);

            cm::Vec cm2_1(0.0f, 1.0f);
            cm::Vec cm3_1(0.0f, 1.0f, 2.0f);
            cm::Vec cm4_1(0.0f, 1.0f, 2.0f, 3.0f);

            Assert::IsTrue(CheckOperation(glm::normalize(glm2_1), cm::normalize(cm2_1)));
            Assert::IsTrue(CheckOperation(glm::normalize(glm3_1), cm::normalize(cm3_1)));
            Assert::IsTrue(CheckOperation(glm::normalize(glm4_1), cm::normalize(cm4_1)));
        }

        TEST_METHOD(Comparisons) { // TESTED
            glm::vec1 glm1(.5f), glm2(0.5f);
            cm::Vec cm1(0.5f), cm2(0.5f);

            Assert::AreEqual(glm1 == glm2, cm1 == cm2);
            Assert::AreEqual(glm1 != (glm2 + glm::vec1(0.1f)), cm1 != (cm2 + cm::Vec(0.1f)));
        }

        TEST_METHOD(Cross) { // TESTED
            glm::vec3 glm3_1(1.0f, 1.0f, 3.33f), glm3_2(0.0f, 1.0f, -1.0f);
            cm::Vec cm3_1(1.0f, 1.0f, 3.33f), cm3_2(0.0f, 1.0f, -1.0f);

            Assert::IsTrue(CheckOperation(glm::cross(glm3_1, glm3_2), cm::cross(cm3_1, cm3_2)));
        }
    };
}
