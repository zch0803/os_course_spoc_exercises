
定义了5个信号量

```
sem_t mutex_AM;// AM路段只允许一辆自行车
sem_t mutex_BM;// BM路段只允许一辆自行车
sem_t mutex_A2B;// B->A方向只允许一辆自行车
sem_t mutex_B2A; // B->A方向只允许一辆自行车
sem_t print_lock; // 用于打印相关信息用
```

输出结果如下：

```
thread 7 BtoA: A<---M<-*-B
thread 0 AtoB: A-*->M--->B
thread 7 BtoA: at M
thread 0 AtoB: at M
thread 7 BtoA: A<-*-M<---B
thread 0 AtoB: A--->M-*->B
thread 7 BtoA: at A
thread 0 AtoB: at B
thread 6 BtoA: A<---M<-*-B
thread 4 AtoB: A-*->M--->B
thread 6 BtoA: at M
thread 4 AtoB: at M
thread 6 BtoA: A<-*-M<---B
thread 6 BtoA: at A
thread 9 BtoA: A<---M<-*-B
thread 9 BtoA: at M
thread 4 AtoB: A--->M-*->B
thread 9 BtoA: A<-*-M<---B
thread 4 AtoB: at B
thread 9 BtoA: at A
thread 8 BtoA: A<---M<-*-B
thread 1 AtoB: A-*->M--->B
thread 8 BtoA: at M
thread 1 AtoB: at M
thread 8 BtoA: A<-*-M<---B
thread 1 AtoB: A--->M-*->B
thread 1 AtoB: at B
thread 8 BtoA: at A
thread 2 AtoB: A-*->M--->B
thread 5 BtoA: A<---M<-*-B
thread 5 BtoA: at M
thread 2 AtoB: at M
thread 2 AtoB: A--->M-*->B
thread 5 BtoA: A<-*-M<---B
thread 2 AtoB: at B
thread 5 BtoA: at A
thread 3 AtoB: A-*->M--->B
thread 3 AtoB: at M
thread 3 AtoB: A--->M-*->B
thread 3 AtoB: at B
```