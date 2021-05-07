#include "visitor.hpp"

using namespace visit;
int main() {
    // declare operations to be performed
    Talk talk;
    Walk walk;

    Cat cat;
    cat.perform(talk);
    cat.perform(walk);

    Dog dog;
    dog.perform(talk);
    dog.perform(walk);

    Bird bird;
    bird.perform(talk);
    bird.perform(walk);

    Penguin penguin;
    penguin.perform(talk);
    penguin.perform(walk);

    return 0;    return 0;
}
