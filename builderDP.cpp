#include <iostream>
#include <string>

// Product
class Computer {
    std::string cpu;
    std::string ram;
    std::string storage;
public:
    void setCpu(const std::string& cpu) { this->cpu = cpu; }
    void setRam(const std::string& ram) { this->ram = ram; }
    void setStorage(const std::string& storage) { this->storage = storage; }
    void showSpecifications() {
        std::cout << "CPU: " << cpu << "\nRAM: " << ram << "\nStorage: " << storage << std::endl;
    }
};

// Builder Interface
class ComputerBuilder {
public:
    virtual void buildCpu() = 0;
    virtual void buildRam() = 0;
    virtual void buildStorage() = 0;
    virtual Computer* getComputer() = 0;
    virtual ~ComputerBuilder() {} // Virtual destructor for proper cleanup
};

// Concrete Builder for Gaming Computer
class GamingComputerBuilder : public ComputerBuilder {
    Computer* computer;
public:
    GamingComputerBuilder() { computer = new Computer(); }
    void buildCpu() override { computer->setCpu("Intel Core i9"); }
    void buildRam() override { computer->setRam("32GB"); }
    void buildStorage() override { computer->setStorage("1TB SSD"); }
    Computer* getComputer() override { return computer; }
};

// Concrete Builder for Office Computer
class OfficeComputerBuilder : public ComputerBuilder {
    Computer* computer;
public:
    OfficeComputerBuilder() { computer = new Computer(); }
    void buildCpu() override { computer->setCpu("Intel Core i5"); }
    void buildRam() override { computer->setRam("16GB"); }
    void buildStorage() override { computer->setStorage("512GB SSD"); }
    Computer* getComputer() override { return computer; }
};

// Director
class Director {
    ComputerBuilder* builder;
public:
    Director(ComputerBuilder* b) : builder(b) {}
    void construct() {
        builder->buildCpu();
        builder->buildRam();
        builder->buildStorage();
    }
};

int main() {
    // Building a Gaming Computer
    GamingComputerBuilder gamingBuilder;
    Director gamingDirector(&gamingBuilder);
    gamingDirector.construct();
    Computer* gamingComputer = gamingBuilder.getComputer();
    std::cout << "Gaming Computer Specifications:" << std::endl;
    gamingComputer->showSpecifications();
    delete gamingComputer;

    // Building an Office Computer
    OfficeComputerBuilder officeBuilder;
    Director officeDirector(&officeBuilder);
    officeDirector.construct();
    Computer* officeComputer = officeBuilder.getComputer();
    std::cout << "\nOffice Computer Specifications:" << std::endl;
    officeComputer->showSpecifications();
    delete officeComputer;

    return 0;
}



