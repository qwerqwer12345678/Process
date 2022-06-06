
// TermpDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Termp.h"
#include "TermpDlg.h"
#include "afxdialogex.h"
#include "CTypeDB.h"

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


// CTermpDlg 대화 상자



CTermpDlg::CTermpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TERMP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CTermpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_STATIC3, m_static3);
	DDX_Control(pDX, IDC_STATIC4, m_static4);
	DDX_Control(pDX, IDC_STATIC5, m_static5);
	DDX_Control(pDX, IDC_STATIC6, m_static6);
}

BEGIN_MESSAGE_MAP(CTermpDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTermpDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTermpDlg 메시지 처리기

BOOL CTermpDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTermpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTermpDlg::OnPaint()
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
HCURSOR CTermpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTermpDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CTypeDB TypeDB;
	TypeDB.ReadCSVFile();
	CString acount, kcount1, kcount2, tcount;
	int tcount1, tcount2;
	
	//	GetDlgItem(IDC_STATIC2)->SetWindowText(str);
	
	int koverlapcount = 0;
	int toverlapcount = 0;
	for (int i = 1; i < TypeDB.m_Chars.GetSize(); i++)
	{
		SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
		kcount1 = pSCharInfo->m_char;
		for (int j = i - 1; j >= 0; j--)
		{
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(j);
			kcount2 = pSCharInfo->m_char;
			if (kcount1 == kcount2)
			{
				koverlapcount++;
				break;
			}
		}
	}
	for (int i = 1; i < TypeDB.m_Chars.GetSize(); i++)
	{
		SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
		kcount1 = pSCharInfo->m_char;
		tcount1 = pSCharInfo->m_type;
		for (int j = i - 1; j >= 0; j--)
		{
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(j);
			kcount2 = pSCharInfo->m_char;
			tcount2 = pSCharInfo->m_type;
			if (kcount1 == kcount2 && tcount1 == tcount2)
					toverlapcount++;
		}
	}

	acount.Format(_T("%d 개"), TypeDB.m_Chars.GetSize());
	m_static1.SetWindowText(acount);

	kcount1.Format(_T("%d 종"), TypeDB.m_Chars.GetSize() - koverlapcount);
	m_static2.SetWindowText(kcount1);

	tcount.Format(_T("%d 개"), TypeDB.m_Chars.GetSize() - toverlapcount);
	m_static3.SetWindowText(tcount);




		//SCharInfo* ppSCharInfo = TypeDB.m_Chars.GetAt(2);
		//SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(1);
		//m_static1.SetWindowText(pSCharInfo->m_char);

		//str2 = pSCharInfo->m_char;
		//m_static1.SetWindowText(str2);
		// 
		//str3 = ppSCharInfo->m_char;
		//m_static2.SetWindowText(str3);

		//str1.Format(_T("%d"), TypeDB.m_Chars.GetSize());
		//m_static1.SetWindowText(str1); -- 전체글자수 세기
		// 
		//str.Format(_T("%d"), pSCharInfo->m_type);
		//GetDlgItem(IDC_STATIC2)->SetWindowText(str); -- 인트형 파싱 확인

}
