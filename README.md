# C++ Project 
个人C++学习过程中完成的项目。（Projects completed in the course of personal C++ learning.）


# 通讯录管理系统

## 一、项目介绍
通讯录管理系统是一个简单实用的小项目，功能涵盖了联系人管理的各个方面。通过这个项目，可以学习到：

1. **C++中的结构体和指针的使用**。
2. **如何将功能模块化，通过函数组织代码**。
3. **交互式界面的实现**。
4. **如何处理用户输入和数据校验**。

## 二、功能展示
程序启动后，用户会看到以下操作菜单：
```
***************************
*****  1、添加联系人  *****
*****  2、显示联系人  *****
*****  3、删除联系人  *****
*****  4、查找联系人  *****
*****  5、修改联系人  *****
*****  6、清空联系人  *****
*****  0、退出通讯录  *****
***************************
```

以下是每个功能的简要说明：

1. **添加联系人**：输入姓名、性别、年龄、电话、地址，添加新联系人。
2. **显示联系人**：查看所有已保存的联系人信息。
3. **删除联系人**：通过姓名查找并删除联系人。
4. **查找联系人**：输入姓名并快速定位对应的联系人信息。
5. **修改联系人**：修改已有联系人的任意信息。
6. **清空联系人**：一键清空通讯录。
7. **退出程序**：安全结束程序。

---

## 三、核心代码拆解

### 1. 通讯录的核心数据结构

在通讯录中，每个联系人由以下信息组成：`姓名`、`性别`、`年龄`、`电话`和`地址`。我们可以通过一个结构体来保存这些信息。

```cpp
struct Person {
    string name;      // 姓名
    int sex;          // 性别：1-男，2-女
    int age;          // 年龄
    string phone;     // 电话
    string address;   // 地址
};
```

同时，通讯录本身是一个包含多个联系人的集合，用另一个结构体来保存这些联系人和当前联系人数量：

```cpp
struct Addressbook {
    struct Person personArray[MAX]; // 容纳最多1000个联系人
    int size;                       // 实际联系人数量
};
```

通过这样的设计，通讯录相关的操作都可以基于 `Addressbook` 结构体进行。

---

### 2. 主界面设计与导航

程序启动后调用 `showMenu` 函数，展示选项菜单：

```cpp
void showMenu() {
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
```

根据用户输入执行对应功能：

```cpp
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
            case 1: // 添加联系人
                addPerson(&abs);
                break;
            case 2: // 显示联系人
                showPerson(&abs);
                break;
            case 3: // 删除联系人
                deletePerson(&abs);
                break;
            case 4: // 查找联系人
                findPerson(&abs);
                break;
            case 5: // 修改联系人
                modifyPerson(&abs);
                break;
            case 6: // 清空联系人
                clearPerson(&abs);
                break;
            case 0: // 退出通讯录
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
```

---

### 3. 添加联系人

添加联系人是程序的核心功能之一，需要进行多次用户输入并校验数据：

```cpp
void addPerson(Addressbook *abs) {
    if (abs->size == MAX) {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }

    // 姓名
    string tempName;
    cout << "请输入姓名：" << endl;
    cin >> tempName;
    abs->personArray[abs->size].name = tempName;

    // 性别
    int tempSex;
    cout << "请输入性别：1-男，2-女" << endl;
    while (true) {
        cin >> tempSex;
        if (tempSex == 1 || tempSex == 2) {
            abs->personArray[abs->size].sex = tempSex;
            break;
        }
        cout << "输入有误，请重新输入" << endl;	
    }

    // 年龄
    cout << "请输入年龄：" << endl;
    int tempAge;
    while (true) {
        cin >> tempAge;
        if (tempAge >= 0 && tempAge <= 150) {
            abs->personArray[abs->size].age = tempAge;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    // 电话
    cout << "请输入联系电话：" << endl;
    string tempPhone;
    while (true) {
        cin >> tempPhone;
        if (tempPhone.length() == 11) {
            abs->personArray[abs->size].phone = tempPhone;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    // 地址
    string tempAddress;
    cout << "请输入地址：" << endl;
    cin >> tempAddress;
    abs->personArray[abs->size].address = tempAddress;

    // 更新通讯录的人数
    abs->size++;
    cout << "添加成功" << endl;

    system("pause");
    system("cls");
}
```

**注意点**：
1. 边界条件检查：如性别只能是 1 或 2，年龄限制在 0 到 150 之间，手机号必须是 11 位。
2. 动态更新通讯录：每次新增联系人后，`abs->size++` 会加 1。

---

### 4. 删除联系人

删除联系人需要先通过姓名查找目标联系人，然后从数组中移除该联系人（本质是让需要被删除的联系人之后的数据向前移动一位，覆盖需要被删除的联系人数据）：

```cpp
int isExist(Addressbook *abs, string tempName) {
    for (int i = 0; i < abs->size; i++) {
        if (abs->personArray[i].name == tempName) {
            return i; // 返回联系人索引
        }
    }
    return -1; // 未找到
}

void deletePerson(Addressbook *abs) {
    cout << "请输入您要删除的联系人：" << endl;
    string tempName;
    cin >> tempName;

    int flag = isExist(abs, tempName);
    if (flag != -1) {
        for (int i = flag; i < abs->size - 1; i++) {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->size--; // 数组大小减少
        cout << "删除成功" << endl;
    } else {
        cout << "查无此人" << endl;
    }
}
```

---

### 5. 显示联系人

通过遍历通讯录结构体，将每个联系人的信息打印到屏幕上：

```cpp
void showPerson(Addressbook *abs) {
    if (abs->size == 0) {
        cout << "当前通讯录为空" << endl;
    } else {
        for (int i = 0; i < abs->size; i++) {
            cout << "姓名： " << abs->personArray[i].name << "\t";
            cout << "性别： " << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
            cout << "年龄： " << abs->personArray[i].age << "\t";
            cout << "电话： " << abs->personArray[i].phone << "\t";
            cout << "住址： " << abs->personArray[i].address << endl;
        }
    }

    // 暂停窗口并清屏
    system("pause");
    system("cls");
}
```

---

### 6. 查找联系人

通过输入姓名快速定位指定的联系人，并显示其详细信息：

```cpp
void findPerson(Addressbook *abs) {
    cout << "请输入您要查找的联系人：" << endl;
    string tempName;
    cin >> tempName;

    int flag = isExist(abs, tempName);
    if (flag != -1) {
        cout << "姓名： " << abs->personArray[flag].name << "\t";
        cout << "性别： " << (abs->personArray[flag].sex == 1 ? "男" : "女") << "\t";
        cout << "年龄： " << abs->personArray[flag].age << "\t";
        cout << "电话： " << abs->personArray[flag].phone << "\t";
        cout << "住址： " << abs->personArray[flag].address << endl;
    } else {
        cout << "查无此人" << endl;
    }

    // 暂停窗口并清屏
    system("pause");
    system("cls");
}
```

---

### 7. 清空联系人

清空联系人功能将通讯录中现有的所有联系人清空，并重置联系人数量为 0：

```cpp
void clearPerson(Addressbook *abs) {
    cout << "您是否确认要清空所有联系人？" << endl;
    cout << "1 --- 确认" << endl;
    cout << "0 --- 退出" << endl;

    int flag = 0;
    cin >> flag;
    if (flag == 1) {
        abs->size = 0; // 重置通讯录大小
        cout << "联系人已全部清空" << endl;
    }

    // 暂停窗口并清屏
    system("pause");
    system("cls");
}
```

---

