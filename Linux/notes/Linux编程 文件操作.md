## 文件描述符

文件描述符在形式上是一个非负整数。实际上，它是一个索引值，指向内核为每一个进程所维护的该进程打开文件的记录表。当程序打开一个现有文件或者创建一个新文件时，内核向进程返回一个文件描述符。

启动一个进程之后，内核 PCB 的文件描述符表中就已经分配了三个文件描述符。默认支持打开的最大文件数为 1024。

三个特殊的文件描述符

-  标准输入文件
- 标准输出文件
- 标准错误输出文件

```cpp
#define STDIN_FILENO 0 // 标准输入文件
#define STDOUT_FILENO 1 // 标准输出文件
#define STDERR_FILENO 2 // 标准错误输出文件
```

![image-20231122154109440](https://cdn.789ak.com/img/image-20231122154109440.png)



## 系统调用

由[操作系统](https://baike.baidu.com/item/操作系统/192?fromModule=lemma_inlink)实现提供的所有系统调用所构成的集合即[程序接口](https://baike.baidu.com/item/程序接口/150383?fromModule=lemma_inlink)或应用编程接口(Application Programming Interface，API)。是[应用程序](https://baike.baidu.com/item/应用程序?fromModule=lemma_inlink)同系统之间的接口。

![img](https://img2.baidu.com/it/u=2608669739,1475496536&fm=253&fmt=auto&app=138&f=GIF?w=594&h=365)

Linux系统调用是应用程序与Linux内核进行交互的接口，可以请求内核对其提供服务。这些服务包括文件操作、进程管理、内存管理、网络通信等。系统调用可以实现访问系统资源的安全方式，因为它确保了用户空间和内核空间之间的隔离。在Linux系统中，系统调用以C库函数的形式提供给应用程序，而C库函数会调用相应的汇编指令来触发软中断，将控制权转交给内核进行相应的处理。Linux系统调用的调用号通过eax寄存器传递给内核，不同的系统调用有不同的调用号。



## `creat`函数

函数原型：

```cpp
int creat(const char *pathname, mode_t mode);   
```

参数说明： 

- `pathname`：文件路径名，可以是相对路径或绝对路径。 
- `mode`：文件创建模式，用于指定文件的权限、所有权等属性。mode_t是一个无符号整型数据类型。 

![image-20231122155739256](https://cdn.789ak.com/img/image-20231122155739256.png)

函数返回值：

- 如果文件创建成功，**返回文件的描述符**； 
- 如果文件创建失败，**返回-1**。 

creat函数的作用如下： 

1. 检查文件路径名是否合法； 
2. 创建一个新的文件； 
3. 设置文件的权限、所有权等属性； 
4. 返回文件的描述符，以便后续进行读写操作。

在使用时，需要包含以下头文件：

```cpp
#include <sys/types.h> // 包含基本系统数据类型
#include <sys/stat.h> // 包含文件数据结构信息
#include <fcntl.h> // 定义了很多宏和open等函数原型
```

例如，创建一个其他用户可以读、写的文件"lab.kk"。

```cpp
#include <sys/types.h> // 包含基本系统数据类型
#include <sys/stat.h> // 包含文件数据结构信息
#include <fcntl.h> // 定义了很多宏和open等函数原型

int main()
{
        creat("lab.kk", S_IROTH | S_IWOTH);
        return 0;
}
```

也可以用八进制表示：

```cpp
#include <sys/types.h> // 包含基本系统数据类型
#include <sys/stat.h> // 包含文件数据结构信息
#include <fcntl.h> // 定义了很多宏和open等函数原型

int main()
{
        creat("lab.kk", 0006 );
        return 0;
}
```



## `open`函数

`open`函数用于打开一个文件，并返回一个文件描述符，以便后续对文件进行读写操作。它有两种形式的原型： 

```cpp
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```

参数说明：

- `pathname`：文件路径名，可以是相对路径或绝对路径。 
- `flags`：打开文件时的标志，用于指定打开文件的方式（如只读、只写、追加等）。

![image-20231122160924597](https://cdn.789ak.com/img/image-20231122160924597.png)

-  `mode`：如果需要创建新文件，需要指定文件的创建模式（包括文件权限、所有权等属性），此参数仅在第二种形式中使用。



函数返回值： 

- 成功打开文件，返回文件描述符； 
- 打开文件失败，返回-1。

open函数的作用是用于打开文件或者创建文件。

例如，

```cpp
int fd1 = open("lab.kk", O_RDONLY); // 以只读方式打开文件lab.kk
```

```cpp
int fd2 = open("lab.kk", O_WRONLY | O_CREAT, 0644); // 以只写方式打开文件，如果文件不存在则创建，设置权限为0644 
```





[Linux文件描述符_linux查看文件描述符使用情况-CSDN博客](https://blog.csdn.net/m0_67623521/article/details/127055703?ops_request_misc=%7B%22request%5Fid%22%3A%22170063833016800184154448%22%2C%22scm%22%3A%2220140713.130102334.pc%5Fall.%22%7D&request_id=170063833016800184154448&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-4-127055703-null-null.142^v96^pc_search_result_base3&utm_term=Linux 文件描述符&spm=1018.2226.3001.4187)