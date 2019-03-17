本篇只介绍最简单的使用方法


#### Inject && Component

```
public class DaggerA {

    @Inject
    public DaggerA() {
    }
    
    public void daggerA() {
        System.out.println("daggerA");
    }
}
```
首先在被注入的类的构造方法上加`@Inject`注解

```
public class DaggerB {
    
    @Inject
    DaggerA daggerA;

    public void daggerB() {
        daggerA.daggerA();
    }
}
```
然后在注入的类中将DaggerA作为成员变量，并加上`@Inject`注解,  但这时运行肯定会空指针

```
@Component
public interface BComponent {

    void inject(DaggerB daggerB);
}
```
添加接口，并加上`@Component`注解，同时增加inject方法，参数类型为DaggerB

然后ReBuild一下工程，在build -> generated -> source -> apt -> debug 路径下会发现生成的代码

![](http://img.hellofhy.cn/QQ20190317-174834.png)

在DaggerB的构造方法中调用生成的DaggerBComponent进行注入

```
public class DaggerB {

    @Inject
    DaggerA daggerA;

    public DaggerB() {
        DaggerBComponent.builder().build().inject(this);
    }

    public void daggerB() {

        daggerA.daggerA();
    }
}
```
再次运行DaggerB中方法，能够打印字符串"daggerA"，说明类DaggerA注入成功

+ Inject : 提供对象实例的构造方法 + 注入后对应的变量
+ Component : 连接两个Inject的桥梁

#### Module && Provides

但是这样存在的问题是，需要在注入类的构造方法上添加注解，但有时我们无法修改源码,比如想要注入一个OkHttpClient类型的对象
这时候就需要两个新注解，`@Module`和`@Provides`，具体写法如下

```
@Module
public class BModule {

    @Provides
    OkHttpClient provideOkHttpClient() {
        return new OkHttpClient.Builder().build();
    }

}


public class DaggerB {

    @Inject
    DaggerA daggerA;

    @Inject
    OkHttpClient client;

    public DaggerB() {
        DaggerBComponent.builder().build().inject(this);
    }

    public void daggerB() {
        daggerA.daggerA();
    }

    public void okHttp() {
        // 打印结果为false
        System.out.println(client == null);
    }
}
```

+ Module : Component会在所有包含的Module中获取对象
+ Provides : 提供对象实例的方法