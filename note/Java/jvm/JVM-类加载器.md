#### 2、类加载器


概念 : JVM设计者把类加载阶段中的“通过'类全名'来获取定义此类的二进制字节流”这个动作放到Java虚拟机外部去实现，以便让应用程序自己决定如何去获取所需要的类。实现这个动作的代码模块称为“类加载器”。

##### (1)类与类加载器

对于任何一个类，都需要由加载它的类加载器和这个类来确立其在JVM中的唯一性。也就是说，两个类来源于同一个Class文件，并且被同一个类加载器加载，这两个类才相等。


##### (2)双亲委派模型

> 从虚拟机的角度来说，只存在两种不同的类加载器：一种是启动类加载器（Bootstrap ClassLoader），该类加载器使用C++语言实现，属于虚拟机自身的一部分。另外一种就是所有其它的类加载器，这些类加载器是由Java语言实现，独立于JVM外部，并且全部继承自抽象类java.lang.ClassLoader。从Java开发人员的角度来看，大部分Java程序一般会使用到以下三种系统提供的类加载器：


+ **启动类加载器（Bootstrap ClassLoader）**：负责加载`JAVA_HOME\lib`目录中的、并且能被虚拟机识别的类库到JVM内存中(如rt.jar，所有的java.*开头的类均被Bootstrap ClassLoader加载）,如果名称不符合的类库即使放在lib目录中也不会被加载。该类加载器无法被Java程序直接引用。

+ **扩展类加载器（Extension ClassLoader）**：该加载器主要是负责加载`JAVA_HOME\lib\`，该加载器可以被开发者直接使用。

+ **应用程序类加载器（Application ClassLoader）**：该类加载器也称为系统类加载器，它负责加载用户类路径（Classpath）上所指定的类库，开发者可以直接使用该类加载器，如果应用程序中没有自定义过自己的类加载器，一般情况下这个就是程序中默认的类加载器。


我们的应用程序都是由这三类加载器互相配合进行加载的，我们也可以加入自己定义的类加载器。这些类加载器之间的关系如下图所示：

![](http://img.fhypayaso.cn/18-5-1/12560359.jpg)

如上图所示的类加载器之间的这种层次关系，就称为类加载器的双亲委派模型（Parent Delegation Model）。该模型要求除了顶层的启动类加载器外，其余的类加载器都应当有自己的父类加载器。子类加载器和父类加载器不是以继承（Inheritance）的关系来实现，而是通过组合（Composition）关系来复用父加载器的代码。


> 双亲委派模型的工作过程为：如果一个类加载器收到了类加载的请求，它首先不会自己去尝试加载这个类，而是把这个请求委派给父类加载器去完成，每一个层次的加载器都是如此，因此所有的类加载请求都会传给顶层的启动类加载器，只有当父加载器反馈自己无法完成该加载请求（该加载器的搜索范围中没有找到对应的类）时，子加载器才会尝试自己去加载。在ClassLoader源码里也可以看出：


	public abstract class ClassLoader {
	    
	    protected Class<?> loadClass(String name, boolean resolve)
	        throws ClassNotFoundException
	    {
	            //首先，检查该类是否已经被加载
	            Class c = findLoadedClass(name);
	            if (c == null) {
	                long t0 = System.nanoTime();
	                try {
	                    //先调用父类加载器去加载
	                    if (parent != null) {
	                        c = parent.loadClass(name, false);
	                    } else {
	                        c = findBootstrapClassOrNull(name);
	                    }
	                } catch (ClassNotFoundException e) {
	                    // ClassNotFoundException thrown if class not found
	                    // from the non-null parent class loader
	                }
	
	                if (c == null) {
	                    //如果父类加载器没有加载到该类，则自己去执行加载
	                    long t1 = System.nanoTime();
	                    c = findClass(name);
	
	                    // this is the defining class loader; record the stats
	                }
	            }
	            return c;
	    }
	}
	
通过上面代码可以看出，双亲委派模型是通过loadClass()方法来实现的，根据代码以及代码中的注释可以很清楚地了解整个过程其实非常简单：先检查是否已经被加载过，如果没有则调用父加载器的loadClass()方法，如果父加载器为空则默认使用启动类加载器作为父加载器。如果父类加载器加载失败，则先抛出ClassNotFoundException，然后再调用自己的findClass()方法进行加载。
	
> 使用这种模型来组织类加载器之间的关系的好处是Java类随着它的类加载器一起具备了一种带有优先级的层次关系。例如java.lang.Object类，无论哪个类加载器去加载该类，最终都是由启动类加载器进行加载，因此Object类在程序的各种类加载器环境中都是同一个类。否则的话，如果不使用该模型的话，如果用户自定义一个java.lang.Object类且存放在classpath中，那么系统中将会出现多个Object类，应用程序也会变得很混乱。如果我们自定义一个rt.jar中已有类的同名Java类，会发现JVM可以正常编译，但该类永远无法被加载运行。

