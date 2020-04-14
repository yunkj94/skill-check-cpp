#include <iostream>
#include <stdlib.h>
#include "operators.h"

using namespace std;

void PlusValue::Execute(std::stack<std::decimal::decimal128>& stack) {
	std::decimal::decimal128 right = stack.top();
	stack.pop();
	std::decimal::decimal128 left = stack.top();
	stack.pop();
	stack.push(left + right);
}


DecimalValue::DecimalValue(const char* digit) {
	char* endptr;
	value = std::decimal::decimal128(strtod(digit, &endptr));
}

void DecimalValue::Execute(std::stack<std::decimal::decimal128>& stack) {
	stack.push(value);
}
