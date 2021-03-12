#include "linked_list.h"


linked_list_ptr init_1(linked_list_ptr linked1){
	linked1 = (linked_list_ptr)malloc(sizeof(linked_list));
        assert(linked1);
        memset(linked1, 0, sizeof(linked_list));
	linked1->length = 0;
	linked1->head = NULL;
	linked1->tails = NULL;

	return linked1;
}

linked_node_ptr create_node1(DataType data){
	linked_node_ptr node = (linked_node_ptr)malloc(sizeof(linked_node));
	assert(node);
	node->data = data;
	node->next = NULL;

	return node;
}
//头插法插入节点
void insert_h(linked_list_ptr linked1, DataType data){
	if(linked1 == NULL){
		puts("链表未初始化");
	}else{
		linked_node_ptr node = (linked_node_ptr)malloc(sizeof(linked_node));
		assert(node);
		node->data = data;
		node->next = linked1->head;   //新节点next指向当前链表的头部节点
		/*因为是头插法插入新节点，并且链表结构包含有关于链表信息的头尾节点地址，在初次插入时，链表的尾部节点就已经固化下来了，
		 *所以仅当第一次插入节点时赋值给链表结构的尾部节点才是正确的
		*/
		if(linked1->tails == NULL && linked1->head == NULL){
			linked1->head = node;
			linked1->tails = node;
			linked1->length++;
		}else{
			linked1->head = node;  //更新头部节点
			linked1->length++;      //链表长度+1
		}
	}
}
//尾插法
void insert_t(linked_list_ptr linked1, DataType data){
	/* 在这里也是分两种情况，第一种是传进来一个刚初始化过的链表， 第二种是已有至少一个节点的情况下的插入
	 * 因为是尾插法插入新节点，操作端在链表的尾部，在初次插入新节点时 链表的头部节点就已经固化下来了
	*/
	if(linked1->head == NULL && linked1->tails == NULL){
		linked1->head = create_node1(data);
		linked1->tails = linked1->head;
		linked1->length++;
	}else{
		linked1->tails->next = create_node1(data);
		linked1->tails = linked1->tails->next;
		linked1->length++;
	}
}

int get_length_1(linked_list_ptr linked1){
	return linked1->length;
}
// 添加节点要特别处理的是在头部添加新节点跟在尾部添加新节点
void add_node_1(linked_list_ptr linked1, int position, DataType data){
	puts("add node-----");
	linked_node_ptr node = (linked_node_ptr)malloc(sizeof(linked_node));
	assert(node);
	memset(node, 0, sizeof(linked_node));

	node->data = data;
	node->next = NULL;
 
	int previous_pos = 1;   //因为此时的链表是保存有链表信息的结构体，头节点就是当前有效的节点，所以从1开始计数
	linked_node_ptr previous_node = linked1->head;

	if(position < 0 || position > get_length_1(linked1)){
		puts("Illegal position!");
		return ;
	}else if(position == 1){
		puts("---add node debug info---");
		node->next = linked1->head;
		linked1->head = node;
                linked1->length++;
        }else if(position == linked1->length){
                linked1->tails->next = node;
                linked1->tails = node;
                linked1->length++;
        }else{
		//前一个条件限制是否到达末尾，当到达末尾时，就要退出这个循环了，此时获取到的是末尾节点，然后执行后面的操作才不会出现段错误
		//后一个限制次数，以获取到想插入节点的上一个节点，因为单链表是单向往下关联的，所以操作后面的节点要获取它的前一个节点
		while(previous_node != NULL && previous_pos != position - 1){  //这里改成previous_node->next != NULL 则可以传入大于链表长度的位置，大于的一律添加到尾部
			previous_node = previous_node->next;
			previous_pos++;
			puts("---add  func  debug info---");
			printf("previous_pos = %d\n", previous_pos);
		}

		node->next = previous_node->next;
		previous_node->next = node;
		linked1->length++;
		//如果前面previous_node->next != NULL, 那么，这里应该是position  >= length
		if(position == get_length_1(linked1)){
			linked1->tails = node;
		}
	}

}

//需要一个临时变量保存后续部分链表，还需要一个变量保存要删除的地址,因为如果没有这个变量的话，无论是先释放还是先重新链接节点都会造成节点的丢失，造成内存泄漏
//还有就是要特别关注删除尾部的情况，因为记录了尾部指针，所以要单独拿出来做条件判断，如果删的是尾部则要更新尾部指针的指向
void remove_node_1(linked_list_ptr linked1, int position){
	if(position >=1 && position <= linked1->length){
		linked_node_ptr previous_node = linked1->head; //assign first node
		int previous_pos = 1; //第一个位置计数开始

		while(previous_pos != position - 1){
			previous_pos++;
			previous_node = previous_node->next;
		}
                if(position == linked1->length){
                        linked1->tails = previous_node;
                        printf("-------------previous_node data:%d\n", previous_node->data);
                }
		linked_node_ptr temp = previous_node->next;   //保存要删除的节点的地址
		previous_node->next = temp->next;  //重新链接节点
		linked1->length--;
		free(temp);    //释放堆空间

	}else{
		puts("Illegal position");
	}
}
//return node addr
linked_node_ptr find_node_data_1(linked_list_ptr linked1, DataType fdata){
	linked_node_ptr node = linked1->head;
	int count = 1; //计数，防止走到头还是没有查找到，之所以从1开始，因为第一个比较的就是有效的头节点
	while(count != linked1->length && node->data != fdata){
		count++;
		node = node->next;
	}
	if(count == linked1->length){
		puts("not found!");
		return NULL;
	}else{
		puts("found!");
		printf("node addr:%p v:%d pos:%d\n", node, node->data, count);
		return node;
	}
}

void alter_node_data_1(linked_list_ptr linked1, int position, DataType data){
	if(position >=1 && position <= linked1->length){
		int count = 1;
		linked_node_ptr node = linked1->head;
		while(count != position){
			node = node->next;
			count++;
		}
		node->data = data;
		printf("alter node : %d\n", node->data);
	}else{
		puts("Illegal position");
	}
}

void destroy_linked_1(linked_list_ptr linked1){
	linked_node_ptr temp = linked1->head->next;  //保存头节点的下一个节点
	while(temp != NULL){
		free(linked1->head);  //释放头节点
		linked1->length--;
		linked1->head = temp;  //重新设置头节点
		temp = linked1->head->next;  //保存新头节点的下一个节点
                printf("%d\n", get_length_1(linked1));
	}
        free(linked1->head);
        linked1->length--;
        linked1->head = NULL;
        linked1->tails = NULL;
	puts("------------");
}

//这里实现的遍历需要一个临时变量记录下一个节点，因为此时传入的是一个记录了链表信息的链表结构体指针，对这个指针的操作会影响指针指向的内容，导致链表丢失节点
void print_linked(linked_list_ptr linked1){
	linked_node_ptr node = linked1->head;

	while(node != NULL){
		printf("%d\n", node->data);
		node = node->next;
	}
}













