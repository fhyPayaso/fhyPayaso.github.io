
### 数据库表设置

对于比较复杂的系统,  用户-角色-权限应该分别都是多对多的关系， 首先用户和角色， 


### JWT


出现的问题

+ token不能自动续期，


+ token不能在服务端主动作废

    + 更新密码: 可以用密码做签名

    + 更新冻结状态




[深入了解jwt方案的优缺点](https://www.cnblogs.com/nangec/p/12687258.html)

[什么是单点登录（SSO）](https://zhuanlan.zhihu.com/p/66037342)

[讲真，别再使用JWT了！](https://www.jianshu.com/p/af8360b83a9f)  (评论区大型撕逼现场)



java集合

+ List  
	+ ArrayList
		+ 扩容: 首次添加默认10,  需要扩容，每次1.5倍
		+ [ArrayList扩容](https://blog.csdn.net/weixin_47043124/article/details/111071388)
	+ LinkedList
	+ 区别

+ Map
	+ HashMap
		+ 线程不安全	
		+ 初始大小16(若指定大小，扩充为2的幂次方)
		+ 每次扩容一倍
		+ 扩容因子0.75
		+ 可以存null的kv
		+ 数组+链表：1.8后链表超过8，检查数组长度小于64则先扩容，否则转成红黑树
	+ HashTable
		+ 初始大小11
		+ 每次扩容2N+1
		+ 线程安全，方法加锁
		+ 不能存null的kv
	+ ConcurrentHashMap
set

















