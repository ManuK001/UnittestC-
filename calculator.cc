#include <iostream>
#include <stdexcept>
#include "gtest/gtest.h"

// Calculator class
class Calculator {
public:
    static int Add(int a, int b) { return a + b; }
    static int Subtract(int a, int b) { return a - b; }
    static int Multiply(int a, int b) { return a * b; }
    static int Divide(int a, int b) {
        if (b == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return a / b;
    }
};

// Unit tests using Google Test
TEST(CalculatorTest, Add) {
    EXPECT_EQ(Calculator::Add(2, 3), 5);
    EXPECT_EQ(Calculator::Add(-2, 3), 1);
    EXPECT_EQ(Calculator::Add(0, 0), 0);
}

TEST(CalculatorTest, Subtract) {
    EXPECT_EQ(Calculator::Subtract(5, 2), 3);
    EXPECT_EQ(Calculator::Subtract(2, 5), -3);
    EXPECT_EQ(Calculator::Subtract(0, 0), 0);
}

TEST(CalculatorTest, Multiply) {
    EXPECT_EQ(Calculator::Multiply(2, 3), 6);
    EXPECT_EQ(Calculator::Multiply(-2, 3), -6);
    EXPECT_EQ(Calculator::Multiply(0, 5), 0);
}

TEST(CalculatorTest, Divide) {
    EXPECT_EQ(Calculator::Divide(6, 3), 2);
    EXPECT_THROW(Calculator::Divide(5, 0), std::invalid_argument);
    EXPECT_EQ(Calculator::Divide(0, 5), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
