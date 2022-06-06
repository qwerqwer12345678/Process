
// TermpDlg.h: 헤더 파일
//

#pragma once
#include "CTypeDB.h"

// CTermpDlg 대화 상자
class CTermpDlg : public CDialogEx
{
// 생성입니다.
public:
	CTermpDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TERMP_DIALOG };
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
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CStatic m_static4;
	CStatic m_static5;
	CStatic m_static6;
	afx_msg void OnBnClickedButton1();
};
