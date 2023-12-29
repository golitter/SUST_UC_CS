## `close`函数

函数原型：

```cpp
#include <unistd.h>
int close(int fd);
```

参数：

- `fd`：要关闭的文件的文件描述符

返回值：

- 调用成功：返回`0`;
- 调用失败：返回`-1`

功能：**关闭一个已经打开的文件。**



## `read`函数

函数原型：

```cpp
#include <unistd.h>
size_t read(int fd, const void *buf, size_t count);
```

参数：

- `fd`：文件描述符
- `buf`：缓冲区指针，用于缓存从文件中读取的数据
- `count`：要请求读取的字节数

返回值：

- 调用成功：返回实际读取的字节数；
- 调用失败：返回`-1`

功能：**从一个打开的额文件中读取文件。**



## `write`函数

函数原型：

```cpp
#include <unistd.h>
size_t write(int fd, const void *buf, size_t count);
```

参数：

- `fd`：文件描述符
- `buf`：缓冲区指针，准备写入文件的数据
- `count`：要写入文件的字节数

返回值：

- 调用成功：返回实际写入的字节数
- 调用失败：返回`-1`



创建"a.txt"文件，并向文件内写入内容。

```cpp
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
        int fd = creat("a.txt", 0644); // 创建一个主用户可读写，组用户可读，其他用户可读的文件，并得到它的文件标识符
        if(fd == -1) {
                printf("创建失败");
                return 0;
        }
        char buf[256] = {"HELLO WORLD!"};

        write(fd, buf, sizeof(buf));
        close(fd);
        return 0;
}
```

读入"a.txt"文件的内容并输出到屏幕上。

```cpp
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
        int fd = open("a.txt", O_RDONLY);
        if(fd == -1) {
                printf("创建失败");
                return 0;
        }
        char buf[256];
        int n = 0;
        while( (n = read(fd, buf, 256)) > 0 )
        {
                write(STDOUT_FILENO, buf, n);
        }
        close(fd);

        return 0;
}
```

