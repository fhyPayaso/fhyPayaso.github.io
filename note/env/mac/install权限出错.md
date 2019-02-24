今天像往常一样install竟然有权限问题

```
brew install tree
```

报错

```
Error: The following directories are not writable by your user:
/usr/local/share/man/man8
```

查了一下是权限出问题了，然而加了sudo也不行，最后直接用命令获取写usr/local的写入权

```
sudo chown -R $(whoami) /usr/local/*
```