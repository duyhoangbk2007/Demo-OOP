#include "LopTT.h"
class LopCT: public LopTT {
    private:
        //data
    public:
        LopCT();
        ~LopCT();
        void B() override;
        void A() override;
};