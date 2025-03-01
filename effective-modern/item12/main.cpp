
class Base {
    public:
      virtual void mf1() const;
      virtual void mf2(int x);
      virtual int mf3() &&{}; // Member function reference qualifiers; should be invoked on rvalue objects
      virtual void mf4() const;
      virtual int mf5();
    };
    
    class Derived: public Base {
    public:
      virtual void mf1() const override;
      virtual void mf2( int x) override;
      virtual int mf3() && override;
      void mf4() const override;
      int mf5();
    };

int main()
{
    Base b;
    // b.mf3(); // error: passing ‘Base’ as ‘this’ argument discards qualifiers
    auto x = Base().mf3();
    return 0;
}