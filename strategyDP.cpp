#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


// Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0; // Pure virtual function
    virtual ~PaymentStrategy() {}
};

// Concrete Strategy: CreditCardPayment
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid " << amount << " using Credit Card." << std::endl;
    }
};

// Concrete Strategy: PayPalPayment
class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid " << amount << " using PayPal." << std::endl;
    }
};

// Concrete Strategy: BankTransferPayment
class BankTransferPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid " << amount << " using Bank Transfer." << std::endl;
    }
};
// Context
class PaymentContext {
    PaymentStrategy* strategy;
public:
    void setStrategy(PaymentStrategy* newStrategy) {
        strategy = newStrategy;
    }
    void pay(int amount) {
        if (strategy) {
            strategy->pay(amount);
        } else {
            std::cout << "Payment strategy not set!" << std::endl;
        }
    }
};
// Client Code
int main() {
    PaymentContext context;

    // Pay using Credit Card
    context.setStrategy(new CreditCardPayment());
    context.pay(100);
    context.setStrategy(nullptr); // Cleanup previous strategy

    // Pay using PayPal
    context.setStrategy(new PayPalPayment());
    context.pay(200);
    context.setStrategy(nullptr); // Cleanup previous strategy

    // Pay using Bank Transfer
    context.setStrategy(new BankTransferPayment());
    context.pay(300);
    context.setStrategy(nullptr); // Cleanup previous strategy

    return 0;
}

