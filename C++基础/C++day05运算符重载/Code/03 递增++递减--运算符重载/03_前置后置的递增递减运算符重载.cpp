#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class MyInteger {
    // 友元访问私有属性
    friend ostream &operator<<(ostream &cout, MyInteger &myInt);

  public:
    MyInteger(int n) {
        this->m_Num = n;
    };

    //前置++(默认)
    MyInteger &operator++() { // 返回引用
        this->m_Num++;
        return *this;
    }

    //后置++(int区分) 重载
    MyInteger operator++(int) { // 返回值
        //先保存目前数据
        MyInteger tmp = *this;
        this->m_Num++;
        // cout << tmp << endl;
        return tmp;
    }

  public:
    int m_Num;
};

// 只能利用全局函数 进行 << 运算符的重载
ostream &operator<<(ostream &cout, MyInteger &myInt) {
    cout << myInt.m_Num;
    return cout;
}

void test01() {
    MyInteger myInt(0);
    cout << "myInt " << myInt << endl;

    // 前置++
    cout << "++myInt " << ++myInt << endl;
    cout << "myInt " << myInt << endl;

    // 连续前置++
    cout << "++(++myInt) " << ++(++myInt) << endl;
    cout << "myInt " << myInt << endl;

    // 后置++
    cout << "myInt++.m_Num " << myInt++.m_Num << endl; // .属性
    cout << "myInt " << myInt << endl;
    // error 后置++ 无法直接重载<<输出
    // cout << "myInt++ " << myInt++ << endl;

    // 无法连续后置++
    // cout << "(myInt++)++ " << (myInt++)++ << endl; // error 后置++ 无法直接重载<<输出
}

int main() {

    test01();

    /*int a = 10;
    cout << ++(++a) << endl;
    cout << a << endl;*/

    // system("pause");
    return EXIT_SUCCESS;
}