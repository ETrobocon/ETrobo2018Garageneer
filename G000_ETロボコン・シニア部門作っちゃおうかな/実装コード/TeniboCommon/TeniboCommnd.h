/*
	[NOTE] This file is automatically generated. Please do not hand-coded.
  
	Template:C++,EnumDataType.h.xsl
	Generated Date:2018/09/19 14:45:51
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */
#ifndef TeniboCommnd_H
#define TeniboCommnd_H



/**

@author ike
@version 1.0
*/
enum TeniboCommnd
{
	/**
	
	*/
	TC_STOP = 0,
	/**
	ハンドルとアクセルで操作するマニュアルか、自動でボールをひらうモードか。
param1:モード（０：マニュアル、１：オート）
param2, param3：未使用
	*/
	TC_MODE = 1,
	/**
	ハンドルを切る。プラスは右方向、-100から+100
アクセスを踏む。プラスは前進。-100から＋１００
param1:ハンドル値
param2:アクセル値
param3:未使用(0)
	*/
	TC_DRIVE = 2,
	/**
	ヘッドライトをつける。番号によりパターンを指定する。
param1:０＝OFF,それ以外ON
param2:未使用（0）
param3:未使用（0）
	*/
	TC_LIGHT = 4,
	/**
	ボールピックアップモーターのON/OFF
param1:０＝OFF,それ以外ON
param2:未使用（0）
param3:未使用（0）

	*/
	TC_BALLPICK = 5,
	/**
	発話の文字を含む
	*/
	TC_TALK = 16,
	/**
	発話開始マーク
	*/
	TC_TALKS = 32,
	/**
	発話終了マーク
	*/
	TC_TALKE = 64,
	/**
	
	*/
	TC_BEEP = 20,
};

#endif /* TeniboCommnd_H */
