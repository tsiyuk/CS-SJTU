#include "seqList.h"

template<class elemType>
seqList<elemType>::seqList(int iniSize)
{
    data=new elemType[iniSize];
    maxSize=iniSize;
    currentLength=0;
}
template<class elemType>
seqList<elemType>::~seqList()
{
    delete []data;
}
template<class elemType>
void seqList<elemType>::clear()
{
    currentLength=0;
}
template<class elemType>
int seqList<elemType>::length()const
{
    return currentLength;
}
template<class elemType>
void seqList<elemType>::doubleSpace()//扩大空间
{
    elemType*tmp=data;
    maxSize*=2;
    data=new elemType[maxSize];
    for(int i=0;i<currentLength;++i)
        data[i]=tmp[i];
    delete []tmp;
}
template<class elemType>
void seqList<elemType>::insert(int i,const elemType &x)//插入函数
{
    if(currentLength==maxSize)doubleSpace();
    for(int j=currentLength;j>i;j--)
        data[j]=data[j-1];
    data[i]=x;
    ++currentLength;
}
template<class elemType>
void seqList<elemType>::remove(int i)//删除函数
{
    for(int j=i;j<currentLength;j++)
        data[j]=data[j+1];
    --currentLength;
}
template<class elemType>
seqList<elemType> operator+(const seqList<elemType> &s1,const seqList<elemType> &s2)//重载加号运算符
{
    seqList<elemType> tmp;
    tmp.currentLength=s1.currentLength+s2.currentLength;
    tmp.maxSize=s1.maxSize+s2.maxSize;
    tmp.data=new elemType[tmp.currentLength];
    for(int i=0;i<s1.currentLength;i++)
        tmp.data[i]=s1.data[i];
    for(int j=0;j<s2.currentLength;j++)
        tmp.data[j+s1.currentLength]=s2.data[j];
    return tmp;
}
template<class elemType>
seqList<elemType>&seqList<elemType>::operator=(const seqList<elemType> &right)//重载赋值运算符
{
    if(this==&right)
        delete []data;//若两者相同则删除空间
    currentLength=right.currentLength;
    maxSize=right.maxSize;
    data=new elemType[currentLength];
    for(int i=0;i<currentLength;i++)
        data[i]=right.data[i];
    return *this;
}
template<class elemType>
seqList<elemType>::seqList(const seqList<elemType> &obj)//复制构造函数
{
    currentLength=obj.currentLength;
    maxSize=obj.maxSize;
    data=new elemType[currentLength];
    for(int i=0;i<currentLength;i++)
        data[i]=obj.data[i];
}
