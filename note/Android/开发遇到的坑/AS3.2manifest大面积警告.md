AS3.2版本开始 ，新建项目发现manifest大面积警告

> Warning: App is not indexable by Google Search; consider adding at least one Activity with an ACTION-VIEW intent filter. See issue explanation for more details.


官方解释

> To enable Google to crawl your app content and allow users to enter your app from search results, you must add intent filters for the relevant activities in your app manifest. These intent filters allow deep linking to the content in any of your activities. For example, the user might click on a deep link to view a page within a shopping app that describes a product offering that the user is searching for.

要使Google能够抓取您的应用内容并允许用户从搜索结果中进入您的应用，您必须为manifest中的相关活动添加intent filters。它们允许深入链接到您的任何活动中的内容。例如，用户可以点击深层链接以查看购物应用中的页面，该页面描述用户正在搜索的产品。

就是说如果应用在别的地方投放了广告，想让用户直接点击进入你的相应页面，需要给这个页面添加指定的filter规则

#### 解决方法

在至少一个activity的intent-filter中加入

```
    <action android:name="android.intent.action.VIEW" />
```