首先写一个简单的自定义view

```

public class MyView extends View {

    private Paint mPaint;

    public MyView(Context context) {
        super(context);
        initView();
    }

    public MyView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        initView();
    }

    public MyView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    private void initView() {
        mPaint = new Paint();
        mPaint.setColor(Color.parseColor("#ffffff"));
    }

    @Override
    protected void onDraw(Canvas canvas) {
        int x, y = 10;
        for (int i = 0; i < 500; i++) {
            x = i * 20;
            // 连续绘制500个白色原点
            canvas.drawCircle(x, y, 5, mPaint);
        }
        super.onDraw(canvas);
    }
}

```

将上面的view直接写在xml中，会发现如果是父布局是常规的layout可以正常显示，但如果是`HorizontalScrollView`则不显示，这里我们没有重写`onMeasure`,所以自定义view的宽度是match还是wrap都无关

搜到有两种解决办法 :


+ 在`HorizontalScrollView`中设置`fillViewport`属性为true

fillViewport 的作用是 : 如果 ScrollView的子view宽度或高度比较小，即使子view设置了martch_parent也不会生效，而fillViewport属性就是控制ScrollView的内容是否充满视图

这样做虽然能够让自定义view展示，但是却无法滑动了


+ 重写measure方法，主动设置宽高, 这样既能显示又能滑动

原因待查

