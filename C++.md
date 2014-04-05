##How to convert multiple integers into string efficiently?
```C++
    #include<sstream>
    stringstream ss;
    ss << 2 << 3 << 4 << 5;
    string s  = ss.str();;

```