#include <vector>
using namespace std ;
class TypoCoderDiv2
{
    public:
        int count(vector <int> rating)
        {
            int ret = 0;
            bool color = 0;
            for (unsigned i = 0; i < rating.size(); i++){
                if (rating[i] >= 1200 && color == 0){
                    ret ++;
                    color = 1;
                }else if (rating[i] < 1200 && color == 1){
                    ret ++;
                    color = 0;
                }
            }
            return ret;
            return int() ;
        }
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
