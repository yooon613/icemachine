
// icemachine.cppDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "ColorListBox.h"

#define TIMER_DATARECEIVE		1000

#define INDEX_STX				0
#define INDEX_STATUS			1
#define INDEX_COMMAND			2
#define INDEX_DATA_1			3
#define INDEX_DATA_2			4
#define INDEX_CHECK				5
#define INDEX_ETX				6

#define COMMAND_TEMP_SET_READ		0xC1
#define COMMAND_TEMP_READ           0xC2
#define COMMAND_EC_TEMP_READ        0XC3
#define COMMAND_ICE_OUT_TIMEOUT     0xD0
#define COMMAND_RESET               0xE0
#define COMMAND_SET_VALUE_READ      0XE1
#define COMMAND_STATIC_CHECK        0xCF


#define					COLOR_BLACK												RGB(0, 0, 0)
#define					COLOR_DKRED												RGB(128, 0, 0)
#define					COLOR_BLUE												RGB(0, 0, 255)
#define					COLOR_RED												RGB(255, 0, 0)


enum LOGTYPE
{
	NONE = 0,
	RECV,
	SEND,
	ERR
};

// CicemachinecppDlg 대화 상자
class CicemachinecppDlg : public CDialogEx
{
// 생성입니다.
public:
	CicemachinecppDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ICEMACHINECPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnDestroy();
	CComboBox m_combo_port;
	CComboBox m_combo_parity;
	CComboBox m_combo_baudrate;
	CComboBox m_combo_databit;
	CComboBox m_combo_stopbit;
	CComboBox m_combo_modeset;
	CComboBox m_combo_readset;
	CButton m_butt_connection;
	CButton m_butt_close;
	CButton m_butt_modeset;
	CButton m_butt_dataclear;
	CButton m_butt_reset;
	CButton m_butt_statecheck;
	CButton m_butt_icewaterset;
	CButton m_butt_read;
	CButton m_butt_timeout;
	CButton m_butt_settingvalue;
	CButton m_butt_receive;
	CButton m_check_box_TIMER;
	CStatic m_stat_port;
	CStatic m_stat_parity;
	CStatic m_stat_baudrate;
	CStatic m_stat_databit;
	CStatic m_stat_stopbit;
	CStatic m_stat_modeset;
	CStatic m_stat_iceout;
	CStatic m_stat_waterout;
	CStatic m_stat_readset;
	CStatic m_stat_minset;
	CStatic m_stat_secset;
	CStatic m_stat_lowtemp;
	CStatic m_stat_hightemp;
	CEdit m_edit_control_ice;
	CEdit m_edit_control_water;
	CEdit m_edit_control_min;
	CEdit m_edit_control_sec;
	CEdit m_edit_control_lowtemp;
	CEdit m_edit_control_hightemp;
	CColorListBox m_list_log;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	

	double m_dRange1 = 0.0;
	double m_dRange2 = 0.0;
	int m_dRange3 = 0;
	int m_dRange4 = 0;
	int m_dRange5 = 40;

	afx_msg void OnBnClickedButtonconnection();
	afx_msg void OnBnClickedButtonclose();
	afx_msg void OnBnClickedButtonmodesetting();
	afx_msg void OnBnClickedButtonstaticdataclear();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonstaticcheck();
	afx_msg void OnBnClickedButtonIcewatersetting();
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedButtonTimeout();
	afx_msg void OnBnClickedButtonSettingvalue();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonReceive();
	int m_iPort = 0;

	BYTE m_bySendData[100] = { 0x00, };
	BOOL m_bConnect = FALSE;

	BYTE Calc_Check(BYTE* pData, int _nCnt);

	void list_box(CString strLog);
	BOOL Message_Check(BYTE* pRecvData, int _nRecvCnt);
	void Receive_Data();
	void AddLog(LOGTYPE _logtype, CString _strLog);
	
};
