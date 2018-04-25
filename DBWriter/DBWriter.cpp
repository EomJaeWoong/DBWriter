// DBWriter.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int g_iData			= 0;

int g_iStage		= 0;
int g_iAccount		= 0;

int g_iAccountNo	= 0;
int g_iLevel		= 0;
int g_iExp			= 0;

CAyaStreamSQ			g_DBMessageQueue(5000);
CMemoryPool<st_DBQUERY> g_DBMessagePool;

unsigned __stdcall UpdateThread(LPVOID updateArg)
{
	int iMessageType = -1;

	while (1)
	{
		if (g_DBMessageQueue.GetFreeSize() <= sizeof(st_DBQUERY*))
			continue;

		iMessageType = rand() % 3;

		//////////////////////////////////////////////////////////////////
		//Message Type 넣기
		//////////////////////////////////////////////////////////////////
		g_DBMessagePool.Lock();
		st_DBQUERY* pDBQuery = g_DBMessagePool.Alloc();
		g_DBMessagePool.Unlock();

		pDBQuery->type = iMessageType;

		//////////////////////////////////////////////////////////////////
		// Message 생성
		//////////////////////////////////////////////////////////////////
		switch (iMessageType)
		{
		case df_DBQUERY_MSG_DATA_1 :
			((st_DBQUERY_MSG_DATA_1 *)(pDBQuery->message))->iData =
				InterlockedIncrement((long *)&g_iData);
			break;

		case df_DBQUERY_MSG_DATA_2 :
			((st_DBQUERY_MSG_DATA_2 *)(pDBQuery->message))->iStage =
				InterlockedIncrement((long *)&g_iStage);
			((st_DBQUERY_MSG_DATA_2 *)(pDBQuery->message))->iAccount =
				InterlockedIncrement((long *)&g_iAccount);
			break;

		case df_DBQUERY_MSG_DATA_3 :
			((st_DBQUERY_MSG_DATA_3 *)(pDBQuery->message))->iAccountNo =
				InterlockedIncrement((long *)&g_iAccountNo);
			((st_DBQUERY_MSG_DATA_3 *)(pDBQuery->message))->iLevel =
				InterlockedIncrement((long *)&g_iLevel);
			((st_DBQUERY_MSG_DATA_3 *)(pDBQuery->message))->iExp =
				InterlockedIncrement((long *)&g_iExp);
			break;

		default :
			break;
		}

		///////////////////////////////////////////////////////////////////
		// Message 넣기
		///////////////////////////////////////////////////////////////////
		g_DBMessageQueue.Lock();
		g_DBMessageQueue.Put((char*)&pDBQuery, sizeof(pDBQuery));
		g_DBMessageQueue.Unlock();

		Sleep(10);
	}
}

unsigned __stdcall DBWriterThread(LPVOID dbwriterArg)
{
	//--------------------------------------------------------------
	// MYSQL 객체
	//--------------------------------------------------------------
	MYSQL *connection = NULL, conn;

	//--------------------------------------------------------------
	// 실질적 데이터
	//--------------------------------------------------------------
	MYSQL_RES *sql_result;
	MYSQL_ROW sql_row;

	int query_stat;

	//--------------------------------------------------------------
	// 초기화
	//--------------------------------------------------------------
	mysql_init(&conn);

	//--------------------------------------------------------------
	// DB연결
	//--------------------------------------------------------------
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char *)NULL, 0);
	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connection error :%s\n", mysql_error(&conn));
		return 1;
	}

	// 한글 사용
	// 나중에 문제가 생기면 찾아보셈
	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_result=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	char query[200] = { 0, };

	st_DBQUERY* pDBQuery = NULL;

	while (1)
	{

	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

