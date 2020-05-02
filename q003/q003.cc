/*
 * Q003 集計と並べ替え
 *
 * 以下のデータファイルを読み込んで、出現する単語ごとに数をカウントし、アルファベット辞書順に並び変えて出力してください。
 * data.txt
 * 単語の条件は以下となります
 * - "I"以外は全て小文字で扱う（"My"と"my"は同じく"my"として扱う）
 * - 単数形と複数形のように少しでも文字列が異れば別単語として扱う（"dream"と"dreams"は別単語）
 * - アポストロフィーやハイフン付の単語は1単語として扱う（"isn't"や"dead-end"）
 *
 * 出力形式:単語=数
 *
 * [出力イメージ]
 * （省略）
 * highest=1
 * I=3
 * if=2
 * ignorance=1
 * （省略）
 *
 * 参考
 * http://eikaiwa.dmm.com/blog/4690/
 */
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

// 参考:以下でファイルを開くことが出来る
// ifstream ifs("data.txt");

int main() {
    ifstream ifs("data.txt");
    char c;
    string text;
    while(ifs.get(c)) {
        text += c;
    }
    replace(text.begin(), text.end(), '\n', ' ');

    //できない・・
    //string tmp = regex_replace(text, regex("[;.,]"), "");

    text.erase(remove(text.begin(), text.end(), ';'), text.end());
    text.erase(remove(text.begin(), text.end(), '.'), text.end());
    text.erase(remove(text.begin(), text.end(), ','), text.end());

    vector<string> words;
    vector<string> words_unique;
    stringstream ss{text};
    string buf;
    while(getline(ss, buf, ' ')) {
        words.push_back(buf);
    }
    words_unique = words;
    sort(words_unique.begin(), words_unique.end());
    words_unique.erase(unique(words_unique.begin(), words_unique.end()), words_unique.end());
    for(string word : words_unique) {
        cout << word << '=' << count(words.begin(), words.end(), word) << endl;
    }
}
