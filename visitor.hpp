//
// Created by saheed on 12/29/21.
//

#ifndef UNTITLED1_VISITOR_H
#define UNTITLED1_VISITOR_H

#include <memory>
#include <iostream>

class Dog;
class Cat;
class Bird;
class Penguin;

// @visitor pattern: This is the "VISITOR" Class interface
// (Put custom object operations in here, not in their Class def.)
class Operation // VISITOR Class interface (
{
public:
    virtual void dogOperation(Dog &dog) = 0;
    virtual void catOperation(Cat &cat) = 0;
    virtual void birdOperation(Bird &bird) = 0;
    virtual void pengOperation(Penguin &peng) = 0;
    virtual void pengOperation(Bird &peng) = 0; // multiple visitable states
    virtual void pengOperation(Penguin &peng, std::string location) = 0; // multiple visitable states
};

class Animal
{ public:
    // @visitor pattern: this is the ACCEPT; where visitors are accepted :)
    virtual void perform(Operation &op) = 0;
    // with these we handle multiple visitable states
//    virtual void perform(Operation &op, Bird bird)= 0;
//    virtual void perform(Operation &op, std::string location)= 0;
};

class Dog : public Animal
{ public: Dog(){ std::cout << "\nI am a Dog!\n";}
    void perform(Operation &op) override {
        op.dogOperation(*this);
    }
};

class Cat : public Animal
{ public: Cat(){ std::cout << "\nI am a Cat!\n";}
    void perform(Operation &op) override {
        op.catOperation(*this);
    }
};

class Bird : public Animal
{ public: Bird(){ std::cout << "\nI am a Bird!\n";}
    void perform(Operation &op) override {
        op.birdOperation(*this);
    }
};

class Penguin : public Bird
{ public: Penguin(){ std::cout << "\nI am a Penguin!\n";}
    void perform(Operation &op) override {
        op.pengOperation(*this);
    }
};

// Talk is an Operation. So, implement how you want your object to sound!
class Talk : public Operation
{
public:
    void dogOperation(Dog &dog) override {
     std::cout << "woof!\n";
    }

    void catOperation(Cat &cat) override{
        std::cout << "meow!\n";
    }

    void birdOperation(Bird &bird) override{
        std::cout << "Hissss!\n";
    }

    void pengOperation(Penguin &peng) override{
        std::cout << "Quirk quirk!\n";
    }

    void pengOperation(Bird &peng) override{
        std::cout << "A penguin is a bird. So ... ";
        birdOperation(peng);
    }

    void pengOperation(Penguin &peng, std::string location) override{
    }

};

// This is done without changing any of the above classes
// Walk is an Operation. So, implement how you want your object to move!
class Walk : public Operation
{
public:
    void dogOperation(Dog &dog) override {
        std::cout << "Dogs run!\n";
    }

    void catOperation(Cat &c) override{
        std::cout << "Cats sneak ;)\n";
    }

    void birdOperation(Bird &bird) override{
        std::cout << "Birds fly fly fly!\n";
    }

    void pengOperation(Penguin &peng) override{
        birdOperation(peng); // going down the object hierarchy
        std::cout << "Penguins swim and walk!\n";
    }

    void pengOperation(Bird &peng) override{
        std::cout << "A penguin is a bird. And ... ";
        birdOperation(peng);
    }

    void pengOperation(Penguin &peng, std::string location) override{
        if (location == "land")
            std::cout << "Penguins walk on land!\n";
        else if (location == "water")
            std::cout << "Penguins swim in water!\n";
        else
            std::cout << "Penguins swim and walk!\n";
    }
};


#endif //UNTITLED1_VISITOR_H
