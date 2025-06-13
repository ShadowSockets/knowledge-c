前言
使用git做版本控制的时候，在源代码目录有些文件是不希望加到版本控制中的，例如工程文件、临时文件等。
一般在执行<git init>命令初始化空仓库前，在 .git 的同级目录下增加一个 .gitignore文件，并写入不需要追踪的文件或文件夹就可以了；

如果是已有的项目变更.gitignore文件，并且想让其生效，那么需要执行以下命令了：
```shell
git rm -r --cached .                #清除缓存
git add .                           #重新trace file
git commit -m "update .gitignore"   #提交和注释
git push origin master              #可选，如果需要同步到remote上的话
```


###基本语法
```text
以斜杠 “/” 开头表示目录；
以星号 “*” 通配多个字符；
以问号 “?” 通配单个字符;
以方括号 “[]” 包含单个字符的匹配列表；
以叹号 “!” 表示不忽略匹配到的文件或目录；
```

###示例：这是一个.gitignore文件的内容示例
```text
/debug/
*.dsp  
lib/a.dll
test.pdb
/.idea
```
```text
第一行代表忽略当前目录下的debug文件夹及其子文件
第二行代表忽略所有以 .dsp 为结尾的文件，子文件夹中的也会被忽略
第三行代表忽略当期目录下的lib文件夹中的a.dll文件
第四行代表忽略当前目录下的test.pdb文件
第五行代表忽略当前目录下的.idea文件夹及其子文件
```