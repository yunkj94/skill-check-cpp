/*
 * Q008 埋め込み文字列の抽出
 *
 * 一般に、定数定義の場合を除いて、プログラム中に埋め込み文字列を記述するのは良くないとされています。
 * そのような埋め込み文字列を見つけるために、埋め込み文字列や埋め込み文字（"test"や'a'など）が
 * 記述された行を出力するプログラムを作成してください。
 *
 * - 実行ディレクトリ配下（再帰的にチェック）に存在するすべてのccファイルをチェックする
 * - ファイル名はディレクトリ付きでも無しでも良い
 * - 行の内容を出力する際は、先頭のインデントは削除しても残しても良い
 * - マクロの内容まで判定する必要はない
 * - コメント内にあるものは、文字列に見えても表示しない

[出力イメージ]
q001.cc(12): return "test";  // テストデータ
q002.cc(10): static const char* DATA = "test"
q002.cc(11): + "aaa";
q002.cc(20): if (test == 'x') {
q004.cc(13): Pattern pattern = Pattern.compile("(\".*\")|(\'.*\')");

 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>

using namespace std;

static void listFiles(const char* dir, vector<string>& list) {
	DIR* dp;
	string parent(dir);

	dp = opendir(dir);
	if (!dp) {
		return;
	}
	parent += "/";
	while (1) {
		dirent* entry = readdir(dp);
		if (!entry) {
			break;
		}
		if (entry->d_name[0] != '.') {
			string fname = parent + entry->d_name;
			struct stat sb;
			stat(fname.c_str(), &sb);
			if (S_ISDIR(sb.st_mode)) {
				// ディレクトリ
				listFiles(fname.c_str(), list);
			} else if (fname.size() > 3 && fname.compare(fname.size() - 3, 3, ".cc") == 0) {
				list.push_back(fname);
			}
		}
	}
	closedir(dp);
}

