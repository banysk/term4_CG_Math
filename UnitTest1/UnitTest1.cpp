#include "pch.h"
#include "CppUnitTest.h"
#include "../CG/lib/Math.hpp"
#include "../CG/glm/glm.hpp"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    // Functions
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

    // Main
	TEST_CLASS(Vec)
	{
	public:
		TEST_METHOD(Constructor) // TESTED
		{
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

        TEST_METHOD(MultiplicationByInt) { // TESTED
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

        TEST_METHOD(DivisionByInt) { // TESTED
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
