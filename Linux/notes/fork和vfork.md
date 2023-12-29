`fork`和`vfork`是用于创建新进程的函数，在Linux的C语言编程中非常常见。 



## fork函数

`fork`函数是用于创建一个新的进程，新进程是调用进程的副本。新进程将包含调用进程的地址空间、文件描述符、栈和数据。在`fork`之后，父进程和子进程将并发执行。

-  `fork`后会有两个并发程序执行
- 子进程复制了父进程的数据段，包括全局变量

`fork`函数原型：

```cpp
pid_t fork(void);
```

`fork`函数返回值为：

- 如果是在父进程中，返回新创建的子进程的进程ID； 
- 如果是在子进程中，返回0； 
- 若出现错误，返回-1。 



```cpp
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * fork后会有两个并发程序执行
 * 子进程复制了父进程的数据段，包括全局变量
*/
int main() {
    pid_t val;
    printf("PID before fork(): %d\n",getpid());
    val = fork();
    // *********************************************************************
    if(val == 0) {
        printf("I am the child process, PID is %d\n", getpid());
    } else if(val > 0) {
        printf("I am parent process, PID is %d\n", getpid());
    } else {
        printf("Error");
    }
}
```

![image-20231121145831531](https://cdn.789ak.com/img/image-20231121145831531.png)

从`fork`语句后开始父进程和子进程。

![image-20231121150110720](https://cdn.789ak.com/img/image-20231121150110720.png)

## vfork函数

`vfork`函数是Linux和Unix系统中用于创建新进程的另一个函数，与`fork`函数类似，但行为有所不同。`vfork`创建的新进程与调用进程共享地址空间，这样可以减少内存的使用。然而，需要注意的是，在子进程调用`exec`或`exit`之前，父进程会被阻塞。 

- `vfork`创建的子进程与父进程共享地址空间
- 调用`vfork`创建子进程后，**父进程会被挂起，直到子进程结束**

```cpp
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * vfork创建的子进程与父进程共享地址空间
 * 调用vfork创建子进程后，父进程被挂起，直到子进程结束。
*/
int A = 0;
int B = 0;
int main()
{
    pid_t val;
    val = vfork();
    if(val == 0) {
        ++A, ++B;
        printf("A: %d , B: %d\n", A, B);
    } else {
        ++A, ++B;
        printf("A: %d , B: %d\n", A, B);

    }
    
}
```

![image-20231121150436009](https://cdn.789ak.com/img/image-20231121150436009.png)

如果将`vfork`换为`fork`：

```cpp
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int A = 0;
int B = 0;
int main()
{
    pid_t val;
    val = fork();
    if(val == 0) {
        ++A, ++B;
        printf("A: %d , B: %d\n", A, B);
    } else {
        ++A, ++B;
        printf("A: %d , B: %d\n", A, B);

    }
    
}
```

![image-20231121150526469](https://cdn.789ak.com/img/image-20231121150526469.png)

可以发现：`vfork`创建的子进程与父进程共享地址空间。

