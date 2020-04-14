#pragma once
#include <decimal/decimal>
#include <iostream>
#include <stack>

// 計算用の基底クラス
class IValue {
public:
	virtual ~IValue() {}

	virtual void Execute(std::stack<std::decimal::decimal128>& stack) = 0;
};

// 足し算クラス
class PlusValue: public IValue {
public:
	virtual ~PlusValue() {}

	virtual void Execute(std::stack<std::decimal::decimal128>& stack);
};


// 数値クラス
class DecimalValue: public IValue {
	std::decimal::decimal128 value;
public:
	DecimalValue(const char* digit);
	virtual ~DecimalValue() {}

	virtual void Execute(std::stack<std::decimal::decimal128>& stack);
};
