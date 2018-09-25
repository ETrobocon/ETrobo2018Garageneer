#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "human_detector.hpp"

/******************************************************************************
 * 関数名 | int detectHuman(int *trans_id);                                   *
 * 概要   | 人物認証関数                                                      *
 * 引数   | 退場者の靴が乗っている運搬車のID                                  *
 * 戻り値 | 入場者か退場者を表す整数型                                        *
 * 詳細   | 人物の指紋を判別し、入退場者の判定（実装が簡単なためpythonを使用）*
 ******************************************************************************/
int HumanDetector::detectHuman(int *trans_id){

	//システムコールでpythonのコードを実行
	system("python ~/HumanDetector.py");

	//変数宣言
	FILE *fp; //pythonコードのファイルポインタ
	int data[2]; // 出力変数（0:入退店者判別整数型、1：退店者の乗っている運搬車ID）

	fp = fopen("list.txt","r"); //pythonで保存したファイルをオープン

	// ファイルオープンエラー
	if(fp == NULL){
		printf("There is no data! \n");
		return -1;
	}

	// ファイルの値読み込み（指紋情報）
	for(int i=0;i<2;i++){
		fscanf(fp, "%d", &(data[i]) );
	}
	fclose(fp);

	// 認証者＝入場者
	if(data[0] == 0){
		printf("[setmode = %d][id = %d]\n", data[0],data[1]);
		*trans_id = data[1];
		return 0;
	}
	// 認証者＝退場者
	else if(data[0] == 1){
		printf("[setmode = %d] [id = %d]\n", data[0],data[1]);
		*trans_id = data[1];
		return 1;
	}
	// エラー
	else printf("[Error] Human_Detector \n");
}
