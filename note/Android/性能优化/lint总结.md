> 经历了一次lint的整理

#### onMeasure、onLayout、onDraw中不能new对象

+ View绘制的时候，这几个方法会被频繁调用，每次都new对象的话，会加重GC的任务，浪费性能

+ 解决方法 : 将要创建的对象提升到成员变量，在view初始化的时候就实例化，使用的时候在方法中动态改变对象的属性即可

#### Handler导致的内存泄漏

```

    private Handler handler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            super.handleMessage(msg);
        }
    };

```

+ 这个问题是刚接触内存泄漏时一定会遇到的一个问题，这里不多说原因，解决方案大部分会选择用静态Handler去持有外部类的弱引用，但是外部类类型不确定，所以最好还是封装下

```
public class WeakHandler extends Handler {

    private WeakReference<IHandler> mRef;

    // 使用的类直接实现，handleMessage方法中写具体逻辑
    public interface IHandler {
        void handleMessage(Message msg);
    }

    //初始化时传入自身
    public WeakHandler(IHandler context) {
        mRef = new WeakReference<>(context);
    }

    @Override
    public void handleMessage(Message msg) {
        if (mRef.get() != null && msg != null) {
            mRef.get().handleMessage(msg);
        }
    }

    public void clear() {
        // 这里是为了防止队列中的Message持有自身，外部销毁时调用
        this.removeCallbacksAndMessages(null);
    }
}

```



#### AppCompatImageView 

有一些自定义View继承了ImageView，会报红建议使用AppCompatImageView，先看看官方是怎么介绍的

AppCompatImageView支持旧版平台上的兼容功能，包括：
       
+ 允许通过ViewCompat中的背景色调方法动态显示其背景色。
  
+ 允许使用backgroundTint和backgroundTintMode设置背景色调。
  
+ 允许通过ImageViewCompat中的图像色调方法动态着色其图像。
  
+ 允许使用tint和tintMode设置图像色调。
  
+ 还增加了与旧版Android版本的矢量绘图兼容性。

当在布局中使用ImageView并且appcompat提供顶级活动/对话框时，将自动使用此选项。


总的来说就是一种兼容性更更好的ImageView,而且在AppCompatActivity中使用的ImageView都会被自动替换成AppCompatImageView，而继承自ImageView的自定义View则不会，所以需要自己选择AppCompatImageView去继承