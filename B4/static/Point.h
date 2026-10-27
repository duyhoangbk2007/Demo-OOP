//Khai báo lớp
class Point
{
    public:
        static int n;
        const static int m = 3;
    public:
        int xVal;
        int yVal;
        const int z;
    public:
        //Constructor
        Point();
        //Point(const Point&);
        //Point(const int&, const int&);
        //Destructor
        ~Point();
        //get
        int Get_xVal();
        //set
        void Set_xVal(const int&);
        void TT(const int&);
        void Show();
};