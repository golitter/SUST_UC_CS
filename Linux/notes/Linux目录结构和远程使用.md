![003vPl7Rty6E8kZRlAEdc&690](https://atts.w3cschool.cn/attachments/uploads/2014/06/003vPl7Rty6E8kZRlAEdc690.jpg)

![img](https://img2018.cnblogs.com/blog/1320926/201906/1320926-20190602191411298-1453828893.png)

| 目录名     | 作用                                            |
| ---------- | ----------------------------------------------- |
| 根目录 '/' | 文件系统结构的起始点                            |
| /root      | 系统管理员的工作目录                            |
| /home      | 普通用户工作目录                                |
| /bin       | 存放二进制可执行文件，存放最经常使用的命令      |
| /sbin      | 系统管理员使用的系统管理程序                    |
| /boot      | 启动linux时使用的一些核心文件                   |
| /dev       | 设备文件，包括块设备和字符设备                  |
| /etc       | 系统管理文件和配置文件                          |
| /lib       | 动态链接共享库文件                              |
| /mnt       | 临时挂载别的文件系统的挂载目录                  |
| /usr       | 包含所有的用户程序(/usr/bin)，库文件(usr/bin)等 |
| /var       | 系统产生的缓存文件，日志记录                    |

### 命令行简介

登入后有一长溜字符前缀：

![image-20230906084457600](https://cdn.789ak.com/img/image-20230906084457600.png)

![image-20230906084523662](https://cdn.789ak.com/img/image-20230906084523662.png)

![img](https://cdn.789ak.com/img/@H$71TB2%5DTP5ZLPHVD9W%7B%7DF_tmb.jpg)

### 开关命令

- 注销

```shell
logout # 或者 exit
```

- 关机

```shell
shutdown -h now # 或者 halt -p 或者 poweroff
```

- 重启

```shell
reboot # 或者 shutdown -r now
```

## 远程终端访问

一般linux经常要用到远程终端访问。

Secure Shell(SSH) 是由 IETF(The Internet Engineering Task Force) 制定的建立在应用层基础上的安全网络协议。它是专为远程登录会话(甚至可以用Windows远程登录Linux服务器进行文件互传)和其他网络服务提供安全性的协议，可有效弥补网络中的漏洞。通过SSH，可以把所有传输的数据进行加密，也能够防止DNS欺骗和IP欺骗。还有一个额外的好处就是传输的数据是经过压缩的，所以可以加快传输的速度。目前已经成为Linux系统的标准配置。

- SSH

  为远程登录会话和其他网络服务提供安全性的协议

  利用SSH协议可以有效防止远程管理过程中的信息泄露问题

远程终端访问的软件有很多，其他只要安装有ssh在windows的cmd命令行都可以进行远程访问，还是推荐XShell或者vscode的remote插件。

ssh安装

```shell
sudo apt-get install openssh-client 
sudo apt-get install openssh-server 
```

启动ssh服务

```shell
sudo service ssh start
```



### 登录

#### 口令登录

命令格式为`ssh linux用户名@linux的IP地址`

例如：

```shell
ssh golitter@127.0.0.1
```

#### 公钥登录

每次登录远程主机都需要输入密码是很不方便的，如果想要省去这一步骤，可以利用密钥对进行连接，还可以提高安全性。

使用`ssh-keygen`产生公钥，将公钥复制到远程主机中即可。

## 远程文件管理

SFTP（SSH File Transfer Protocol）：S[SH文件](https://so.csdn.net/so/search?q=SH文件&spm=1001.2101.3001.7020)传输协议（安全文件传送协议），为传输文件提供一种安全的网络的加密方法，SFTP是SSH的其中一部分。

- SFTP

  是一种安全的远程文件传输协议

  是SSH协议类似，在传输过程中会进行加密







[Linux 系统目录结构_w3cschool](https://www.w3cschool.cn/linux/linux-system-contents.html)

[SSH简介及两种远程登录的方法_ssh @_Jack LDZ的博客-CSDN博客](https://blog.csdn.net/li528405176/article/details/82810342?ops_request_misc=%7B%22request%5Fid%22%3A%22169395904316777224499788%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=169395904316777224499788&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-82810342-null-null.142^v93^insert_down1&utm_term=ssh&spm=1018.2226.3001.4187)