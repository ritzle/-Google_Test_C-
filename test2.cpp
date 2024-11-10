#include "lib/googletest/googlemock/include/gmock/gmock.h"
#include "lib/googletest/googletest/include/gtest/gtest.h"

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

// Вспомогательный класс для тестов MathApp
class MathAppTest : public ::testing::Test {
 protected:
  CalculatorMock calculator_mock;  // Мок-объект для CalculatorInterface
  MathApp* math_app;  // Указатель на объект MathApp

  void SetUp() override {
    math_app = new MathApp(&calculator_mock);  // Инициализация MathApp
  }

  void TearDown() override {
    delete math_app;  // Освобождаем память
  }
};

TEST_F(MathAppTest, CalculateSum) {
  EXPECT_CALL(calculator_mock, add(3, 5)).WillOnce(testing::Return(8));
  int result = math_app->calculateSum(3, 5);
  ASSERT_EQ(result, 8);
}

TEST_F(MathAppTest, CalculateDifference) {
  EXPECT_CALL(calculator_mock, subtract(10, 4)).WillOnce(testing::Return(6));
  int result = math_app->calculateDifference(10, 4);
  ASSERT_EQ(result, 6);
}

TEST_F(MathAppTest, CalculateProduct) {
  EXPECT_CALL(calculator_mock, multiply(3, 5)).WillOnce(testing::Return(15));
  int result = math_app->calculateProduct(3, 5);
  ASSERT_EQ(result, 15);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
