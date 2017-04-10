/***************************************************************************
*|
*|	概要　スコアクラスの定義
*|　作成者　GS2 16 中田湧介
*|　作成日　2017/4/07
*|___________________________________________________________________________
****************************************************************************/
/* ---- ライブラリのインクルード ---------- */
#include "Score.h"
#include "audio\include\AudioEngine.h"

USING_NS_CC;
using namespace cocos2d::experimental;


bool  Score::SceneFlag = false;
float Score::ScoreActionSpd = 1.0f;		//スコアのアクションの速度


bool Score::init()
{
	if (!Node::init()) {

		return false;
	}

	m_Score = rand()%999;

	////初期化
	//Score::SceneFlag = false;
	//ScoreActionSpd = 1.0f;
	//音楽ファイルを予めロードしておく
	AudioEngine::preload("Sounds\\SlideSE.ogg");

	
	userDefault = cocos2d::UserDefault::getInstance();


	//基盤ノードを作成する
	for (int i = 0; i < MAX_SCORE + 1; i++)
	{
		m_NodeNumber[i] = Node::create();
	}
	
	return true;
}


/***************************************************************************
*|	概要　　ランキングを取得する
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
void Score::ScoreAcquisition()
{
	RankingScore[First] = userDefault->getIntegerForKey("name1");
	RankingScore[Scound] = userDefault->getIntegerForKey("name2");
	RankingScore[Third] = userDefault->getIntegerForKey("name3");
	RankingScore[Fourth] = userDefault->getIntegerForKey("name4");
	RankingScore[Fifth] = userDefault->getIntegerForKey("name5");
}


/***************************************************************************
*|	概要　　スコアのランキングを調べる
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
void Score::RankingSort()
{
	//今回のスコアがランキングのどこに位置するか求める
	int i = Fifth;
	while ((RankingScore[i] < m_Score)&&(i > 0))
	{
		i--;
	}

	//今回のスコアがランキングに入っているならば
	if (i != score)
	{
		//ランキングを入れ替える
		for (int j = 2; i <= j; j--)
		{
			RankingScore[j + 1] = RankingScore[j];
		}

		//今回のスコアをランキングに入れる
		RankingScore[i] = m_Score;
	}

	
}

/***************************************************************************
*|	概要　　スコアを保存する
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
void Score::ScoreResister()
{
	userDefault->setIntegerForKey("name1", RankingScore[First]);
	userDefault->setIntegerForKey("name2", RankingScore[Scound]);
	userDefault->setIntegerForKey("name3", RankingScore[Third]);
	userDefault->setIntegerForKey("name4", RankingScore[Fourth]);
	userDefault->setIntegerForKey("name5", RankingScore[Fifth]);
	userDefault->flush();
}


/***************************************************************************
*|	概要　　スコアのスプライト設定
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
void Score::ScoreIndicate(int Ranking)
{

	int j;
		//桁数を初期化する
		Digit = 1;
		//対象のスコアを保存する
		ScoreNumber = RankingScore[Ranking];
		ScoreNumber2 = RankingScore[Ranking];

		//今回のスコアの場合
		if (Ranking == 5)
		{
			ScoreNumber = m_Score;
			ScoreNumber2 = m_Score;
		}

		//スコアが何桁あるのか求める
		//整数がなくなるまで10で除法する
		
		//スコアが0じゃないとき
		if ((ScoreNumber2 - ScoreNumber != ScoreNumber2))
		{
			while (ScoreNumber2 - ScoreNumber != ScoreNumber2)
			{
				ScoreNumber /= 10;
				//何回ループしたかカウントする
				Digit *= 10;
			
			}
			//小数になるまでかけたが、桁数を知りたいので10で割る
			Digit /= 10;
		}


		

		//対象のスコアを保存する
		ScoreNumber = RankingScore[Ranking];
		ScoreNumber2 = RankingScore[Ranking];
		//今回のスコアの場合
		if (Ranking == 5)
		{
			ScoreNumber = m_Score;
			ScoreNumber2 = m_Score;
		}
		j = 0;
		while (Digit != 0)
		{
			//残りの値が0になる時、「Digit桁の値を求める」でエラーになる
			//残りの値が0になる時、桁数分の0を表示して
			if (ScoreNumber2 <= 0)
			{
				//Digit桁の値を求める
				ScoreNumber = 0;
			}
			else
			{
				//Digit桁の値を求める
				ScoreNumber /= Digit;
			}

			//ランキングによって画像を変える
			switch (Ranking)
			{
			case First:
				//数字のスプライトを作成する
				s_Number = Sprite::create("Images\\Number1.png");
				break;
			case Scound:
				//数字のスプライトを作成する
				s_Number = Sprite::create("Images\\Number2.png");
				break;
			case Third:
				//数字のスプライトを作成する
				s_Number = Sprite::create("Images\\Number3.png");
				break;
			default:
				//数字のスプライトを作成する
				s_Number = Sprite::create("Images\\Number.png");
				break;
			}

		
			//レクトを設定する
			s_Number->setTextureRect(Rect(ScoreNumber * 64, 0, 64, 64));
			if ( Ranking == 5)
			{
				////座標
				s_Number->setPosition(Vec2(200 +  64 * j - SCREEN_SIZE_WIDTH, 500));
			}
			else
			{
				////座標
				s_Number->setPosition(Vec2(630 + 64 * j + SCREEN_SIZE_WIDTH, 500 - (Ranking * 82)));
			}

			//基盤ノードにぶら下げる
			m_NodeNumber[Ranking]->addChild(s_Number);
			this->addChild(m_NodeNumber[Ranking]);

			//スコアから求めた値を引く
			ScoreNumber2 -= ScoreNumber * Digit;
			ScoreNumber = ScoreNumber2;
			//次はDigit-1桁を見る
			Digit /= 10;
			j++;
	}
}

/***************************************************************************
*|	概要　　スコアのアクション
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
void Score::ScoreAction(int Ranking)
{
	//今回のスコアでないか
	if ((Ranking > First)&&(Ranking < score))
	{
		MoveBy* action = MoveBy::create(ScoreActionSpd, Vec2(-1 * SCREEN_SIZE_WIDTH, 0.0f));
		m_NodeNumber[Ranking]->runAction(action);
	}
	//最後のランキングか
	else if (Ranking == First)
	{
		MoveBy* action = MoveBy::create(ScoreActionSpd, Vec2(-1 * SCREEN_SIZE_WIDTH, 0.0f));
		CallFunc* action2 = CallFunc::create(CC_CALLBACK_0(Score::SceneFlagChenge,this));
		Sequence* action3 = Sequence::create(action, action2, nullptr);
		m_NodeNumber[Ranking]->runAction(action3);

	}
	else
	{
		MoveBy* action = MoveBy::create(ScoreActionSpd, Vec2(SCREEN_SIZE_WIDTH, 0.0f));
		m_NodeNumber[Ranking]->runAction(action);
	}

	int id = AudioEngine::play2d("Sounds\\SlideSE.ogg");

}

/***************************************************************************
*|	概要　　シーン切り替えしてもいいか変更する
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
void Score::SceneFlagChenge()
{
	SceneFlag = true;
}


