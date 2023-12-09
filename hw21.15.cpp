#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class B {
public:
    virtual void f() const {
        std::cout << "A function B::f() was called " << std::endl;
    }
};

class D : public B {
public:
    void f() const override {
        std::cout << "A function D::f() was called" << std::endl;
    }
};

int main() {
    std::vector<B*> objects;

    objects.push_back(new B());
    objects.push_back(new D());

    std::for_each(objects.begin(), objects.end(), [](B* obj) {
        obj->f();
    });

    for (B* obj : objects) {
        delete obj;
    }

    return 0;
}


