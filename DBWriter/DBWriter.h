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
	BYTE message[200]; //�޽��� ������ �� �����Ϳ���
};

//--------------------------------------------------------------------------------------------
//  DB ���� �޽��� - ȸ������
//--------------------------------------------------------------------------------------------
#define df_DBQUERY_MSG_DATA_1		0
struct st_DBQUERY_MSG_DATA_1
{
	int		iData;
};

//--------------------------------------------------------------------------------------------
//  DB ���� �޽��� - �������� Ŭ����
//--------------------------------------------------------------------------------------------
#define df_DBQUERY_MSG_DATA_2		1
struct st_DBQUERY_MSG_DATA_2
{
	int		iStage;
	int		iAccount;
};

//--------------------------------------------------------------------------------------------
//  DB ���� �޽��� - 
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