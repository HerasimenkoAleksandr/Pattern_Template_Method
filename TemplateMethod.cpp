#include <iostream>
using namespace std;



class AbstractClass {
  
public:
    void TemplateMethod() {
       FirstOperation();
       SecondOperations();
       ThirdOperation();
       Hook1();
       
    }
   
protected:
    void FirstOperation() {
        std::cout << "the first operation is defined in the base class\n";
    }
   
    virtual void SecondOperations() = 0;
    virtual void  ThirdOperation() = 0;

    virtual void Hook1(){}
   
};

class ConcreteClass1 : public AbstractClass {
protected:
    void  SecondOperations() override {
        std::cout << "ConcreteClass1 says: Implemented SecondOperations\n";
    }
    void ThirdOperation() override {
        std::cout << "ConcreteClass1 says: Implemented ThirdOperation\n";
    }
};

class ConcreteClass2 : public AbstractClass {
protected:
    void  SecondOperations() override {
        std::cout << "ConcreteClass2 says: Implemented SecondOperations\n";
    }
    void ThirdOperation() override {
        std::cout << "ConcreteClass2 says: Implemented ThirdOperation\n";
    }
    void Hook1() override {
        std::cout << "ConcreteClass2 says: Overridden Hook1\n";
    }
};

void ClientCode(AbstractClass* obj) {
 
 obj->TemplateMethod();
   
}

int main() {
    std::cout << "Same client code can work with different subclasses:\n";
    ConcreteClass1* concreteClass1 = new ConcreteClass1;
    ClientCode(concreteClass1);
    std::cout << "\n";
    std::cout << "Same client code can work with different subclasses:\n";
    ConcreteClass2* concreteClass2 = new ConcreteClass2;
    ClientCode(concreteClass2);
    delete concreteClass1;
    delete concreteClass2;
    return 0;
}