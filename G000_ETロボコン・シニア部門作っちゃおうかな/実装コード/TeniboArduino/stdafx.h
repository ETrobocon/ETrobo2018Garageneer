// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#ifdef WIN32

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <BricRoboCOM.h>
#include <BricRoboRTE.h>
#include "TestDummy\arudinoTypes.h"
#include "TestDummy\\SoftwareSerial.h"
#include "TestDummy\DummySerial.h"
#include "TestDummy\\DummyArduino.h"

extern DummySerial Serial;

#else

#include <BricRoboCOM.h>
#include <BricRoboRTE.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Servo.h>

#endif

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
#define LENGTH_OF(a)    (sizeof(a) / sizeof((a)[0]))


//#define DEBUG