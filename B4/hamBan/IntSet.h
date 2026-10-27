class RealSet;
class IntSet
{
    private:
        double *p;
        int n;
    public:
        IntSet(const int&);
        ~IntSet();
        void Show();
        void SetToReal(RealSet&);
};