
// TermDlg.h: 헤더 파일
//

#pragma once
#include "afxwin.h"

struct SCharInfo
{
	CString m_char;
	int m_type, m_sheet, m_sx, m_sy, m_line, m_order, m_width, m_height;

	SCharInfo()
	{
		m_char.Empty();
	}
};

// CTermDlg 대화 상자
class CTermDlg : public CDialogEx
{
// 생성입니다.
public:
	CTermDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
public:
	CArray<SCharInfo*, SCharInfo*> m_Chars;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TERM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	void RemoveAll();

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
	afx_msg void OnBnClickedButton1();
	CStatic m_static1;
	afx_msg void OnEnChangeEdit1();
};
