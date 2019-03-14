项目所引用的 AAR 、Library 等第三方库所包含的 Manifest 清单文件与主 Module （默认名为 app ）中定义的 Manifest 内容合并时发生冲突。


在主Module中添加
```
<uses-sdk tools:overrideLibrary="com.xxx.xxx, com.xxx.xxx" />
```