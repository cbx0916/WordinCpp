#include<iostream>
using namespace std;

#define DAY 7

int main(){
    const int monday = 1;
    cout << "一周有" << DAY << "天" << endl;
    cout << "Monday是第" << monday << "天" << endl;

    char str1[] = "abcde";
    char *str2 = "nnnasd";
    string str3 = "hasfkf";
    int a = 11111;
    int b = 22222;
    cout << "a=" << a << "\nb=" << b << endl;
    swap1(a,b);
    cout << "a=" << a << "\nb=" << b << endl;
    swap2(&a, &b);

}

void swap1(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}
void swap2(int* a, int* b){
    int buffer = *a;
    *a = *b;
    *b = buffer;

}
void swap3(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
void swap4(const int &a,const int &b){
    int tmp = a;
    // a = b;
    // b = tmp;
}