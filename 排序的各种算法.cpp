//
//  main.cpp
//  Sort
//
//  Created by 唧唧歪歪 on 15/4/20.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//
#include<iostream>
#include<vector>
using namespace std;
void Insert_Sort(vector<int> &vec);//插入排序；
void Merge_Sort(vector<int> &vec,int start,int end);//归并排序；
void Merge(vector<int> &vec,int start,int mid,int end);//递归调用中间函数；
void Bubble_Sort(vector<int> & vec);//冒泡排序；
void Quick_Sort(vector<int> &vec,int start,int end);//快速排序；
int Parition(vector<int> &vec,int start,int end);//递归调用中间函数；
void Heap_Sort(vector<int> &vec);//堆排序；
void Build_Max_Heap(vector<int> &vec,int length);//建最大堆；
void Heap_Heapify(vector<int> &vec,int target,int length);//调整为最大堆；

//插入排序；
void Insert_Sort(vector<int> &vec)
{
    int i,j;//临时变量；
    int key;//当前关键字；
    
    for(i=1;i<vec.size();i++)
    {
        key=vec[i];
        j=i-1;
        while(j>=0&&vec[j+1]<vec[j])
        {
            vec[j+1]=vec[j];
            vec[j]=key;
            j--;
        }
    }
}

//归并排序；
void Merge_Sort(vector<int> &vec,int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        Merge_Sort(vec,start,mid);
        Merge_Sort(vec,mid+1,end);
        Merge(vec,start,mid,end);
    }
}
//递归调用中间排序函数；
void Merge(vector<int> &vec,int start,int mid,int end)
{
    vector<int> v1,v2;//表示两个中间数组；
    int i;
    for(i=start;i<=mid;i++)
    {
        v1.push_back(vec[i]);
    }
    v1.push_back(9999999);
    
    for(i=mid+1;i<=end;i++)
    {
        v2.push_back(vec[i]);
    }
    v2.push_back(9999999);
    
    int m=0,n=0;//临时变量；
    for(i=start;i<=end;i++)
    {
        if(v1[m]>v2[n])
        {
            vec[i]=v2[n];
            n++;
        }
        else
        {
            vec[i]=v1[m];
            m++;
        }
    }
}

//冒泡排序；
void Bubble_Sort(vector<int> &vec)
{
    int i,j;//临时变量；
    int key;//关键字；
    
    for(i=0;i<vec.size()-1;i++)//循环次数；
    {
        for(j=0;j<vec.size()-i-1;j++)
        {
            key=vec[j];
            if(key>vec[j+1])
            {
                vec[j]=vec[j+1];
                vec[j+1]=key;
            }
        }
    }
}

//快速排序；
void Quick_Sort(vector<int> &vec,int start,int end)
{
    if(start<end)
    {
        int part=Parition(vec,start,end);
        Quick_Sort(vec,start,part-1);
        Quick_Sort(vec,part+1,end);
    }
}
//递归调用函数；
int Parition(vector<int> &vec,int start,int end)
{
    int i,p;//表示划分数组的分隔符号；
    int key=vec[end];//表示关键字；
    i=start;//设置分割线的下标值；
    int temp;//临时变量；
    for(p=start;p<end;p++)
    {
        //确定划分线j的位置；
        if(vec[p]<=key)
        {
            //交换位置；
            temp=vec[i];
            vec[i]=vec[p];
            vec[p]=temp;
            i++;
        }
    }
    temp=vec[i];
    vec[i]=vec[end];
    vec[end]=temp;
    
    return i;
}

//堆排序；
void Heap_Sort(vector<int> &vec)
{
    int size=(int)vec.size();//数组大小；
    int heap_length=(int)vec.size();//堆大小；
    Build_Max_Heap(vec,heap_length);
    
    int i;//临时变量；
    int temp;//表示临时变量；
    for(i=0;i<size-1;i++)
    {
        heap_length--;
        temp=vec[1];
        vec[1]=vec[heap_length];
        vec[heap_length]=temp;
        Build_Max_Heap(vec,heap_length);
    }
}
//建最大堆；
void Build_Max_Heap(vector<int> &vec,int length)
{
    int i;//临时变量；
    for(i=length/2;i>=1;i--)
    {
        Heap_Heapify(vec,i,length);//建立最大堆；
    }
}
//调整为最大堆；
void Heap_Heapify(vector<int> &vec,int target,int length)
{
    int i=target;
    int largest;
    int temp;
    if((i*2+1)<length&&vec[i*2+1]>vec[i])
    {
        largest=i*2+1;
    }
    else
    {
        largest=i;
    }
    if(i*2<length&&vec[i*2]>vec[largest])
    {
        largest=i*2;
    }
    if(largest!=i)
    {
        temp=vec[largest];
        vec[largest]=vec[i];
        vec[i]=temp;
        Heap_Heapify(vec,largest,length);
    }
}

int main()
{
    vector<int> vec;
    int num,temp,i;
    cin>>num;
    for(i=0;i<num;i++)
    {
        cin>>temp;
        vec.push_back(temp);
    }
    int sort_num;//表示排序；
    cin>>sort_num;
    switch(sort_num)
    {
        case 0:
        {
            Insert_Sort(vec);
        };break;
        case 1:
        {
            Merge_Sort(vec,0,(int)vec.size()-1);
        };break;
        case 2:
        {
            Bubble_Sort(vec);
        };break;
        case 3:
        {
            Quick_Sort(vec,0,(int)vec.size()-1);
        };break;
    }
    for(i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    vector<int> vec1;
    cin>>num;
    vec1.push_back(num);
    for(i=0;i<num;i++)
    {
        cin>>temp;
        vec1.push_back(temp);
    }
    Heap_Sort(vec1);
    
    for(i=1;i<vec1.size();i++)
    {
        cout<<vec1[i]<<" ";
    }
    cout<<endl;
}
