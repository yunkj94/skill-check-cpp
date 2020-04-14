/*
 * Q005 データクラスと様々な集計
 *
 * 以下のファイルを読み込んで、WorkDataクラスのインスタンスを作成してください。
 * data.txt
 * (先頭行はタイトルなので読み取りをスキップする)
 *
 * 読み込んだデータを以下で集計して出力してください。
 * (1) 役職別の合計作業時間
 * (2) Pコード別の合計作業時間
 * (3) 社員番号別の合計作業時間
 * 上記項目内での出力順は問いません。
 *
 * 作業時間は "xx時間xx分" の形式にしてください。
 * また、WorkDataクラスは自由に修正してください。
 *
[出力イメージ]
部長: xx時間xx分
課長: xx時間xx分
一般: xx時間xx分
Z-7-31100: xx時間xx分
I-7-31100: xx時間xx分
T-7-30002: xx時間xx分
（省略）
194033: xx時間xx分
195052: xx時間xx分
195066: xx時間xx分
（省略）
 */
#include <iostream>

using namespace std;

class WorkData {
	// 社員番号
	string number;
	// 部署
	string department;
	// 役職
	string position;
	// Pコード
	string pCode;
	// 作業時間(分)
	int workTime;
public:
	WorkData() {}
	WorkData(const WorkData& src);

	WorkData& operator=(const WorkData& right);
};

WorkData::WorkData(const WorkData& src):
	number(src.number), department(src.department),
	position(src.position), pCode(src.pCode), workTime(src.workTime) {
}
WorkData& WorkData::operator=(const WorkData& right) {
	number = right.number;
	department = right.department;
	position = right.position;
	pCode = right.pCode;
	workTime = right.workTime;
	return *this;
}
