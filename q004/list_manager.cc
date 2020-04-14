#include <iostream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list_manager.h"

using namespace std;

ListManager::ListManager()
	:compareCount(0),exchangeCount(0) {
	srand((unsigned int)time(NULL));
	dataSize = 100;
	dataList = new int[dataSize];
	for (int i = 0; i < dataSize; i++) {
		dataList[i] = rand();
	}
	
}

ListManager::~ListManager() {
	delete[] dataList;
}

int ListManager::Compare(int index1, int index2) {
	compareCount++;
	return (dataList[index1] > dataList[index2]) - (dataList[index1] < dataList[index2]);
}

void ListManager::Exchange(int index1, int index2) {
	exchangeCount++;
	int tmp = dataList[index1];
	dataList[index1] = dataList[index2];
	dataList[index2] = tmp;
}

void ListManager::CheckResult() {
	int data = dataList[0];
	for (int i = 1; i < dataSize; i++) {
		if (data > dataList[i]) {
			stringstream str;
			str << "並び替えられていない:[" << (i - 1) << "]=" << data << ", [" << i << "]=" << dataList[i];
			throw logic_error(str.str());
		}
		data = dataList[i];
	}
	cout << "ソートOK: 比較=" << compareCount << ", 入れ替え=" << exchangeCount << endl;
}
