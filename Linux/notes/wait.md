`wait` 函数是用于等待子进程结束并获取子进程的终止状态的系统调用。它在父进程中使用，用于等待其子进程终止并获得子进程的退出状态。 

函数原型：

```cpp
pid_t wait(int *status);
```

`status` 是一个指向整型的指针，用于存储子进程终止时的退出状态，可以通过它获取子进程的退出状态。 

`wait` 函数返回已终止子进程的进程ID，如果没有已终止的子进程，`wait` 会一直阻塞父进程，直到有子进程结束为止。 

```cpp
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {
    pid_t val;
    printf("PID before fork(): %d\n",getpid());
    val = fork();
    if(val == 0) {
        printf("I am the child process, PID is %d\n", getpid());
    } else if(val > 0) {
        wait(NULL);
        printf("I am parent process, PID is %d\n", getpid());
    } else {
        printf("Error");
    }
}
```

![image-20231121153009314](https://cdn.789ak.com/img/image-20231121153009314.png)











[【精选】Linux中wait()函数_linux wait-CSDN博客](https://blog.csdn.net/modi000/article/details/124605195?ops_request_misc=%7B%22request%5Fid%22%3A%22170054928216800182745173%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=170054928216800182745173&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-1-124605195-null-null.142^v96^pc_search_result_base3&utm_term=linux wait&spm=1018.2226.3001.4187)