/*
 * Q006 空気を読んで改修
 *
 * 標準入力から「逆ポーランド記法」で記載された1行の入力を受け取り、その計算結果を出力する処理を実装してください。
 * 実装するのは四則演算（+ - * /）です。
 *
 * https://ja.wikipedia.org/wiki/%E9%80%86%E3%83%9D%E3%83%BC%E3%83%A9%E3%83%B3%E3%83%89%E8%A8%98%E6%B3%95
 *
 * ただし、現状は以下の実装が終わっています。
 * - 逆ポーランド記法を分解して、計算しやすい値リストに変換する処理の一部（Q006.parseLine）
 * - 計算しやすい値として管理するためのクラス群の一部（IValue,DecimalValue,PlusValue）
 *
 * 途中まで終わっている実装を上手く流用しながら、残りの処理を実装してください。
 * エラー入力のチェックは不要です。
 *
 * 実行例：
 *
 * 入力） 3 1.1 0.9 + 2.0 * -
 * 出力） -1
 * （または -1.00 など、小数点に0がついてもよい）
 */
#include <iostream>
#include <vector>
#include <string.h>
#include "operators.h"

using namespace std;

static void parseLine(const char* text, vector<IValue*>& opeList) {
	const char* pStart = text;
	const char* pTmp = text;

	while(1) {
		if (!*pTmp || strchr(" \t\r\n", *pTmp)) {
			if (pStart != pTmp) {
				string word(pStart, pTmp - pStart);
				// TODO 一部処理だけ実装
				if (word == "+") {
					opeList.push_back(new PlusValue());
				} else {
					// その他は数値として扱う
					opeList.push_back(new DecimalValue(word.c_str()));
				}
			}
			pStart = pTmp + 1;
		}
		if (!*pTmp) {
			// 終了
			break;
		}
		pTmp++;
	}
}

