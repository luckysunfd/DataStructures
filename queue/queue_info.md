## Queue
---

1.队列是一种从头部出，尾部进的线性结构， first in first out
  
  顺序队列的单向形式有内存空间浪费的问题，所以应用面较窄，一般使用循环顺序队列
  
  有一下单向顺序队列

offset   

       |0  | 1 | 2 |

       | a | b | c | 
   
   front， rear 初始化状态下指向offset -1的数组位置
   
   进队列的时候，rear尾部指针+1 然后保存到数组的相应位置，直到存满整个数组，也就是 数组长度-1 的偏移处结束

   出队列的时候，front头部指针也是+1，然后弹出该位置上的数据，直到rear指针出结束，此时front，rear指向同一个位置
   显而易见，此时的队列状态为空

   但是，有一个问题，随着front的向上增长，之前的位置已经不可读写了，造成了空间的浪费

   
   如果能够循环利用存储空间就好了，也就是说理想状态下 的存储空间应该是首尾相顾的，例如
   |0|1|2|3| 3后面的地址应该是offset 0的地址，但是我们直到，内存是平坦线性的，物理上永远不会出现前面说述的状态
   那么，我们只能从编码上实现，利用一些技巧来从读写上实现 利用同一个简单手法来实现内存空间的循环利用，比如说访问了offset 3后
   用同一个简单手法直接可以访问offset 0

   这个问题可以看成是在一个 数字环内 循环访问， 形象的比喻， 数字时钟

   我们直到求余运算就是取的在一个数字环内的数，例如上面所说的时钟

   利用取余就可以实现 ， 假设一个 数组有3个元素，为了更好的描述，称之为maxsize ，offset范围则即从0-2

   front，rear 初始状态指向0

   进队： （rear + 1）% maxsize的结果作为偏移值 访问数组位置
   
           rear = 0时， rear+1 % maxsize = 1；
           
           rear = 1，   rear+1 % maxsize = 2;
           
           rear = 2,    rear+1 & maxsize = 0;
           

   出队： （front + 1）% maxsize
           
   之所以从0开始，是因为需要牺牲一个空间为代价来判断队列是否为空，是否已满

   当rear == front时，就是已空
   当rear + 1 % maxsize == front时就是已满
   
   

   如果一个空间都不浪费的情况，已满已空状态都是rear，front都指向同一个位置，无法判断了，这个自己从两遍队列的出队入队，看看各种情况就了解了

  adt:
  
  struct sequence_queue{
  
        int (*p)[10];   //容器
        int front;   //指向头部
        int rear;   //指向尾部
  }

  void init(seq_queueptr);
  
  bool is_full(seq_queueptr);
  
  bool is_empty(seq_queueptr);
  
  void enter_queue(seq_queueptr);
  
  DataType delete_queue(seq_queueptr);
  
  int get_length(seq_queueptr);

---

2.队列的链式存储方式

利用链表实现

adt:


//节点的结构体

struct queueNode{

    DataType data;
    queue *next;
}

//链式队列的结构体

struct queueinfo{

    queueptr front;
    queueptr rear;
    int length;
}


参照链表的实现，用尾插法插入节点，front即相当于链表的头部节点，rear相当于链表的尾部节点
插入前需要判断头部节点是否已经赋值节点，没有则赋值头节点、尾节点，长度+1
若已经有，则利用尾节点将新节点加入，然后更新尾部节点指向新节点，长度+1 就可以了

出队则是看成链表从头部开始删除节点的过程


 
