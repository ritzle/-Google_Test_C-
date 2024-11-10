#include <vector>

#include "lib/googletest/googlemock/include/gmock/gmock.h"
#include "lib/googletest/googletest/include/gtest/gtest.h"

using namespace std;

class CalculatorInterface {
 public:
  virtual ~CalculatorInterface() = default;
  virtual int add(int a, int b) = 0;
  virtual int subtract(int a, int b) = 0;
  virtual int multiply(int a, int b) = 0;
};

class CalculatorMock : public CalculatorInterface {
 public:
  MOCK_METHOD(int, add, (int a, int b), (override));
  MOCK_METHOD(int, subtract, (int a, int b), (override));
  MOCK_METHOD(int, multiply, (int a, int b), (override));
};

class MathApp {
  CalculatorInterface* calculator_;

 public:
  explicit MathApp(CalculatorInterface* calculator) : calculator_(calculator) {}

  int calculateSum(int a, int b) { return calculator_->add(a, b); }
  int calculateDifference(int a, int b) { return calculator_->subtract(a, b); }
  int calculateProduct(int a, int b) { return calculator_->multiply(a, b); }
};

// Параметризованный тест для MathApp
class MathAppTest : public ::testing::TestWithParam<vector<int>> {
 protected:
  CalculatorMock calculator_mock;
  MathApp* math_app;

  int a;
  int b;
  int expectedSum;
  int expectedDifference;
  int expectedProduct;

  void SetUp() override {
    math_app = new MathApp(&calculator_mock);

    // Инициализация полей с параметрами из TestWithParam
    const auto& param = GetParam();
    a = param[0];
    b = param[1];
    expectedSum = param[2];
    expectedDifference = param[3];
    expectedProduct = param[4];
  }

  void TearDown() override { delete math_app; }
};

// Параметризованный тест для суммы
TEST_P(MathAppTest, CalculateSum) {
  EXPECT_CALL(calculator_mock, add(a, b))
      .WillOnce(testing::Return(expectedSum));
  int result = math_app->calculateSum(a, b);
  ASSERT_EQ(result, expectedSum);
}

// Параметризованный тест для разности
TEST_P(MathAppTest, CalculateDifference) {
  EXPECT_CALL(calculator_mock, subtract(a, b))
      .WillOnce(testing::Return(expectedDifference));
  int result = math_app->calculateDifference(a, b);
  ASSERT_EQ(result, expectedDifference);
}

// Параметризованный тест для произведения
TEST_P(MathAppTest, CalculateProduct) {
  EXPECT_CALL(calculator_mock, multiply(a, b))
      .WillOnce(testing::Return(expectedProduct));
  int result = math_app->calculateProduct(a, b);
  ASSERT_EQ(result, expectedProduct);
}

// Определение параметров для тестов через vector
INSTANTIATE_TEST_SUITE_P(
    MathAppTests, MathAppTest,
    ::testing::Values(
        vector<int>{3, 5, 8, 2, 15},    // 3 + 5 = 8, 3 - 5 = -2, 3 * 5 = 15
        vector<int>{10, 4, 14, 6, 40},  // 10 + 4 = 14, 10 - 4 = 6, 10 * 4 = 40
        vector<int>{7, 2, 9, 5, 14}     // 7 + 2 = 9, 7 - 2 = 5, 7 * 2 = 14
        ));

int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
