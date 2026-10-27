//Khai báo lớp
class Point
{
    public:
        int xVal;
        int yVal;
    public:
        //Constructor
        Point();
        Point(const Point&);
        Point(const int&, const int&);
        //Destructor
        ~Point();
        //get
        int Get_xVal();
        int Get_yVal();
        //set
        void Set_xVal(const int&);
        void Set_yVal(const int&);
        void Show();
};