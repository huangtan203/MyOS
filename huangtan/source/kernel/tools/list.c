#include"tools/list.h"
void list_init(list_t *list){
    list->last = (list_node_t*)0;
    list->first = (list_node_t*)0;
    list->count = 0;
}
/*
typedef struct _list_t{
    list_node_t *first;
    list_node_t *last;
    int count;
}list_t;
*/
void list_insert_first(list_t *list, list_node_t *node){
    node->next=list->first;
    node->prev=(list_node_t*)0;
    if(list_is_empty(list)){
        list->last=node;
        list->first=node;
    }else{
        list->first->prev=node;
        list->first=node;   
    }
    list->count++;
}

void list_insert_last(list_t *list, list_node_t *node){
    node->next=(list_node_t*)0;
    node->prev=list->last;
    if(list_is_empty(list)){
        list->last=node;
        list->first=node;
    }else{
        list->last->next=node;
        list->last=node;
    }
    list->count++;
}
list_node_t* list_remove_first(list_t *list){
    if(list_is_empty(list) ) return (list_node_t*)0;
    list_node_t*remove_node=list->first;
    list_node_t*next=list->first->next;
    if(next==(list_node_t*)0){
        list->last=(list_node_t*)0;
        list->first=(list_node_t*)0;
        list->count=0;
    }else{
        next->prev=(list_node_t*)0;
        list->first=next;
    }
    remove_node->next=(list_node_t*)0;
    remove_node->prev=(list_node_t*)0;
    list->count--;
    return remove_node;
}
list_node_t* list_remove(list_t *list,list_node_t* remove_node){
    if(list_is_empty(list) ) return (list_node_t*)0;
    list_node_t*next=remove_node->next;
    list_node_t*prev=remove_node->prev;
    if(next==(list_node_t*)0&&prev==(list_node_t*)0){
        list->last=(list_node_t*)0;
        list->first=(list_node_t*)0;
        list->count=0;
    }
    else if(next==(list_node_t*)0){
        list->last=prev;
        prev->next=(list_node_t*)0;
        list->count--;
    }else if(prev==(list_node_t*)0){
        list->first=next;
        next->prev=(list_node_t*)0;
        list->count--;
    }else{
        next->prev=prev;
        prev->next=next;
        list->count--;
    }
    remove_node->next=(list_node_t*)0;
    remove_node->prev=(list_node_t*)0;
    return remove_node;
}