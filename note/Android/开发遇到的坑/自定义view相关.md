
#### 自定义view构造方法

> 三个构造方法的调用时机

```
    // 直接手动new的时候调用
    public MyView(Context context) {
        super(context);
    }

    // 直接在布局文件中使用的时候调用
    public MyView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }

    // 直接在布局文件中使用，同时包含自定义属性的时候调用
    public MyView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

```