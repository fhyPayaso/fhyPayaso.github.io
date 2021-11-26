

## 八股文汇总

+ [JavaGuide](https://github.com/Snailclimb/JavaGuide)
+ [CS-Notes](https://github.com/CyC2018/CS-Notes)
+ [Java全栈知识体系](https://www.pdai.tech/md/java/basic/java-basic-oop.html)
+ [JavaGuide(gitee)](https://snailclimb.gitee.io/javaguide/#/)

## 面经问题/细节补充
	
### Java基础	
	
+ **Java中Boolean 占几个字节**

	目前没有明确的答案:
	+ 布尔仅凭01就可标识 所以只占1bit (错误)
	+ Java中最小的类型为Byte, 占8bit， Boolean和最小的字节补齐
	+ Boolean与int处理方式相同, 占四个字节，但在bool数组时和byte处理相同, 占一个字节 (确信)

	[参考](https://blog.csdn.net/amoscn/article/details/97377833)

+ **拆箱、装箱**

	+ 装箱: Integer.valueOf() 拆箱: intValue()
	+ 常量池
		+ Integer，Short， Byte, Long常量池-128~127,
		+  Character常量池：0~127, 
		+  Boolean ： true, false
		+  Double, Float没有常量池
	
	


+ **Java泛型**
	
	+ Java中泛型是伪泛型,  可通过反射突破约束
	+ 泛型通配符, ? 、extend、 super
	+ 类型擦除与多态的冲突
	+ PECS

	[泛型擦除](https://www.cnblogs.com/wuqinglong/p/9456193.html)
	
+ **equals、==、hashCode**
	+ hashCode()的默认行为是对堆上的对象产生独特值， 两个对象不重写则hashCode不可能相等


+ **重写与重载**

	+ 重写是是在父子类之间, 重载是在一个类内
	+ 重写方法名, 参数必须一样, 重载方法名一样, 参数必须不一样
	+ 重写方法返回值, 异常抛出必须是父类方法的子类,  重载无限制
	+ 重写方法限制符不能比父类更严格, 重载无限制
	+ 重写在运行时确定, 重载编译时就确定
	+ 构造方法不能重写, 但能重载

	
+ **构造方法**

	+ 一个类没写构造方法, 则默认添加无参构造方法; 若写了有参构造方法，则不会自动添加无参构造
	+ 子类构造方法调用前要先调用父类构造方法。若子类构造方法不调super, 则父类必须有无参的构造方法供默认调用


+ **Java 集合**
	+ HashMap rehash可能发生的并发问题
	+ 集合之间各个版本的差异
		+ LinkList:  jdk1.6使用双向循环链表，jdk1.7取消循环, 只使用双向链表
		+ ArrayList: 无参构造方法 jdk1.7 默认构建10个长度的数组, jdk1.8 默认构建空数组, add时懒加载


+ **synchronized 之前为什么重**

	java的线程会一对一的映射到原生线程之上, 而监视器锁（monitor）是依赖于底层的操作系统的 Mutex Lock实现的, 每次挂起都需要从用户态切换到内核态
	
	
+ **反序列化对单例的破坏**

	反序列化时可以通过反射调用单例的构造方法, 产生多个对象, 解决方法：
	+ 采用枚举方式的单例写法
	+ 在单例类中加一个`readResolve`方法 [参考](https://blog.csdn.net/leo187/article/details/104332138)

		```
		public Object readResolve(){
	            return getInstance();
	        }
		```

+ **ThreadLocal 内存泄露问题**

	ThreadLocal的原理是每个Tread内部都有一个ThreadLocalMap，key是ThreadLocal本身的弱引用包装,  value是ThreadLocal.set的值,  弱引用在垃圾回收的时候会被清除, 所以会出现key为null的value。

	解决方法： 调用remove防止内存泄露






+ TreadLocal为什么用弱引用
+ 一个方法内部使用HashMap是否会出现线程安全问题
+ AQS中的CHL为什么用双向链表
+ AQS里有几个队列
+ ConcurrentHashMap怎么获取长度的
+ ConcurrentHashMap为什么先用CAS再用synchronized,  CAS失败线程会阻塞吗，为啥1.8相比1.7加锁方式改了
+ 偏向锁是有锁状态吗,  偏向锁会调用操作系统的lock吗
+ 偏向锁对象头什么时候写入线程信息的 , 偏向锁和锁消除有啥关系
+ JVM一般调哪些参数，堆大小参数怎么设置
+ 线程池阻塞队列参数，为什么叫阻塞队列，不能用正常的队列吗
+ happens-before原则



+ mybatis一级缓存、二级缓存
+ spring bean初始化的循环依赖问题，如何解决，如果不是单例作用域能解决吗



