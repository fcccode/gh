#pragma once

#include<WinSock2.h>
#include "Packet.h"
enum E_DATA_IN_OUT_TYPE
{
	E_TYPE_DATA_OUT,
	E_TYPE_DATA_IN
};

typedef VOID(WINAPI*SENDPROCHANDLER)(SOCKET, CONST CHAR*, DWORD, LPARAM, LPARAM, LPARAM, LPARAM);
typedef VOID(WINAPI*RECVPROCHANDLER)(LPBYTE, DWORD);


typedef BOOL (APIENTRY*DETACHPROCESS) ();
typedef BOOL (APIENTRY*ATTACHPROCESS) (SENDPROCHANDLER, RECVPROCHANDLER);
typedef VOID (APIENTRY*DISPATCHGAMEDATA) (LPBYTE, DWORD, LPVOID);
typedef VOID (APIENTRY*SETGLOBALENV) (LPVOID);

class CCoreLib
{
public:
    CCoreLib( void );
    ~CCoreLib( void );
	static void WINAPI SendData2GameServer(LPBYTE byteBuffer, DWORD dwSize, DISPATCH_CONTEXT* ctx);
	static BOOL AttachHookIntoGameProcess(SENDPROCHANDLER, RECVPROCHANDLER in_hdr = NULL);
	static BOOL DetachHookFromGameProcess(VOID);

};

