
通过Android Studio 的Sdk Manager安装NDK, 完成后运行原来的项目会报如下错误

```
No toolchains found in the NDK toolchains folder for ABI with prefix: mips64el-linux-android
```

到`/Users/fanhongyu/Library/Android/sdk/ndk-bundle/toolchains/`目录下查看确实没有`mips64el-linux-android`文件


> 解决办法


前往 [NDK官网下载](https://developer.android.com/ndk/downloads/?hl=zh-cn)，找到**历史归档**，下载r18之前的版本，因为r18b中确实已经移除了`mips64el-linux-android`文件



之后clean和build没问题，但是运行之后出现新问题


```
* What went wrong:
Execution failed for task ':app+stub:transformNativeLibsWithStripDebugSymbolForRelease'.
> A problem occurred starting process 'command '/Users/XXXX/Library/Android/sdk/ndk-bundle/toolchains/mips64el-linux-android-4.9/prebuilt/darwin-x86_64/bin/mips64el-linux-android-strip''

* Try:
Run with --stacktrace option to get the stack trace. Run with --info or --debug option to get more log output.
```



> 解决办法

+ 一种解决办法是同时升级gradle编译工具的版本。但是因为项目的原因，无法使用最新版本的gradle编译工具，只能使用2.3.0版本的编译工具，所以使用一个绕过问题的方法，

+ 在/Users/XXXX/Library/Android/sdk/ndk-bundle/toolchains/mips64el-linux-android-4.9/prebuilt/darwin-x86_64/bin/目录创建一个mips64el-linux-android-strip的空文件。记得使用chmod命令修改空文件的执行权限。亲测可行



[[解决]No toolchains found in the NDK toolchains folder for ABI with prefix
](https://www.jianshu.com/p/fd3d49c7f1f8)

[Android NDK编译错误解决](https://ivonhoe.github.io/2018/06/05/ndk17-build-error/)