#### `chmod`( change file mode bits)

功能：变更**文件**或**目录**的权限。

两种方法：符号方式，进制方式。

- 符号方式

格式

```shell
chmod key file_name
```

$$
key = 【操作对象】【操作符号】【用户权限】
$$

| 操作对象  | 操作符号 | 用户权限 |
| --------- | -------- | -------- |
| u(user)   | +        | r        |
| g(group)  | -        | w        |
| o(others) | =        | x        |
| a(all)    |          |          |

```shell
chmod u+x,g+w,o+x now #主用户加可执行权限，组用户加写权限，其他用户加可执行权限
```

![image-20230913102739263](https://cdn.789ak.com/img/image-20230913102739263.png)

```shell
chmod a+w now # 所有用户加上写权限
```

![image-20230913102930331](https://cdn.789ak.com/img/image-20230913102930331.png)

- 进制方式

![image-20230913103057517](https://cdn.789ak.com/img/image-20230913103057517.png)

`r`用4表示，`w`用2表示，`x`用1表示。

```shell
chmod 777 now # 所有用户都可读可写可执行
```

![image-20230913103229156](https://cdn.789ak.com/img/image-20230913103229156.png)

```shell
chmod 644 now # 主用户可读可写，组用户可读，其他用户可读
```

![image-20230913103325674](https://cdn.789ak.com/img/image-20230913103325674.png)

#### `umask`

功能：用来设置文件的缺省权限的掩码

>目录**默认权限**：755
>
>文件**默认权限**：644

```shell
umask
umask -S
```

![image-20230913103533286](https://cdn.789ak.com/img/image-20230913103533286.png)

掩码值的含义：设置了权限**掩码**之后，默认的文件和目录权限**减去掩码值**才是真实的文件和目录的权限。

系统设置的权限掩码umask为022。

![image-20230913103807186](https://cdn.789ak.com/img/image-20230913103807186.png)

- 文件和目录的默认权限

目录权限为777，真实权限777 - 0222 = 755

文件权限为666，真实权限666 - 022 = 644

更改umask

```shell
umask 021 
```

> 运行umask命令只对当前shell环境起作用。

#### `chown`( change file owner and group)

功能：更改文件或目录的所有者。

选项`-R`表示**递归式**的改变指定目录及其所有子目录/文件的**主用户**

>只有**超级用户root**才能使用该命令

![image-20230920102949232](https://cdn.789ak.com/img/image-20230920102949232.png)

#### `chgrp`(change group ownership)

功能：改变文件或目录的所属组。

选项`-R`同`chown`

![image-20230920103119253](https://cdn.789ak.com/img/image-20230920103119253.png)