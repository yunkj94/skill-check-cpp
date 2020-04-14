#pragma once

class ListManager
{
	int* dataList;
	int compareCount;
	int exchangeCount;
	int dataSize;
public:
	ListManager();
	~ListManager();

	int Compare(int index1, int index2);
	void Exchange(int index1, int index2);
	void CheckResult();
	inline int GetSize() { return dataSize; }
};
