#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
static int point = 0;
///���ڼ�������Ƿ��������
struct PCB{
int pid;
int priority;
int time;
PCB next;
};
void tailCreate(PCB L){
srand((unsigned int)time(0));
///��ʱ��Ϊ��������ӣ���֤ÿ���������һ��
int priority = rand() % 5;///���������
PCB s, r = L;
for (int i = 0; i<5; i++)
{				///���ʱ��Ϊ1��50
int number = rand() % 5;
while (number == 0)
///�����0��һֱ�����ֱ�����ֲ���0��Ϊֹ
number = rand() % 5;
///tail_insert��β�巨��ʼ��
s = new PCB;
s->pid = i + 1;
s->priority = (i + priority) % 5 + 1;
s->time = number;
if (s->priority != 5 || r->next == NULL)
///���r->next==NULL��ʾΪ����ֻ��һ��ͷ��㣬��ֱ�Ӳ���
{
r->next = s;
r = s;
}
if ((s->priority == 5) && (r->next != NULL))
///������в�Ϊ�գ��ͽ�������ͷ������
{
s->next = L->next;
L->next = s;
}
}
r->next = NULL;}
void run(PCB L)///����
{
PCB c = L;	PCB p = L;
for (L; L; L = L->next)
{
if (L->next == NULL)
break;
///���ڴ��ڴ���ͷ��㣬���Դ�L->next��ʼ
L->next->priority = L->next->priority - 1;
L->next->time = L->next->time - 1;
if (L->next->time == 0){
///�������ʱ��Ϊ0���ͽ����Ƴ�������		{
cout << ��run over�� <<"->PID->"<< L->next->pid << endl;
L->next->time = -1;
L->next = L->next->next;
///���ڳ�����L->next = L->next->next;�ⲽ��
///����ִ��forѭ���ĵ��������ʽ����������L->next->next�����㣬����ִ��L->next->next->next������
///������Ҫ�ж�һ��L->next->next������
if (L->next != NULL&&L->next->time != 0)
{
L->next->priority = L->next->priority - 1;
L->next->time = L->next->time - 1;
}
///���L->next->next->time��ֵ����0,��Ὣ���Ƴ����У�����ִ��L->next=L->next->next�ⲽ
///������Ҫwhileѭ�����ж�
while (L->next != NULL&&L->next->time == 0)
{
cout << ��run over�� <<"->PID->"<< L->next->pid << endl;
L->next->time = -1;
L->next = L->next->next;
point = point + 1;
if (L->next != NULL)
{
L->next->priority = L->next->priority - 1;
L->next->time = L->next->time - 1;
}
}
point = point + 1;
}
if (L->next != NULL&&L->next->priority == 0)
///���������Ϊ0�ͽ������0���ڶ���
{			//
PCB q = L->next;
L->next = L->next->next;
q->priority = 5;
q->next = c->next;
c->next = q;
///����ִ����L->next=L->next->next
///�����ֻ�ִ�������ǲ�ͬ���ز���
if (L->next != NULL&&L->next->time != 0)
{
L->next->priority = L->next->priority - 1;
L->next->time = L->next->time - 1;
}
while (L->next != NULL&&L->next->time == 0)
{
cout << ��run over�� << ��->PID->��<next->pid << endl;
L->next->time = -1;
L->next = L->next->next;
point = point + 1;
if (L->next != NULL)
{
L->next->priority = L->next->priority - 1;
L->next->time = L->next->time - 1;
}
}
}
}
L = p;
}
int main(){	PCB L, m;	L = new PCB;
//��ʼ��ͷ���
L->next = NULL;	tailCreate(L);
m = L;
L = L->next;
cout << ��=" << endl;
cout << ��Init�� << endl;
cout << "==�� << endl;
for (L; L; L = L->next)
{		cout <<��PID :��<< L->pid << endl;
cout << ��Time :��<time << endl;
cout << ��Priority :��<priority << endl;
cout << " " << endl;
cout << endl;	}
cout << "============= " << endl;
cout << ��Init successful!�� << endl;
cout << ��==============�� << endl;
cout << endl;
cout << ��run order!�� << endl;
while (point != 5)
{
run(m);
}
system(��pause��);
return 0; }
��������������������������������
��Ȩ����������ΪCSDN������С椦���ɺ����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/weixin_43233174/article/details/105233103#include 
#include <time.h>
#include <stdlib.h>
using namespace std;
static int point = 0;
///���ڼ�������Ƿ��������
struct PCB{
int pid;
int priority;
int time;
PCB next;
};
void tailCreate(PCB L){
srand((unsigned int)time(0));
///��ʱ��Ϊ��������ӣ���֤ÿ���������һ��
int priority = rand() % 5;///���������
PCB s, r = L;
for (int i = 0; i<5; i++)
{				///���ʱ��Ϊ1��50
int number = rand() % 5;
while (number == 0)
///�����0��һֱ�����ֱ�����ֲ���0��Ϊֹ
number = rand() % 5;
///tail_insert��β�巨��ʼ��
s = new PCB;
s->pid = i + 1;
s->priority = (i + priority) % 5 + 1;
s->time = number;
if (s->priority != 5 || r->next == NULL)
///���r->next==NULL��ʾΪ����ֻ��һ��ͷ��㣬��ֱ�Ӳ���
{
r->next = s;
r = s;
}
if ((s->priority == 5) && (r->next != NULL))
///������в�Ϊ�գ��ͽ�������ͷ������
{
s->next = L->next;
L->next = s;
}
}
r->next = NULL;}
void run(PCB L)///����
{
PCB c = L;	PCB p = L;
for (L; L; L = L->next)
{
if (L->next == NULL)
break;
///���ڴ��ڴ���ͷ��㣬���Դ�L->next��ʼ
L->next->priority = L->next->priority - 1;
L->next->time = L->next->time - 1;
if (L->next->time == 0){
///�������ʱ��Ϊ0���ͽ����Ƴ�������		{
cout << ��run over�� <<"->PID->"<< L->next->pid << endl;
L->next->time = -1;
L->next = L->next->next;
///���ڳ�����L->next = L->next->next;�ⲽ��
///����ִ��forѭ���ĵ��������ʽ����������L->next->next�����㣬����ִ��L->next->next->next������
///������Ҫ�ж�һ��L->next->next������
if (L->next != NULL&&L->next->time != 0)
{
L->next->priority = L->next->priority - 1;
L->next->time = L->next->time - 1;
}
///���L->next->next->time��ֵ����0,��Ὣ���Ƴ����У�����ִ��L->next=L->next->next�ⲽ
///������Ҫwhileѭ�����ж�
while (L->next != NULL&&L->next->time == 0)
{
cout << ��run over�� <<"->PID->"<< L->next->pid << endl;
L->next->time = -1;
L->next = L->next->next;
point = point + 1;
if (L->next != NULL)
{
L->next->priority = L->next->priority - 1;
L->next->time = L->next->time - 1;
}
}
point = point + 1;
}
if (L->next != NULL&&L->next->priority == 0)
///���������Ϊ0�ͽ������0���ڶ���
{			//
PCB q = L->next;
L->next = L->next->next;
q->priority = 5;
q->next = c->next;
c->next = q;
///����ִ����L->next=L->next->next
///�����ֻ�ִ�������ǲ�ͬ���ز���
if (L->next != NULL&&L->next->time != 0)
{
L->next->priority = L->next->priority - 1;
L->next->time = L->next->time - 1;
}
while (L->next != NULL&&L->next->time == 0)
{
cout << ��run over�� << ��->PID->��<next->pid << endl;
L->next->time = -1;
L->next = L->next->next;
point = point + 1;
if (L->next != NULL)
{
L->next->priority = L->next->priority - 1;
L->next->time = L->next->time - 1;
}
}
}
}
L = p;
}
int main(){	PCB L, m;	L = new PCB;
//��ʼ��ͷ���
L->next = NULL;	tailCreate(L);
m = L;
L = L->next;
cout << ��=" << endl;
cout << ��Init�� << endl;
cout << "==�� << endl;
for (L; L; L = L->next)
{		cout <<��PID :��<< L->pid << endl;
cout << ��Time :��<time << endl;
cout << ��Priority :��<priority << endl;
cout << " " << endl;
cout << endl;	}
cout << "============= " << endl;
cout << ��Init successful!�� << endl;
cout << ��==============�� << endl;
cout << endl;
cout << ��run order!�� << endl;
while (point != 5)
{
run(m);
}
system(��pause��);
return 0; }

