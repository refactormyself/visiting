#ifndef APP_ANIMAL_VISITOR_HPP
#define APP_ANIMAL_VISITOR_HPP

#include <iostream>

#include "animal_library.hpp"

namespace app {

    // Talk is an Operation. So, implement how you want your object to sound!
    class Talk : public anim::Operation {
    public:
        void dogOperation(anim::Dog &dog) override {
            dog.setMessage("woof!\n");
        }

        void catOperation(anim::Cat &cat) override {
            cat.setMessage("meow!\n");
        }

        void birdOperation(anim::Bird &bird) override {
            bird.setMessage("Hissss!\n");
        }

        void pengOperation(anim::Penguin &peng) override {
            peng.setMessage("Quirk quirk!\n");
        }

        void pengOperation(anim::Bird &peng) override {
            std::cout << "A penguin is a bird. So ... ";
            birdOperation(peng);
        }

        void pengOperation(anim::Penguin &peng, std::string location) override {
        }
    };

// This is done without changing any of the above classes

    // Walk is an Operation. So, implement how you want your object to move!
    class Walk : public anim::Operation {
    public:
        void dogOperation(anim::Dog &dog) override {
            dog.setMessage("Dogs run!\n");
        }

        void catOperation(anim::Cat &cat) override {
            cat.setMessage("Cats sneak ;)\n");
        }

        void birdOperation(anim::Bird &bird) override {
            bird.setMessage("Birds fly fly fly!\n");
        }

        void pengOperation(anim::Penguin &peng) override {
            birdOperation(peng); // going down the object hierarchy
            peng.setMessage("Penguins swim and walk!\n");
        }

        void pengOperation(anim::Bird &peng) override {
            std::cout << "A penguin is a bird. And ... ";
            birdOperation(peng);
        }

        void pengOperation(anim::Penguin &peng, std::string location) override {
            if (location == "land")
                peng.setMessage("Penguins walk on land!\n");
            else if (location == "water")
                peng.setMessage("Penguins swim in water!\n");
            else
                peng.setMessage("Penguins swim and walk!\n");
        }
    };
}
#endif //APP_ANIMAL_VISITOR_HPP
