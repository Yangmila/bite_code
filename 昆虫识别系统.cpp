#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
#include<algorithm> 
#include<vector>

using namespace std;
//��¼���ݿ����������
string insect[] = { "�л����", "��Ӭ", "�л�����", "��Բ�δ���", "ţ�", "��Ӭ", "��������", "���Ƿɻ�" };

//��¼���ݿ���������
string feature[] = { 
"���п�", "β������", "�аߵ�", "�´��ƺ�ɫ", "��ƺ�ɫ", "���غ�", "������ɫ", "��ɫ����", "�ƶ��", "������ɫ",//������������
//0      1       2      3       4       5           6          7         8        9

"ֻ��һ�Գ��", "ǰ������", "���Ĥ��͸��", "����", "��׳", "ͷ��������", "����", "����ʽ����",//����Ŀ������
//  10           11         12      13      14          15          16          17

"˫��Ŀ", "ֱ��Ŀ", "����Ŀ", "���", "����", "Ӭ��", //����Ŀ��
//  18          19          20         21         22         23  

"�л����", "��Ӭ", "�л�����", "��Բ�δ���", "ţ�", "��Ӭ", "��������", "���Ƿɻ�" };//�������
//24      25       26        27       28      29      30     31

//��Ź���Ľṹ�� 
typedef struct 
{  
	int relation[7];   //��ϵ 
	int name;		   //������  
}Rule;// ��ſ��ܵ����� 

typedef struct
{
	int insect;         // name 
	double confidence; //���Ŷ� = ����������� / ����������;
	int site;          // ��rule�е�λ��
	int num;           // ����������� 
	int size;          // ��animal�������������� 
}Result;

vector<Result> result;
//�����
//�������ʱ�������-1����������� 
Rule rule[15] = 
{
{ { 10, -1 }, 18 },
// R1��ֻ��һ�Գ���˫��Ŀ��
{ { 11, -1 }, 19 },
// R2��ǰ��������ֱ��Ŀ��
{ { 12, 13, -1 }, 20 },
// R3�����Ĥ��͸��&���������Ŀ��
{ { 18, 14, -1 }, 21 },
// R4��˫��Ŀ&��׳����ࣻ
{ { 18, 15, -1 }, 22 },
// R5��˫��Ŀ&ͷ�������Ρ�Ӭ�ࣻ
{ { 18, 16, -1 }, 22 },
// R6��˫��Ŀ&���ۡ�Ӭ�ࣻ
{ { 18, 17, -1 }, 23 },
// R7��˫��Ŀ&����ʽ���������ࣻ
{ { 18, 21, 0, -1 }, 24 },
// R8��˫��Ŀ&���&���п���л���򵣻
{ { 18, 1, 5, 8, -1 }, 25 },
// R9��˫��Ŀ&β������&���غ�&�ƶ�����Ӭ��
{ { 18, 2, -1, 0}, 26 },
// R10��˫��Ŀ&����&�аߵ�&���п���л����ã�
{ { 20, 1, 3, -1 }, 27 },
// R11������Ŀ&β������&�´��ƺ�ɫ����Բ�δ��ѣ�
{ { 18, 21, 4, 5, 8, -1 }, 28 },
// R12:˫��Ŀ&���&��ƺ�ɫ&���غ�&�ƶ���ţ򵣻
{ { 18, 22, 9, 8, 5, -1 }, 29 },
// R13��˫��Ŀ&Ӭ��&����ɫ&���غ�&�ƶ�����Ӭ��
{ { 20, 1, 5, 6, -1 }, 30 },
// R14������Ŀ&β������&���غ�&������ɫ���������ѣ�
{ { 19, 4, 7, 8, -1 }, 31 } 
// R15��ֱ��Ŀ&��ƺ�ɫ&��ɫ����&�ƶ������Ƿɻ�
};

int flag[23] = { 0 };  //��Ǹ��������Ƿ�ѡ��
int IsInsect(int a);
int change_speices();  //�����������������Ĺ������ 
int fnum();            //��ȡflag��ǵ���Ŀ 
int z_inference();     //�������� 
int category();        //���������� 
void cal_confi();      //�������Ŷ� 
void r_inference();    //�������� 
void input();          //���� 
void menu();           //�˵� 

//�ж����Ŷȴ�С
bool Compare(const Result& a, const Result& b)
{
	return a.confidence > b.confidence;
}

//���򲢷���������
void Rsort(vector<Result>& r)
{
	//��������������������
	sort(r.begin(), r.end(), Compare);
	return;
}

//ѡ�������˵� 
void menu()
{
	//���֪ʶ��������������������ĳ�Ա��ÿ���4������
	for (int i = 0; i < sizeof(feature) / sizeof(feature[0]) - sizeof(insect) / sizeof(insect[0]); i++)
	{
		if (i % 4 == 0 && i != 0)
		{
			cout << endl;
		}
		cout << setiosflags(ios::left) << setw(2) << i << ".";
		cout << setiosflags(ios::left) << setw(15) << feature[i];
	}
	memset(flag, 0, sizeof(flag));//��ʼ���������Ϊ0
}

//��������ֵѡ������ 
void input()
{
	for (int i = 0; i < sizeof(feature) / sizeof(feature[0]) - sizeof(insect) / sizeof(insect[0]); i++)
	{
		flag[i] = 0;
	 }
	cout << endl; 
	int  key = 0;
	cout << "*****************************************************************************"<<endl;
	cout << "��������ѡ����������������ɺ�������-1.����";
	while (key != -1)//������-1ʱֹͣ��������
	{ 
		cin >> key;
		if (key >= 0 && key <= 23)
		{
			flag[key] = 1;
		}
		else if (key != -1)
		{
			cout << "�������������һ��������" << endl;
			cin.clear();		//��������������
			cin.sync(); 		//������뻺����
			cout << "��������룺";
		}
	}
}

//��ĳ���������ĳ������ 
int IsInsect(int a)
{
	if (a >= sizeof(feature) / sizeof(feature[0]) - sizeof(insect) / sizeof(insect[0]) && a <= sizeof(feature) / sizeof(feature[0]))
	{
		return 1;
	}
	return 0;
}

//�ж��Ƿ�ĳһ������ 
int IsPlant_speices(int a)
{
	if (a >= 18 && a <= 23)
	{
		return 1;
	}
	return 0;
}

//����flag�����б�ǵ����� 
int fnum()
{
	int fum = 0;
	for (int i = 0; i < 24; i++)
	if (flag[i] == 1)
	{
		fum++;
	}
	return fum;
}

//�����ӡ�������
int category()
{
	bool k;
	int count = 0;
	for (int i = 18; i < 24; i++)
	{
		k = false;
		if (flag[i] == 1)
		{
			k = true;
			count++;
			if (count == 1)
			{
				cout << "�޷�ʶ������! ������Ϊ��";
			}
			cout << setiosflags(ios::left) << setw(10) << feature[i];
		}
	}
	cout << endl;
	if (!k)
	{
		cout << "ϵͳ�޸�����" << endl;
	}
	return 1;
}

//�ı�����ֵ���仯flag�������Ƿ����������࣬�����õ�����ʵ��գ���flagΪ0
int change_speices()
{
	int i, j, key;
	bool t;
	int temp[23] = { 0 }; //��ʱ�洢�������޸�
	int f[23] = { 0 }; // ���ʹ�ù���flag 
	for (i = 0; i < 7; i++)
	{ 
		//ǰ7������
		t = true;
		j = 0;
		key = rule[i].relation[j];
		while (key != -1)//����������ϵ
		{
			if (flag[key] == 1)
			{
				temp[key] = 1;
			}
			else 
			{
				memset(temp, 0, sizeof(temp));
				t = false;
				break;
			}
			j++;
			key = rule[i].relation[j];
		}
		if (t)
		{
			for (int k = 0; k <= 17; k++)
			{
				if (temp[k] == 1)
				{
					f[k] = 1;
				}
			}
			flag[rule[i].name] = 1;
		}
		memset(temp, 0, sizeof(temp));
	}
	//ɾ�����������ʵ��������� 
	for (i = 0; i <= 17; i++)
	{
		if (f[i] == 1)
		{
			flag[i] = 0;
		}
	}
	return 1;
}

//���¼������Ŷ� 
void cal_confi()
{
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 7; j < 15; j++)
		{
			if (result[i].insect == rule[j].name)
			{
				result[i].confidence = 1.0 * result[i].num / result[i].size;
				break;
			}
		}
	}
}

//˫����������������ȥ����ʵ������������������
int z_inference()
{
	int key, num;
	int i, j;
	int fum = fnum();
	cout << endl;
	for (i = 7; i < 15; i++)
	{  
		//�������
		Result temp;
		j = 0; num = 0;
		key = rule[i].relation[j];
		while (key != -1)
		{
			if (flag[key] == 1)
			{
				num++;
			}
			j++;
			key = rule[i].relation[j];
		}
		//��ʱj������rule[i]�����е������� 
		if (num != 0 && fum <= j)
		{  
			//����������С�ڵ��ڵ��������flag�����б��λ��Ŀ���ڴ�������������򲻷���result
			if (IsInsect(rule[i].name))
			{ 
				// �Ǿ�������� 
				temp.insect = rule[i].name;
				int size = j; //rule[i]�����е�������
				temp.size = size;
				temp.confidence = 1.0 * num / size;
				temp.site = i;
				temp.num = num;
				result.push_back(temp);
			}
		}
	}
	if (!result.empty())
	{
		Rsort(result);  //�����ŶȴӸߵ������� 
	}
	//��������� 
	if (result.empty()) 
	{ 
		//�����������޷����κ�һ��������,����û���������棬������һ����� 
		category();
	}
	else if (result.front().confidence == 1.0)
	{ 
		//���ܸ��������պ������������������û����
		cout << "����Ϊ��" << feature[result.front().insect] << endl;
		result.clear();//���
		return 1;
	}
	else//��������ѯ������
	{
		r_inference();
	}
}

//�������㣬���뷴������ 
void r_inference()
{
	vector<Result>::iterator it = result.begin();
	int enquire[23];  
	//�������ѯ�ʹ����������飨0����û�д�������1�����У�2���������	��֪���� 
	memset(enquire, -1, sizeof(enquire));
	for (int i = 0; i< result.size();)
	{
		//�����Ŷ���߿�ʼѯ��
		bool in_i = true; // i ++ �ı�� 
		int  nu = result[i].size;
		for (int j = 0; j < nu; j++)
		{  
			//ѯ������ 
			if (flag[rule[result[i].site].relation[j]] == 0)
			{
				int en = rule[result[i].site].relation[j];
				char c;
				if (enquire[en] == -1)
				{ 
					//������δ��ѯ�ʹ��������ѯ����䣬����ֱ���жϴ��� 
					cout << "�Ƿ�������������" << feature[rule[result[i].site].relation[j]] << endl;
					cout << "Y(y) or N(n) or D(don't know) : ";
					cin >> c;
					while (c != 'Y' && c != 'y' && c != 'N' && c != 'n' && c != 'D' && c != 'd')
					{
						cout << "���ѡ��Y(y) N(n) D(d)!" << endl;
						cin >> c;
					}
				}
				if (enquire[en] == 1 || c == 'Y' || c == 'y')
				{
					//�д�����  �ı����Ŷ�
					result[i].num++;
					enquire[en] = 1;
				}
				else if (enquire[en] == 0 || c == 'N' || c == 'n')
				{ 
					// û�д�����  ֱ��ȥ��
					enquire[en] = 0;
					result.erase(it + i);
					//eraseɾ����i������������ɾ������Ԫ�أ�������ָ��ɾ��֮ǰԪ�غ�ĵ�һ��Ԫ��
					in_i = false; //���������Ԫ�أ���i������ 
					if (result.empty())//resultΪ�գ���������˳� 
					{
						category();
					}
					break;
				}
				else if (enquire[en] == 2 || c == 'D' || c == 'd')
				{
					enquire[en] = 2;  // ��ȷ������֪���������ŶȲ��ı� 
				} 	
			}
		}
		if (in_i)
		{
			++i;
		}
	}

	if (!result.empty())
	{
		// �ı����Ŷ� 
		cal_confi();
		if (result.size() > 1) //��������
		{
			Rsort(result);
		}
		//�ж�ѯ�ʺ����˫������
		if (result.front().confidence == 1.0)
		{
			cout << "�����ǣ�" << feature[result.front().insect] << endl;
		}
		else
		{
			cout << "�������Ϊ�����ŶȴӸߵ��ͣ�:";
			for (vector<Result>::iterator it = result.begin(); it != result.end(); ++it)
			{
				cout << setiosflags(ios::left) << setw(10) << feature[(*it).insect] << " ";
			}
			cout << endl;
		}
		result.clear(); // ��� 
	}
}
int main()
{
	char q;
	cout << "*****************************************************************************"<<endl;
	cout << "*                            ����ʶ��ϵͳ                                   *"<<endl;
	cout << "*****************************************************************************"<<endl;
	cout << "�Ƿ����ϵͳ��Y(y) N(n)"<<endl;
	cin >> q;
	cout << "*****************************************************************************"<<endl;
	while (q != 'N' && q != 'n')
	{
		menu();
		input();
		change_speices();
		z_inference();
		cout << endl << "������(Y/N)" << endl;
		cin >> q;
		system("cls");//���������µĲ���
	}
	return 0;
}

