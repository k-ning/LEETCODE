//
//  main.cpp
//  SingleLinkedList
//
//  Created by 唧唧歪歪 on 15/4/21.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct LinkListNode
{
    int value;//单链表的值；
    LinkListNode * next;//单链表的节点；
};
LinkListNode * MakeList(vector<int> v);//建立单链表；
void ShowLinkList(LinkListNode * head);//单链表中数据的扫描；
LinkListNode * Insert(LinkListNode * & head,int pos,int value);//向单链表中插入数据；
LinkListNode * Delete(LinkListNode * & head,int pos);//删除单链表中的数据；
int Find(LinkListNode * head,int value);//查找链表中的value元素；
int Length(LinkListNode * head);//返回链表的长度；
//创建链表；
LinkListNode * MakeList(vector<int> v)
{
    int i;//临时变量；
    LinkListNode * head;
    LinkListNode * node=new LinkListNode();
    node->value=v[0];
    node->next=NULL;
    head=node;
    
    LinkListNode * temp=node;
    for(i=1;i<v.size();i++)
    {
        LinkListNode * l1=new LinkListNode();
        l1->value=v[i];
        l1->next=NULL;
        temp->next=l1;
        temp=temp->next;
    }
    return head;
}

//打印链表；
void ShowLinkList(LinkListNode * head)
{
    LinkListNode * l1=head;
    while(l1!=NULL)
    {
        cout<<l1->value;
        if(l1->next!=NULL)
        {
            cout<<"->";
        }
        l1=l1->next;
    }
    cout<<endl;
}
//向链表中插入元素；
LinkListNode * Insert(LinkListNode * & head,int pos,int value)
{
    LinkListNode * node=new LinkListNode();
    node->value=value;
    node->next=NULL;
    
    LinkListNode * temp;//表示临时链表；
    LinkListNode * tt=head;
    temp=head;
    if(temp==NULL)
    {
        cout<<"链表为空,插入不成功!"<<endl;
        return head;
    }
    int i=1;
    while(temp!=NULL&&i<pos)
    {
        tt=temp;
        temp=temp->next;
        i++;
    }
    if(temp==NULL)
    {
        if(i==pos)
        {
            tt->next=node;
        }
        else
        {
            cout<<"插入数据的位置比链表的容积大,插入失败!"<<endl;
        }
    }
    else
    {
        if(tt==head)
        {
            node->next=head;
            head=node;
        }
        else
        {
            node->next=temp;
            tt->next=node;
        }
    }
    return head;
}
//删除链表中的元素；
LinkListNode * Delete(LinkListNode * & head,int pos)
{
    LinkListNode * node=head;
    LinkListNode * temp=head;
    int i=1;
    if(node==NULL)
    {
        cout<<"链表中没有元素"<<endl;
        return head;
    }
    
    while(node!=NULL&&i<pos)
    {
        temp=node;
        node=node->next;
        i++;
    }
    if(node==NULL)
    {
        if(i==pos)
        {
            temp->next=NULL;
        }
        else
        {
            cout<<"链表的长度比需要删除的数据下标小,无法删除!"<<endl;
        }
    }
    else
    {
        if(temp==head)
        {
            head=temp->next;
        }
        else
        {
            temp->next=node->next;
        }
    }
    return head;
}
//单链表中元素的查找,返回元素的位置下标；
int Find(LinkListNode * head,int value)
{
    LinkListNode * temp=head;
    if(temp==NULL)
    {
        cout<<"单链表为空,没有需要的数据!"<<endl;
        return -1;
    }
    int i=1;
    while(temp!=NULL)
    {
        i++;
        if(temp->value!=value)
        {
            temp=temp->next;
        }
        else
        {
            break;
        }
    }
    if(temp==NULL)
    {
        cout<<"当前没有需要查找的数据,查找失败!"<<endl;
        return -1;
    }
    else
    {
        return i=i-1;
    }
}
int Length(LinkListNode * head)
{
    int size=0;
    LinkListNode * node=head;
    while(node!=0)
    {
        size++;
        node=node->next;
    }
    return size;
}
//主函数；
int main()
{
    //添加元素；
    vector<int> v;
    int size;
    cin>>size;
    int i;
    int temp;
    for(i=0;i<size;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    //创建链表；
    LinkListNode * head=MakeList(v);
    //打印链表；
    ShowLinkList(head);
    cout<<"请输入向链表中插入的值:"<<endl;
    int value;
    cin>>value;
    cout<<"请输入向链表中插入数据的位置:"<<endl;
    int pos;
    cin>>pos;
    //向链表中插入元素；
    Insert(head,pos,value);
    //打印链表；
    ShowLinkList(head);
    cout<<"请输入删除链表中元素的位置:"<<endl;
    cin>>pos;
    Delete(head,pos);
    ShowLinkList(head);
    cout<<"请输入需要查找的元素值:"<<endl;
    cin>>value;
    pos=Find(head,value);
    if(pos!=-1)
    {
        cout<<value<<"元素的位置为:"<<pos<<endl;
    }
    cout<<"链表的大小为:"<<Length(head)<<endl;
}
