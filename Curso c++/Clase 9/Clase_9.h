
class A
{
    public:
        void fn1A();
        void fn2A();
    private:
        void fn3A();
        int attr1A;
};

class B : public A
{
    public:
        void fn_b1();
        void fn_b2();
    private:
        void fn_b3();
        int attr_b1;

};