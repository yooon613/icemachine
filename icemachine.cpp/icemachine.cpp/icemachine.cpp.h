
// icemachine.cpp.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CicemachinecppApp:
// �� Ŭ������ ������ ���ؼ��� icemachine.cpp.cpp�� �����Ͻʽÿ�.
//

class CicemachinecppApp : public CWinApp
{
public:
	CicemachinecppApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CicemachinecppApp theApp;