#include "lib/googletest/googlemock/include/gmock/gmock.h"
#include "lib/googletest/googletest/include/gtest/gtest.h"

class ProductService {
 public:
  virtual ~ProductService() = default;
  virtual bool isProductAvailable(const std::string& productId) = 0;
  virtual double getProductPrice(const std::string& productId) = 0;
};

class PaymentService {
 public:
  virtual ~PaymentService() = default;
  virtual bool processPayment(double amount) = 0;
};

class MockProductService : public ProductService {
 public:
  MOCK_METHOD(bool, isProductAvailable, (const std::string& productId),
              (override));
  MOCK_METHOD(double, getProductPrice, (const std::string& productId),
              (override));
};

class MockPaymentService : public PaymentService {
 public:
  MOCK_METHOD(bool, processPayment, (double amount), (override));
};

class Order {
 private:
  ProductService* productService_;
  PaymentService* paymentService_;

 public:
  Order(ProductService* productService, PaymentService* paymentService)
      : productService_(productService), paymentService_(paymentService) {}

  bool placeOrder(const std::string& productId, int quantity) {
    if (!productService_->isProductAvailable(productId)) {
      return false;
    }

    double price = productService_->getProductPrice(productId);
    double totalAmount = price * quantity;

    return paymentService_->processPayment(totalAmount);
  }
};

class OrderTest : public ::testing::Test {
 protected:
  MockProductService mockProductService;
  MockPaymentService mockPaymentService;
  Order* order;

  void SetUp() override {
    order = new Order(&mockProductService, &mockPaymentService);
  }

  void TearDown() override { delete order; }
};

TEST_F(OrderTest, PlaceOrder_Success) {
  // Ожидаем, что продукт будет доступен и его цена будет 10.0
  EXPECT_CALL(mockProductService, isProductAvailable("product1"))
      .WillOnce(testing::Return(true));
  EXPECT_CALL(mockProductService, getProductPrice("product1"))
      .WillOnce(testing::Return(10.0));

  EXPECT_CALL(mockPaymentService, processPayment(20.0))
      .WillOnce(testing::Return(true));

  bool result = order->placeOrder("product1", 2);
  ASSERT_TRUE(result);
}

TEST_F(OrderTest, PlaceOrder_ProductUnavailable) {
  EXPECT_CALL(mockProductService, isProductAvailable("product2"))
      .WillOnce(testing::Return(false));

  bool result = order->placeOrder("product2", 2);
  ASSERT_FALSE(result);
}

TEST_F(OrderTest, PlaceOrder_PaymentFailed) {
  EXPECT_CALL(mockProductService, isProductAvailable("product3"))
      .WillOnce(testing::Return(true));
  EXPECT_CALL(mockProductService, getProductPrice("product3"))
      .WillOnce(testing::Return(15.0));

  EXPECT_CALL(mockPaymentService, processPayment(30.0))
      .WillOnce(testing::Return(false));

  bool result = order->placeOrder("product3", 2);
  ASSERT_FALSE(result);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}