#include "avl.h"



ptr_avl Get_New_Node(ElemType data) {
    ptr_avl new_node = (ptr_avl)malloc(sizeof(avl_t));
    assert(new_node != NULL);

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;

    return new_node;
}

unsigned int Get_Height(ptr_avl avl) {
    if( avl == NULL ) {
        return 0;
    }

    return ( Get_Height(avl->left) > Get_Height(avl->right) ? Get_Height(avl->left) : Get_Height(avl->right) ) + 1;
}

void Set_Height(ptr_avl avl) {
    if( avl != NULL ) {
        avl->height = Get_Height(avl);
    }
}

/* four case */
// right-right 
ptr_avl Left_Rotation(ptr_avl avl) {
    ptr_avl new_root = avl->right;
    ptr_avl will_old_root_right = new_root->left;

    // Perform rotation
    new_root->left = avl;
    avl->right = will_old_root_right;

    // Updating height
    Set_Height(avl);
    Set_Height(new_root);

    return new_root;
}

// left-right
ptr_avl Left_Right_Rotation(ptr_avl avl) {
    avl->left = Left_Rotation(avl->left);
    return Right_Rotation(avl);
}

// left-left
ptr_avl Right_Rotation(ptr_avl avl) {
    ptr_avl new_root = avl->left;
    ptr_avl will_old_root_left = new_root->right;

    // Perform rotation
    new_root->right = avl;
    avl->left = will_old_root_left;

    // Updating height
    Set_Height(avl);
    Set_Height(new_root);

    return new_root;
}

// right-left
ptr_avl Right_Left_Rotation(ptr_avl avl) {
    avl->right = Right_Rotation(avl->right);
    return Left_Rotation(avl);
}

ptr_avl Get_Min_Node(ptr_avl avl) {
    if( avl != NULL ) {
        while( avl->left != NULL ) {
            avl = avl->left;
        }
        return avl;
    }

    return NULL;
}

int Get_BF(ptr_avl avl) {
    return Get_Height(avl->left) - Get_Height(avl->right);
}

ptr_avl Insert_Node(ptr_avl avl, ElemType data) {
    if( avl == NULL ) {
        avl = Get_New_Node(data);
    }
    else if (data < avl->data ) {
        avl->left = Insert_Node(avl->left, data);
    }else{
        avl->right = Insert_Node(avl->right, data);
    }

    // updating height
    Set_Height(avl);
    // get balanced factor
    int bf = Get_BF(avl);

    /* four case 不平衡的话就要平衡后再返回 */
    if( bf > 1 && data < avl->left->data ) {
        // left-left, need right rotation
        return Right_Rotation(avl);
    }
    if( bf > 1 && data > avl->left->data ) {
        // left-right, need l-r rotation
        return Left_Right_Rotation(avl);
    }
    if( bf < -1 && data > avl->right->data ) {
        // right-right, need left rotation
        return Left_Rotation(avl);
    }
    if( bf < -1 && data < avl->right->data ) {
        // right-left, need r-l rotation
        return Right_Left_Rotation(avl);
    }

    // 平衡则不做处理， 直接返回
    return avl;
}

ptr_avl Del_Node(ptr_avl avl, ElemType data) {
    if( avl == NULL ) {
        return NULL;
    }

    if( data < avl->data ) {
        avl->left = Del_Node(avl->left, data);
    }else if( data > avl->data ) {
        avl->right = Del_Node(avl->right, data);
    }else{
        /* same as val */
        ptr_avl temp = NULL;

        // only left child
        if( avl->right == NULL ) {
            temp = avl->left;
            free(avl);
            return temp;
        }else if( avl->left == NULL ) {
            temp = avl->right;
            free(avl);
            return temp;
        }else{
            temp = Get_Min_Node(avl->right);
            avl->data = temp->data;
            avl->right = Del_Node(avl->right, temp->data);
        }
        return avl;
    }

    if( avl == NULL )
        return avl;

    // Updating height
    Set_Height(avl);

    // get balanced factor
    int bf = Get_BF(avl);
    // 不平衡？ 平衡下再平衡
    if( bf > 1 && Get_BF(avl->left) >= 0 ) {
        // left-left, need right-rotation
        return  Right_Rotation(avl);
    }
    if( bf > 1 && Get_BF(avl->left) < 0 ) {
        // left-right, need left-right-rotation
        return Left_Right_Rotation(avl);
    }
    if( bf < -1 && Get_BF(avl->right) <=0 ) {
        // right-right. need left-rotation
        return Left_Rotation(avl);
    }
    if( bf < -1 && Get_BF(avl->right) > 0 ) {
        // right-left, need right-left rotation
        return Right_Left_Rotation(avl);
    }

    // 删除之后依旧平衡，不做处理，直接返回
    return avl;
}

void In_Traversal(ptr_avl avl) {
    if( avl != NULL ) {
        In_Traversal(avl->left);
        printf("node val:%d -> Height:%d -> BF:%d\n", avl->data, Get_Height(avl), Get_BF(avl));
        In_Traversal(avl->right);
    }
}
