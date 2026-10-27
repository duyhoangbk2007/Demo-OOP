class Number {
    private:
        double data;
    public:
        Number(const double& = 0.0);
        ~Number();
        operator int();
        operator double();
};