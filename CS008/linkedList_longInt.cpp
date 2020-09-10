/*
使用链表存储长整型数
实现两个长整型数的遍历输出，大小比较，加法以及减法（只允许大数减小数）
*/

#include <iostream>
using namespace std;

//储存数据的节点
struct node
{
    int data;
    node *next;

    node():data(-1),next(nullptr){}
    node(int n, node* p = nullptr):data(n), next(p){}
};

//传入头指针,将单链表反转
void reverse(node *head)
{
    node* cur = head->next->next;
    node* cur_next; 
    head->next->next = nullptr;
    while(cur != nullptr){
        cur_next = cur->next;
        cur->next = head->next;
        head->next = cur;
        cur = cur_next;
    }
}

//传入两个头指针，将两个数相加，结果存储于一个新的单链表,返回单链表的头指针
node* add(node* num1, node* num2)
{
    reverse(num1);
    reverse(num2);//倒置两个链表
    node* p = num1->next, *q = num2->next;
    node* head = new node(-1);
    int sum = 0;
    bool flag = 0;//是否进位的标志
    node *cur = head;
    while(p != nullptr||q != nullptr){
        sum = 0;
        if(p != nullptr){
            sum += p->data;
            p = p->next;
        }
        if(q != nullptr){
            sum += q->data;
            q = q->next;
        }
        if(flag) sum++;
        cur->next = new node(sum%10);
        cur = cur->next;
        flag = (sum>=10)?1:0;//判断是否进位
    }
    if(flag) cur->next = new node(1);//多进一位

    reverse(num1);
    reverse(num2);//将原本的链表恢复为正序
    reverse(head);
    return head;
} 

//获取单链表的长度
int get_length(node* head)
{
    int l = 0;
    if(head->next == nullptr)
        return 0;
    node* p = head->next;
    while(p!=nullptr){
        ++l;
        p = p->next;
    }
    return l;
}

//当num1大于等于num2时，返回true，否则返回false
bool greaterEqual(node *num1, node *num2)
{
    int length1 = get_length(num1), length2 = get_length(num2);
    if(length1 == length2){
        node* p =num1->next, *q = num2->next;
        while(p->next != nullptr&& (p->data == q->data)){
            p = p->next;
            q = q->next;
        }
        if(p->data < q->data) return false;
        else return true;
    }
    else{
        if(length1 > length2) return true;
        else return false;
    }
}

//遍历该单链表
void traverse(node* head)
{
    node *p = head->next;
    while(p != nullptr){
        cout<<p->data;
        p = p->next;
    }
}

//删除该节点的下一个节点
void del(node* p)
{
    node* d = p->next;
    p->next = d->next;
    delete d;
}

//创建一个单链表
void create(node* head)
{
    char ch[257];
    node* p =head;
    cin.getline(ch, 256);
    for(int i = 0;ch[i] != '\0';i++){
        p->next = new node(ch[i]-'0');
        p->next->next = nullptr;
        p = p->next;
    }
}

//将num1和num2中的正整数相减，结果作为返回值，存放于动态数组中。
//调用函数时，必须保证num1大于num2
node* sub(node *num1, node * num2)
{
    if(!greaterEqual(num1, num2)){
        cout<<"num1 is smaller than num2.";
        return nullptr;
    }
    reverse(num1);
    reverse(num2);//倒置两个链表
    node* p = num1->next, *q = num2->next;
    node* head = new node(-1);
    int sub = 0;
    bool flag = 0;//是否退位的标志
    node *cur = head;
    while(p != nullptr){
        sub = 0;
        sub += p->data;
        p = p->next;
        if(q != nullptr){
            sub -= q->data;
            q = q->next;
        }
        if(flag) sub--;
        if(sub >= 0){
        cur->next = new node(sub);
        flag = 0;
        }
        else{
            cur->next = new node(sub+10);
            flag = 1;
        }
        cur = cur->next;
    }
    reverse(num1);
    reverse(num2);//将原本的链表恢复为正序
    reverse(head);
    while(head->next->data == 0&&head->next->next != nullptr){
        del(head);//删除该节点的下一个节点
    }

    return head;
    
}

int main()
{
    node* num1 = new node;
    node* num2 = new node;
    cout<<"please input num1."<<endl;
    create(num1);
    cout<<"please input num2."<<endl;
    create(num2);
    node* num3;
    num3 = add(num1, num2);
    traverse(num1);
    cout<<" + ";
    traverse(num2);
    cout<<" = ";
    traverse(num3);
    cout<<endl;
    traverse(num1);
    cout<<" >= ";
    traverse(num2);
    greaterEqual(num1, num2)?(cout<<" True"):(cout<<" False");
    cout<<endl;
    node* num4;
    num4 = sub(num2, num1);
    traverse(num2);
    cout<<" - ";
    traverse(num1);
    cout<<" = ";
    traverse(num4);

    return 0;
}
