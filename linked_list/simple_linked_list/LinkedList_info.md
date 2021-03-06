## LinkedList 

### 一 基础
链表是一种线性存储结构，是用逻辑上相连的空间存储数据的一种数据结构

不同于数组的物理连续地址空间，链表关联上下元素地址空间的是指针，用指针来约束前后关系，例如在单向链表中，各节点依靠next指针域关联后续节点，双向链表则因为有前后指针，所以可以联系前后节点

如下|data | next ptr| -》 |data | next ptr|, 其中每个节点的next指针域都包含有指向一个节点的地址

---

### 二 链表种类
依据指针域有无previous指针域

1. 单链表  
2. 双向链表

首尾相连de循环链表 

单循环链表
双循环链表

---

### 三 头插法  尾插法

链表的创建 依据在头部还是尾部插入节点的不同，有两种方法：
头插法

尾插法

所谓头插法指的是在创建链表的时候将新节点插入到当前链表的头部位置
而尾插法则是指在创建链表的时候将新节点插入到当前链表的尾部

---

### 四  链表adt

每一个链表节点都包含一个存储数据的数据域以及指向下一个节点或者前后节点的指针域，显然链表结构体应该如下所定义那样

struct linkednode{

	    datatype data;
	    struct linkednode *next;
	    (or struct linkednode *previous;)
};

上面是单独定义了一个链表节点，用其作为头部节点引导整个链表时会缺少某些关于链表的属性信息，例如，头部节点地址，尾部节点地址，链表长度

也可以单独再另外定义一个链表结构，存储整个链表的信息，如下定义

struct linked{

	    int length; 
	    struct linked *head;
	    struct linked *tails;
};

当然也可以直接使用头节点作为链表来使用

---

### 五  链表操作

初始化

按照头尾插入法插入新节点

在指定位置插入节点

求长度

删除节点

查找节点

修改节点

遍历节点

### 6 注意

链表操作最重要的是 不能因为 对当前链表进行某一操作而让链表部分甚至全部丢失

