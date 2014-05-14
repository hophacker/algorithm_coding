#include "euler.h"
class numberSpell{
private: 
    static const char* baseNumberString[];
    static const char* tensString[] ;
private:
    static string spellBase(ui n);
    static string spellTens(ui n);
    static string spellHundreds(ui n);
    static string spellThousands(ui n);
public:
    static string spell(ui n);
};
