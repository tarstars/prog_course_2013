#pragma once

class A {
public:
	virtual int eval(int x)=0;  //=0 - означает, что эта ф-ия не используется
								//такую ф-ию не нужно описывать в .cpp файле
								//чисто-виртуальная ф-ия
	virtual ~A(){}
};