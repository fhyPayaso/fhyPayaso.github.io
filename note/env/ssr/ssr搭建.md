+ 搬瓦工 : https://bwh88.net/

+ hosteons : https://hosteons.com/



+ ssr客户端下载: https://ssr.tools/175



### 搭建SSR服务器
此处注意：SS服务器和SSR服务器只需要搭一个。

#### 1. ssh登录服务器

```
wget --no-check-certificate https://raw.githubusercontent.com/teddysun/shadowsocks_install/master/shadowsocksR.sh
```

如出现错误提示 bash: wget: command not found，可以请在先执行 yum -y install wget 或者 apt-get install -y wget 命令。成功后，再执行上面的命令。如果没有出现提示错误，请略过。


#### 2.等待上一步的命令执行结束后，继续执行命令：

```
chmod +x shadowsocksR.sh
```


#### 3.等待上一步的命令执行结束后，继续执行命令:

```
./shadowsocksR.sh 2>&1 | tee shadowsocksR.log
```

根据需要选择，不懂的话直接选1，或者默认回车。下面会提示你输入你的 SSR SERVER 的密码和端口。不输入就是默认。跑完命令后会出来你的 SSR 客户端的信息。
全部选择完毕后，当出现如下命令就说明安装成功了：


纽约

Your Server IP        :  149.28.48.183
Your Server Port      :  18448
Your Password         :  22612261
Your Protocol         :  origin
Your obfs             :  plain
Your Encryption Method:  aes-256-cfb

```




### 开启BBR加速

+ 安装 BBR：

```
wget --no-check-certificate https://github.com/teddysun/across/raw/master/bbr.sh
```

+ 获取读写权限

```
chmod +x bbr.sh
```


+ 启动BBR安装：

```
./bbr.sh
```

+ 查看bbr是否启动成功

```
lsmod | grep bbr
```

如果看到 tcp_bbr 就说明 BBR 已经启动了。

