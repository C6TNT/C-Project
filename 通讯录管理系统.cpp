#include <iostream>
#include <string>

#define MAX 1000

using namespace std;

struct Person
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

struct Addressbook
{
	struct Person personArray[MAX];
	int size;
};

//展示界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;	
}

void addPerson(Addressbook *abs)
{
	if(abs->size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string tempName;
		cout << "请输入姓名： " << endl;
		cin >> tempName;
		abs->personArray[abs->size].name = tempName;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int tempSex;
		
		while(true)
		{
			cin >> tempSex;
			if(tempSex == 1 || tempSex == 2)
			{
				abs->personArray[abs->size].sex = tempSex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;	
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int tempAge;
		
		while(true)
		{
			cin >> tempAge;
			if(tempAge >= 0 && tempAge <=150)
			{
				abs->personArray[abs->size].age = tempAge;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//电话
		cout << "请输入联系电话：" << endl;
		string tempPhone;
		
		while(true)
		{
			cin >> tempPhone;
			if(tempPhone.length() == 11)
			{
				abs->personArray[abs->size].phone = tempPhone;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//地址
		cout << "请输入地址：" << endl;
		string tempAddress;
		cin >> tempAddress;
		abs->personArray[abs->size].address = tempAddress;
		
		//更新通讯录的人数
		abs->size ++;
		
		cout << "添加成功" << endl;
		
		system("pause");
		system("cls");
		
	}
}

void showPerson(Addressbook *abs)
{
	if(abs->size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for(int i = 0; i < abs->size; i ++)
		{
			cout << "姓名： " << abs->personArray[i].name << "\t";
			cout << "性别： " << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].age << "\t";
			cout << "电话： " << abs->personArray[i].phone << "\t";
			cout << "住址： " << abs->personArray[i].address<< endl;
		}
	}
	
	system("pause");
	system("cls");
	
}

int isExist(Addressbook *abs, string tempName)
{
	for(int i = 0; i < abs->size; i++)
	{
		if(abs->personArray[i].name == tempName)
		{
			return i;
		}
	}
	
	return -1;
	
}

void deletePerson(Addressbook *abs)
{
	cout << "请输入您要删除的联系人: " << endl;
	string tempName;
	cin >> tempName;
	
	int flag = isExist(abs, tempName);
	
	if(flag != -1)
	{
		for(int i = flag; i < abs->size; i ++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size --;
		
		cout << "删除成功" << endl;
		
	}
	else
	{
		cout << "查无此人" << endl;
	}
	
	system("pause");
	system("cls");
}

void findPerson(Addressbook *abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string tempName;
	cin >> tempName;
	
	int flag = isExist(abs, tempName);
	
	if(flag != -1)
	{
		cout << "姓名： " << abs->personArray[flag].name << "\t";
		cout << "性别： " << (abs->personArray[flag].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[flag].age << "\t";
		cout << "电话： " << abs->personArray[flag].phone << "\t";
		cout << "住址： " << abs->personArray[flag].address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	
	system("pause");
	system("cls");
}

void modifyPerson(Addressbook *abs)
{
	cout << "请输入您要修改的联系人: " << endl;
	string tempName;
	cin >> tempName;
	
	int flag = isExist(abs, tempName);
	
	if(flag != -1)
	{
		//姓名
		string tName;
		cout << "请输入姓名： " << endl;
		cin >> tName;
		abs->personArray[flag].name = tName;
		
		//性别
		cout << "请输入性别： " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int tempSex;
		
		while(true)
		{
			cin >> tempSex;
			if(tempSex == 1 || tempSex == 2)
			{
				abs->personArray[flag].sex = tempSex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;	
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int tempAge;
		
		while(true)
		{
			cin >> tempAge;
			if(tempAge >= 0 && tempAge <=150)
			{
				abs->personArray[flag].age = tempAge;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//电话
		cout << "请输入联系电话：" << endl;
		string tempPhone;
		
		while(true)
		{
			cin >> tempPhone;
			if(tempPhone.length() == 11)
			{
				abs->personArray[flag].phone = tempPhone;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//地址
		cout << "请输入地址：" << endl;
		string tempAddress;
		cin >> tempAddress;
		abs->personArray[flag].address = tempAddress;
		
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	
	system("pause");
	system("cls");
}

void clearPerson(Addressbook *abs)
{
	cout << "您是否确认要清空所有联系人：" << endl;
	cout << "1 --- 确认" << endl;
	cout << "0 --- 退出" << endl;
	int flag = 0;
	cin >> flag;
	if(flag)
	{
		abs->size = 0;
		cout << "联系人已全部清空" << endl;
	}
	
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	
	Addressbook abs;
	abs.size = 0;
	
	while(true)
	{
		showMenu();
		
		cin >> select;
		
		switch (select) 
		{
			case 1://添加联系人
			addPerson(&abs);
			break;
			case 2://显示联系人
			showPerson(&abs);
			break;
			case 3://删除联系人
			deletePerson(&abs);
			break;
			case 4://查找联系人
			findPerson(&abs);
			break;
			case 5://修改联系人
			modifyPerson(&abs);
			break;
			case 6://清空联系人
			clearPerson(&abs);
			break;
			case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
	
}

