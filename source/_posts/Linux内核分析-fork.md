---
title: linux内核分析——fork()
date: 2019-01-07
categories: Linux
tags: 
- Linux
copyright: true
---


## linux内核分析——fork()

> 分析版本 linux-4.18



### 一、c++层面的fork()与vfork()

在Unix环境下编写c/c++程序，可以通过引入`#include<unistd.h>`头文件来使用其中的`fork()`和`vfork()`函数,以课设题目中要求的程序举例,

```
int main()
{
    pid_t pid;
    string input, output;
    cin >> input;
    pid = fork();
    // pid = vfork();

    if (pid < 0)
    {
        cout << "error fork";
    }
    else if (pid == 0)
    {
        // 在子进程中进行转换操作
        output = change(input);
        // cout << "child  ,id : " << getpid() << endl;
    }
    else
    {
        // 在父进程中进行输出操作
        cout<<" 输出结果为 : "<<output<<endl;
        // cout << "father ,id : " << getpid() << endl;
    }
    exit(0);
}
```

其中`change()`函数功能为将输入的字符串进行大小写变换，具体实现如下

```
string change(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return str;
}
```
下面分别调用fork和vfork两个函数，观察结果

+ fork()

	<img src="http://img.hellofhy.cn/19-1-7/99468250.jpg" width="60%" height="50%" />

	可以看到转换函数并未产生作用

+ vfork()

	<img src="http://img.hellofhy.cn/19-1-7/38451921.jpg" width="60%" height="50%" />

	输入的字符串转换成功
	
	
通过查阅资料，简单总结一下`fork`和`vfork`异同

##### 相同点

+ 两者的返回值代表的含义相同，当进程复制完成后，会将当前进程刚复制好的子进程的pid返回，而子进程没有自己的子进程，所以返回0，即:
	
	+ 返回值-1 : 复制进程出错
	+ 返回值0 : 当前为子线程
	+ 返回值大于0 : 当前为父亲线程

+ 无论是fork还是vfork，在执行完后，都会变成两个进程，下面的代码会被执行两次，每个进程各执行一次


##### 不同点

+ 内存空间的使用
	+ fork操作产生的子进程是将父亲进程的数据段、代码段拷贝一份，之后执行代码两者相互不影响
	+ 而vfork操作的子进程和父进程共用一块数据段、栈和堆

+ 执行顺序
	+ fork操作之后的两个进程执行顺序随机，由调度器决定
	+ vfork保证子进程先运行，在调用exec 或exit 之后父进程才可能被调度运行。如果在
   调用这两个函数之前子进程依赖于父进程的进一步动作，则会导致死锁。


所以对于刚才的两次结果来说，fork之后两个进程空间不影响，子进程的操作不会导致父进程变量的改变，而vfork则可以做到; 

另外在调用vfork时，程序结束的标志并不能使用`return0`,而要用`exit(0)`，因为vfork子进程必然先执行，return操作会破坏函数栈，且函数栈与父进程共用，子进程完毕后父进程再想执行就会因为函数栈缺失发生段错误，所以一定要直接`exit(0)`


### 二、glibc与系统调用

#### 1、glibc与libc的区别

glibc 和 libc 都是 Linux 下的 C 函数库，不过

+ libc 是 Linux 下的 ANSI C 函数库
+ glibc 是 Linux 下的 GUN C 函数库

那么ANSI C和GUN C有什么区别呢

+ ANSI C是基本的C语言函数库，包含了C语言最基本的库函数。这个库可以根据 头文件划分为 15 个部分，包括`<math.h>,<stdio.h>`...等

+ GNU C 函数库类似于第三方插件。Linux 的一些操作是用 C 语言实现的，因此，GUN 组织开发了一个 C 语言的库 以便让我们更好的利用 C 语言开发基于 Linux 操作系统的程序。

不过现在的不同的 Linux 的发行版本对这两个函数库有不同的处理方法，有的可能统一集成在glibc里了，例如ubuntu。 

所以说，我们编写程序时所调用的fork()函数，是在libc/glibc中实现的，而对于fork这种系统调用，glibc并没有实际的操作，只是调用了操作系统所提供的**系统调用**接口。

### 2、系统调用

提到系统调用，先回顾下操作系统**内核态**和**用户态**的概念 :

+ **用户态** : 当一个进程在执行用户自己的代码时处于用户运行态（用户态），此时特权级最低，为Ring3，是普通的用户进程运行的特权级，大部分用户直接面对的程序都是运行在用户态。Ring3状态不能访问Ring0的地址空间，包括代码和数据；

+ **内核态** : 当一个进程因为系统调用陷入内核代码中执行时处于内核运行态（内核态），此时特权级最高，为0级。执行的内核代码会使用当前进程的内核栈，每个进程都有自己的内核栈。

用户运行一个程序，该程序创建的进程开始时运行自己的代码，处于用户态。如果要执行文件操作、网络数据发送等操作必须通过write、send等系统调用，这些系统调用会调用内核的代码。进程会切换到Ring0，然后进入内核地址空间去执行内核代码来完成相应的操作。内核态的进程执行完后又会切换到Ring3，回到用户态。

这样，用户态的程序就不能随意操作内核地址空间，具有一定的安全保护作用。这说的保护模式是指通过内存页表操作等机制，保证进程间的地址空间不会互相冲突，一个进程的操作不会修改另一个进程地址空间中的数据。

我们所研究的fork便是一种系统调用，调用时会发生从用户态到内核态的切换，去执行内核部分的代码，所以fork的真正实现在linux内核代码中才可以看到


### 三、内核代码分析

#### 1、 fork与vfork的系统调用 

首先我们先看下fork和vfork的系统调用定义中具体操作，这里研究的是4.18版本的Linux内核:

+ **sys_fork**

	<img src="http://img.hellofhy.cn/19-1-7/46125080.jpg" width="60%" height="50%" />
	
	sys_fork中先检查了MMU的配置，如果支持nommu模式直接调用_do_fork方法，否则返回错误。
	
	这里的MMU是指存**储器管理单元**(*Memory Management Unit*),具有内存映射功能，而内存映射的行为会影响到`fork(),vfork(),clone()和ptrace()`的工作方式。

+ **sys_vfork**

	<img src="http://img.hellofhy.cn/19-1-7/7147810.jpg" width="60%" height="50%" />
	
	sys_vfork则是直接调用_do_fork方法，不过第一个参数为几个标志的或运算结果
	

所以无论是fork还是vfork，真正的操作都是在 `_do_fork()`函数中完成的，这时的函数调用情况为

<img src="http://img.hellofhy.cn/19-1-7/18245292.jpg" width="70%" height="70%" />



#### 2、 \_do\_fork()源码分析

##### (1) 参数分析

<img src="http://img.hellofhy.cn/19-1-7/16527447.jpg" width="40%" height="40%" />


+ **clone_flags** : 用来控制进程复制过的一些属性信息, 描述你需要从父进程继承那些资源。该标志位的4个字节分为两部分。最低的一个字节为子进程结束时发送给父进程的信号代码，通常为SIGCHLD；剩余的三个字节则是各种clone标志的组合（本文所涉及的标志含义详见下表），也就是若干个标志之间的或运算。通过clone标志可以有选择的对父进程的资源进行复制

+ **stack_start** : 子进程用户态堆栈的地址 

+ **stack_size** : 用户状态下栈的大小, 该参数通常是不必要的, 总被设置为0 

+ **parent_tidptr** : 父进程在用户态下pid的地址，该参数在CLONE\_PARENT\_SETTID标志被设定时有意义 

+ **child_tidptr** : 子进程在用户太下pid的地址，该参数在CLONE\_CHILD\_SETTID标志被设定时有意义 

+ **tls** : linux2.5.32以后, 添加了**TLS**(*Thread Local Storage*)机制, 该参数代替了老版本的regs 

其中`clone_flags`的含义如下表所示:


<img src="http://img.hellofhy.cn/19-1-9/58914826.jpg" width="80%" />


##### (2)内容分析

<img src="http://img.hellofhy.cn/19-1-7/55599425.jpg" width="60%" />

+ 文档注释里所说的ptrace是一个系统调用函数，提供了一个进程（the “tracer”）监察和控制另一个进程（the “tracee”）的方法。所以这段代码即为根据参数所传入的**clone_flags**参数来决定子进程是否需要被监听和控制，如果需要则根据**clone_flags**来确定监听事件的类型，分为: `vfork、clone、fork`三种,最后检查该种事件是否允许被监听，如果不允许，则监听事件标志置零。

+ 紧接着调用`copy_process`方法进行真正的进程拷贝操作，返回值赋给局部变量`struct task_struct *p;`，这个`task_struct`类型即为进程的核心部分PCB。  

+ `add_latent_entropy()`函数依赖于`add_device_randomness()`,作用为向输入池中添加特殊的设备/启动数据，以此来帮助完成初始化操作。

+ 最后检查刚复制好的进程PCB是否有错误，如有错误，直接返回错误信息

<img src="http://img.hellofhy.cn/19-1-7/83888141.jpg" width="60%" />

+ `trace_sched_process_fork()`需要在线程激活之前进行，如果线程退出过快，下面代码的线程指针可能会无效

+ 紧接着从PCB结构体中获取子进程的pid，再通过`pid_vnr`获取当前命名空间下的局部pid，赋值给局部变量nr

+ 如果需要对父进程的pid设置，则通过`put_user()`,将子进程的局部pid与父进程的pid相关联

+ 如果调用类型为vfork，则将子进程的标志位`vfork_done`作为参数，进行vfork的初始化.

	`init_completion()`会将done字段初始化为0，wait字段的自旋锁为未锁，等待队列为空。这说明调用该完成量的进程必须等待某事件完成(即另外一进程必须先调用completiom()唤醒该完成量)。 
	
	`get_task_struct()`作用为增加进程的引用计数
	
	
<img src="http://img.hellofhy.cn/19-1-7/14226258.jpg" width="60%" />

+ `wake_up_new_task()`将子进程加入运行队列，唤醒子进程，分配CPU时间片，此时子进程开始真正执行

+ 如果开始的监听事件有效，则调用`ptrace_event_pid`方法，开始监听与控制

+ 这时子进程已经开始执行，所以在vfork的调用类型下， 通过`wait_for_vfork_done()`方法来判断父进程是否可以执行，正好与之前的`init_completion()`操作相对应，若vfork已经执行完成，则通知ptrace，父进程开始执行

+ `put_pid()` 判断当前的pid->count是否等于1，如果等于1的话，再减去1的话，就是0.
说明后面没有人用这个pid了，因此要把ns中对pid的缓存去掉，并通过put\_pid\_ns将ns的ns->kref 一次减1

+ 最后返回子进程在当前命名空间下的pid



#### 2、 copy_process()源码分析

从上面的分析可以知道，真正创建子进程PCB的操作为`copy_process`,因为这个方法是在太长，所以只选择重要部分进行分析

##### (1) PCB复制

<img src="http://img.hellofhy.cn/19-1-7/9892081.jpg" width="50%" />


可以看到，真正完成PCB复制工作的方法是`dup_task_struct`，这里对`dup_task_struct`的源码进行简单分析:

<img src="http://img.hellofhy.cn/19-1-7/3108309.jpg" width="70%" />

最终执行完`dup_task_struct`之后，子进程除了`tsk->stack`指针与主进程不同之外，其余全部都一样

##### (2) 检查上限

<img src="http://img.hellofhy.cn/19-1-7/5382753.jpg" width="60%" />

+ 通过`atomic_read`和`task_rlimit`两个方法来判断进程是否超过上限
+ 通过`nr_threads`来判断线程是否超过max_threads

##### (3) 信息复制

<img src="http://img.hellofhy.cn/19-1-7/83239058.jpg" width="60%" />

这部分用于复制所有进程信息，包括文件系统、信号处理函数、信号、内存管理等，最后的`copy_thread_tls`作用是初始化子进程内核栈

##### (4) pid的分配与设置

<img src="http://img.hellofhy.cn/19-1-7/4732954.jpg" width="60%" />

<img src="http://img.hellofhy.cn/19-1-7/35665155.jpg" width="60%" />













