#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
#include<algorithm> 
#include<vector>

using namespace std;
//记录数据库内昆虫个体
string insect[] = { "中华盗虻", "麻蝇", "中华按蚊", "巨圆臀大蜓", "牛虻", "绿蝇", "乐仙蜻蜓", "东亚飞蝗" };

//记录数据库昆虫特征
string feature[] = { 
"飞行快", "尾部亮黑", "有斑点", "下唇黄褐色", "体黄褐色", "背棕黑", "胸深蓝色", "暗色斑纹", "雌额宽", "体青绿色",//区别个体的特征
//0      1       2      3       4       5           6          7         8        9

"只有一对翅膀", "前翅狭长", "翅膀膜质透明", "翅膀多", "粗壮", "头部半球形", "复眼", "刺吸式口器",//区别目类特征
//  10           11         12      13      14          15          16          17

"双翅目", "直翅目", "蜻蜓目", "虻类", "蚊类", "蝇类", //昆虫目类
//  18          19          20         21         22         23  

"中华盗虻", "麻蝇", "中华按蚊", "巨圆臀大蜓", "牛虻", "绿蝇", "乐仙蜻蜓", "东亚飞蝗" };//昆虫个体
//24      25       26        27       28      29      30     31

//存放规则的结构体 
typedef struct 
{  
	int relation[7];   //关系 
	int name;		   //推理结果  
}Rule;// 存放可能的昆虫 

typedef struct
{
	int insect;         // name 
	double confidence; //置信度 = 满足的特性数 / 所含特征数;
	int site;          // 在rule中的位置
	int num;           // 满足的特征数 
	int size;          // 此animal的所含总特征数 
}Result;

vector<Result> result;
//规则库
//输入规则时最后输入-1则代表规则结束 
Rule rule[15] = 
{
{ { 10, -1 }, 18 },
// R1：只有一对翅膀→双翅目；
{ { 11, -1 }, 19 },
// R2：前翅狭长→直翅目；
{ { 12, 13, -1 }, 20 },
// R3：翅膀膜质透明&翅膀多→蜻蜓目；
{ { 18, 14, -1 }, 21 },
// R4：双翅目&粗壮→虻类；
{ { 18, 15, -1 }, 22 },
// R5：双翅目&头部半球形→蝇类；
{ { 18, 16, -1 }, 22 },
// R6：双翅目&复眼→蝇类；
{ { 18, 17, -1 }, 23 },
// R7：双翅目&刺吸式口器→蚊类；
{ { 18, 21, 0, -1 }, 24 },
// R8：双翅目&虻类&飞行快→中华盗虻；
{ { 18, 1, 5, 8, -1 }, 25 },
// R9：双翅目&尾部亮黑&背棕黑&雌额宽→麻蝇；
{ { 18, 2, -1, 0}, 26 },
// R10：双翅目&蚊类&有斑点&飞行快→中华按蚊；
{ { 20, 1, 3, -1 }, 27 },
// R11：蜻蜓目&尾部亮黑&下唇黄褐色→巨圆臀大蜓；
{ { 18, 21, 4, 5, 8, -1 }, 28 },
// R12:双翅目&虻类&体黄褐色&背棕黑&雌额宽→牛虻；
{ { 18, 22, 9, 8, 5, -1 }, 29 },
// R13：双翅目&蝇类&青绿色&背棕黑&雌额宽→绿蝇；
{ { 20, 1, 5, 6, -1 }, 30 },
// R14：蜻蜓目&尾部亮黑&背棕黑&胸深蓝色→乐仙蜻蜓；
{ { 19, 4, 7, 8, -1 }, 31 } 
// R15：直翅目&体黄褐色&暗色斑纹&雌额宽→东亚飞蝗
};

int flag[23] = { 0 };  //标记各个特征是否选择
int IsInsect(int a);
int change_speices();  //将可以推理出昆虫类的规则进行 
int fnum();            //获取flag标记的数目 
int z_inference();     //正向推理 
int category();        //输出昆虫类别 
void cal_confi();      //计算置信度 
void r_inference();    //反向推理 
void input();          //输入 
void menu();           //菜单 

//判断置信度大小
bool Compare(const Result& a, const Result& b)
{
	return a.confidence > b.confidence;
}

//排序并返回排序结果
void Rsort(vector<Result>& r)
{
	//调用数组容器的排序函数
	sort(r.begin(), r.end(), Compare);
	return;
}

//选择特征菜单 
void menu()
{
	//输出知识库中特征数组除昆虫名的成员，每输出4个换行
	for (int i = 0; i < sizeof(feature) / sizeof(feature[0]) - sizeof(insect) / sizeof(insect[0]); i++)
	{
		if (i % 4 == 0 && i != 0)
		{
			cout << endl;
		}
		cout << setiosflags(ios::left) << setw(2) << i << ".";
		cout << setiosflags(ios::left) << setw(15) << feature[i];
	}
	memset(flag, 0, sizeof(flag));//初始化标记数组为0
}

//特征输入值选择数字 
void input()
{
	for (int i = 0; i < sizeof(feature) / sizeof(feature[0]) - sizeof(insect) / sizeof(insect[0]); i++)
	{
		flag[i] = 0;
	 }
	cout << endl; 
	int  key = 0;
	cout << "*****************************************************************************"<<endl;
	cout << "请输入所选昆虫特征（输入完成后，请输入-1.）：";
	while (key != -1)//当输入-1时停止特征输入
	{ 
		cin >> key;
		if (key >= 0 && key <= 23)
		{
			flag[key] = 1;
		}
		else if (key != -1)
		{
			cout << "输入错误，请输入一个特征：" << endl;
			cin.clear();		//清除流错误错误标记
			cin.sync(); 		//清空输入缓冲区
			cout << "请继续输入：";
		}
	}
}

//是某昆虫而不是某种物种 
int IsInsect(int a)
{
	if (a >= sizeof(feature) / sizeof(feature[0]) - sizeof(insect) / sizeof(insect[0]) && a <= sizeof(feature) / sizeof(feature[0]))
	{
		return 1;
	}
	return 0;
}

//判断是否某一物种类 
int IsPlant_speices(int a)
{
	if (a >= 18 && a <= 23)
	{
		return 1;
	}
	return 0;
}

//返回flag数组中标记的总数 
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

//输出打印物种类别
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
				cout << "无法识别昆虫! 所属类为：";
			}
			cout << setiosflags(ios::left) << setw(10) << feature[i];
		}
	}
	cout << endl;
	if (!k)
	{
		cout << "系统无该昆虫" << endl;
	}
	return 1;
}

//改变特征值，变化flag，推理是否有物种种类，并将用到的事实清空，改flag为0
int change_speices()
{
	int i, j, key;
	bool t;
	int temp[23] = { 0 }; //临时存储，方便修改
	int f[23] = { 0 }; // 标记使用过的flag 
	for (i = 0; i < 7; i++)
	{ 
		//前7个规则
		t = true;
		j = 0;
		key = rule[i].relation[j];
		while (key != -1)//遍历该条关系
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
	//删除推理过的事实，保留结果 
	for (i = 0; i <= 17; i++)
	{
		if (f[i] == 1)
		{
			flag[i] = 0;
		}
	}
	return 1;
}

//重新计算置信度 
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

//双向推理，正向推理不下去，事实不够，采用逆向推理
int z_inference()
{
	int key, num;
	int i, j;
	int fum = fnum();
	cout << endl;
	for (i = 7; i < 15; i++)
	{  
		//检查规则库
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
		//此时j保存则rule[i]所含有的特征数 
		if (num != 0 && fum <= j)
		{  
			//给定特征数小于等于的情况，即flag数组中标记位数目大于此昆虫的特征数则不放入result
			if (IsInsect(rule[i].name))
			{ 
				// 是具体的昆虫 
				temp.insect = rule[i].name;
				int size = j; //rule[i]所含有的特征数
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
		Rsort(result);  //对置信度从高到低排序 
	}
	//正向推理后 
	if (result.empty()) 
	{ 
		//给定特征数无法用任何一规则推理,可能没有这种昆虫，可能是一种类别 
		category();
	}
	else if (result.front().confidence == 1.0)
	{ 
		//可能给的特征刚好推理出，可能特征还没用完
		cout << "昆虫为：" << feature[result.front().insect] << endl;
		result.clear();//清空
		return 1;
	}
	else//逆向推理，询问特征
	{
		r_inference();
	}
}

//特征不足，进入反向推理 
void r_inference()
{
	vector<Result>::iterator it = result.begin();
	int enquire[23];  
	//用来标记询问过的特征数组（0代表没有此特征，1代表有，2代表不请楚、	不知道） 
	memset(enquire, -1, sizeof(enquire));
	for (int i = 0; i< result.size();)
	{
		//从置信度最高开始询问
		bool in_i = true; // i ++ 的标记 
		int  nu = result[i].size;
		for (int j = 0; j < nu; j++)
		{  
			//询问特征 
			if (flag[rule[result[i].site].relation[j]] == 0)
			{
				int en = rule[result[i].site].relation[j];
				char c;
				if (enquire[en] == -1)
				{ 
					//此特征未被询问过，则输出询问语句，否则直接判断处理 
					cout << "是否有以下特征：" << feature[rule[result[i].site].relation[j]] << endl;
					cout << "Y(y) or N(n) or D(don't know) : ";
					cin >> c;
					while (c != 'Y' && c != 'y' && c != 'N' && c != 'n' && c != 'D' && c != 'd')
					{
						cout << "输出选择：Y(y) N(n) D(d)!" << endl;
						cin >> c;
					}
				}
				if (enquire[en] == 1 || c == 'Y' || c == 'y')
				{
					//有此特征  改变置信度
					result[i].num++;
					enquire[en] = 1;
				}
				else if (enquire[en] == 0 || c == 'N' || c == 'n')
				{ 
					// 没有此特征  直接去掉
					enquire[en] = 0;
					result.erase(it + i);
					//erase删除后i不自增，就能删除最后的元素，迭代器指向删除之前元素后的第一个元素
					in_i = false; //如果擦除了元素，则i不自增 
					if (result.empty())//result为空，输出类别后退出 
					{
						category();
					}
					break;
				}
				else if (enquire[en] == 2 || c == 'D' || c == 'd')
				{
					enquire[en] = 2;  // 不确定、不知道，则置信度不改变 
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
		// 改变置信度 
		cal_confi();
		if (result.size() > 1) //重新排序
		{
			Rsort(result);
		}
		//判断询问后进行双向推理
		if (result.front().confidence == 1.0)
		{
			cout << "昆虫是：" << feature[result.front().insect] << endl;
		}
		else
		{
			cout << "昆虫可能为（置信度从高到低）:";
			for (vector<Result>::iterator it = result.begin(); it != result.end(); ++it)
			{
				cout << setiosflags(ios::left) << setw(10) << feature[(*it).insect] << " ";
			}
			cout << endl;
		}
		result.clear(); // 清空 
	}
}
int main()
{
	char q;
	cout << "*****************************************************************************"<<endl;
	cout << "*                            昆虫识别系统                                   *"<<endl;
	cout << "*****************************************************************************"<<endl;
	cout << "是否进入系统：Y(y) N(n)"<<endl;
	cin >> q;
	cout << "*****************************************************************************"<<endl;
	while (q != 'N' && q != 'n')
	{
		menu();
		input();
		change_speices();
		z_inference();
		cout << endl << "继续？(Y/N)" << endl;
		cin >> q;
		system("cls");//清屏进行新的操作
	}
	return 0;
}

