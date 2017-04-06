//
//  main.cpp
//  函数对象3
//
//  Created by 郭悟清 on 2017/4/4.
//  Copyright © 2017年 郭悟清. All rights reserved.
//

#include <iostream>
#include <iterator>
using namespace std;

class MyLess
{
public:
    bool operator()(const int &c1,const int &c2)
    {
        if((c1%10)<(c2%10))
            return true;
        else
            return false;
            
    }
};
bool MyCompare(int a1,int a2)
{
    if((a1%10)<(a2%10))
        return false;
    else
        return true;
}
template <class T,class Pred>
T MyMax(T first,T last,Pred Myless)
{
    T tmpMax=first;
    for(;first!=last;first++)
        if(Myless(*tmpMax,*first))
            tmpMax=first;
    return tmpMax;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[]={35,7,13,19,12};
    cout<<*MyMax(a, a+5, MyLess())<<endl;
    cout<<*MyMax(a, a+5, MyCompare)<<endl;
    return 0;
}
