# 死锁与IPC(lec 20) spoc 思考题


- 有"spoc"标记的题是要求拿清华学分的同学要在实体课上完成，并按时提交到学生对应的ucore_code和os_exercises的git repo上。

## 个人思考题

### 20.1 死锁概念 
1. 尝试举一个生活中死锁实例。
2. 可重用资源和消耗资源有什么区别？

 > 可重用和不可撤销；
 
3. 资源分配图中的顶点和有向边代表什么含义？
4. 出现死锁的4个必要条件是什么？

### 20.2 死锁处理方法 
1. 死锁处理的方法有哪几种？它们的区别在什么地方？
2. 安全序列的定义是什么？

 > 进程的最大资源需要量小于可用资源与前面进程占用资源的总合；

3. 安全、不安全和死锁有什么区别和联系？

### 20.3 银行家算法 
1. 什么是银行家算法？
2. 安全状态判断和安全序列是一回事吗？

### 20.4 死锁检测 
1. 死锁检测与安全状态判断有什么区别和联系？

 > 死锁检测、安全状态判断和安全序列判断的本质就是资源分配图中的循环等待判断。

### 20.5 进程通信概念 
1. 直接通信和间接通信的区别是什么？

 > 本质上来说，间接通信可以理解为两个直接通信，间接通信中假定有一个永远有效的直接通信方。

2. 同步和异步通信有什么区别？

### 20.6 信号和管道 

2. 写一个检查本机网络服务工作状态并自动重启相关服务的程序。
3. 什么是管道？

### 20.7 消息队列和共享内存 
1. 写测试用例，测试管道、消息队列和共享内存三种通信机制进行不同通信间隔和通信量情况下的通信带宽、通信延时、带宽抖动和延时抖动方面的性能差异。
 
## 小组思考题

1. （spoc） 每人用python实现[银行家算法](https://github.com/chyyuu/ucore_lab/blob/master/related_info/lab7/deadlock/bankers-homework.py)。大致输出可参考[参考输出](https://github.com/chyyuu/ucore_lab/blob/master/related_info/lab7/deadlock/example-output.txt)。除了`YOUR CODE`部分需要填写代码外，在算法的具体实现上，效率也不高，可进一步改进执行效率。[code](https://github.com/zch0803/os_course_spoc_exercises/blob/master/all/banker.py)
2. (spoc) 以小组为单位，请思考在lab1~lab5的基础上，是否能够实现IPC机制，请写出如何实现信号，管道或共享内存（三选一）的设计方案。
3. (spoc) 扩展：用C语言实现某daemon程序，可检测某网络服务失效或崩溃，并用信号量机制通知重启网络服务。[信号机制的例子](https://github.com/chyyuu/ucore_lab/blob/master/related_info/lab7/ipc/signal-ex1.c)
4. (spoc) 扩展：用C语言写测试用例，测试管道、消息队列和共享内存三种通信机制进行不同通信间隔和通信量情况下的通信带宽、通信延时、带宽抖动和延时抖动方面的性能差异。[管道的例子](https://github.com/chyyuu/ucore_lab/blob/master/related_info/lab7/ipc/pipe-ex2.c)
