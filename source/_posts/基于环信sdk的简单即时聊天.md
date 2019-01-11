---
title: 基于环信sdk的简单即时聊天
date: 2018-01-15 15:04:51
tags: android
---

在一些小项目的开发过程中，需求里可能会有实现聊天功能的要求，完全由后端实现可能会比较繁琐，这里我们选择通过集成环信SDK来实现简单的聊天功能。

<!-- more-->
> 不洗碗工作室 @Author fhyPayaso

## 一、前期准备

+ 首先我们需要在环信官网上注册开发者账号并创建应用，获取到AppKey，具体流程请见[注册并创建应用](http://docs.easemob.com/im/000quickstart/10register)


## 二、集成sdk
+ 在biuld.gradle中添加如下依赖
 
    	compile 'com.google.android.gms:play-services-gcm:9.4.0'
    	compile 'com.hyphenate:hyphenate-sdk:3.3.0'
    	
+ 在Manifest中添加需要的权限，记得在 `android:value`添加你之前注册好的AppKey

		<uses-permission android:name="android.permission.VIBRATE" />
	    <uses-permission android:name="android.permission.INTERNET" />
	    <uses-permission android:name="android.permission.RECORD_AUDIO" />
	    <uses-permission android:name="android.permission.CAMERA" />
	    <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
	    <uses-permission android:name="android.permission.ACCESS_MOCK_LOCATION" />
	    <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
	    <uses-permission android:name="android.permission.MOUNT_UNMOUNT_FILESYSTEMS"/>  
	    <uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" />
	    <uses-permission android:name="android.permission.GET_TASKS" />
	    <uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
	    <uses-permission android:name="android.permission.CHANGE_WIFI_STATE" />
	    <uses-permission android:name="android.permission.WAKE_LOCK" />
	    <uses-permission android:name="android.permission.MODIFY_AUDIO_SETTINGS" />
	    <uses-permission android:name="android.permission.READ_PHONE_STATE" />
	    <uses-permission android:name="android.permission.RECEIVE_BOOT_COMPLETED" />
		<application
	        android:icon="@drawable/ic_launcher"
	        android:label="@string/app_name"
	        android:name="Your Application">
		   	<!-- 设置环信应用的AppKey -->
	        <meta-data
	            android:name="EASEMOB_APPKEY"
	            android:value="Your AppKey"/>
	        <!-- 声明SDK所需的service SDK核心功能-->
	        <service
	            android:name="com.hyphenate.chat.EMChatService"
	            android:exported="true"/>
	        <service
	            android:name="com.hyphenate.chat.EMJobService"
	            android:exported="true"
	            android:permission="android.permission.BIND_JOB_SERVICE"
	            />
	        <!-- 声明SDK所需的receiver -->
	        <receiver android:name="com.hyphenate.chat.EMMonitorReceiver">
	            <intent-filter>
	                <action android:name="android.intent.action.PACKAGE_REMOVED"/>
	                <data android:scheme="package"/>
	            </intent-filter>
	            <!-- 可选filter -->
	            <intent-filter>
	                <action android:name="android.intent.action.BOOT_COMPLETED"/>
	                <action android:name="android.intent.action.USER_PRESENT"/>
	            </intent-filter>
	        </receiver>
		</application>
		
## 三、初始化sdk

+ 首先要在Application的onCreate方法中初始化SDK的设置

		EMOptions options = new EMOptions();
		
		// 在这里可以进行一些初始化设置，例如默认添加好友时，是不需要验证的，可以改成需要验证
		options.setAcceptInvitationAlways(false);
		...
		//初始化
		EMClient.getInstance().init(this, options);


+ 如果你的应用中包含第三方登录功能，为了防止SDK重复初始化，需要在初始化sdk`EMClient.getInstance().init(applicationContext, options)`方法前添加判断：

		appContext = this;
		int pid = android.os.Process.myPid();
		String processAppName = getAppName(pid);
		// 如果APP启用了远程的service，此application:onCreate会被调用2次
		// 为了防止环信SDK被初始化2次，加此判断会保证SDK被初始化1次
		// 默认的APP会在以包名为默认的process name下运行，如果查到的process name不是APP的process name就立即返回
		if (processAppName == null ||!processAppName.equalsIgnoreCase(appContext.getPackageName())) {
		    Log.e(TAG, "enter the service process!");
		    
		    // 则此application::onCreate 是被service 调用的，直接返回
		    return;
		}


+ 其中的`getAppName()`具体实现为:
	
		private String getAppName(int pID) {
		
			String processName = null;
	    	ActivityManager am = (ActivityManager) this.getSystemService(ACTIVITY_SERVICE);
	    	List l = am.getRunningAppProcesses();
	    	Iterator i = l.iterator();
	    	PackageManager pm = this.getPackageManager();
	    	
	    	while (i.hasNext()) {
	    		ActivityManager.RunningAppProcessInfo info = (ActivityManager.RunningAppProcessInfo) (i.next());
	    		try {
	    			if (info.pid == pID) {
	    				processName = info.processName;
	    				return processName;
	            	}
	        	} catch (Exception e) {
	            // Log.d("Process", "Error>> :"+ e.toString());
	        	}
	    	}
	    	return processName;
		}
		
## 四、登录注册

### 注册
注册模式分为两种，开放注册和授权注册。

+ 开放注册：能够直接在客户端进行注册，可以在测试中使用，在正式使用环境中不推荐。
+ 授权注册：授权注册需要后端通过环信提供的 REST API 注册，之后将信息保存到服务器并返回客户端。

具体方法如下：

        new Thread(new Runnable() {
            @Override
            public void run() {

                try {
                    EMClient.getInstance().createAccount(editUsername.getText().toString().trim(), editPassword.getText().toString().trim());
                    Log.i(TAG, "register: 注册成功");
                } catch (HyphenateException e) {
                	//注册失败会抛出异常
                    e.printStackTrace();
                    Log.i(TAG, "register: 注册失败" + e.getErrorCode() + " , " + e.getMessage());
                }
            }
        }).start();
        
因为`EMClient.getInstance().createAccount(String username,password)`是同步方法，所以使用的时候需要自己创建线程，包括之后的同步方法都需要开新线程，不再赘述。


### 登录

登录方法为异步方法，可以直接调用，并在回调函数中打印信息：

	EMClient.getInstance().login(editUsername.getText().toString().trim(), 
	        editPassword.getText().toString().trim(), new EMCallBack() {
	            @Override
	            public void onSuccess() {

                //保证进入主页面后本地会话和群组都 load 完毕
                EMClient.getInstance().groupManager().loadAllGroups();
                EMClient.getInstance().chatManager().loadAllConversations();
                startActivity(new Intent(LoginActivity.this, FriendListActivity.class));
                Log.i(TAG, "onSuccess: 登录成功");
            }

            @Override
            public void onError(int code, String error) {

                Log.i(TAG, "onError: 登录失败，" + error);
            }

            @Override
            public void onProgress(int progress, String status) {

            }
        });
        
### 自动登录
sdk中自动登录属性是默认为true的，如果要取消自动登录，可以在sdk初始化的时候设置`options.setAutoLogin(false)`

### 退出登录
	EMClient.getInstance().logout(true, new EMCallBack() {
	            
	    @Override
	    public void onSuccess() {
	        Log.i(TAG, "onSuccess: 退出成功");
	    }
	    
	    @Override
	    public void onProgress(int progress, String status) {
	        
	    }
	    
	    @Override
	    public void onError(int code, String message) {
	        Log.i(TAG, "onError: 退出失败，" + message);
	    }
	});
	
如果集成了第三方的推送功能，那么方法中的第一个参数需要设置为true，目的是解绑设备token，否则的话可能出现退出之后依然能收到推送的情况。

## 五、好友管理
### 添加好友

	//参数为要添加的好友的username和添加理由，默认为无需验证
	EMClient.getInstance().contactManager().addContact(toAddUsername, reason);
	
### 删除好友

	EMClient.getInstance().contactManager().deleteContact(username);
	
### 获取好友列表

	List<String> usernames = EMClient.getInstance().contactManager().getAllContactsFromServer();
	
环信只是即时通讯的消息通道。环信本身不提供用户体系，环信既不保存任何 APP 业务数据，也不保存任何 APP 的用户信息。所以我们需要通过获取到的username向app的服务端查询用户的详细信息。

### 搜索好友

环信sdk并不提供搜索好友的接口，但我们可以通过服务端的sdk接口将所有用户的username导入环信，保证查到的好友可以添加，然后通过服务端搜索获取具体用户的username，实现通过搜索添加好友功能。

## 六、即时聊天

### 文本消息发送

具体方法如下：

	//创建一条文本消息，content为消息文字内容，username为对方用户名
	EMMessage message = EMMessage.createTxtSendMessage(content, username);
	//如果是群聊，设置chattype，默认是单聊
	if (chatType == CHATTYPE_GROUP)
	    message.setChatType(ChatType.GroupChat);
	//发送消息
	EMClient.getInstance().chatManager().sendMessage(message);


### 消息接收监听

我们可以通过实现`EMMessageListener`接口的方法来设置消息的监听

	public class ChatActivity extends AppCompatActivity implements EMMessageListener {
	
	
	    @Override
	    protected void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.activity_chat);
	        //添加信息监听
	        EMClient.getInstance().chatManager().addMessageListener(this);
	    }
	
	    @Override
	    public void onMessageReceived(List<EMMessage> messages) {
	       
	        //收到消息，在这里进行RecyclerView重新加载和渲染
	    }
	
	    @Override
	    public void onCmdMessageReceived(List<EMMessage> messages) {
	    
			//收到传透消息，如头像、昵称的更新等
	    }
	
	    @Override
	    public void onMessageRead(List<EMMessage> messages) {
	    
	    	//收到已读回执
	    }
	
	    @Override
	    public void onMessageDelivered(List<EMMessage> messages) {
	
			//收到送达回执
	    }
	
	    @Override
	    public void onMessageChanged(EMMessage message, Object change) {
	
			//消息状态变动
	    }
	}	

在不需要的时候移除listener，如在activity的`onDestroy()`时

	EMClient.getInstance().chatManager().removeMessageListener(this);
	
	
### 获取消息记录

具体方法为：

	EMConversation conversation = EMClient.getInstance().chatManager().getConversation(username);
	//获取此会话的所有消息
	List<EMMessage> messages = conversation.getAllMessages();
	
在RecyclerView的adapter中将messages显示到ui中

	EMTextMessageBody textMessageBody = (EMTextMessageBody) emMessage.getBody();
	txtMessage.setText(textMessageBody.getMessage());
	
SDK默认加载的聊天记录最多为20条，可以在初始化SDK时进行设置`options.setNumberOfMessagesLoaded(number)`


## 七、Demo展示


![](http://p0y1qzu73.bkt.clouddn.com/18-1-15/73472058.jpg)



本文只简单介绍了实现文字即时聊天的方法，SDK更多的功能请见[环信开发文档](http://docs.easemob.com/im/200androidclientintegration/10androidsdkimport)