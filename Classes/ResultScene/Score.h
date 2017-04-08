/***************************************************************************
*|
*|	概要　　スコアクラスの宣言
*|　作成者　GS2 16 中田湧介
*|　作成日　2017/4/08
*|___________________________________________________________________________
****************************************************************************/
#pragma once
/* ---- ライブラリのインクルード ---------- */
#include "cocos2d.h"

enum ScoreNumber
{
	First,
	Scound,
	Third,
	Fourth,
	Fifth,
	ScoreNumber
};
//ランキング数
const int MAX_SCORE = 5;

class Score :public cocos2d::Node
{
public:
	virtual bool init();

	CREATE_FUNC(Score);


	//スコアを取得する
	void ScoreAcquisition();

	//スコアのランキングを調べる
	void RankingSort();

	//スコアの保存
	void ScoreResister();

	//スコアのレクトを設定・描画
	void ScoreIndicate(int Ranking);

	//スコアのアクション
	void ScoreAction(int Ranking);

	//数
	cocos2d::Sprite* s_Number;

	//スコアの桁数
	int Digit;
	//今回のスコア
	int m_Score;


	//ランキングスコア
	int RankingScore[MAX_SCORE];

	bool static SceneFlag;	//シーン切り替えしてもいいか

private:
	cocos2d::UserDefault* userDefault;
	const float SCREEN_SIZE_WIDTH = 980.0f; //画面の長さ
	const float SCREEN_SIZE_LENGTH = 640.0f; //画面の長さ
	int ScoreNumber; //桁数を求める際に代入して使用して使う変数
	int ScoreNumber2;
	Node* m_NodeNumber[MAX_SCORE + 1];
};

