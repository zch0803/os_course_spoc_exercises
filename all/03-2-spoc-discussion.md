# lec6 SPOC思考题


NOTICE
- 有"w3l2"标记的题是助教要提交到学堂在线上的。
- 有"w3l2"和"spoc"标记的题是要求拿清华学分的同学要在实体课上完成，并按时提交到学生对应的git repo上。
- 有"hard"标记的题有一定难度，鼓励实现。
- 有"easy"标记的题很容易实现，鼓励实现。
- 有"midd"标记的题是一般水平，鼓励实现。

## 与视频相关思考题

### 6.1	非连续内存分配的需求背景
 1. 为什么要设计非连续内存分配机制？
 1. 非连续内存分配中内存分块大小有哪些可能的选择？大小与大小是否可变
 1. 为什么在大块时要设计大小可变，而在小块时要设计成固定大小？小块时的固定大小可以提供多种选择吗？

### 6.2	段式存储管理
 1. 什么是段、段基址和段内偏移？
 1. 段式存储管理机制的地址转换流程是什么？为什么在段式存储管理中，各段的存储位置可以不连续？这种做法有什么好处和麻烦？

### 6.3	页式存储管理
 1. 什么是页（page）、帧（frame）、页表（page table）、存储管理单元（MMU）、快表（TLB, Translation Lookaside Buffer）和高速缓存（cache）？
 1. 页式存储管理机制的地址转换流程是什么？为什么在页式存储管理中，各段的存储位置可以不连续？这种做法有什么好处和麻烦？

 > 多次存储访问

### 6.4	页表概述
 1. 每个页表项有些什么内容？有哪些标志位？它们起什么作用？
 1. 页表大小受哪些因素影响？

 >  页大小、地址空间大小、进程数目

### 6.5	快表和多级页表
 1. 快表（TLB）与高速缓存（cache）有什么不同？
 1. 为什么快表中查找物理地址的速度非常快？它是如何实现的？为什么它的的容量很小？
 1. 什么是多级页表？多级页表中的地址转换流程是什么？多组页面有什么好处和麻烦？

### 6.6	反置页表
 1. 页寄存器机制的地址转换流程是什么？
 1. 反置页表机制的地址转换流程是什么？
 1. 反置页表项有些什么内容？

 >  PID、逻辑页号、标志位

### 6.7	段页式存储管理
 1. 段页式存储管理机制的地址转换流程是什么？这种做法有什么好处和麻烦？
 1. 如何实现基于段式存储管理的内存共享？
 1. 如何实现基于页式存储管理的内存共享？

## 个人思考题
---

（1） (w3l2) 请简要分析64bit CPU体系结构下的分页机制是如何实现的
```
  + 采分点：说明64bit CPU架构的分页机制的大致特点和页表执行过程
  - 答案没有涉及如下3点；（0分）
  - 正确描述了64bit CPU支持的物理内存大小限制（1分）
  - 正确描述了64bit CPU下的多级页表的级数和多级页表的结构或反置页表的结构（2分）
  - 除上述两点外，进一步描述了在多级页表或反置页表下的虚拟地址-->物理地址的映射过程（3分）
 ```
- [x]  

>  

## 小组思考题
---

（1）(spoc) 某系统使用请求分页存储管理，若页在内存中，满足一个内存请求需要150ns (10^-9s)。若缺页率是10%，为使有效访问时间达到0.5us(10^-6s),求不在内存的页面的平均访问时间。请给出计算步骤。 

- [x]  

> 500=0.9\*150+0.1\*x

（2）(spoc) 有一台假想的计算机，页大小（page size）为32 Bytes，支持32KB的虚拟地址空间（virtual address space）,有4KB的物理内存空间（physical memory），采用二级页表，一个页目录项（page directory entry ，PDE）大小为1 Byte,一个页表项（page-table entries
PTEs）大小为1 Byte，1个页目录表大小为32 Bytes，1个页表大小为32 Bytes。页目录基址寄存器（page directory base register，PDBR）保存了页目录表的物理地址（按页对齐）。

PTE格式（8 bit） :
```
  VALID | PFN6 ... PFN0
```
PDE格式（8 bit） :
```
  VALID | PT6 ... PT0
```
其
```
VALID==1表示，表示映射存在；VALID==0表示，表示映射不存在。
PFN6..0:页帧号
PT6..0:页表的物理基址>>5
```
在[物理内存模拟数据文件](./03-2-spoc-testdata.md)中，给出了4KB物理内存空间的值，请回答下列虚地址是否有合法对应的物理内存，请给出对应的pde index, pde contents, pte index, pte contents。
```
1) Virtual Address 6c74
   Virtual Address 6b22
2) Virtual Address 03df
   Virtual Address 69dc
3) Virtual Address 317a
   Virtual Address 4546
4) Virtual Address 2c03
   Virtual Address 7fd7
5) Virtual Address 390e
   Virtual Address 748b
```

比如答案可以如下表示： (注意：下面的结果是错的，你需要关注的是如何表示)
```
Virtual Address 7570:
  --> pde index:0x1d  pde contents:(valid 1, pfn 0x33)
    --> pte index:0xb  pte contents:(valid 0, pfn 0x7f)
      --> Fault (page table entry not valid)
      
Virtual Address 21e1:
  --> pde index:0x8  pde contents:(valid 0, pfn 0x7f)
      --> Fault (page directory entry not valid)

Virtual Address 7268:
  --> pde index:0x1c  pde contents:(valid 1, pfn 0x5e)
    --> pte index:0x13  pte contents:(valid 1, pfn 0x65)
      --> Translates to Physical Address 0xca8 --> Value: 16
```
* 计算过程：
  * 页目录大小为32Bytes，所以首先把虚拟地址中的最高5位作为PDE的索引，加上PDBR的PD基址，在PDE表中找到相应的表项，判断是否合法。
  * 若PDE合法，则使用PDE表中的最低7位作为PTE的页帧号（左移5位），加上虚拟地址中的中间5位索引，然后在PTE表中找到相应的表项，判断是否合法。
  * 若PTE合法，则使用PTE表中的最低7位作为物理地址的页帧号（左移5位），加上虚拟地址中的最低5位偏移，读出相应的数值。
* 根据以上计算过程编写了[程序](https://github.com/junjiek/os_course_spoc_exercises/blob/master/03-2-spoc/map.py)
* 计算结果：

```
Virtual Address 0x6c74:
    --> pde index: 0x1b pde contents:(valid 0x1, pfn 0x20)
        --> pte index: 0x3 pte contents:(valid 0x1, pfn 0x61)
            --> Translated to Physical Address 0xc34 --> Value: 0x6

Virtual Address 0x6b22:
    --> pde index: 0x1a pde contents:(valid 0x1, pfn 0x52)
        --> pte index: 0x19 pte contents:(valid 0x1, pfn 0x47)
            --> Translated to Physical Address 0x8e2 --> Value: 0x1a

Virtual Address 0x3df:
    --> pde index: 0x0 pde contents:(valid 0x1, pfn 0x5a)
        --> pte index: 0x1e pte contents:(valid 0x1, pfn 0x5)
            --> Translated to Physical Address 0xbf --> Value: 0xf

Virtual Address 0x69dc:
    --> pde index: 0x1a pde contents:(valid 0x1, pfn 0x52)
        --> pte index: 0xe pte contents:(valid 0x0, pfn 0x7f)
            --> Fault (page table entry not valid)

Virtual Address 0x317a:
    --> pde index: 0xc pde contents:(valid 0x1, pfn 0x18)
        --> pte index: 0xb pte contents:(valid 0x1, pfn 0x35)
            --> Translated to Physical Address 0x6ba --> Value: 0x1e

Virtual Address 0x4546:
    --> pde index: 0x11 pde contents:(valid 0x1, pfn 0x21)
        --> pte index: 0xa pte contents:(valid 0x0, pfn 0x7f)
            --> Fault (page table entry not valid)

Virtual Address 0x2c03:
    --> pde index: 0xb pde contents:(valid 0x1, pfn 0x44)
        --> pte index: 0x0 pte contents:(valid 0x1, pfn 0x57)
            --> Translated to Physical Address 0xae3 --> Value: 0x16

Virtual Address 0x7fd7:
    --> pde index: 0x1f pde contents:(valid 0x1, pfn 0x12)
        --> pte index: 0x1e pte contents:(valid 0x0, pfn 0x7f)
            --> Fault (page table entry not valid)

Virtual Address 0x390e:
    --> pde index: 0xe pde contents:(valid 0x0, pfn 0x7f)
        --> Fault (page directory entry not valid)

Virtual Address 0x748b:
    --> pde index: 0x1d pde contents:(valid 0x1, pfn 0x0)
        --> pte index: 0x4 pte contents:(valid 0x0, pfn 0x7f)
            --> Fault (page table entry not valid)

```

（3）请基于你对原理课二级页表的理解，并参考Lab2建页表的过程，设计一个应用程序（可基于python、ruby、C、C++、LISP、JavaScript等）可模拟实现(2)题中描述的抽象OS，可正确完成二级页表转换。
 > 答案见[github](https://github.com/zch0803/os_course_spoc_exercises/blob/master/all/03-2-spoc-discussion/map.py)

（4）假设你有一台支持[反置页表](http://en.wikipedia.org/wiki/Page_table#Inverted_page_table)的机器，请问你如何设计操作系统支持这种类型计算机？请给出设计方案。

 (5)[X86的页面结构](http://os.cs.tsinghua.edu.cn/oscourse/OS2015/lecture06#head-1f58ea81c046bd27b196ea2c366d0a2063b304ab)
--- 

## 扩展思考题

阅读64bit IBM Powerpc CPU架构是如何实现[反置页表](http://en.wikipedia.org/wiki/Page_table#Inverted_page_table)，给出分析报告。

--- 
