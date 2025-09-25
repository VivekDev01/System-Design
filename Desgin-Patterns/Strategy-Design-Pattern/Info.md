
### **Conclusion**

* **Encapsulate what varies & keep it separate from what remains same.**
* **Solution to inheritance is not more inheritance.**
* **Composition should be favoured over inheritance.**
* **Code to interface & not to concretion.**
* **Do NOT Repeat Yourself (DRY).**

---
---

## UML Class Diagram – Payment System (Strategy Pattern)

```mermaid
classDiagram
    class PaymentStrategy {
        <<interface>>
        +pay(amount: double) void
    }

    class UPI {
        +pay(amount: double) void
    }

    class CreditCard {
        +pay(amount: double) void
    }

    class NetBanking {
        +pay(amount: double) void
    }

    class PaymentContext {
        -strategy: PaymentStrategy
        +setStrategy(s: PaymentStrategy) void
        +executePayment(amount: double) void
    }

    PaymentStrategy <|.. UPI
    PaymentStrategy <|.. CreditCard
    PaymentStrategy <|.. NetBanking
    PaymentContext --> PaymentStrategy : uses
