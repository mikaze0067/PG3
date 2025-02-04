#include <cstdio>
using namespace std;

class Animal {
public:
    virtual void sound() const = 0;
};


class Dog : public Animal {
public:
    void sound() const override {
        printf("イヌ鳴き声：ワン\n");
    }
};


class Cat : public Animal {
public:
    void sound() const override {
        printf("ネコ鳴き声:ニャー\n");
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->sound();
    animal2->sound();

    delete animal1;
    delete animal2;

    return 0;
}