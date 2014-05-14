#include "testBigIntBase.h"

void test(const char* label, int testValue, int rightValue){
    printf("%s <%s>: \tIt outputs [%d], \n\t\tthe expected value is [%d]\n", 
            (testValue==rightValue?"Right":"Wrong"), label, testValue, rightValue);
}
void test(const char* label, BigIntBase test, const char* rightValue){
    const char* testValue = test.toStringInBase(10).c_str();
    printf("%s <%s>: \tIt outputs [%s], \n\t\tthe expected value is [%s]\n", 
            (strcmp(testValue,rightValue)==0?"Right":"Wrong"), label, testValue, rightValue);
}
void problem20(){
    BigIntBase res(1);
    for (int i = 2; i <= 100; i++){
        BigIntBase a(i);
        res *= a;
    }
    int total = 0;
    for (ui i = 0; i < res.size; i++){
        total += res[i];
    }
    test("p20", total, 648);
}
void testAdd(){
    BigIntBase a1("99999999999999999999999999999999999"), a2("1"), 
               a3 = a2 + a1,
               a7("37107287533902102798797998220837590246510135740250"), 
               a8("46376937677490009712648124896970078050417018260538"), 
               a9 = a7 + a8;

    //BigIntBase + BigIntBase
    test("AddBB", a3, "100000000000000000000000000000000000");
    //BigIntBase + BigIntBase
    test("AddBB", a9, "83484225211392112511446123117807668296927154000788"); 
}
void testSubtract(){
    BigIntBase a4("83484225211392112511446123117807668296927154000788"), a5("46376937677490009712648124896970078050417018260538"),
               a6 = a4 - a5;
    //BigIntBase - BigIntBase
    test("SubBB", a6 , "37107287533902102798797998220837590246510135740250");
}
void testMultiply(){
    BigIntBase b1("123098787980787"), b2("1231298789708088"), 
               b3 = b1 * b2, b4("129387128974897812"), 
               b5 = b4 * 1234,  
               b6("129387128974897812"), b7("22341234123"), b8 = b6/b7;
    //BigIntBase * BigIntBase
    test("MulBB", b3, "151571388655275562950682505256");
    //BigIntBase * int
    test("MulBI", b5, "159663717155023900008");
}
void testDivid(){
    BigIntBase g1("123"), g2("123123124123123123123"), g3("987988767");
    g1 = g1 / g1;
    test("DivBB", g1, "1");
    g2 /= g3;
    test("DivBB", g2, "124619963541");
    g2 %= g3;
    test("ModBB", g2, "133378899");
}
void testCapacity(){
    BigIntBase a;
    test("Cap", a.capacity, 0);   //1
}
void testCompare(){
    BigIntBase b("123"), _b1("1234"), _b2("122");
    test("ComBB", b.compare(_b1), -1); //2
    test("ComBB", b.compare(_b2), 1); //3
    test("ComBB", b.compare(b), 0); //4
}
void testGCD(){
    BigIntBase a("169"), b("169169169169169169169169169"), c = a.gcd(b);
    test("gcdBB", c, "169");
    test("gcd", a, "169");
    test("gcd1", b, "169169169169169169169169169");
    test("gcd1", b, "169169169169169169169169169");
    BigIntBase e("123412341234123412341234123412341234"), f("12312312312414123123412312312312312412314123");
    BigIntBase g = e.gcd(f);
}
void testFour(){
    return;
//    BigIntBase a("169"), b("169169169169169169169169169");
//    BigIntBase c = a * b  * (a+b);// (b -a);
//    test("Four", c, "28589589589589589589589646683");
}
void testPermutation(){
    BigIntBase a = BigIntBase::permutation(123, 60);
    test("PerII", a, "6126426623277607558830892659050738012468992831594946549976844836830737333775846630022365422877182368153600000000000000");
}
void testCombination(){
    BigIntBase a = BigIntBase::combination(123, 60);
    test("Com", a, "736262001162891618184199485661336016");
}
void testPow(){
    BigIntBase a("1234"), b = a.pow(40);
    test("Pow", b, "4493723926702212177102715930895505163093661512740028111091444935676043681712474862933310710677287635716764659044658735742976");
}
void testFactorial(){
    BigIntBase a = BigIntBase::factorial(100);
    test("Fac", a, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
}
int main(){
    //  use results of euler problems to test
    problem20();
    testAdd();
    testSubtract();
    testMultiply();
    testDivid();
    testCapacity();
    testCompare();
    testGCD();
    testPow();
    testFour();
    testCombination();
    testPermutation();
    testFactorial();
}


