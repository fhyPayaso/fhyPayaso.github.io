### SpannableString相关

初接触textview的时候，总感觉用起来很死板,样式很固定,文字外观一复杂起来: 比如数学公式、特定字的点击事件、单独加粗等，就不好实现，事实上这些都可应通过SpannableString或者html来实现，本文介绍前者


#### 一、SpannableString

SpannableString，是CharSequence的一种，原本的CharSequence只是一串字符序列，没有任何样式，而SpannableString可以在字符序列基础上对指定的字符进行润饰，在开发中，TextView可以通过setText(CharSequence)传入SpannableString作为参数，来达到显示不同样式文字的效果。

**创建方式**

```
SpannableString spannableString = new SpannableString("test");
```

**修饰方式**

```
spannableString.setSpan(Object what, int start, int end, int flags);
```


+ what：对SpannableString进行润色的各种Span；
+ int：需要润色文字段开始的下标；
+ end：需要润色文字段结束的下标；
+ flags：决定开始和结束下标是否包含的标志位，有四个参数可选

	+ **SPAN\_INCLUSIVE\_EXCLUSIVE**：包括开始下标，但不包括结束下标
	+ **SPAN\_EXCLUSIVE\_INCLUSIVE**：不包括开始下标，但包括结束下标
	+ **SPAN\_INCLUSIVE\_INCLUSIVE**：既包括开始下标，又包括结束下标
	+ **SPAN\_EXCLUSIVE\_EXCLUSIVE**：不包括开始下标，也不包括结束下标

	这里要注意的是，flags仅对新插入的字符生效，对初始化的SpannableString是不影响的
	
#### 二、各种span

上面参数中的what，就是具体决定文字样式的参数, 总览如下:

![](https://upload-images.jianshu.io/upload_images/3279407-426f8688601a6846)

可以看出所有Span都继承于CharacterStyle这个抽象类，另外MetricAffectingSpan、ReplacementSpan和ClickableSpan都是抽象类

Span | 含义 
---- | --- 
ClickableSpan | 抽象类，可点击效果，重写onClick方法响应点击事件
MetricAffectingSpan | 自定义Span时可继承
ReplacementSpan | MetricAffectingSpan的子类，一般继承此类自定义span
AbsoluteSizeSpan | 指定文字大小
TypefaceSpan  | 可以设置不同的字体
AlignmentSpan.Standard  | 标准文本对齐
BackgroundColorSpan  | 文本背景颜色
ForegroundColorSpan  | 文字字体颜色
LeadingMarginSpan  | 文本缩进
TabStopSpan  | 制表位偏移样式
TextAppearanceSpan  | 使用style文件来定义文本样式
RelativeSizeSpan  | 对于文本设定的大小的相对比例
ScaleXSpan  | 将字体按比例进行横向缩放
URLSpan  | 可以打开一个链接
StyleSpan  | 正常、粗体、斜体和同时加粗倾斜四种样式
StrikethroughSpan | 删除线样式
QuoteSpan | 在文本左侧添加一条表示引用的竖线
UnderlineSpan | 给一段文字加上下划线
SubscriptSpan | 脚注样式，比如化学式的常见写法
SuperscriptSpan | 上标样式，比如数学上的次方运算
BulletSpan | 文本着重样式，类似于HTML中的\<li>标签的圆点效果
DrawableMarginSpan 、IconMarginSpan | 图片\+Margin样式
ImageSpan | 图片样式，主要用于在文本中插入图片  聊天中的emoji表情显示用的就是这个
MaskFilterSpan | 文本滤镜  目前只有模糊效果和浮雕效果
RasterizerSpan | 光栅化


除了CharacterStyle的子类，还有用于**段落的级Span**，他们都实现ParagraphStyle接口

Span | 含义 
---- | --- 
LeadingMarginSpan | 用来处理像word中项目符号一样的接口；
AlignmentSpan | 用来处理整个段落对其的接口；
LineBackgroundSpan | 用来处理一行的背景的接口；
LineHeightSpan | 用来处理一行高度的接口；
TabStopSpan | 用来将字符串中的"\t"替换成相应的空行；
WrapTogetherSpan | ???



#### 三、自定义Span

即使这么多类型的Span有时也不能应付复杂的需求，这里我们通过自定义来实现一个能改变背景和添加左侧icon的Span，选择继承抽象类ReplacementSpan

##### ReplacementSpan

**(1) getSize**

```
/**
 * 用于计算Span宽度
 *
 * @param paint 用于绘制的画笔
 * @param text  被绘制的文字内容
 * @param start span的起始位置
 * @param end   span的结束位置
 * @param fm    包含TextView的字体详细属性值
 * @return 返回值作为Span最终被绘制的宽度
 */
@Override
public int getSize(Paint paint, CharSequence text, int start, int end, Paint.FontMetricsInt fm) {
   
}
    
```


**(2) draw**



```
/**
 * 绘制文字效果
 *
 * @param canvas 画布
 * @param text   TextView的文字内容
 * @param start  span的起始位置
 * @param end    span的结束位置
 * @param x      最小margin下的左侧边界?
 * @param top    该行文字显示区域的top值
 * @param y      Baseline
 * @param bottom 该行文字显示区域的bottom值
 * @param paint  画笔
 */
@Override
public void draw(Canvas canvas, CharSequence text, int start, int end, float x, int top, int y, int bottom, Paint paint) {

}

```

##### FontMetricsInt


```
public static class FontMetricsInt {
    /**
     * The maximum distance above the baseline for the tallest glyph in
     * the font at a given text size.
     */
    public int   top;
    /**
     * The recommended distance above the baseline for singled spaced text.
     */
    public int   ascent;
    /**
     * The recommended distance below the baseline for singled spaced text.
     */
    public int   descent;
    /**
     * The maximum distance below the baseline for the lowest glyph in
     * the font at a given text size.
     */
    public int   bottom;
    /**
     * The recommended additional space to add between lines of text.
     */
    public int   leading;

    @Override public String toString()
    {
        return "FontMetricsInt: top=" + top + " ascent=" + ascent +
                " descent=" + descent + " bottom=" + bottom +
                " leading=" + leading;
    }
}

```

直接用一张图来解释

![](https://upload-images.jianshu.io/upload_images/1242368-7c4722273322a1df.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1000/format)

其中top和ascent为负值，因为以Baseline=0为标准













