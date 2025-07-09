
// icemachine.cppDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "icemachine.cpp.h"
#include "icemachine.cppDlg.h"
#include "afxdialogex.h"
#include "API_SerialCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

														// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CicemachinecppDlg 대화 상자



CicemachinecppDlg::CicemachinecppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ICEMACHINECPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CicemachinecppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOBOX_PORT, m_combo_port);
	DDX_Control(pDX, IDC_COMBOBOX_Parity, m_combo_parity);
	DDX_Control(pDX, IDC_COMBOBOX_baudrate, m_combo_baudrate);
	DDX_Control(pDX, IDC_COMBOBOX_DATABIT, m_combo_databit);
	DDX_Control(pDX, IDC_COMBOBOX_stopbit, m_combo_stopbit);
	DDX_Control(pDX, IDC_COMBOX_modesetting, m_combo_modeset);
	DDX_Control(pDX, IDC_COMBOBOX_DATAREAD, m_combo_readset);
	DDX_Control(pDX, IDC_BUTTON_connection, m_butt_connection);
	DDX_Control(pDX, IDC_BUTTON_close, m_butt_close);
	DDX_Control(pDX, IDC_BUTTON_modesetting, m_butt_modeset);
	DDX_Control(pDX, IDC_BUTTON_staticdataclear, m_butt_dataclear);
	DDX_Control(pDX, IDC_BUTTON_RESET, m_butt_reset);
	DDX_Control(pDX, IDC_BUTTON_staticcheck, m_butt_statecheck);
	DDX_Control(pDX, IDC_BUTTON_ICEWATERSETTING, m_butt_icewaterset);
	DDX_Control(pDX, IDC_BUTTON_READ, m_butt_read);
	DDX_Control(pDX, IDC_BUTTON_TIMEOUT, m_butt_timeout);
	DDX_Control(pDX, IDC_BUTTON_SETTINGVALUE, m_butt_settingvalue);
	DDX_Control(pDX, IDC_BUTTON_RECEIVE, m_butt_receive);
	DDX_Control(pDX, IDC_STATIC_Text_Port, m_stat_port);
	DDX_Control(pDX, IDC_STATIC_Text_Parity, m_stat_parity);
	DDX_Control(pDX, IDC_STATIC_TEXT_Baudrate, m_stat_baudrate);
	DDX_Control(pDX, IDC_STATIC_Text_databit, m_stat_databit);
	DDX_Control(pDX, IDC_STATIC_TEXT_stopbit, m_stat_stopbit);
	DDX_Control(pDX, IDC_STATIC_TEXT_modesetting, m_stat_modeset);
	DDX_Control(pDX, IDC_STATIC_TEXT_ice, m_stat_iceout);
	DDX_Control(pDX, IDC_STATIC_text_water, m_stat_waterout);
	DDX_Control(pDX, IDC_STATICTEXT_READSETTING, m_stat_readset);
	DDX_Control(pDX, IDC_STATIC_TEXT_MINSETTING, m_stat_minset);
	DDX_Control(pDX, IDC_STATIC_TEXT_SECSETTING, m_stat_secset);
	DDX_Control(pDX, IDC_STATIC_TEXT_LOWTEMP, m_stat_lowtemp);
	DDX_Control(pDX, IDC_STATIC_TEXT_HIGHTEMP, m_stat_hightemp);
	DDX_Control(pDX, IDC_LISTBOX, m_list_log);
	DDX_Control(pDX, IDC_EDIT_ICE, m_edit_control_ice);
	DDX_Control(pDX, IDC_EDIT_WATER, m_edit_control_water);
	DDX_Control(pDX, IDC_EDIT_MIN, m_edit_control_min);
	DDX_Control(pDX, IDC_EDIT_SEC, m_edit_control_sec);
	DDX_Control(pDX, IDC_EDIT_LOWTEMP, m_edit_control_lowtemp);
	DDX_Control(pDX, IDC_EDIT_HIGHTEMP, m_edit_control_hightemp);


	DDX_Text(pDX, IDC_EDIT_ICE, m_dRange1);
	DDV_MinMaxDouble(pDX, m_dRange1, 0.0, 10.0);

	DDX_Text(pDX, IDC_EDIT_WATER, m_dRange1);
	DDV_MinMaxDouble(pDX, m_dRange1, 0.0, 10.0);

	DDX_Text(pDX, IDC_EDIT_MIN, m_dRange2);
	DDV_MinMaxDouble(pDX, m_dRange2, 0, 9);

	DDX_Text(pDX, IDC_EDIT_SEC, m_dRange3);
	DDV_MinMaxInt(pDX, m_dRange3, 0, 59);

	DDX_Text(pDX, IDC_EDIT_LOWTEMP, m_dRange4);
	DDV_MinMaxInt(pDX, m_dRange4, 0, 10);

	DDX_Text(pDX, IDC_EDIT_HIGHTEMP, m_dRange5);
	DDV_MinMaxInt(pDX, m_dRange5, 40, 70);




	DDX_Control(pDX, IDC_CHECKBOX_TIMER, m_check_box_TIMER);
}

BEGIN_MESSAGE_MAP(CicemachinecppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_connection, &CicemachinecppDlg::OnBnClickedButtonconnection)
	ON_BN_CLICKED(IDC_BUTTON_close, &CicemachinecppDlg::OnBnClickedButtonclose)
	ON_BN_CLICKED(IDC_BUTTON_modesetting, &CicemachinecppDlg::OnBnClickedButtonmodesetting)
	ON_BN_CLICKED(IDC_BUTTON_staticdataclear, &CicemachinecppDlg::OnBnClickedButtonstaticdataclear)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CicemachinecppDlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_staticcheck, &CicemachinecppDlg::OnBnClickedButtonstaticcheck)
	ON_BN_CLICKED(IDC_BUTTON_ICEWATERSETTING, &CicemachinecppDlg::OnBnClickedButtonIcewatersetting)
	ON_BN_CLICKED(IDC_BUTTON_READ, &CicemachinecppDlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_TIMEOUT, &CicemachinecppDlg::OnBnClickedButtonTimeout)
	ON_BN_CLICKED(IDC_BUTTON_SETTINGVALUE, &CicemachinecppDlg::OnBnClickedButtonSettingvalue)
	ON_BN_CLICKED(IDC_BUTTON_RECEIVE, &CicemachinecppDlg::OnBnClickedButtonReceive)

	ON_WM_TIMER()
END_MESSAGE_MAP()


// CicemachinecppDlg 메시지 처리기

BOOL CicemachinecppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

									// TODO: 여기에 추가 초기화 작업을 추가합니다.

									// Port 콤보박스 초기화
	CString strPort = TEXT("");
	for (int i = 1; i < 11; i++)
	{
		strPort.Format(TEXT("%d"), i);
		m_combo_port.AddString(strPort);
	}

	m_combo_port.SetCurSel(8);

	// databit 콤보박스 초기화
	CString strdatabit = TEXT("");
	for (int i = 7; i < 9; i++)
	{
		strdatabit.Format(TEXT("%d"), i);
		m_combo_databit.AddString(strdatabit);
	}
	m_combo_databit.SetCurSel(1);

	// Parity 콤보박스 초기화
	m_combo_parity.AddString(TEXT("None"));
	m_combo_parity.AddString(TEXT("Odd"));
	m_combo_parity.AddString(TEXT("Even"));

	m_combo_parity.SetCurSel(0);

	// Stop bit 콤보박스 초기화
	m_combo_stopbit.AddString(TEXT("1"));
	m_combo_stopbit.AddString(TEXT("1.5"));
	m_combo_stopbit.AddString(TEXT("2"));

	m_combo_stopbit.SetCurSel(0);

	// Baudrate 콤보박스 초기화
	m_combo_baudrate.AddString(TEXT("4800"));
	m_combo_baudrate.AddString(TEXT("9600"));
	m_combo_baudrate.AddString(TEXT("19200"));
	m_combo_baudrate.AddString(TEXT("38400"));
	m_combo_baudrate.AddString(TEXT("57600"));
	m_combo_baudrate.AddString(TEXT("115200"));

	m_combo_baudrate.SetCurSel(1);


	// 모드설정 콤보박스 초기화
	m_combo_modeset.AddString(TEXT("NORMAL MODE"));
	m_combo_modeset.AddString(TEXT("COMMUNICATION MODE"));

	m_combo_modeset.SetCurSel(0);

	// 읽기설정 콤보박스 초기화
	m_combo_readset.AddString(TEXT("Evaporator & Condensor 온도"));
	m_combo_readset.AddString(TEXT("제빙기 온도"));
	m_combo_readset.AddString(TEXT("제빙기 온도 설정값"));

	m_combo_readset.SetCurSel(0);

	m_check_box_TIMER.SetCheck(BST_CHECKED);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CicemachinecppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CicemachinecppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CicemachinecppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//ENTER, ESC 키 누를시 종료 않기 위한 함수 
BOOL CicemachinecppDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_SYSKEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_F4:
			return TRUE;
			break;
		default:
			break;
		}
	}

	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_ESCAPE:
		case VK_RETURN:
			return TRUE;
			break;
		default:
			break;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CicemachinecppDlg::OnBnClickedButtonconnection()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// port 콤보박스 값 가져오기
	CString strData = _T("");    // 초기화
	int nData = 0;
	int nIdx = m_combo_port.GetCurSel();
	m_combo_port.GetLBText(m_combo_port.GetCurSel(), strData);
	TRACE(strData + _T("\n"));

	// databit 콤보박스 값 가져오기
	CString strData1 = _T("");
	int nData1 = 0;
	int nIdx1 = m_combo_databit.GetCurSel();
	m_combo_databit.GetLBText(m_combo_databit.GetCurSel(), strData1);
	TRACE(strData1 + _T("\n"));

	// Parity 콤보박스 값 가져오기
	CString strData2 = _T("");
	int nData2 = 0;
	int nIdx2 = m_combo_parity.GetCurSel();
	m_combo_parity.GetLBText(m_combo_parity.GetCurSel(), strData2);
	TRACE(strData2 + _T("\n"));

	// stopbit 콤보박스 값 가져오기
	CString strData3 = _T("");
	int nData3 = 0;
	int nIdx3 = m_combo_stopbit.GetCurSel();
	m_combo_stopbit.GetLBText(m_combo_stopbit.GetCurSel(), strData3);
	TRACE(strData3 + _T("\n"));

	// baudrate 콤보박스 값 가져오기
	CString strData4 = _T("");
	int nData4 = 0;
	int nIdx4 = m_combo_baudrate.GetCurSel();
	m_combo_baudrate.GetLBText(m_combo_baudrate.GetCurSel(), strData4);
	TRACE(strData4 + _T("\n"));


	// 데이터 형변환
	m_iPort = _ttoi(strData);

	int iDatabit;
	iDatabit = _ttoi(strData1);
	BYTE biDatabit = (BYTE)iDatabit;

	int iParity;
	iParity = _ttoi(strData2);
	BYTE biParity = (BYTE)iParity;

	int iStopbit;
	iStopbit = _ttoi(strData3);
	BYTE biStopbit = (BYTE)iStopbit;

	double dBaudrate;
	dBaudrate = _wtof(strData4);
	DWORD dwBaudrate = (DWORD)dBaudrate;


	int nResult = api_SerialCom_Open(m_iPort, dwBaudrate, biDatabit, biParity, nIdx3);  // COM 포트에 연결할 때 사용하는 함수
	CString strResult;

	strResult.Format(TEXT("시리얼 Port = %d, 시리얼 통신 Open = %d\n"), m_iPort, nResult);
	TRACE(strResult);
	AddLog(NONE, strResult);

	if (nResult > 0)
	{
		AddLog(NONE, _T("통신 연결 성공"));
		//m_list_log.AddString(_T("통신 연결 성공"));
		//m_list_log.SetCurSel(m_list_log.GetCount() - 1);
		m_bConnect = TRUE;

		int nChk = m_check_box_TIMER.GetCheck();
		if (nChk == BST_CHECKED)
		{
			SetTimer(TIMER_DATARECEIVE, 200, NULL);
		}

	}
	else
	{
		AddLog(NONE, _T("통신 연결 실패"));
		m_bConnect = FALSE;
	}





}




void CicemachinecppDlg::OnBnClickedButtonclose()
{
	api_SerialCom_Close(m_iPort);
	AddLog(NONE, _T("통신 연결 종료"));

	KillTimer(TIMER_DATARECEIVE);
}


void CicemachinecppDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	AddLog(NONE, _T("프로그램 종료"));
	api_SerialCom_Close(m_iPort);

	KillTimer(TIMER_DATARECEIVE);

}


void CicemachinecppDlg::OnBnClickedButtonmodesetting()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 모드설정 콤보박스 값 가져오기
	int nIdx5 = m_combo_modeset.GetCurSel();
	int nCnt = 0;

	m_bySendData[nCnt++] = 0x02;  // STX
	m_bySendData[nCnt++] = 0x01;  // STATUS
	m_bySendData[nCnt++] = 0xA0;  // COMMAND

	if (nIdx5 == 0)
		m_bySendData[nCnt++] = 0x00;  // DATA 1 일반모드  
	else
		m_bySendData[nCnt++] = 0x01;  // 통신모드

	m_bySendData[nCnt++] = 0x00;  // DATA2

								  //byCheck = bySendData[0] ^ bySendData[1] ^ bySendData[2] ^ bySendData[3] ^ bySendData[4];

	m_bySendData[nCnt++] = Calc_Check(m_bySendData, nCnt);	// CHECK
	m_bySendData[nCnt++] = 0x03;          // ETX

	if (m_bConnect == TRUE)
	{
		api_SerialCom_WriteByte(m_iPort, m_bySendData, nCnt);  // Queue 버퍼에 데이터를 송신하는 함수

		CString strLog = _T("");
		strLog.AppendFormat(_T("[송신데이터: 모드 설정]     "));
		for (int i = 0; i < nCnt; i++)
		{
			strLog.AppendFormat(_T("%02X  "), m_bySendData[i]);
		}
		AddLog(SEND, strLog);
	}

	//if (nIdx5 == 0)
	//{
	//	BYTE bySendData[100] = { 0x00, };
	//	int nCnt = 0;

	//	bySendData[nCnt++] = 0x02;
	//	bySendData[nCnt++] = 0x01;
	//	bySendData[nCnt++] = 0xA0;
	//	bySendData[nCnt++] = 0x00;  // 일반모드
	//	bySendData[nCnt++] = 0x00;
	//	bySendData[nCnt++] = 0xA0;
	//	bySendData[nCnt++] = 0x03;
	//	api_SerialCom_WriteByte(m_iPort, bySendData, nCnt);
	//}

	//else if (nIdx5 == 1)
	//{
	//	BYTE bySendData[100] = { 0x00, };
	//	int nCnt = 0;

	//	bySendData[nCnt++] = 0x02;
	//	bySendData[nCnt++] = 0x01;
	//	bySendData[nCnt++] = 0xA0;
	//	bySendData[nCnt++] = 0x01; // 통신모드
	//	bySendData[nCnt++] = 0x00;
	//	bySendData[nCnt++] = 0xA0;
	//	bySendData[nCnt++] = 0x03;
	//	api_SerialCom_WriteByte(m_iPort, bySendData, nCnt);
	//}


}

// 정확한 데이터인지 확인 후 일치 검사 함수
BOOL CicemachinecppDlg::Message_Check(BYTE* pRecvData, int _nRecvCnt)
{
	BOOL bResult = FALSE;  // 초기화

						   // 메시지 패킷 검사해서 정상 유무 판단
	CString strText = TEXT("");
	strText.Format(TEXT("Receive Data [STK] %02X, [Command] %02X, [ETK] %02X"), pRecvData[INDEX_STX], pRecvData[INDEX_COMMAND], pRecvData[INDEX_ETX]);
	TRACE(strText);
	if (m_bySendData[INDEX_STX] == pRecvData[INDEX_STX] && m_bySendData[INDEX_COMMAND] == pRecvData[INDEX_COMMAND] && m_bySendData[INDEX_ETX] == pRecvData[INDEX_ETX])
	{
		if (pRecvData[INDEX_STATUS] == 0x00)
		{
			// Check 값 일치여부 검사 추가
			if (pRecvData[INDEX_CHECK] == Calc_Check(pRecvData, INDEX_CHECK))
			{
				bResult = TRUE;
			}
		}
	}

	return bResult;
}

void CicemachinecppDlg::Receive_Data()
{
	int n_result1 = api_SerialCom_GetDataInQueue(m_iPort);

	if (n_result1 > 0)
	{
		// 데이터 수신 성공 메시지를 로그에 추가
		AddLog(NONE, _T("데이터 수신 성공"));

		// 버퍼에 있는 문자열 길이 로그를 추가
		CString strResult = _T("");
		strResult.Format(TEXT("버퍼에 있는 문자열 길이, %d"), n_result1);
		TRACE(strResult);
		AddLog(RECV, strResult);

		BYTE byRecvData[100];
		api_SerialCom_ReadByte(m_iPort, byRecvData, n_result1);

		// 수신 데이터 로그를 추가
		strResult.AppendFormat(_T("[수신데이터]     "));
		for (int i = 0; i < n_result1; i++)
		{
			strResult.AppendFormat(_T("%02X  "), byRecvData[i]);
		}
		AddLog(RECV, strResult);

		// 정확한 데이터인지 확인 후 일치하면..
		if (Message_Check(byRecvData, n_result1) == TRUE)
		{
			// 수신데이터 Parsing(분석)
			switch (byRecvData[INDEX_COMMAND])
			{
			case COMMAND_TEMP_SET_READ:    // C1
			{
				int low_temp_C1 = (int)(byRecvData[INDEX_DATA_1]);
				int high_temp_C1 = (int)(byRecvData[INDEX_DATA_2]);

				CString strSetTemp = _T("");
				strSetTemp.AppendFormat(_T("[분위기 온도 설정값 읽기] : 저온 %d도, 고온 %d도"), low_temp_C1, high_temp_C1);
				AddLog(RECV, strSetTemp);
			}
			break;

			case COMMAND_TEMP_READ:         // C2
			{
				int temp_C2 = (int)(byRecvData[INDEX_DATA_1]);
				CString strTemp = _T("");
				strTemp.AppendFormat(_T("[분위기 온도 읽기] : %d도"), temp_C2);
				AddLog(RECV, strTemp);
			}
			break;

			case COMMAND_EC_TEMP_READ:     // C3
										   // 24년 1월 8일 진행 예정
			{
				int Evaporator_Temp = 0;
				int Condensor_Temp = 0;
				CString strTempC3;

				// Evaporator Temp - DATA1 
				Evaporator_Temp = (int)(byRecvData[INDEX_DATA_1]);
				if (Evaporator_Temp >= 128)
				{
					Evaporator_Temp = Evaporator_Temp - 256;
				}

				// Condensor Temp - DATA2
				Condensor_Temp = (int)(byRecvData[INDEX_DATA_2]);
				if (Condensor_Temp >= 128)
				{
					Condensor_Temp = Condensor_Temp - 256;
				}

				strTempC3 = _T("");
				strTempC3.AppendFormat(_T("[Evaporator & Condensor 온도읽기] : %d도, %d도"), Evaporator_Temp, Condensor_Temp);
				AddLog(RECV, strTempC3);
			}
			break;

			case COMMAND_ICE_OUT_TIMEOUT:    // D0
											 // byRecvData[DATA1], byRecvData[DATA2] 값을 십진수로 바꾸어서 리스트 박스에 출력 요망
											 // 표기방법 - "얼음 투출 타임아웃 설정 : 몇분 몇초"
			{
				int min_D0 = (int)(byRecvData[INDEX_DATA_1]);
				int sec_D0 = (int)(byRecvData[INDEX_DATA_2]);

				CString strTimeout = _T("");
				strTimeout.AppendFormat(_T("[얼음 투출 타임아웃 설정] : %d분 %d초"), min_D0, sec_D0);
				AddLog(RECV, strTimeout);
			}
			break;

			case COMMAND_SET_VALUE_READ:    // E1 
											// byRecvData[DATA1], byRecvData[DATA2] 값을 십진수로 바꾸어서 리스트 박스에 출력 요망
											// 표기방법 - "분위기 온도 설정 : 저온 몇도, 고온 몇도"
			{
				int low_temp_E1 = (int)(byRecvData[INDEX_DATA_1]);
				int high_temp_E1 = (int)(byRecvData[INDEX_DATA_2]);

				CString strTempWrite = _T("");
				strTempWrite.AppendFormat(_T("[분위기 설정값 쓰기] : 저온 %d도, 고온 %d도"), low_temp_E1, high_temp_E1);
				AddLog(RECV, strTempWrite);
			}
			break;

			case COMMAND_STATIC_CHECK:    // CF
			{
				CString strErCode = _T("");

				// DATA1
				BOOL bNo_Ice = byRecvData[INDEX_DATA_1] & 0x01;
				BOOL bDetect_Ice = (byRecvData[INDEX_DATA_1] >> 1) & 0x01;
				BOOL bComp_Movement = (byRecvData[INDEX_DATA_1] >> 2) & 0x01;
				BOOL bMotor_Movement = (byRecvData[INDEX_DATA_1] >> 3) & 0x01;
				BOOL bSOL_Detect = (byRecvData[INDEX_DATA_1] >> 4) & 0x01;
				BOOL bDetect_Cup = (byRecvData[INDEX_DATA_1] >> 5) & 0x01;
				BOOL bCommunication_Mode = (byRecvData[INDEX_DATA_1] >> 6) & 0x01;
				BOOL bFull_Ice = (byRecvData[INDEX_DATA_1] >> 7) & 0x01;

				strErCode.Format(TEXT("콤푸 동작상태 : %d, 기어모터 동작상태 : %d, 출빙 SOL 감지 : %d, 컵레버 감지 : %d, 통신모드 : %d, 만빙 : %d"), (int)bComp_Movement, (int)bMotor_Movement, (int)bSOL_Detect, (int)bDetect_Cup, (int)bCommunication_Mode, (int)bFull_Ice);
				AddLog(RECV, strErCode);


				// DATA2
				BYTE Error_Code = byRecvData[INDEX_DATA_2] & 0x0F;
				int nError_Code = (int)Error_Code;
				//strErCode.AppendFormat(_T("[Error Code] : E%d"), nError_Code);
				//list_box(strErCode);

				switch (nError_Code)
				{
				case 0:
					strErCode.Format(_T("[Error Code] : No Error"));
					break;
				case 1:
					strErCode.Format(_T("[Error Code] : E%d -> 급수부적합"), nError_Code);
					break;
				case 2:
					strErCode.Format(_T("[Error Code] : E%d -> 배수부적합"), nError_Code);
					break;

				case 3:
					strErCode.Format(_T("[Error Code] : E%d -> 분위기온도 저온"), nError_Code);
					break;

				case 4:
					strErCode.Format(_T("[Error Code] : E%d -> 분위기 온도 고온 "), nError_Code);
					break;

				case 5:
					strErCode.Format(_T("[Error Code] : E%d -> Condensor 고온"), nError_Code);

					break;

				case 6:
					strErCode.Format(_T("[Error Code] : E%d -> Evaporator 저온"), nError_Code);

					break;

				case 7:
					strErCode.Format(_T("[Error Code] : E%d -> G/M 부적합"), nError_Code);

					break;

				case 8:
					strErCode.Format(_T("[Error Code] : E%d -> 제빙기능 부적합"), nError_Code);

					break;

				case 9:
					strErCode.Format(_T("[Error Code] : E%d -> 점검주기"), nError_Code);

					break;

				case 12:
					strErCode.Format(_T("[Error Code] : E%d -> I2C 통신 에러"), nError_Code);

					break;

				case 15:
					strErCode.Format(_T("[Error Code] : E%d -> FAN MT 부적합"), nError_Code);

					break;

				default:
					strErCode.Format(_T("[Error Code] : E%d -> 알 수 없는 에러"), nError_Code);


					break;

				}
				AddLog(RECV, strErCode);



			}
			break;

			default:
				break;
			}
		}
	}
}

//BYTE CicemachinecppDlg::Calc_Check(BYTE[] pData, int _nCnt)
BYTE CicemachinecppDlg::Calc_Check(BYTE* pData, int _nCnt)  // checksum 계산하는 함수 
{
	BYTE byCheck = 0x00;
	for (int i = 1; i < _nCnt; i++)
	{
		byCheck ^= pData[i];
	}

	return byCheck;
}






void CicemachinecppDlg::OnBnClickedButtonstaticdataclear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nCnt1 = 0;

	m_bySendData[nCnt1++] = 0x02;  //STX
	m_bySendData[nCnt1++] = 0x01;  // STATUS
	m_bySendData[nCnt1++] = 0xC0;  // COMMAND
	m_bySendData[nCnt1++] = 0x01;  // DATA1
	m_bySendData[nCnt1++] = 0x00;  // DATA2
	m_bySendData[nCnt1++] = Calc_Check(m_bySendData, nCnt1);  // CHECK
	m_bySendData[nCnt1++] = 0x03;  // ETX

	if (m_bConnect == TRUE)
	{

		api_SerialCom_WriteByte(m_iPort, m_bySendData, nCnt1);

		CString strLog1 = _T("");
		strLog1.AppendFormat(_T("[송신데이터: 상태 데이터 클리어]     "));

		for (int i = 0; i < nCnt1; i++)
		{
			strLog1.AppendFormat(_T("%02X  "), m_bySendData[i]);
		}
		AddLog(SEND, strLog1);
	}

}


void CicemachinecppDlg::OnBnClickedButtonReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nCnt2 = 0;

	m_bySendData[nCnt2++] = 0x02; //ETX
	m_bySendData[nCnt2++] = 0x01; //STATUS
	m_bySendData[nCnt2++] = 0xE0; //COMMAND
	m_bySendData[nCnt2++] = 0x00; //DATA1
	m_bySendData[nCnt2++] = 0x00; //DATA2
	m_bySendData[nCnt2++] = Calc_Check(m_bySendData, nCnt2); //CHECK
	m_bySendData[nCnt2++] = 0x03; //ETX

	if (m_bConnect == TRUE)
	{
		api_SerialCom_WriteByte(m_iPort, m_bySendData, nCnt2);  // Queue버퍼에 데이터를 송신하는 함수
		CString strLog2 = _T("");
		strLog2.AppendFormat(_T("[송신데이터: RESET]     "));

		for (int i = 0; i < nCnt2; i++)
		{
			strLog2.AppendFormat(_T("%02X  "), m_bySendData[i]);
		}
		AddLog(SEND, strLog2);
	}
}



void CicemachinecppDlg::OnBnClickedButtonstaticcheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nCnt3 = 0;

	m_bySendData[nCnt3++] = 0x02; //STX
	m_bySendData[nCnt3++] = 0x01; //STATUS
	m_bySendData[nCnt3++] = 0xCF; //COMMAND
	m_bySendData[nCnt3++] = 0x00; //DATA1
	m_bySendData[nCnt3++] = 0x00; //DATA2
	m_bySendData[nCnt3++] = Calc_Check(m_bySendData, nCnt3);  // CHECK
	m_bySendData[nCnt3++] = 0x03; //STX

	if (m_bConnect == TRUE)
	{
		api_SerialCom_WriteByte(m_iPort, m_bySendData, nCnt3);  // Queue버퍼에 데이터를 송신하는 함수
		CString strLog3 = _T("");
		strLog3.AppendFormat(_T("[송신데이터: 상태확인]     "));

		for (int i = 0; i < nCnt3; i++)
		{
			strLog3.AppendFormat(_T("%02X  "), m_bySendData[i]);
		}
		AddLog(SEND, strLog3);
	}

}


void CicemachinecppDlg::OnBnClickedButtonIcewatersetting()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//nout_ice = GetDlgItemInt(IDC_EDIT_ICE);
	//nout_water = GetDlgItemInt(IDC_EDIT_WATER);

	// 출빙
	CString strData = TEXT("");
	GetDlgItemText(IDC_EDIT_ICE, strData);
	double dIce = _wtof(strData);    // CString을 double 형으로 형변환
	int nIce_Sec = (int)(dIce * 10) / 10;
	int nIce_MiliSec = (int)(dIce * 10) % 10;

	// 출수
	CString strData1 = TEXT("");
	GetDlgItemText(IDC_EDIT_WATER, strData1);
	double dWater = _wtof(strData1);    // CString을 double 형으로 형변환
	int nWater_Sec = (int)(dWater * 10) / 10;
	int nWater_MiliSec = (int)(dWater * 10) % 10;


	int nCnt9 = 0;

	m_bySendData[nCnt9++] = 0x02;
	m_bySendData[nCnt9++] = 0x01;
	m_bySendData[nCnt9++] = 0xB0;
	//bySendDataB0[nCnt9++] = (BYTE)(nout_ice << 4);
	m_bySendData[nCnt9++] = (BYTE)(nIce_Sec << 4) + (BYTE)(nIce_MiliSec);
	//bySendDataB0[nCnt9++] = (BYTE)nout_water;
	m_bySendData[nCnt9++] = (BYTE)(nWater_Sec << 4) + (BYTE)(nWater_MiliSec);
	m_bySendData[nCnt9++] = Calc_Check(m_bySendData, nCnt9);
	m_bySendData[nCnt9++] = 0x03;

	if (m_bConnect == TRUE)
	{
		api_SerialCom_WriteByte(m_iPort, m_bySendData, nCnt9);
		CString strLog9 = _T("");
		strLog9.AppendFormat(_T("[송신데이터 : 출빙 출수 설정]     "));

		for (int i = 0; i < nCnt9; i++)
		{
			strLog9.AppendFormat(_T("%02X  "), m_bySendData[i]);
		}
		AddLog(SEND, strLog9);


	}

}


void CicemachinecppDlg::OnBnClickedButtonRead()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 읽기 설정 콤보박스 값 가져오기
	int nIdx6 = m_combo_readset.GetCurSel();

	int nCnt6 = 0;

	int nCnt7 = 0;

	int nCnt8 = 0;

	if (nIdx6 == 0)  // 설정을 Evaporator & Condensor 온도로 했을 경우
	{
		m_bySendData[nCnt6++] = 0x02;  //STX
		m_bySendData[nCnt6++] = 0x01;  //STATUS
		m_bySendData[nCnt6++] = 0xC3;  //COMMAND
		m_bySendData[nCnt6++] = 0x00;  //DATA1
		m_bySendData[nCnt6++] = 0x00;  //DATA2
		m_bySendData[nCnt6++] = Calc_Check(m_bySendData, nCnt6);  //CHECK
		m_bySendData[nCnt6++] = 0x03;  //ETX

		if (m_bConnect == TRUE) {
			api_SerialCom_WriteByte(m_iPort, m_bySendData, nCnt6);

			CString strLog6 = _T("");
			strLog6.AppendFormat(_T("[송신데이터 : 데이터 읽기]     "));

			for (int i = 0; i < nCnt6; i++)
			{
				strLog6.AppendFormat(_T("%02X  "), m_bySendData[i]);
			}
			AddLog(SEND, strLog6);
		}
	}
	else if (nIdx6 == 1) // 설정을 제빙기 온도로 했을 경우
	{
		m_bySendData[nCnt7++] = 0x02; //STX
		m_bySendData[nCnt7++] = 0x01; //STATUS
		m_bySendData[nCnt7++] = 0xC2; //COMMAND
		m_bySendData[nCnt7++] = 0x00; //DATA1
		m_bySendData[nCnt7++] = 0x00; //DATA2
		m_bySendData[nCnt7++] = Calc_Check(m_bySendData, nCnt7); //CHECK
		m_bySendData[nCnt7++] = 0x03; //ETX

		if (m_bConnect == TRUE) {
			api_SerialCom_WriteByte(m_iPort, m_bySendData, nCnt7);

			CString strLog7 = _T("");
			strLog7.AppendFormat(_T("[송신데이터 : 데이터 읽기]     "));

			for (int i = 0; i < nCnt7; i++)
			{
				strLog7.AppendFormat(_T("%02X  "), m_bySendData[i]);
			}
			AddLog(SEND, strLog7);

		}
	}
	else if (nIdx6 == 2) // 설정을 제빙기 온도 설정값으로 했을 경우
	{
		m_bySendData[nCnt8++] = 0x02; //STX
		m_bySendData[nCnt8++] = 0x01; //STATUS
		m_bySendData[nCnt8++] = 0xC1; //COMMAND
		m_bySendData[nCnt8++] = 0x00; //DATA1
		m_bySendData[nCnt8++] = 0x00; //DATA2
		m_bySendData[nCnt8++] = Calc_Check(m_bySendData, nCnt8); //CHECK
		m_bySendData[nCnt8++] = 0x03; //ETX

		if (m_bConnect == TRUE) {
			api_SerialCom_WriteByte(m_iPort, m_bySendData, nCnt8);

			CString strLog8 = _T("");
			strLog8.AppendFormat(_T("[송신데이터 : 데이터 읽기]     "));

			for (int i = 0; i < nCnt8; i++)
			{
				strLog8.AppendFormat(_T("%02X  "), m_bySendData[i]);
			}
			AddLog(SEND, strLog8);
		}

	}
}


void CicemachinecppDlg::OnBnClickedButtonTimeout()
{
	// todo: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nmin_setting = 0;
	int nsec_setting = 0;

	nmin_setting = GetDlgItemInt(IDC_EDIT_MIN);
	nsec_setting = GetDlgItemInt(IDC_EDIT_SEC);

	int nCnt8 = 0;

	m_bySendData[nCnt8++] = 0x02;
	m_bySendData[nCnt8++] = 0x01;
	m_bySendData[nCnt8++] = 0xD0;
	m_bySendData[nCnt8++] = (BYTE)nmin_setting;
	m_bySendData[nCnt8++] = (BYTE)nsec_setting;      // 0~59초를 입력받지만 Hex로 보내짐
	m_bySendData[nCnt8++] = Calc_Check(m_bySendData, nCnt8);
	m_bySendData[nCnt8++] = 0x03;


	if (m_bConnect == TRUE)
	{
		api_SerialCom_WriteByte(m_iPort, m_bySendData, nCnt8);
		CString strLog8 = _T("");
		strLog8.AppendFormat(_T("[송신데이터 : 타임아웃 설정]     "));

		for (int i = 0; i < nCnt8; i++)
		{
			strLog8.AppendFormat(_T("%02X  "), m_bySendData[i]);
		}
		AddLog(SEND, strLog8);
	}


}


void CicemachinecppDlg::OnBnClickedButtonSettingvalue()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nlow_temp = 0;
	int nhigh_temp = 0;

	nlow_temp = GetDlgItemInt(IDC_EDIT_LOWTEMP);
	nhigh_temp = GetDlgItemInt(IDC_EDIT_HIGHTEMP);

	int nCnt10 = 0;

	m_bySendData[nCnt10++] = 0x02;
	m_bySendData[nCnt10++] = 0x01;
	m_bySendData[nCnt10++] = 0xE1;
	m_bySendData[nCnt10++] = (BYTE)nlow_temp;   // 10진수를 16진수로 
	m_bySendData[nCnt10++] = (BYTE)nhigh_temp;
	m_bySendData[nCnt10++] = Calc_Check(m_bySendData, nCnt10);
	m_bySendData[nCnt10++] = 0x03;

	if (m_bConnect == TRUE)
	{
		api_SerialCom_WriteByte(m_iPort, m_bySendData, nCnt10);
		CString strLog10 = _T("");
		strLog10.AppendFormat(_T("[송신데이터 : 분위기 설정값 쓰기]     "));

		for (int i = 0; i < nCnt10; i++)
		{
			strLog10.AppendFormat(_T("%02X  "), m_bySendData[i]);
		}
		AddLog(SEND, strLog10);
	}

}


void CicemachinecppDlg::OnBnClickedButtonReceive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Receive_Data();

}





void CicemachinecppDlg::OnTimer(UINT_PTR nIDEvent)
{
	CDialogEx::OnTimer(nIDEvent);

	switch (nIDEvent)
	{
	case TIMER_DATARECEIVE:
	{
		Receive_Data();
	}
	break;

	default:
		break;
	}


}

// List Box 기본형으로 사용시 함수 사용
void CicemachinecppDlg::list_box(CString strLog)
{
	SYSTEMTIME system;
	GetSystemTime(&system);
	CString strTime = TEXT("");
	strTime.Format(TEXT("%u-%02u-%02u\r %02u:%02u:%02u:%03u   "), system.wYear, system.wMonth, system.wDay, system.wHour + 9, system.wMinute, system.wSecond, system.wMilliseconds);
	m_list_log.AddString(strTime + strLog);
	m_list_log.SetCurSel(m_list_log.GetCount() - 1);
}


// List Box 컬러로 출력 사용시 함수 사용
void CicemachinecppDlg::AddLog(LOGTYPE _logtype, CString _strLog)
{
	CString strTime = TEXT("");
	SYSTEMTIME system;
	GetSystemTime(&system);
	strTime.Format(TEXT("%u-%02u-%02u\r %02u:%02u:%02u:%03u"), system.wYear, system.wMonth, system.wDay, system.wHour + 9, system.wMinute, system.wSecond, system.wMilliseconds);
	//strTime.Format(TEXT("%u-%02u-%02u\r %02u:%02u:%02u"), system.wYear, system.wMonth, system.wDay, system.wHour + 9, system.wMinute, system.wSecond);
	CString strLog = TEXT("");
	COLORREF colorText = COLOR_BLACK;
	switch (_logtype)
	{
	case NONE:
		strLog = strTime + _strLog;
		break;
	case RECV:
		strLog = strTime + TEXT("(RECV)  ");
		strLog += _strLog;
		colorText = COLOR_DKRED;
		break;
	case SEND:
		strLog = strTime + TEXT("(SEND)  ");
		strLog += _strLog;
		colorText = COLOR_BLUE;
		break;
	case ERR:
		strLog = strTime + _strLog;
		colorText = COLOR_RED;
		break;
	default:
		break;
	}

	m_list_log.AddString(strLog, colorText);
	m_list_log.SetCurSel(m_list_log.GetCount() - 1);

	if (m_list_log.GetCount() > 10000)
		m_list_log.DeleteString(0);
}


