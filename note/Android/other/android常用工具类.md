---
title: android常用工具类
date: 2017-12-16 22:19:05
categories: Android
tags: 
- Android
- 工具类
copyright: false
---

整理的Android常用工具类,用于SimpleAndoid项目的编写
<!-- more-->
### NetWork工具类
	isNetworkConnected       : 判断网络是否连接
    openNetSetting           : 打开网络设置界面
    getNetworkTypeName       : 获取网络类型名称
    getCurrentNetworkState   : 获取当前网络的状态
    getCurrentNetworkSubtype : 获取当前网络的具体类型
    isConnectedByState       : 判断当前网络是否已经连接
    isConnectingByState      : 判断当前网络是否正在连接
    isDisconnectedByState    : 判断当前网络是否已经断开
    isDisconnectingByState   : 判断当前网络是否正在断开
### Fragment管理类 → FragmentUtils

	addFragment              : 新增fragment
	addFragment              : 新增fragment
	hideAddFragment          : 先隐藏后新增fragment
	addFragments             : 新增多个fragment
	removeFragment           : 移除fragment
	removeToFragment         : 移除到指定fragment
	
### ToastUtils（待定）

	shortToast            : 自定义Toast调用
	longToast             : 自定义Toast调用
	cancelToast           : 取消显示Toast
	Toast                 : 默认Toast调用
	show                  : 屏幕中心位置短时间显示Toast。
	ToastShortBottomCenter: 屏幕底部中间位置显示短时间Toast
	
### FileUtils  文件管理工具类

	rename             : 重命名文件\文件夹
	getFolderName      : 获取文件夹名称
	getFilesArray      : 获取文件夹下所有文件
	openImage          : 打开图片
	openVideo          : 打开视频
	openURL            : 打开URL
	
### 正则表达式工具类

	phoneNoHide          : 手机号码，中间4位星号替换
	cardIdHide           : 银行卡号，保留最后4位，其他星号替换
	idHide               : 身份证号，中间10位星号替换
	checkVehicleNo       : 是否为车牌号（沪A88888）
	isContinuousNum      : 判断字符串是否为连续数字 45678901等
	isAlphaBetaString    : 是否是纯字母
	isContinuousWord     : 判断字符串是否为连续字母 xyZaBcd等
	isRealDate           : 是否是日期 20120506 共八位，前四位-年，中间两位-月，最后两位-日
	
### 时间工具类

    todayYyyyMmDd         : 当天的年月日
    todayHhMmSs           : 当天的时分秒
    todayYyyyMmDdHhMmSs   : 当天的年月日时分秒
    parseYyyy             : 获取年
    parseMm               : 获取月
    parseDd               : 获取日
    parseYyyyMmDd         : 获取年月日
    parseHhMmSs           : 时分秒
    getWeekNumber         : 获取星期几
    dateIsBefore          : 比较日期
    
### 字符串工具类

	isEmpty(String str) 判断字符串是否为空或长度为0
	isBlank(String str) 判断字符串是否为空或长度为0 或由空格组成
	utf8Encode(String str) 以utf-8格式编码
	capitalizeFirstLetter(String str) 首字母大写
	
### Json工具类

	list2json         : List集合转换为Json
	array2json        : 对象数组转换为Json
	set2json          : Set集合转为Json
	string2json       : 字符串转换为Json
	
### 缓存工具类

	put             : 保存String数据到缓存中
	getAsString     : 读取String数据
	getAsJSONObject : 读取JSONObject数据
	getAsJSONArray  : 读取JSONArray数据
	getAsBinary     : 获取byte数据
	getAsObject     : 读取Serializable数据
	getAsBitmap     : 读取bitmap数据
	getAsDrawable   : 读取Drawable数据
	file            : 获取缓存文件
	remove          : 除某个key
	clear           : 清除所有数据
	
### 日志工具类

	init: 设置log总开关,debug模式(true:打印日志  false：不打印)
	a   : assert日志或者打印是否执行到这里等
	i   : Info日志或者打印是否执行到这里等
	d   : Debug日志或者打印是否执行到这里等
	w   : Warn日志或者打印是否执行到这里等
	v   : Verbose日志或者打印是否执行到这里等
	e   : Error日志或者打印是否执行到这里等
	json: 输出Json的格式字符串
	xml : 输出xml的格式字符串
	file: 保存到文件
	
### 屏幕辅助工具类

    getScreenWidth           : 获得屏幕宽度
    getScreenHeight          : 获得屏幕高度
    getStatusHeight          : 获得状态栏的高度
    getRealScreenHeight      : 获取整块屏幕的高度
    getNavigationAreaHeight  : 获取虚拟按键区域的高度
    getNavigationBarrH       : 获取导航栏高度
    snapShotWithStatusBar    : 获取当前屏幕截图，包含状态栏
    snapShotWithoutStatusBar : 获取当前屏幕截图，不包含状态栏
    getTitleBarHeight        : 获得标题栏高度
    getStatusBarHeight       : 获取通知栏高度
    shoot                    : 截屏并保存
    takeScreenShot           : 获取指定Activity的截屏，保存到png文件
    dp2px/px2dp/sp2px        : sp、dp、px转换
	
### AlertDialog工具类



### 软键盘管理工具类

	openKeybord      : 打卡软键盘
	closeKeybord     : 关闭软键盘
	TimerHideKeyboard: 通过定时器强制隐藏虚拟键盘
	isKeybord        : 输入法是否显示
	hideInputMethod  : 隐藏输入法
	showInputMethod  : 显示输入法

### App工具类

	getSysClientOs             : 获得客户端操作系统名称
	getSysSdk                  : 获取当前操作系统的sdk版本
	getSysLanguage             : 获取当前操作系统的语言
	getSysModel                : 获取手机型号
	getSysRelease              : 获取操作系统的版本号

### 图片管理工具类（delete）

	instance                         : 单例对象
	LoadContextBitmap                : Glide请求图片，会受到Context生命周期控制
	LoadFragmentBitmap               : Glide请求图片，会受到Fragment生命周期控制
	LoadSupportv4FragmentBitmap      : Glide请求图片，会受到support.v4.app.Fragment生命周期控制
	LoadContextCircleBitmap          : 加载设置圆形图片

### Glide图片加载工具类（delete）

	instance                         : 单例对象
	LoadContextBitmap                : Glide请求图片，会受到Context生命周期控制
	LoadFragmentBitmap               : Glide请求图片，会受到Fragment生命周期控制
	LoadSupportv4FragmentBitmap      : Glide请求图片，会受到support.v4.app.Fragment生命周期控制
	LoadContextCircleBitmap          : 加载设置圆形图片
	

### SharedPreferences封装类

	put						：保存数据的方法，拿到数据保存数据的基本类型，然后根据类型调用不同的保存方法
	get						：获取保存数据的方法，我们根据默认值的到保存的数据的具体类型，然后调用相对于的方法获取值
	remove					：移除某个Key值
	clear					：清除所有数据
	contains				：查询某个Key值是否存在
