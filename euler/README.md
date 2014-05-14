"Euler" math library(C++)
========

Euler is a c++ math library created with careful consideration of running speed which you can hire to hack all kinds of math problems and do a lot of cool calculation.

Euler contains an independent big integer library which can be used to operate on really big integers, with all the basic integer opeartions(+-\*/,int,long,unsigned) and some advanced algorithms provided(greatest common divisor).
Why I created "Euler"?
--------
Euler was first created when I was hacking a series of computational problems from 
[projecteuler](http://projecteuler.net/). There were a lot of repeated program routines among those questions which I thought could be combined into one integral library. As a result, the work started!

When I was writing "euler.cc" and "euler.h", some big integer problems came up me which bothered me a lot. Though I have used Java's big integer library, which is nicely designed. There is one reason that keep me in C++ stubbornly, that is its speed!

The computational problems from euler sometimes take your computer more than 10 minutes of running time, and maybe you need to run the program for several times in order to debug. I will save you much more time if I can use C++ instead of Java or other languages!

Why another big integer library
--------
At first, I tried some big integer libraries. However, none of them could meet my need.
They were either too simple to support some useful functions or too buggy to use. 

If you search "Big Integer Library" on google, there's [one library]((https://mattmccutchen.net/bigint/)) ranked #1 on the page which is just built by C++. You may think that this is wise choice since that is "chosen" by google, right? 

I'll tell you, no! It's buggy! That library does not even support calculation like:
```a = a * a; ``` or ```a = a/a``` 
Why? If your library wants to support "self-caculation" like this, you may need rewrite the code like this:
```C++ 
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
```
You may think we can still use the library "chosen" by google and write our own code like:
```C++ 
   BigInteger b = a, c = a * b;
```
How inconvinient this way is! And human do need code like ```a=a*a;```
Also, that library does not work at all when I multiply two very long integers(19695 digits). Buggy!
The last but not least thing I want to tell you about that library is that it is too slow, at least when compared to my version of implementation.

After so many frustrations and disappointments from all those libraries, I decided to implement my own!

As a result, Euler has two parts now, one for normal math problems, such as calculating the sum of all the factors from a given number, the other is for big integer problems, such as calculating the greatest common divisor(GCD) of ```123412341234123412341234123412341234```  and ```12312312312414123123412312312312312412314123```.


How to use `Big Integer Library`
============
Clone Euler to your project folder: `git clone https://github.com/hophacker/euler`
 
Make it, and all the objects and targets will go into folder "lib".

Open the file "testBigIntBase.cc", you will find lots of examples about how to use the BigInteger library.

Feel lazy to check the code? Here are some cool examples:

**(1)Get GCD of the two numbers I give above:**

```C++
    BigIntBase e("123412341234123412341234123412341234");
    BigIntBase f("12312312312414123123412312312312312412314123");
    BigIntBase g = e.gcd(f);
    cout << g << endl
```

You will get the answer is `7`

**(2)Get k-permutations of n where k=60 and n=123**

`BigIntBase a = BigIntBase::permutation(123, 60);`

`cout << a << endl`

Don't be hesitate, try it now and you will get the answer `6126426623277607558830892659050738012468992831594946549976844836830737333775846630022365422877182368153600000000000000`

**(3)Get the power of base=1234 to exponent=40**

```C++
    BigIntBase a("1234"), b = a.pow(40);
    cout << b << endl;
```

The answer is:`4493723926702212177102715930895505163093661512740028111091444935676043681712474862933310710677287635716764659044658735742976`



How to use `Normal math functions`
------------
Actually, I think it's trivial to show these examples here. You can just check the file *euler.cc* and you will get the right way by looking at the function names and my comments.


