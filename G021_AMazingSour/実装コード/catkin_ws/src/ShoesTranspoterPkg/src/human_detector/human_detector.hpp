/* インクルードガード */
#ifndef _INCLUDE_HUMANDETECTOR_H_
#define _INCLUDE_HUMANDETECTOR_H_

/* クラス：人物認証機（指紋認証機管理クラス）*/
class HumanDetector{
/* コンストラクタとデストラクタ */
public://公開部分
	HumanDetector(){};//コンストラクタ
	~HumanDetector(){};//デストラクタ
/* メソッド */
public://公開部分
	int detectHuman(int *trans_id);//人物認証関数
};
#endif