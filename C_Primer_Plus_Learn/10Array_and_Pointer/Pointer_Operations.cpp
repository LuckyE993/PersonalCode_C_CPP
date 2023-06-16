//
// Created by Lucky_E on 2023-06-16.
//样例代码
//
#include <iostream>
using namespace std;

int main()
{
    int urn[5] = {1,2,3,4,5,};

    int *ptr1, *ptr2, *ptr3;

    ptr1 = urn;
    ptr2 = &urn[2];

    cout << "pointer value: ptr1 =" << ptr1<<endl;
    cout<<"dereferenced pointer: *ptr1 =" << *ptr1<<endl;
    cout<<"pointer address value: &ptr1 =" << &ptr1<<endl;
    cout<<endl;

    ptr3 = ptr1+4;
    cout<<"Adding an int(4*4) to ptr1 ptr3 = "<<ptr3<<endl;
    cout<<"pointer value: *ptr3 = " <<*ptr3<<endl;
    cout<<"point address value &ptr3 = "<<&ptr3<<endl;
    cout<<endl;

    ptr1++;
    cout<<"pointer value after ptr1++: ptr1++ = "<<ptr1<<endl;
    cout<<"dereferenced pointer value: *ptr1 =" << *ptr1<<endl;
    cout<<endl;

    ptr2--;
    cout<<"pointer value after ptr2--: ptr2-- = "<<ptr2<<endl;
    cout<<"dereferenced pointer value: *ptr2 =" << *ptr2<<endl;
    cout<<endl;

    cout<<"Pointer reset to the Original value"<<endl;
    ptr1--;ptr2++;

    cout<<"Subtract one pointer to another pointer"<<endl;
    cout<<"ptr1 = "<<ptr1<<"  ptr2 = "<<ptr2<<endl;
    cout<<"ptr2 - ptr1 = "<<ptr2-ptr1<<endl;
    cout<<"This explains that the subtraction between two pointers is their data "<<endl;





    return 0;
}
