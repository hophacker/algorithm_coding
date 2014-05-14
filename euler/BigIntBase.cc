#include "BigIntBase.h"

const BigUnit BigIntBase::digitMul[][10]={
    {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},
    {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9},
    {0x0,0x2,0x4,0x6,0x8,0x10,0x12,0x14,0x16,0x18},
    {0x0,0x3,0x6,0x9,0x12,0x15,0x18,0x21,0x24,0x27},
    {0x0,0x4,0x8,0x12,0x16,0x20,0x24,0x28,0x32,0x36},
    {0x0,0x5,0x10,0x15,0x20,0x25,0x30,0x35,0x40,0x45},
    {0x0,0x6,0x12,0x18,0x24,0x30,0x36,0x42,0x48,0x54},
    {0x0,0x7,0x14,0x21,0x28,0x35,0x42,0x49,0x56,0x63},
    {0x0,0x8,0x16,0x24,0x32,0x40,0x48,0x56,0x64,0x72},
    {0x0,0x9,0x18,0x27,0x36,0x45,0x54,0x63,0x72,0x81}
}; 
BigIntBase::BigIntBase(bool forCapacity, ui _capacity){
    setCapacity(_capacity);
}
BigIntBase::BigIntBase(ui val, ui _capacity){
    assert(GetNumberOfDigits(val) <= _capacity);
    setCapacity(_capacity);
    assign(val);
}
BigIntBase::BigIntBase(int val, ui _capacity){
    BigIntBase((ui)val, _capacity);
}
BigIntBase::BigIntBase(): size(0), capacity(0){
//    setCapacity();
}

void BigIntBase::initializeUI(ui n){
    setCapacity(capacityOfI32);
    if (n == 0){
        setZero();
    }else{
        size = 0;
        while(n != 0){
            data[size++] = n % 10;
            n /= 10;
        }
    }
}
BigIntBase::BigIntBase(const char* numStr){
    size = strlen(numStr);
    setCapacity(size*2);
    for (ui i = 0; i < size; i++){
        data[i] = numStr[size-1-i] - '0';
    }
}
BigIntBase::BigIntBase(const BigIntBase& rhs){
    //cout << "Operator copy has been called" << endl;
    assign(rhs);
}
BigIntBase::BigIntBase(const BigIntBase& rhs, int rhsCapacity){
    assign(rhs);
}



/*
 *--------------------------------------------------------------------------------------
 *       Class:  BigIntBase
 *      Method:  BigIntBase :: calcDigit
 * Description:  Caculate the digit
 * Just like human normally do division math. We only do subtraction of the length of b.size
 * For subsequent subtractions, we consider the length of b.size+1
 *--------------------------------------------------------------------------------------
 */

int BigIntBase::subCompare(int pos, ui len, BigIntBase &b){
    while(len > 0 && data[pos+len-1] == 0) len--;

    if (len != b.size) return len - b.size;
    else{
        for (int i = len-1; i >= 0; i--){
            if (data[i+pos] == b[i]) continue;
            else return data[i+pos] - b[i];
        }
        return 0;
    }
}
int BigIntBase::compare(BigIntBase &b) {
    BigIntBase& a = *this;
    if (a.size != b.size) return a.size - b.size;
    else{
        for (int i = a.size - 1; i >= 0; i--){
            if (a[i] == b[i]) continue;
            else return a[i] - b[i];
        }
        return 0;
    }
}
BigUnit BigIntBase::calcDigit(int pos, ui len, BigIntBase* B){
    // B.size >= len
    int L = 0, R = 9, M, cmp;
    // [L,M] {L, M}
    while(L <= R){
        M = (L+R) >> 1;
        cmp = subCompare(pos, len, B[M]);
        if (cmp >= 0){ //[M,R] {M+1,R}
            L = M+1;
        }else{ //[L,M-1] {L,M-1}
            R = M-1;
        }
    }
    return R;
}
void BigIntBase::assign(const BigIntBase& rhs){
    this->size = rhs.size;
    this->setCapacity(rhs.size);
    memcpy(this->data, rhs.data, sizeof(BigUnit) * this->capacity);
}

void BigIntBase::assign(ui val){
    if (val == 0){
        setZero();
    }else{
        size = 0;
        while(val != 0){
            data[size++] = val % 10;
            val /= 10;
        }
    }
}
void BigIntBase::assign(int val){
    assign((ui)val);
}

//Only add "addCapacity" here.
void BigIntBase::setCapacity(ui _capacity){
    free(data);
    data = new BigUnit[capacity=_capacity+addCapacity];
}

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BigIntBase
 *      Method:  BigIntBase :: clear
 * Description:  This mothod set the capacity of underline arrary to length and clear all
 * array unit to value.
 *--------------------------------------------------------------------------------------
 */
void BigIntBase::clear(ui length, BigUnit value){
    if (capacity < length){
        length += 2;
        setCapacity(length);
    }
    for (ui i = 0; i < length; i++)
        (*this)[i] = value;
}
void BigIntBase::expand(int newCapacity){
#ifdef DEBUG
    print();
    cerr << "expand here" << endl;
    cerr << "new capacity is: " << newCapacity << endl;
#endif
    BigUnit* newData = new BigUnit[newCapacity];
    BigUnit* temp = data;
    memcpy(newData, data, sizeof(BigUnit)*capacity);
    data = newData;
    capacity = newCapacity;
    free(temp);
}
/*
 * If the requested idx >= capacity, it will expand the capacity twice.
 * The benefit is that the other part of the program does not need to consider expansion  issue.
 * Thus, this little trick can largely reduce the programming complexity. 
 * Also, in this way, the program is easier to read and to maintain.
 */
BigUnit& BigIntBase::operator[](const ui idx) {
    if (idx >= capacity) expand(capacity << 1);
    return data[idx];
}
void BigIntBase::add(BigIntBase &a, BigIntBase &b){
    assert(a.size >= b.size);
    if (a.isZero()){
        operator = (b);
        return;
    } else if (b.isZero()) {
        operator = (a);
        return;
    }
    BigIntBase& c = *this;
    ui i;
    bool carry = 0;
    BigUnit t;
    for (i = 0; i < b.size; i++){
        t = a[i] + b[i] + carry;
        if (t >= 10) carry = 1, t = t - 10;
        else carry = 0;
        c[i] = t;
    }
    for (; i < a.size && carry; i++){
        t = a[i] + 1;
        if (t == 10) carry = 1, t = 0;
        else carry = 0;
        c[i] = t;
    }
    for (; i < a.size; i++)
        c[i] = a[i];
    if (carry){
        c[i] = 1;
        size = a.size + 1;
    }else size = a.size;
}
void BigIntBase::subtract(BigIntBase &A, BigIntBase &B){
    if (&A == &B){
        operator = (0);
        return;
    }else if(B.isZero()){
        operator = (A);
        return;
    }
    BigIntBase *a, *b, *c = this;
    if (this == &A) a = new BigIntBase(*this); else a = &A;
    if (this == &B) a = new BigIntBase(*this); else b = &B;
    setCapacity(a->size);
    ui i;
    bool carry = 0;
    BigUnit t;
    for (i = 0; i < b->size; i++){
        t = carry + (*b)[i];
        if ((*a)[i] < t){
            (*c)[i] = 10 + (*a)[i] - t;
            carry = 1;
        }else{
            (*c)[i] = (*a)[i] - t;
            carry = 0;
        }
    }
    for (; i < a->size && carry; i++)
        if ((*a)[i] == 0) (*c)[i] = 9;
        else (*c)[i] = (*a)[i]-1, carry = 0;
    for (; i < a->size; i++)
        (*c)[i] = (*a)[i];

    size = a->size-1;
    while( (*c)[size] == 0 && size >= 0) size--;
    size++;
}
//subtract b * (10^pos)
void BigIntBase::subtract(int pos, BigIntBase &b){
    BigIntBase &a = *this;
    ui i;
    bool carry = 0;
    BigUnit t;
    for (i = 0; i < b.size+1; i++){
        t = carry + b[i];
        if (a[i+pos] < t){
            a[i+pos] = 10 + a[i+pos] - t;
            carry = 1;
        }else{
            a[i+pos] -= t;
            carry = 0;
        }
    }
}
void BigIntBase::multiply(BigIntBase &A, BigIntBase &B){
    if (A.isZero() || B.isZero()){
        setZero();
        return;
    }else if (A.isOne()){
        if (this != &B) operator = (B); //How about f1 *= f2 and f2 == BigIntBase(1)
        return;
    } else if (B.isOne()) {
        if (this != &A) operator = (A);
        return;
    }
    BigIntBase *a, *b;
    if (this == &A) a = new BigIntBase(*this); else a = &A;
    if (this == &B) a = new BigIntBase(*this); else b = &B;

    clear(a->size * b->size, 0);
    BigIntBase& c = *this;
    BigUnit t, carry;
    for (ui i = 0; i < a->size; i++){
        carry = 0;
        for (ui j = 0; j < b->size; j++){
            t = c[i+j] + (*a)[i] * (*b)[j] + carry;
            c[i+j] = t % 10;
            carry = t / 10;
        }
        c[i+b->size] += carry;
    }
    carry = 0;
    for (ui i = 0; i < a->size + b->size; i++){
        t = c[i] + carry;
        c[i] = t % 10;
        carry /= 10;
    }
    size = a->size + b->size;
    while( size > 0 && c[size-1] == 0 ) size --;
}
void BigIntBase::multiply(BigIntBase &A, int b){
    if (A.isZero() || b == 0) {
        setZero();
        return;
    } else if (A.isOne()){
        operator = (b); //How about f1 *= f2 and f2 == BigIntBase(1)
        return;
    } else if (b == 1) {
        if (this != &A) operator = (A);
        return;
    }
    BigIntBase *a;
    if (this == &A) a = new BigIntBase(*this); else a = &A;

    clear(a->size + 10, 0); // an int number is at most 10 digit long
    BigIntBase& c = *this;
    int t, carry = 0;
    ui i;
    for (i = 0; i < a->size; i++){
        t = (*a)[i] * b + carry;
        c[i] = t % 10;
        carry = t / 10;
    }
    while(carry != 0){
        c[i++] = carry % 10;
        carry /= 10;
    }
    size = i;
}
BigIntBase BigIntBase::divide(BigIntBase &A, BigIntBase &b){
    BigIntBase a = A;
    assert(!b.isZero());
    if (b.isOne()){
        operator = (a);
        return operator = (0);
    }else if (a.size < b.size){
        operator = (0);
        return a;
    }


    BigIntBase B[10];
    B[0] = 0; 
    for (int i = 1; i <= 9; i++) B[i] = b + B[i-1];
    //If b = *this, clear must be after calclulating B
    ui bSize = b.size;

    clear(a.size - bSize + 1, 0);

    a[a.size] = 0;
    ui len;
    for (int i = a.size-bSize; i >= 0; i--){
        if (a[i+bSize-1] == 0 && a[i+bSize] == 0){
            data[i] = 0;
            continue;
        }
        data[i] = a.calcDigit(i, bSize+1, B);
        a.subtract(i, B[data[i]]);
    }
    size = a.size - bSize + 1;
    shrink();
    a.shrink();
    return a;
}
BigIntBase BigIntBase::square(){
    return (*this)*(*this);
}
BigIntBase& BigIntBase::operator=(const BigIntBase& rhs) {
    assign(rhs);
    return *this;
}
BigIntBase& BigIntBase::operator=(const int rhs) {
    assign(rhs);
    return *this;
}
BigIntBase BigIntBase::operator+(BigIntBase& b) {
    BigIntBase ret(true, max(b.size, this->size)+1);
    if (this->size > b.size)
        ret.add(*this, b);
    else 
        ret.add(b, *this);
    return ret;
}

BigIntBase BigIntBase::operator-(BigIntBase& b){
    assert(compare(b) >= 0);
    BigIntBase ret;
    ret.subtract(*this, b);
    return ret;
}

void BigIntBase::operator-=(BigIntBase& b){
    if (this == &b){
        operator = (0);
        return;
    }else if(b.size == 0){
        return;
    }
    assert(compare(b) >= 0);
    BigIntBase &a = *this;
    ui i;
    bool carry = 0;
    BigUnit t;
    for (i = 0; i < b.size; i++){
        t = carry + b[i];
        if (a[i] < t){
            a[i] = 10 + a[i] - t;
            carry = 1;
        }else{
            a[i] = a[i] - t;
            carry = 0;
        }
    }
    for (; i < a.size && carry; i++)
        if (a[i] == 0) a[i] = 9;
        else a[i] = a[i]-1, carry = 0;
    for (; i < a.size; i++)
        a[i] = a[i];
}
void BigIntBase::operator-=(ui B){
    BigIntBase b = BigIntBase(B);
    *this -= b;
}
void BigIntBase::operator-=(int B){
    BigIntBase b = BigIntBase(B);
    *this -= b;
}
BigIntBase& BigIntBase::operator--(){
    bool carry = 1;
    BigIntBase &a = *this;
    for (int i = 0; i < a.size && carry; i++)
        if (a[i] == 0) a[i] = 9;
        else a[i] = a[i]-1, carry = 0;
}
BigIntBase BigIntBase::operator*(BigIntBase& b) {
    BigIntBase ret;
    ret.multiply(*this, b);
    return ret;
}
BigIntBase BigIntBase::operator*(int b) {
    BigIntBase ret;
    ret.multiply(*this, b);
    return ret;
}
void BigIntBase::operator*=(BigIntBase& b) {
    multiply(*this, b);
}

void BigIntBase::operator*=(ui b){
    if (this->isZero() || b == 0) {
        setZero();
        return;
    } else if (this->isOne()){
        operator = (b); //How about f1 *= f2 and f2 == BigIntBase(1)
        return;
    } else if (b == 1) {
        return;
    }
    BigIntBase &a = *this;

    int t, carry = 0;
    ui i;

    for (i = 0; i < a.size; i++){
        t = a[i] * b + carry;
        a[i] = t % 10;
        carry = t / 10;
    }
    while(carry != 0){
        a[i++] = carry % 10;
        carry /= 10;
    }
    size = i;
}
BigIntBase BigIntBase::operator/(BigIntBase &b){
    BigIntBase ret;
    ret.divide(*this, b);
    return ret;
}

void BigIntBase::operator/=(BigIntBase& b){
    this->divide(*this, b);
}
BigIntBase BigIntBase::operator%(BigIntBase &b){
    return divide(*this,b);
}
void BigIntBase::operator%=(BigIntBase& b){
    *this = divide(*this,b);
}
string BigIntBase::toStringInBase(ui base){
    if (base == 10){
        string s(size, ' ');
        for (ui i = 0; i < size; i++)
            s[i] = (*this)[size-1-i]+'0';
        return s;
    }else{
        cout << "base " << base << " hasn't been implemented";
        return NULL;
    }
}

ostream& operator <<(ostream &os, BigIntBase& n) {
    os << n.toStringInBase(10);
    return os;
}
void BigIntBase::print(){
    cerr << toStringInBase(10) << endl;
}

BigIntBase BigIntBase::gcd(BigIntBase& B){
    BigIntBase a = *this, b = B, c;
    while(!b.isZero()){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

BigIntBase BigIntBase::pow(ui n){
    if (n == 0) return BigIntBase();
    else if (n == 1) return BigIntBase(*this);

    BigIntBase ret(*this, size);
    int i = 31;
    for (i = 31; i >= 0 && bit(n,i)==0; i--);
    for (i--; i >= 0; i--){
        ret = ret * ret;
        if (bit(n,i))
            ret *= (*this);
    }
    return ret;
}
BigIntBase BigIntBase::factorial(int n){
    BigIntBase ret = BigIntBase::ONE();
    for (int i = 1; i <= n; i++) ret *= i;
    return ret;
}
BigIntBase BigIntBase::permutation(int a, int b){
    BigIntBase ret = BigIntBase::ONE();
    while(b--) {
        ret *= a;
        a--;
    }
    return ret;
}
BigIntBase BigIntBase::combination(int a, int b){
    BigIntBase num = BigIntBase::ONE();
    BigIntBase denom = BigIntBase::ONE();
    if (a - b < b) b = a - b;
    for (int i = 1; i <= b; i++) denom *= i, num *= (a-i+1);
    return num/denom;
}

bool BigIntBase::isPalindrome(){
    for (ui i = 0; i < size/2; i++)
        if (data[i] != data[size - i - 1]) 
            return false;
    return true;
}





