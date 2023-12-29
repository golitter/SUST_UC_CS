## 网络管理命令

#### `ifconfig`

功能：配置和显示Linux的网络接口和参数。

![image-20230920105241475](https://cdn.789ak.com/img/image-20230920105241475.png)

- 最前面是网卡名。

- flags里面分别是：
  - UP：表示接口已经启用
  - BROADCAST：表示主机支持广播
  - RUNNING：表示接口在工作中
  - MULTICAST：表示主机支持多播
  - mtu：最大传输单元，1500字节。
- inet：网卡的IP地址
- netmask：网络掩码
- broadcast：广播地址
- inet6：网卡的IPv6地址
- ether：以太网mac地址
- RX部分
  - `RX packets`：接收的正确数据包数
  - `RX bytes`：接收的数据量
  - `RX errors`：接收的错误的数据包数
  - `RX dropped`：接收时丢弃的数据包数
  - `RX overruns`：接收时由于速度过快而丢失的数据包数
- TX部分：
  - `TX packets`：发送正确数据包数
  - `TX bytes`：发送的数据量
  - `TX errors`：发送的错误的数据包数
  - `TX dropped`：发送时丢弃的数据包数
  - `TX overruns`：发送时由于速度过快而丢失的数据包数

#### `netstat`

功能：打印Linux系统中网络系统的状态信息。

| 选项 | 功能            |
| ---- | --------------- |
| -a   | 显示所有端口    |
| -at  | 显示所有tcp端口 |
| -au  | 显示所有udp端口 |

![image-20230920110415665](https://cdn.789ak.com/img/image-20230920110415665.png)

- `Proto`：协议名。
- `Recv-Q`：网络接收队列
- `Send-Q`：网络发送队列
- `Local Address`：本地ip和端口
- `Foreign Address`：与本机端口通信的外部主机ip和端口
- `State`：链路状态

#### `ping`

功能：测试主机之间网络的连通性。

| 选项 | 功能               |
| ---- | ------------------ |
| -c   | 设置回应次数       |
| -s   | 设置数据包大小     |
| -v   | 设置命令的执行过程 |

![image-20230920110805870](https://cdn.789ak.com/img/image-20230920110805870.png)

- `ping`：目标主机的域名和ip
- 56(84)：不带包头的包大小和带包头的包大小
- icmp_seq：ping序列，从1开始
- ttl：剩余的生存时间
- time：响应时间，数值越小，速度越快
- transmitted：发出去的包数
- received：返回的包数
- packet loss：丢包率
- time：耗费时间
- min/avg/max：最小/平均/最大响应时间
- mdev：本机硬件耗费时间

## 通信命令

#### `write`

功能：当前用户向另一个用户发送信息。

#### `wall`

功能：当前用户向所有用户发送信息。

## 进程管理命令

### 查看进程命令

#### `ps`

功能：查看系统中正在运行的进程

| 选项 | 功能                                             |
| ---- | ------------------------------------------------ |
| -a   | 显示当前终端下的所有进程，包括其他用户启动的进程 |
| -u   | 以用户的形式，显示系统中的进程                   |
| -x   | 忽略终端机，显示所有进程                         |
| -l   | 使用详细的格式显示进程信息                       |

![image-20230920111720460](https://cdn.789ak.com/img/image-20230920111720460.png)

- PID：进程编号
- TTY：进程所运行的终端
- TIME：进程占用的CPU处理时间
- CMD：启动进程的命令

![image-20230920111852020](https://cdn.789ak.com/img/image-20230920111852020.png)

- UID：用户ID
- PID：进程ID
- PPID：父进程ID
- C：CPU的使用百分比
- STIME：启动时间
- TTY：登录终端
- TIME：CPU运行时间
- CMD：指令

![image-20230920112239061](https://cdn.789ak.com/img/image-20230920112239061.png)

- %CPU：进程的cpu占用率
- %MEM：进程的内存占用率
- VSZ：进程所使用的虚存的大小
- RSS：进程使用的物理内存大小
- STAT：进程的状态
  - R：正在执行
  - S：睡眠状态
  - s：包含子进程
  - <：高优先级

![image-20230920112448549](https://cdn.789ak.com/img/image-20230920112448549.png)

- F：进程的标识符（flag）
- S：进程的状态（STAT）
- UID：代表执行者ID
- PID：进程ID
- PPID：父进程ID
- C：CPU使用的资源百分比
- PRI：进程的执行优先级，值越小越早执行
- NI：进程的优先级的修正数值
- ADDR：程序在内存的部分。如果是执行的程序，一般为 '-'
- SZ：使用的内存大小
- WCHAN：这个程序是否正在运行中

#### `pstree`

功能：以树状图的形式显示系统中的进程。

| 选项 | 功能                       |
| ---- | -------------------------- |
| -a   | 显示每个进程的完整命令     |
| -c   | 不使用精简标识法           |
| -u   | 列出每个进程的所属用户名称 |
| -p   | 列出每个进程的PID          |

![image-20230920113001038](https://cdn.789ak.com/img/image-20230920113001038.png)

#### `top`

功能：实时监控进程的状态，屏幕自动每3秒刷新一次。

`top`命令是一个用于监视系统运行状态的实用工具。它提供了实时的对系统资源使用情况的监控，包括CPU占用率、内存使用情况、进程信息等。

使用top命令可以获得一个动态更新的终端窗口，其中显示了各个进程的相关信息。默认情况下，top命令按照CPU使用率降序排列进程，并显示当前的系统负载情况。

[TOP命令参数详解---10分钟学会top用法_top参数详解_江湖人称小青年的博客-CSDN博客](https://blog.csdn.net/langzi6/article/details/124805024?ops_request_misc=%7B%22request%5Fid%22%3A%22169517558516800180680888%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=169517558516800180680888&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-124805024-null-null.142^v94^insert_down28v1&utm_term=top&spm=1018.2226.3001.4187)

> 感觉上面这个博客对top命令的阐述很完美。没必要再写一遍了。

