# C++ 新特性关键字

#### 1.noexcept

+ 版本: C++11

+ 作用 : 该关键字告诉编译器，函数中不会发生异常,这有利于编译器对程序做更多的优化。如果在运行时，noexecpt函数向外抛出了异常（如果函数内部捕捉了异常并完成处理，这种情况不算抛出异常），程序会直接终止，调用std::terminate()函数，该函数内部会调用std::abort()终止程序。


+ 例子: 

    ```
    //C++11之前
    void swap(Type& x, Type& y) throw()   
    {
            x.swap(y);
    }
    //C++11
    void swap(Type& x, Type& y) noexcept  
    {
        x.swap(y);
    }
    ```

    有条件的noexcept


    ```
    // 如果操作x.swap(y)不发生异常，那么函数swap(Type& x, Type& y)一定不发生异常。
    void swap(Type& x, Type& y) noexcept(noexcept(x.swap(y)))
    {
        x.swap(y);
    }
    ```

#### 2.constexpr


+ 版本: C++11/14

+ 作用: constexpr修饰的表达式可以在编译期间计算出结果, 在运行时直接作为常量使用


+ 特点: 

	C++11中的constexpr指定的函数返回值和参数必须要保证是字面值，而且必须有且只有一行return代码，这给函数的设计者带来了更多的限制，比如通常只能通过return 三目运算符+递归来计算返回的字面值。

	而C++14中只要保证返回值和参数是字面值就行了，函数体中可以加入更多的语句，方便了更灵活的计算。
	
+ 例子:

	```
	const int func() 
	{
	    return 10;
	}
	main()
	{
	  int arr[func()];
	}
	//error : 函数调用在常量表达式中必须具有常量值
	
	```
	可以看到const修饰的函数并不能当做常数使用，因为在编译期间并不能进行优化，而是到运行时才能确定值
	
	```
	constexpr func() 
	{
	    return 10;
	}
	main()
	{
	  int arr[func()];
	}
	//编译通过
	
	```
	在编译期间就可以计算出函数值为10
	


#### 3.explicit


+ 作用: C++中的explicit关键字只能用于修饰只有一个参数或全部参数都有默认值的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的, 跟它相对应的另一个关键字是implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式).


+ 例子: 


	```
	#include <iostream>
	using namespace std;
	
	class A
	{
	public:
	    //这里用explicit关键词来修饰类构造函数.
	    explicit A(int i = 5, int j = 10)
	    {
	        m_a = i;
	        m_b = j;
	    }
	private:
	    int m_a;
	    int m_b;
	};
	
	int main()
	{
	    A s;
	    //这样直接赋值,会被提示错误,因为explicit抑制隐式转换的进行
	    s = 10;//这样会报错!!!
	    //当然显示转换还是可以的.
	    s = A(20);
	
	    system("pause");
	    return 0;
	}
	```






#### 4.assert

+ 作用 : 作用是如果它的条件返回错误，则终止程序执行。

+ 头文件: `<cassert>/ <assert.h>`

+ 例子: 

    ```

    int resetBufferSize(int nNewSize)
    {
    　　//利用assert函数检验参数合法性
    　　assert(nNewSize >= 0);
    　　assert(nNewSize <= MAX_BUFFER_SIZE);
    　　...
    }
    ```

#### 5.reinterpret_cast

+ 作用: reinterpret_cast运算符是用来处理无关类型之间的转换；它会产生一个新的值，这个值会有与原始参数（expressoin）有完全相同的比特位。

+ 使用场景：

    + 从指针类型到一个足够大的整数类型
    + 从整数类型或者枚举类型到指针类型
    + 从一个指向函数的指针到另一个不同类型的指向函数的指针
    + 从一个指向对象的指针到另一个不同类型的指向对象的指针
    + 从一个指向类函数成员的指针到另一个指向不同类型的函数成员的指针
    + 从一个指向类数据成员的指针到另一个指向不同类型的数据成员的指针

+ 例子:

    ```
    unsigned int val = reinterpret_cast<unsigned int>( p ); // void *p
    ```





#### static_cast



反正我感觉无论我之后如何读研找工作, 最终的目的都是在好一点的城市买一个房子然后和小可爱结婚, 为了达成这个目标, 我觉得我们两个人应该是在统一战线上的, 我们两个的任何选择都是相互影响紧密相关的, 


就像我之前说过的, 婚姻是两个人从原生家庭走出来组建新家庭的事, 这个新家庭的主人就是你和我


不知道说这么多小可爱会不会觉得烦, 但这确实是我的心里话













