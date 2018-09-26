#include "../motor_controller/motor_controller.hpp"

/* インクルードガード */
#ifndef  MOVE_CONTROLLER_CLASS
#define MOVE_CONTROLLER_CLASS

/* 旋回方向 */
enum EN_TurnOri
{
	en_turn_right, /* 右方向 */
	en_turn_left,  /* 左方向 */
	en_turn_back   /* 右方向（180度反転）*/
};

/* 移動タイプ */
enum EN_MoveType
{
	en_front_line_right,  /* 進行方向：前、ライン上ライトセンサ：右 */
	en_front_line_left,   /* 進行方向：前、ライン上ライトセンサ：左 */
	en_front_line_center, /* 進行方向：前、ライン上ライトセンサ：両方 */
	en_rear_line_right,   /* 進行方向：後、ライン上ライトセンサ：右 */
	en_rear_line_left,    /* 進行方向：後、ライン上ライトセンサ：左 */
	en_rear_line_center,  /* 進行方向：後、ライン上ライトセンサ：両方 */
};

/* クラス：移動管理部 */
class MoveController{

	/*　アトリビュート */
	private://非公開部分
	MotorController m_motor_controller[2];//モータコントローラ

	/* コンストラクタとデストラクタ */
	public:
	/* コンストラクタ */
	MoveController()
	{
		m_motor_controller[0] = MotorController( MOTOR_TYPE_RIGHT ); //右モータ
		m_motor_controller[1] = MotorController( MOTOR_TYPE_LEFT );  //左モータ
	}
	/* デストラクタ */
	~MoveController(){}

	/* メソッド */
	public:
	void moveTranspoter( EN_MoveType move_type); //運搬車の直進
	void stopTranspoter(); //運搬車の停止
	void turnTranspoter( EN_TurnOri turn_ori ); //運搬車の旋回
};
#endif