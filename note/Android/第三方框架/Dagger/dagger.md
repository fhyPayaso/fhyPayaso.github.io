基础学习-dagger2简单使用

dagger2是一款的依赖注入框架，可以帮助我们简化对象实例的生成


+ 引入依赖库 : 

```
compile 'com.google.dagger:dagger:2.11'
annotationProcessor 'com.google.dagger:dagger-compiler:2.11'
```

+ 常用注解

	+ `@Module`: 统一管理多个对象的生成
	+ `@Provides`: 在加了`@Module`注解的类中使用，加在真正生成对象实例的方法上
	+ `@Component`: 统一管理多个module,并且明确有哪些类需要注入这些module所提供的实例
	+ `@Inject`: 加在需要使用的对象变量上，获取对象实例
	+ `@Named`: 给实例命名，防止同类型注入混淆
	+ `@Singleton`: 单例化对象，直接加在提供实例的方法上即可，同时对应的Component上也要加上这个注解，否则会报错，但是需要注意的是，这种单例只在一个activity中有效，如果要做到全局单例则需要自定义注解

+ 简单使用，目的是通过dagger帮我们把类A注入到MainActivity当中
	
	首先创建Module，并写好真正提供实例的方法
	
	```
	@Module
	public class MainModule {
	
	    @Provides
	    // 真正提供实例的方法
	    A provideA() {
	        return new A();
	    }
	}
	```
	
	然后建立Component,确认有需要哪些Module来提供实例(可以添加多个)，并且确认有哪些activity/fragment要用到这些实例
	
	```
	@Component(modules = MainModule.class)
	public interface MainComponent {
	
		//指定向MainActivity中注入实例
	    void inject(MainActivity activity);
	    
	}
	```
	
	然后将项目rebuild一下，dagger会通过apt自动帮我们生成`DaggerxxxxComponent`类
	![](http://img.hellofhy.cn/18-10-28/28505928.jpg)
	
	
	```
	public class MainActivity extends AppCompatActivity {
	    
	    // 需要注入的对象添加Inject注解
	    @Inject
	    A a;
	
	    @Override
	    protected void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.activity_main);
	        // 将activity/fragment与component绑定
	        DaggerMainComponent.create().inject(this);
	    }
	}
	```
	
	最后在activity的onCreate方法中做初始化操作，将MainActivity与DaggerMainComponent绑定,并且给注入的变量添加`@Inject`注解,这样接下来就可以直接使用a对象，不必再手动创建实例了
	
	
+ **构造函数带参数**

	```
	@Module
	public class MainModule {
	
	    @Provides
	    ObjectA provideA() {
	        return new ObjectA();
	    }
	
	    @Provides
	    ObjectB provideB(ObjectA objectA) {
	        return new ObjectB(objectA);
	    }
	}
	```
	这种情况不要在构造方法里之间new出参数，只需要在module中对参数类型添加一个依赖即可

+ **module之间依赖**

	```
	@Module(includes = {OneModule.class})
	public class MainModule {
	
	    @Provides
	    ObjectA provideA() {
	        return new ObjectA();
	    }
	
	    @Provides
	    ObjectB provideB(ObjectA objectA) {
	        return new ObjectB(objectA);
	    }
	}
	```
	这里给Module注解添加了OneModule参数，这样Component中即使不添加OneModule.class也能够使用里面提供的实例
	
+ `@Scoped`**自定义注解实现全局单例**

	上面我们提到，`@Singleton`只能保证一个activity/fragment中的单例，但如果想要做到全局单例需要结合`@Scoped`注解去实现，这个注解实际上的作用是控制对象的生命周期，`@Singleton`其实也是`@Scoped`类型的注解
	
	首先创建一个app级别的module，内部提供所有全局单例的实现，注意给提供实例的方法添加`@Singleton`注解
	
	```
	@Module
	public class AppModule {
	
	    @Singleton
	    @Provides
	    RealSingleton provideRealSingleton() {
	        return new RealSingleton();
	    }
	}
	```

	相应的，建立app级别的component,当然也要加`@Singleton`注解，但是这里我们不用写指定哪一个activity去使用的inject方法，而是先写一个抽象方法返回单例对象
	
	```
	@Singleton
	@Component(modules = {AppModule.class})
	public interface AppComponent {
	
	    RealSingleton getRealSingleton();
	}
	```
	
	在application初始化时,之间获取AppComponent对象的实例，并向外暴露get方法来获取
	
	```
	public class App extends Application {
	
	    private AppComponent mAppComponent;
	
	    @Override
	    public void onCreate() {
	        super.onCreate();
	        mAppComponent = DaggerAppComponent.builder().appModule(new AppModule()).build();
	    }
	    
	    public AppComponent getAppComponent() {
	        return mAppComponent;
	    }
	}
	```
	
	开始自定义注解过程
	
	```
	@Scope // 与dagger相关联
	@Documented // 标记在文档
	@Retention(RetentionPolicy.RUNTIME) // 运行时注解
	public @interface ActivityScoped {
	
	}
	```
	
	接下来开始回到与各个Activity相关的Component,使其依赖于刚才建立的App级别的component，并且添加上自定义的`@ActivityScoped`来改变单例的作用范围
	
	
	```
	@ActivityScoped
	@Component(dependencies = AppComponent.class)
	public interface MainComponent {
	
	    void inject(MainActivity activity);
	
	    void inject(TestActivity activity);
	}
	```
	
	最后在activity中使用全局单例,在构建Component的过程中使其依赖于全局的AppComponent(和app生命周期绑定),
	
	```
	public class TestActivity extends AppCompatActivity {
	
	    @Inject
	    RealSingleton mRealSingleton;
	    
	    @Override
	    protected void onCreate(@Nullable Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.activity_test);
	
	        DaggerMainComponent.builder()
	                .appComponent(((App)getApplication()).getAppComponent())
	                .build()
	                .inject(this);
	
	    }
	}
	```
	
	