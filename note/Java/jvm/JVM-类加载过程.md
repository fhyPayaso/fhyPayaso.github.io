##Java基础之-JVM-类加载过程


概念: 虚拟机把描述类的数据从Class文件加载到内存，并对数据进行校验，转换，解析和初始化，最终形成可以被虚拟机直接使用的Java类型，这就是Java的类加载的过程。

在Java语言中，类的加载，连接和初始化过程都是在程序运行期间完成的(动态性)，这样虽然会增加类的加载性能开销，但是这也为java应用程序提供高度的灵活性。


类从被加载到虚拟机内存中开始，到卸载出内存为止，它的生命周期包括了：**加载(Loading)、验证(Verification)、准备(Preparation)、解析(Resolution)、初始化(Initialization)、使用(Using)、卸载(Unloading)**七个阶段，其中验证、准备、解析三个部分统称**链接**。


加载、验证、准备、初始化和卸载这5个阶段的顺序是确定的，类的加载过程必须按照这种顺序按部就班地开始，而解析阶段则不一定：它在某些情况下可以在初始化阶段之后再开始，这是为了支持Java语言的运行时绑定（也称为动态绑定或晚期绑定）。另外注意这里的几个阶段是按顺序开始，而不是按顺序进行或完成，因为这些阶段通常都是互相交叉地混合进行的，通常在一个阶段执行的过程中调用或激活另一个阶段。

![](http://img.hellofhy.cn/18-5-1/89563219.jpg)


> 加载阶段

### 1. 加载 : 查找并加载类的二进制数据

加载时类加载过程的第一个阶段，在加载阶段，虚拟机需要完成以下三件事情：

+ 通过一个类的全类名来获取定义此类的二进制字节流,途径可能有多种，包括:

	+ 从本地系统中直接加载
	+ 通过网络下载.class文件
	+ 从zip，jar等归档文件中加载.class文件
	+ 从专有数据库中提取.class文件
	+ 将Java源文件动态编译为.class文件

+ *将这个字节流所代表的静态存储结构转化为方法区的运行时数据结构*

+ 在内存中生成一个代表这个类的java.lang.Class对象，作为方法区这个类的各种数据访问入口

相对于类加载过程的其他阶段，加载阶段(准确地说，是加载阶段中获取类的二进制字节流的动作)是开发期可控性最强的阶段，因为加载阶段可以使用系统提供的类加载器(ClassLoader)来完成，也可以由用户自定义的类加载器完成，开发人员可以通过定义自己的类加载器去控制字节流的获取方式。

加载阶段完成后，虚拟机外部的二进制字节流就按照虚拟机所需的格式存储在方法区之中，方法区中的数据存储格式有虚拟机实现自行定义，虚拟机并未规定此区域的具体数据结构。然后在java堆中实例化一个java.lang.Class类的对象，这个对象作为程序访问方法区中的这些类型数据的外部接口。

![](https://img-blog.csdn.net/20180807193502837?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2Z4a2NzZG4=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

---

> 链接阶段


加载阶段和连接阶段（Linking）的部分内容（如一部分字节码文件格式验证动作）是交叉进行的，加载阶段尚未完成，连接阶段可能已经开始，**但这些夹在加载阶段之中进行的动作，仍然属于连接阶段的内容，这两个阶段的开始时间仍然保持着固定的先后顺序，加载阶段必定早于连接阶段开始。**


### 2. 验证 : 确保被加载的类的正确性

**(1) 文件格式验证** : 第一阶段要验证字节流是否符合Class文件格式的规范，例如：
		
+ 是否以魔数0xCAFEBABE开头
+ 主次版本号是否在当前虚拟机的处理范围之内
+ *常量池中的常量是否有不被支持的类型*

**(2) 元数据验证**: 第二阶段是对字节码描述的信息进行语义分析*（注意：对比javac编译阶段的语义分析）*，以保证其描述的信息符合Java语言的规范的要求，例如:

+ 一个类是否有父类（除了java.lang.Object之外，所有的类都应当有父类）
+ 这个类的父类是否继承了不允许被继承的类
+ 如果这个类不是抽象类，是否实现了其父类或者接口要求实现的所有的方法
+ 类中的字段，方法是否与父类产生矛盾

**(3) 字节码验证**: 第三阶段主要目的是通过数据流和控制流分析，确定程序语法是否是合法的，符合逻辑的。在第二阶段对**元数据信息中的数据类型**做完校验后，这个阶段将对**类的方法体**进行校验分析，保证被校验类的方法在运行时候不会做出对虚拟机有危害的事情。例如:

+ 保证方法体中的类型转换是有效的，例如可以把一个子类对象赋给父类数据类型，这是安全的，但是把父类对象赋值给子类数据类型则是危险的

+ 保证跳转指令不会跳转到方法体以外的字节码指令上

+ 保证任意时刻操作数栈的数据类型与指令代码序列都能配合工作，例如不会出现类似这种情况：在操作栈中放置一个int类型数据，使用却将他按照long类型使用
	
**(4) 符号引用验证**: 第四阶段的校验确保解析动作能正确执行,发生在虚拟机将符号引用转化为直接引用的时候，这个转换动作发生在连接的第三阶段--解析中发生，符号引用可以看做是对类自身以外的信息进行匹配性校验，例如:
		
+ 符号引用中通过字符串描述的全限定名是否能找到对应的类
+ 在指定的类中是否存在符合方法的字段描述符以及简单名称所描述的方法和字段
+ 符号引用中的类，字段，方法的访问性是否可以被当前类访问。

验证阶段是非常重要的，但不是必须的，它对程序运行期没有影响，如果所引用的类经过反复验证，那么可以考虑采用-Xverifynone参数来关闭大部分的类验证措施，以缩短虚拟机类加载的时间。

---

### 3. 准备：为类的静态变量分配内存，并将其初始化为默认值

准备阶段是正式为类变量分配内存并设置类变量初始值的阶段，这些内存都将在方法区中分配。对于该阶段有以下几点需要注意：
	
+ 这时候进行内存分配的仅包括类变量（static），而不包括实例变量，实例变量会在对象实例化时随着对象一块分配在Java堆中。
+ 这里所设置的初始值通常情况下是数据类型默认的零值（如0、0L、null、false等），而不是被在Java代码中被显式地赋予的值。

	假设一个类变量的定义为：`public static int value = 3`

	那么变量value在准备阶段过后的初始值为0，而不是3，因为这时候尚未开始执行任何Java方法，而把value赋值为3的putstatic指令是在程序编译后，存放于类构造器<clinit>（）方法之中的，所以把value赋值为3的动作将在初始化阶段才会执行。
		
	![](http://img.hellofhy.cn/18-5-1/90110776.jpg)
	

+ 如果类字段的字段属性表中存在ConstantValue属性，即同时被final和static修饰，那么在准备阶段变量value就会被初始化为ConstValue属性所指定的值。

	假设上面的类变量value被定义为： `public static final int value = 3`
	
	编译时Javac将会为value生成ConstantValue属性，在准备阶段虚拟机就会根据ConstantValue的设置将value赋值为3。
	
	

	
> 这里还需要注意如下几点：

+ 对基本数据类型来说，对于类变量（static）和全局变量，如果不显式地对其赋值而直接使用，则系统会为其赋予默认的零值，而对于局部变量来说，在使用前必须显式地为其赋值，否则编译时不通过。从上面可以得知static变量的默认赋值工作在本阶段完成。

	```
	class Test {
	
	    public static int sTest;
	    public static int sTest0 = sTest + 1;
	
	    public int mTest;
	    public int mTest0 = mTest + 1;
	
	
	    public void test() {
	
	        int test, res;
	
	        // 静态变量、全局变量不初始化可以使用，直接默认值
	        res = sTest + 1;
	        res = mTest + 1;
	        // 局部变量不初始化则会报错
	        res = test + 1;
	    }
	}
	```

	
+ 对于同时被static和final修饰的常量，必须在声明的时候就为其显式地赋值，否则编译时不通过；

	```
	public static final int TEST; // 报错
	```

	而只被final修饰的常量则既可以在声明时显式地为其赋值，也可以在类初始化时显式地为其赋值，总之，在使用前必须为其显式地赋值，系统不会为其赋予默认零值。

	```
    public final int TEST0; //  报错
    
    public final int TEST1;

    public Test() {
        this.TEST1 = 0;
    }
	```

	
+ 对于引用数据类型reference来说，如数组引用、对象引用等，如果没有对其进行显式地赋值而直接使用，系统都会为其赋予默认的零值，即null。

+ 如果在数组初始化时没有对数组中的各元素赋值，那么其中的元素将根据对应的数据类型而被赋予默认的零值。


![](https://img-blog.csdn.net/20180807193543399?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2Z4a2NzZG4=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
	
---
		
### 4. 解析 : 把类中的符号引用转换为直接引用

+ **符号引用** : 符号引用是一组符号来描述所引用的目标对象，符号可以是任何形式的字面量，只要使用时能无歧义地定位到目标即可。符号引用与虚拟机实现的内存布局无关，引用的目标对象并不一定已经加载到内存中。

+ **直接引用** : 直接引用可以是直接指向目标对象的指针、相对偏移量或是一个能间接定位到目标的句柄。直接引用是与虚拟机内存布局实现相关的，同一个符号引用在不同虚拟机实例上翻译出来的直接引用一般不会相同，如果有了直接引用，那引用的目标必定已经在内存中存在。

	解析动作主要针对类或接口、字段、类方法、接口方法、方法类型、方法句柄和调用点限定符7类符号引用进行。对应常量池中类型如下

	常量池中类型 | 符号引用
	--- | ---
	CONSTANT\_Class\_Info | 类、接口
	CONSTANT\_Fieldref\_Info | 字段
	CONSTANT\_Methodef\_Info | 类方法
	CONSTANT\_InterfaceMethoder\_Info | 接口方法
	CONSTANT\_MethodType\_Info | 方法类型
	CONSTANT\_MethodHandle\_Info | 方法句柄
	CONSTANT\_InvokeDynamic\_Info | 调用点限定符(和invokedynamic指令相关)

详细的内容可以看 [浅析 JVM 中的符号引用与直接引用](http://patchouli-know.com/2017/03/11/jvm-symbol-link/)，个人感觉可以类比寄存器寻址方式中的直接寻址和间接寻址

---	
	
> 初始化阶段

### 5.初始化: 执行类构造器方法

类的初始化阶段是类加载过程的最后一步，到了初始化阶段，才真正开始执行类中定义的java程序代码。在准备阶段，类变量已赋过一次系统要求的初始值，而在初始化阶段，则是根据程序员通过程序制定的主观计划去初始化类变量和其他资源，或者可以从另外一个角度来表达：初始化阶段是执行类构造器\<clinit\>()方法的过程。



#### (1)init和clinit区别

**执行时机不同** : init是对象构造器方法，也就是说在程序执行 new 一个对象调用该对象类的 constructor 方法时才会执行init方法，而clinit是类构造器方法，也就是在jvm进行类加载—–验证—-解析—–初始化，中的初始化阶段jvm会调用clinit方法。

**执行目的不同** : init是instance实例构造器，对非静态变量解析初始化，而clinit是class类构造器对静态变量，静态代码块进行初始化。看看下面的这段程序就很清楚了。


```
class X {

   static Log log = LogFactory.getLog(); // <clinit>

   private int x = 1;   // <init>

   X(){
      // <init>
   }

   static {
      // <clinit>
   }
}

```

#### (2)clinit详解
	
+ `<clinit>()`方法是由编译器自动收集类中的所有变量的赋值动作和静态语句块中的语句合并产生的，他按照代码中出现的顺序收集，静态语句块中只能访问到定义在静态语句块之前的变量，定义在他之后的，在静态语句块中只能赋值不能访问,例如:

	```
	public class Test {
	
	    static {
	        i = 1; // 可以赋值
	        System.out.println(i);//不能访问,编译器会提示"非法向前引用"
	    }
	
	    static int i = 0;
	
	    static {
	        System.out.println(i);//可以访问
	    }
	}
	```
	我们修改一下

	```
	public class Test {
	    static {
	        i = 2;
	    }
	
	    static int i = 1;
	
	    public static void main(String args[]) {
	        System.out.println(i); // 输出结果为1
	    }
	}
	```
	在准备阶段我们知道i=0，然后类初始化阶段按照顺序执行，首先执行static块中的i=2,接着执行static赋值操作i=1,最后在main方法中获取i的值为1。


+ `<clinit>()`实例构造器`<init>()`方法不同，它不需要显示地调用父类构造器,同时在子类类构造器方法在执行之前必须保证自己父类的类构造器方法已经执行完毕,因此在虚拟机中第一个被执行的<clinit>()方法的类肯定是`java.lang.Object`,下面写个例子


	```
	class Test0 {
	
	    static {
	        System.out.println("Test0");
	    }
	}
	
	class Test1 extends Test0{
	
	    static {
	        System.out.println("Test1");
	    }
	
	    public static int value = 123;
	
	    public Test1() {
	        System.out.println("Test1 init");
	    }
	}
		
	public class Main {
	
	    public static void main(String[] args) {
	
	        System.out.println(Test2.value);
	    }
	}
	
	```
	
	输出结果如下，说明先调用了父类的`<clinit>()`
	
	```
	Test0
	Test1
	123
	```
	

+ `<clinit>()`并不是必须的，如果一个类中没有静态语句块，也没有对变量的赋值操作，那么编译器可以不为这个类生成`<clinit>()`方法。

+ 接口中不能使用静态语句块，但仍然有变量初始化的赋值操作，因此接口与类一样都会生成`<clinit>()`方法，但是接口与类不同的是，执行接口的`<clinit>()`方法不需要先执行父类接口的`<clinit>()`方法，只有父类接口中定义的变量使用时父类接口才会初始化，另外接口实现类在初始化时也一样不会执行接口的`<clinit>()`方法。

+ 虚拟机会保证一个类的`<clinit>()`方法在多线程环境中被正确的加锁、同步，如果多个线程同时去初始化一个类，那么只会有一个线程去执行这个类的`<clinit>()`方法，其他线程都需要阻塞等待，直到活动线程执行`<clinit>()`方法完毕。如果在一个类的`<clinit>()`方法中有耗时很长的操作，就可能造成多个线程阻塞，在实际应用中这种阻塞往往是隐藏的。

	```
	public class DealLoopTest {
	    
	    static class DeadLoopClass {
	        static {
	            if (true) {
	                System.out.println(Thread.currentThread() + "init DeadLoopClass");
	                while (true) {
	                }
	            }
	        }
	    }
	
	    public static void main(String[] args) {
	        Runnable script = new Runnable() {
	            public void run() {
	                System.out.println(Thread.currentThread() + " start");
	                DeadLoopClass dlc = new DeadLoopClass();
	                System.out.println(Thread.currentThread() + " run over");
	            }
	        };
	
	        Thread thread1 = new Thread(script);
	        Thread thread2 = new Thread(script);
	        thread1.start();
	        thread2.start();
	    }
	}

	```
	输出结果如下，说明`<clinit>()`方法被正确加锁，第二个线程被阻塞
	
	```
	Thread[Thread-0,5,main] start
	Thread[Thread-1,5,main] start
	Thread[Thread-0,5,main]init DeadLoopClass
	```
	
	需要注意的是，其他线程虽然会被阻塞，但如果执行`<clinit>()`方法的那条线程退出`<clinit>()`方法后，其他线程唤醒之后不会再次进入`<clinit>()`方法。同一个类加载器下，一个类型只会初始化一次。把上面的死循环改成`Thread.sleep(100)`

	输出结果如下,说明类构造器方法只能被执行一次
	
	```
	Thread[Thread-1,5,main] start
	Thread[Thread-0,5,main] start
	Thread[Thread-1,5,main]init DeadLoopClass
	Thread[Thread-0,5,main] run over
	Thread[Thread-1,5,main] run over
	
	```
	
#### (3)初始化步骤

JVM初始化一个类包含如下几个步骤：

+ 1.假如这个类还没有被加载和连接，则程序先加载并连接该类；

+ 2.假如该类的直接父类还没有被初始化，则先初始化其直接父类（直接父类也依次执行1，2，3 保证类依赖的所有父类都会被初始化）；

+ 3.假如类中有初始化语句，则系统依次执行这些初始化语句。


#### (4)初始化条件

虚拟机规范严格规定了有且只有5中情况（jdk1.7）必须对类进行“初始化”（而加载、验证、准备自然需要在此之前开始）：



+ 遇到new,getstatic,putstatic,invokestatic这失调字节码指令时，如果类没有进行过初始化，则需要先触发其初始化。生成这4条指令的最常见的Java代码场景是：
	+ 使用new关键字实例化对象的时候
	+ 读取或设置一个类的静态字段（被final修饰、已在编译器把结果放入常量池的静态字段除外）的时候
	+ 调用一个类的静态方法的时候。
+ 使用java.lang.reflect包的方法对类进行反射调用的时候，如果类没有进行过初始化，则需要先触发其初始化。
+ 当初始化一个类的时候，如果发现其父类还没有进行过初始化，则需要先触发其父类的初始化。
+ 当虚拟机启动时，用户需要指定一个要执行的主类（包含main()方法的那个类），虚拟机会先初始化这个主类。
+ 当使用jdk1.7动态语言支持时，如果一个java.lang.invoke.MethodHandle实例最后的解析结果REF\_getstatic,REF\_putstatic,REF\_invokeStatic的方法句柄，并且这个方法句柄所对应的类没有进行初始化，则需要先出触发其初始化。

> 举两个例子

> 仅仅通过数组定义来引用类，不会触发此类的初始化

> 常量在编译阶段会存入调用类的常量池中，本质上并没有直接引用到定义常量的类，因此不会触发定义常量的类的初始化

![](https://img-blog.csdn.net/20180807193636720?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2Z4a2NzZG4=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)



通过分析下面例子来总结初始化过程

```
public class StaticTest {

    public static void main(String[] args) {
        staticFunction();
    }

    static StaticTest st = new StaticTest();

    static {
        System.out.println("1");
    }

    {
        System.out.println("2");
    }

    public StaticTest() {
        System.out.println("3");
        System.out.println("a=" + a + ",b=" + b);
    }

    public static void staticFunction() {
        System.out.println("4");
    }

    int a = 110;
    static int b = 112;
}

```

输出结果为

```
2
3
a=110,b=0
1
4
```


这里主要的点之一：**实例初始化不一定要在类初始化结束之后才开始初始化**。
 

类的生命周期是：加载->验证->准备->解析->初始化->使用->卸载，只有在准备阶段和初始化阶段才会涉及类变量的初始化和赋值，因此只针对这两个阶段进行分析
  

类的准备阶段需要做是为类变量分配内存并设置默认值，因此类变量st为null、b为0；（需要注意的是如果类变量是final，编译时javac将会为value生成ConstantValue属性，在准备阶段虚拟机就会根据ConstantValue的设置将变量设置为指定的值，如果这里这么定义：static final int b=112,那么在准备阶段b的值就是112，而不再是0了。）
  

类的初始化阶段需要做是执行类构造器（类构造器是编译器收集所有静态语句块和类变量的赋值语句按语句在源码中的顺序合并生成类构造器，对象的构造方法是`<init>()`，类的构造方法是`<clinit>()`，可以在堆栈信息中看到），因此先执行第一条静态变量的赋值语句即st = new StaticTest ()，此时会进行对象的初始化，对象的初始化是先初始化成员变量再执行构造方法，因此设置a为110->打印2->执行构造方法(打印3,此时a已经赋值为110，但是b只是设置了默认值0，并未完成赋值动作)，等对象的初始化完成后继续执行之前的类构造器的语句，接下来就不详细说了，按照语句在源码中的顺序执行即可。

### 6.卸载

#### 类的生命周期

当Sample类被加载、连接和初始化后，它的生命周期就开始了，当代表Sample类的Class对象不再被引用，即不可触及时，Class对象就会结束生命周期，Sample类在方法区内的数据也会被卸载，从而结束Sample类的生命周期。由此可见，一个类何时结束生命周期，取决于代表它的Class对象何时结束生命周期。

#### 引用关系

+ **类加载器和Class对象**：

　　在类加载器的内部实现中，用一个Java集合来存放所加载类的引用，另一方面，一个Class对象总是会引用它的类加载器，调用Class对象的getClassLoader()方法，就能获得它的类加载器。由此可见，Class实例和加载它的加载器之间为**双向关联关系**。

+ **类、类的Class对象、类的实例对象**：

　　一个类的实例总是引用代表这个类的Class对象，在Object类中定义了getClass()方法，这个方法返回代表对象所属类的Class对象的引用。此外，所有的Java类都有一个静态属性class，它引用代表这个类的Class对象。
　　
　　
#### 类的卸载

**由Java虚拟机自带的类加载器所加载的类，在虚拟机的生命周期中，始终不会被卸载**。前面介绍过，Java虚拟机自带的类加载器包括启动类加载器、扩展类加载器和系统类加载器，**Java虚拟机本身会始终引用这些类加载器**，而这些类加载器则会始终引用它们所加载的类的Class对象，因此这些Class对象始终是可触及的，**由用户自定义的类加载器加载的类是可以被卸载的**。

　　
![](https://images0.cnblogs.com/i/325852/201403/111825528931093.png)

loader1变量和obj变量间接引用代表Sample类的Class对象，而objClass变量则直接引用它，如果程序运行过程中，将上图左侧三个引用变量都置为null，此时Sample对象结束生命周期，MyClassLoader对象结束生命周期，代表Sample类的Class对象也结束生命周期，Sample类在方法区内的二进制数据被卸载，当再次有需要时，会检查Sample类的Class对象是否存在，如果存在会直接使用，不再重新加载；如果不存在Sample类会被重新加载，在Java虚拟机的堆区会生成一个新的代表Sample类的Class实例(可以通过哈希码查看是否是同一个实例)。




参考博客 : 

[JVM（三）：类加载机制（类加载过程和类加载器）](https://blog.csdn.net/boyupeng/article/details/47951037)

[java类的加载机制](https://www.cnblogs.com/ityouknow/p/5603287.html)

[深入理解jvm--Java中init和clinit区别完全解析](https://blog.csdn.net/u013309870/article/details/72975536)

[Java虚拟机类加载机制](https://blog.csdn.net/u013256816/article/details/50829596)

[Java虚拟机类加载机制——案例分析](https://blog.csdn.net/u013256816/article/details/50837863)


[【JVM总结】类的加载、连接和初始化](https://blog.csdn.net/fxkcsdn/article/details/81487032)

[JVM学习之类的卸载机制](https://www.cnblogs.com/sunfie/p/5133289.html)