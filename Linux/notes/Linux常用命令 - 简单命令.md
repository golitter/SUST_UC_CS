## 简单命令

#### `who`

功能：列出所有正在使用系统的用户相关信息。

```shell
who 
who am i
whoami
```

#### `date`

功能：显示或者设置系统的日期和时间。

```shell
date
date -s 12:3:3
```

#### `cal`

功能：显示日历。

```shell
cal
cal 2023
cal 9 2023
```

#### `clear`

功能：清除屏幕上的信息。

```shell
clear
```

#### `passwd`

功能：更改用户密码。

```shell
passwd
passwd other_username
```

## 文件操作命令

### 文件处理命令

#### `pwd`（print working directiry)

功能：打印当前工作目录的绝对路径。

```shell
pwd
```

#### `cd`(change dircetory)

功能：切换目录。

```shell
cd /tmp/a  # 绝对路径
cd a # 相对路径
cd .. # 返回上一级目录
cd - # 返回上一次进入的目录
cd # 或者 cd ~  返回用户家目录
```

#### `ls`(list directory contents)

功能：列出参数的各个属性信息。

```shell
ls
ls -a # 显示隐藏文件
ls -d # 显示目录属性
ls - r # 按时间逆序输出
ls -l # 使用长格式显示文件内容
```

![image-20230906091724122](https://cdn.789ak.com/img/image-20230906091724122.png)

![image-20230906091758147](https://cdn.789ak.com/img/image-20230906091758147.png)

#### `touch`(change file timestamps)

功能：修改文件的时间为系统当前时间。如果文件不存在，则创建一个空文件。

```shell
touch a.txt
```

#### `mkdir`(make directory)

功能：创建目录。

```shell
mkdir folder
mkdir -p folder1/folder2 # 加 -p 一次建立多级目录

```

#### `rmdir`(remove empty directory)

功能：删除空目录。

> 如果该目录中仍有其他文件，那就不能用`rmdir`命令把它删除。
>
> 该目录中的文件必须用`rm`命令先删除。

```shell
rmdir dir1 # 删除dir1这个空目录
rmdir -p dir1/dir2 # 递归删除目录，当子目录删除后，如果父目录为空则删除父目录
```

#### `cp`(copy files and directories)

功能：将**源文件**或**目录**复制到指定目录。

> 命令中的参数可以是**相对路径**，也可以是**绝对路径**。
>
> 可以使用通配符

```shell
cp a b # 将a复制一份为b
cp -f a b # 覆盖已经存在的目标文件，不给出提示
cp -i a b # 同上，给出提示
cp -r dir1 dir2 # 复制目录，包括目录下的各级子目录
```

#### `rm`(remove files or directories)

功能：删除**文件**或**目录**。

```shell
rm a # 删除文件a
rm -i a # 进行交互式删除
rm -f a # 强制删除
rm -r dir1 # 递归删除指定目录及其子目录和文件
```

#### `mv`(move(rename) filies)

功能：移动**文件**或**目录**；给文件**改名**。

```shell
mv a b # 将文件a改为b
mv a ../ # 将文件a移动到上一级目录中
mv dir1 ../ # 将目录dir1移动到上一级目录中
```

### 查看文件命令

#### `cat`(concatenate and display files)

功能：**连接**或**显示**文件内容

```shell
cat a.txt
cat -b a.txt # 对非空行进行编号
cat -n a.txt # 对所有行进行编号
```

#### `more`

功能：**分页**显示文件内容。

| 选项 | 功能              |
| ---- | ----------------- |
| -num | 一次显示num行     |
| +num | 从第num行开始显示 |

```shell
more -4 now
more +4 now
```

![image-20230913095948198](https://cdn.789ak.com/img/image-20230913095948198.png)

![image-20230913100007451](https://cdn.789ak.com/img/image-20230913100007451.png)

#### `less`

功能：**分页**显示文件内容，可实现向上翻页。

```shell
less now
```

![image-20230913100112987](https://cdn.789ak.com/img/image-20230913100112987.png)

#### `head`(output the first part of files)

功能：查看文件的**前n行**。

| 选项 | 功能                  |
| ---- | --------------------- |
| -n   | 显示前n行，默认值是10 |
| -nc  | 显示前面n个字节       |

```shell
head -3 now
```

![image-20230913100323974](https://cdn.789ak.com/img/image-20230913100323974.png)

#### `tail`(output the last part of files)

功能：查看文件的**后n行**。

选项与`head`命令的相同。

#### `wc`

功能：统计文件的**行数，字数，字节数**。

| 选项 | 功能       |
| ---- | ---------- |
| -l   | 统计行数   |
| -w   | 统计字数   |
| -c   | 统计字节数 |

![image-20230913100556278](https://cdn.789ak.com/img/image-20230913100556278.png)

### 文件搜索命令

#### `which`(shows the full path of commands)

功能：查看命令所在的目录

```shell
which ls
```

![image-20230913100712839](https://cdn.789ak.com/img/image-20230913100712839.png)

#### `find`(search for files in a directory hierarchy)

功能：**查找**指定**文件**或**目录**。

| 选项   | 功能               |
| ------ | ------------------ |
| -name  | 根据文件名查找     |
| -size  | 根据文件大小查找   |
| -user  | 根据文件所有者查找 |
| -ctime | 根据修改时间查找   |
| -type  | 根据文件类型查找   |

- 根据文件名查找

```shell
find ./ -name now # 在当前目录下查找文件now
```

![image-20230913101000021](https://cdn.789ak.com/img/image-20230913101000021.png)

- 根据文件大小查找

```shell
find ./ -size 100c # 查找字节数为100的文件
find ./ -size -100c # 查找小于100字节数的文件
find ./ -size +100c # 查找大于100字节数的文件
```

- 根据文件所有者进行查找

```shell
find ./ -user golitter
```

- 根据修改时间进行查找

```shell
find ./ -ctime 20 # 20天的
find ./ -ctime +20 # 大于20天的
find ./ -ctime -20 # 小于20天的
```

- 根据文件类型进行查找

```shell
find ./ -type f # 文件
find ./ -type d # 目录
```

#### `grep`(print lines matching a pattern)

功能：在文件中搜索与字符串匹配的行

[linux三剑客 -- grep_golitter.的博客-CSDN博客](https://blog.csdn.net/qq_63432403/article/details/130649125?spm=1001.2014.3001.5502)