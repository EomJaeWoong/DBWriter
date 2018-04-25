#ifndef __DBWRITER__H__
#define __DBWRITER__H__

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "6535(Djawodnd!)"
#define DB_NAME "test"

#pragma pack(1)

struct st_DBQUERY
{
	WORD type;
	BYTE message[200]; //메시지 역할을 할 데이터영역
};

//--------------------------------------------------------------------------------------------
//  DB 저장 메시지 - 회원가입
//--------------------------------------------------------------------------------------------
#define df_DBQUERY_MSG_DATA_1		0
struct st_DBQUERY_MSG_DATA_1
{
	int		iData;
};

//--------------------------------------------------------------------------------------------
//  DB 저장 메시지 - 스테이지 클리어
//--------------------------------------------------------------------------------------------
#define df_DBQUERY_MSG_DATA_2		1
struct st_DBQUERY_MSG_DATA_2
{
	int		iStage;
	int		iAccount;
};

//--------------------------------------------------------------------------------------------
//  DB 저장 메시지 - 
//--------------------------------------------------------------------------------------------
#define df_DBQUERY_MSG_DATA_3		2
struct st_DBQUERY_MSG_DATA_3
{
	int		iAccountNo;
	int		iLevel;
	int		iExp;
};
#pragma pack(4)

#endif