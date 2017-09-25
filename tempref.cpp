#include <iostream>

class A {
public:
  virtual void me() const { std::cerr << "hi!\n"; }
};

class B {
public:
  B(const A& a_) : a(a_) {}
  virtual void me() const { a.me(); }

private:
  const A& a;
};

class C {
public:
  C(const B& b_) : b(b_) {}
  void me() const { b.me(); }

public:
  const B& b;
};

int main() {
  C c = C(A());
  c.me();
}
