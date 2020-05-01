/*
 * Q002 並べ替える
 *
 * dataListに "ID,名字" の形式で20個のデータがあります。
 * これをID順に並べて表示するプログラムを記述してください。
 *
 * dataListの定義を変更してはいけません。
 *
 * [出力結果イメージ]
 * 1,伊藤
 * 2,井上
 * （省略）
 * 9,清水
 * 10,鈴木
 * 11,高橋
 * （省略）
 * 20,渡辺
 */
#include <iostream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <vector>

using namespace std;

static const char* dataList[] = {
	"8,佐藤",
	"10,鈴木",
	"11,高橋",
	"12,田中",
	"20,渡辺",
	"1,伊藤",
	"18,山本",
	"13,中村",
	"5,小林",
	"3,加藤",
	"19,吉田",
	"17,山田",
	"7,佐々木",
	"16,山口",
	"6,斉藤",
	"15,松本",
	"2,井上",
	"4,木村",
	"14,林",
	"9,清水"
};
static int dataSize = sizeof(dataList) / sizeof(dataList[0]);

struct member {
	int number;
	string name;
};

int main() {
	vector<member> members;

	for(int i = 0; i < dataSize; i++) {
		stringstream ss{dataList[i]};
		member member;
		string buf;
		int column = 0;

		while(getline(ss, buf, ',')) {
			if(column == 0) {
				member.number = stoi(buf);
			} else {
				member.name = buf;
			}
			column++;
		}
		members.push_back(member);
	}

	sort(members.begin(), members.end(),
		[](const member& x, const member& y) { 
			return x.number < y.number;
		});

	for(auto member : members) {
		cout << member.number << ',' << member.name << endl;
	}
	
	return 0;
}

