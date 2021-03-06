
## c++基础

### 1.内联函数inline

函数调用在执行时，首先要在栈中为形参和局部变量分配存储空间，然后还要将实参的值复制给形参，接下来还要将函数的返回地址放入栈中，最后才跳转到函数内部执行。函数执行 return 语句返回时，需要从栈中回收形参和局部变量占用的存储空间，然后从栈中取出返回地址，再跳转到该地址继续执行。

这样在调用函数时，相比于直接执行代码，会增加一定的额外开销。一般情况下可以忽略不计。但如果一个函数内部只有几条语句，执行时间本来就非常短，那么这个函数调用产生的额外开销和函数本身执行的时间相比，就显得不能忽略了。

C++ 用 inline 关键字较好地解决了函数调用开销的问题。在 C++ 中，可以在定义函数时，在返回值类型前面加上 inline 关键字。如：

```
inline int Max (int a, int b)
{
    if(a >b)
        return a;
    return b;
}
```

+ 与普通函数的区别

	当编译器处理调用内联函数的语句时，不会将该语句编译成函数调用的指令，而是直接将整个函数体的代码插人调用语句处，就像整个函数体在调用处被重写了一遍一样。这个过程是在编译期间进行的，会直接增加代码体积，是一种空间换时间的方法。
	
+ 缺点

	内联函数过大反而会影响代码效率，需要注意
	
	+ 代码行数不易过多，一般在10行之内
	+ 不要使用循环和switch语句



**ps** :  有些函数即使声明为内联的也不一定会被编译器内联, ; 比如虚函数和递归函数就不会被正常内联. 通常, 递归函数不应该声明成内联函数.(递归调用堆栈的展开并不像循环那么简单, 比如递归层数在编译时可能是未知的, 大多数编译器都不支持内联递归函数). 有的没有被inline修饰的函数在一些编译器中也可能被编译为内联
