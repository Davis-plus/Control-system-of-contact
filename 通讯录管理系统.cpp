#include<iostream>
using namespace std;
#define MAX 1000
void menu()
{
	cout << "1.添加联系人" << endl;
	cout << "2.显示所有联系人" << endl;
	cout << "3.查找联系人" << endl;
	cout << "4.删除联系人" << endl;
	cout << "5.更改联系人" << endl;
	cout << "6.清空通讯录" << endl;
	cout << "0.退出通讯录" << endl;
}
struct person
{
	string name;
	int sex;
	string number;
	string address;
};
struct addressbooks
{
	struct person personArr[MAX];
	int m_size;//通讯录人数
};
void add(struct addressbooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "人满，退出！";
		return;
	}
	string name;
	cout << "请输入姓名" << endl;
	cin >> name;
	abs->personArr[abs->m_size].name = name;
	cout << "请输入性别 男1，女2" << endl;
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArr[abs->m_size].sex = sex;
			break;
		}
		else
		{
			cout << "请重试" << endl;
		}
		
	}
	

	cout << "请输入号码" << endl;
	string number;
	cin >> number;
	abs->personArr[abs->m_size].number = number;
	cout << "请输入地址" << endl;
	string address;
	cin >> address;
	abs->personArr[abs->m_size].address = address;
	abs->m_size++;
	system("cls");
	
}
void showperson(struct addressbooks *abs)
{
	if (abs->m_size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名:" << abs->personArr[i].name << endl;
			cout << "性别:" << (abs->personArr[i].sex == 1 ? "男" : "女") << endl;
			cout << "电话:" << abs->personArr[i].number << endl;
			cout << "地址:" << abs->personArr[i].address << endl;
			cout << endl;
		}
	}
	
	system("PAUSE");
}
void detect(struct addressbooks* abs)
{
	
	system("cls");
	menu();
	if (abs->m_size == 0)
	{
		cout << "当前通讯录为空！" << endl;
		return;
		cout << "已退回菜单栏" << endl;
		system("PAUSE");
	}

	string name;
	cin >> name;
	for (int i = 0; i < abs->m_size; i++)
	{
		if (name == abs->personArr[i].name)
		{
			cout << abs->personArr[i].name << endl;
			cout << abs->personArr[i].sex << endl;
			cout << abs->personArr[i].number << endl;
			cout << abs->personArr[i].address << endl;
		}
		else
		{
			cout << "未找到联系人" << endl;
		}
	}
	system("PAUSE");
}
int jiancha(struct addressbooks* abs )
{
	string name;
	cin >> name;
	for (int i = 0; i < abs->m_size; i++)
	{
		if (name == abs->personArr[i].name)
		{
			return i;
		}
		
	}
	return -1;
	
}
void deleteperson(struct addressbooks* abs)
{
	
	
	int sez = jiancha(abs);
	if (sez !=-1)
	{
		
		for (int i =sez; i < abs->m_size; i++)
		{
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->m_size--;
	}
	else
	{
		cout << "联系人不存在" << endl;
	}

	system("PAUSE");
	
	
}
void change(struct addressbooks* abs)
{
	int abb=jiancha(abs);
	if (abb != -1)
	{
		cout << "请输入要更改成的姓名" << endl;
		string name;
		cin >> name;
		abs->personArr[abb].name = name;
		cout << "请输入新性别男1，女2" << endl;
		int sex;
		cin >> sex;
		abs->personArr[abb].sex = sex;
		cout << "新号码" << endl;
		string number;
		cin >> number;
		abs->personArr[abb].number = number;
		cout << "新地址" << endl;
		string address;
		cin >> address;
		abs->personArr[abb].address = address;
		
	}
	else
	{
		cout << "该联系人不存在" << endl;
	}
	system("PAUSE");

	
	
}
void clear(struct addressbooks *abs)
{
	abs->m_size = 0;
	cout << "清空联系人完毕哦！" << endl;
	system("PAUSE");
}


int main()
{
	menu();

	int count = 0;
	addressbooks abs;
	abs.m_size = 0;
	while (true)
	{
		cin >> count;
		switch (count)
		{
		case 1: add(&abs);
			menu();
			break;
		case 2: 
			showperson(&abs);
			break;
		case 3:detect(&abs);
			break;
		case 4:
			deleteperson(&abs);
			break;
		case 5:
		{
			cout << "输入要更改的姓名！" << endl;
			change(&abs);
		}
			break;
		case 6:
			clear(&abs);
			break;
		case 0:
			break;

		default:
			break;
		}
		if(count==0)
		break;
	}
	system("PAUSE");
	return 0;
}

