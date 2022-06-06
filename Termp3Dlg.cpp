
// TermpDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Termp.h"
#include "TermpDlg.h"
#include "afxdialogex.h"
#include "CTypeDB.h"
#include "opencv2/opencv.hpp"

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
	DDX_Control(pDX, IDC_PIC, m_pic1);
	DDX_Control(pDX, IDC_SPIN1, m_spin1);
	DDX_Control(pDX, IDC_SPIN2, m_spin2);
	DDX_Control(pDX, IDC_STATIC9, m_static9);
	DDX_Control(pDX, IDC_STATIC10, m_static10);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
}

BEGIN_MESSAGE_MAP(CTermpDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTermpDlg::OnBnClickedButton1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CTermpDlg::OnDeltaposSpin1)
	ON_WM_LBUTTONDOWN()
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
	m_spin1.SetRange(1, 3);

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


bool TF ;
int sheet1 = 0, sheet2 = 0, sheet3 = 0, skcount1 = 0, skcount2 = 0, skcount3 = 0, stcount1 = 0, stcount2 = 0, stcount3 = 0;
void CTermpDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	sheet1 = 0, sheet2 = 0, sheet3 = 0, skcount1 = 0, skcount2 = 0, skcount3 = 0, stcount1 = 0, stcount2 = 0, stcount3 = 0;
	
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
		MessageBox(dlg.GetPathName());

	TF = TypeDB.ReadCSVFile(dlg.GetPathName());
	if (TF == TRUE)
	{
		m_edit1.SetWindowText(_T("월인천강지곡 권상"));
		TypeDB.m_nChar = TypeDB.m_Chars.GetSize();
		CString acount, kcount1, kcount2, tcount;
		int tcount1 = 0, tcount2 = 0, mcount1 = 0, mcount2 = 0;
		int koverlapcount = 0, toverlapcount = 0;

		for (int i = 0; i < TypeDB.m_Chars.GetSize(); i++)
		{
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
			kcount1 = pSCharInfo->m_char;
			mcount1 = pSCharInfo->m_sheet;

			if (mcount1 == 1)
				sheet1++;
			else if (mcount1 == 2)
				sheet2++;
			else if (mcount1 == 3)
				sheet3++;

			for (int j = i - 1; j >= 0; j--)
			{
				if (i == 0)
					break;
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
				{
					toverlapcount++;
					if (pSCharInfo->m_sheet == 1)
						stcount1++;
					else if (pSCharInfo->m_sheet == 2)
						stcount2++;
					else if (pSCharInfo->m_sheet == 3)
						stcount3++;
				}
			}
		}

		for (int i = 1; i < TypeDB.m_Chars.GetSize(); i++)
		{
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
			kcount1 = pSCharInfo->m_char;
			mcount1 = pSCharInfo->m_sheet;

			for (int j = i - 1; j >= 0; j--)
			{
				SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(j);
				kcount2 = pSCharInfo->m_char;
				mcount2 = pSCharInfo->m_sheet;
				if (mcount1 == mcount2 && kcount1 == kcount2)
				{
					if (mcount2 == 1)
						skcount1++;
					else if (mcount2 == 2)
						skcount2++;
					else if (mcount2 == 3)
						skcount3++;
					break;
				}
			}
		}
		
		BeginWaitCursor();
		m_spin1.SetPos(1);

		cv::Mat img = cv::imread("E:\\programing\\월인천강지곡 권상\\01_scan\\001.jpg", cv::ImreadModes::IMREAD_UNCHANGED);
		CDC* pDC;
		CImage* mfcImg = nullptr;
		pDC = m_pic1.GetDC();
		CRect rect;
		m_pic1.GetClientRect(&rect);
		cv::resize(img, img, cv::Size(rect.Width(), rect.Height()));
		BITMAPINFO bitmapInfo;
		//bitmapInfo.bmiHeader.biYPelsPerMeter = 0;
		bitmapInfo.bmiHeader.biBitCount = 24;
		bitmapInfo.bmiHeader.biWidth = img.cols;
		bitmapInfo.bmiHeader.biHeight = -img.rows;
		bitmapInfo.bmiHeader.biPlanes = 1;
		bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bitmapInfo.bmiHeader.biCompression = BI_RGB;
		//bitmapInfo.bmiHeader.biClrImportant = 0;
		//bitmapInfo.bmiHeader.biClrUsed = 0;
		//bitmapInfo.bmiHeader.biSizeImage = 0;
		//bitmapInfo.bmiHeader.biXPelsPerMeter = 0;


		if (img.channels() == 3)
		{
			mfcImg = new CImage();
			mfcImg->Create(img.cols, img.rows, 24);
		}
		else if (img.channels() == 1)
		{
			cv::cvtColor(img, img, cv::COLOR_GRAY2RGB);
			mfcImg = new CImage();
			mfcImg->Create(img.cols, img.rows, 24);
		}
		else if (img.channels() == 4)
		{
			bitmapInfo.bmiHeader.biBitCount = 32;
			mfcImg = new CImage();
			mfcImg->Create(img.cols, img.rows, 32);
		}
		::StretchDIBits(mfcImg->GetDC(), 0, 0, img.cols, img.rows,
			0, 0, img.cols, img.rows, img.data, &bitmapInfo,
			DIB_RGB_COLORS, SRCCOPY);

		mfcImg->BitBlt(::GetDC(m_pic1.m_hWnd), 0, 0);

		CClientDC dc(this);
		CPen penR(PS_SOLID, 1, RGB(255, 0, 0));
		CPen penG(PS_SOLID, 1, RGB(0, 255, 0));
		CBrush brush(NULL_BRUSH);
		
		for (int i = 0; i < TypeDB.m_Chars.GetSize(); i++)
		{
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
			if (pSCharInfo->m_sheet == 1)
			{
				dc.SelectStockObject(NULL_BRUSH);
				dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
				dc.SelectObject(&penG);
				dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
				//pSCharInfo->m_sx, pSCharInfo->m_sy, pSCharInfo->m_width, pSCharInfo->m_height
			}
		}

		acount.Format(_T("%d 개"), TypeDB.m_nChar);
		m_static1.SetWindowText(acount);
		kcount1.Format(_T("%d 종"), TypeDB.m_Chars.GetSize() - koverlapcount);
		m_static2.SetWindowText(kcount1);
		tcount.Format(_T("%d 개"), TypeDB.m_Chars.GetSize() - toverlapcount);
		m_static3.SetWindowText(tcount);

		CString set, set1, set2, set3;
		set1.Format(_T("%d 개"), sheet1);
		m_static4.SetWindowText(set1);
		set2.Format(_T("%d 종"), sheet1 - skcount1);
		m_static5.SetWindowText(set2);
		set3.Format(_T("%d 개"), sheet1 - stcount1);
		m_static6.SetWindowText(set3);

		SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(0);
		dc.SelectStockObject(NULL_BRUSH);
		dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
		dc.SelectObject(&penR);
		dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
		m_static9.SetWindowText(pSCharInfo->m_char);
		set.Format(_T("%d장   %d행   %d번"), pSCharInfo->m_sheet, pSCharInfo->m_line, pSCharInfo->m_order);
		m_static10.SetWindowText(set);

		mfcImg->ReleaseDC();
		delete mfcImg;
		mfcImg = nullptr;
		img.release();
		ReleaseDC(pDC);
		EndWaitCursor();
	}
	else
	{
		MessageBox(_T("읽기 실패"));
		m_edit1.SetWindowText(_T(""));
		m_static1.SetWindowText(_T("- 개"));
		m_static2.SetWindowText(_T("- 개"));
		m_static3.SetWindowText(_T("- 개"));
		m_static4.SetWindowText(_T("- 개"));
		m_static5.SetWindowText(_T("- 개"));
		m_static6.SetWindowText(_T("- 개"));
		m_static9.SetWindowText(_T("유니코드"));
		m_static10.SetWindowText(_T("장   행   번"));
	}
}

int presentPos;
int old_i = 0;

void CTermpDlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	//CPaintDC dc(this);
	//dc.SetMapMode(MM_)

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
//
	CString set, scount1, scount2, scount3;
	presentPos = pNMUpDown->iPos + pNMUpDown->iDelta;

	CClientDC dc(this);
	CPen penG(PS_SOLID, 1, RGB(0, 255, 0));
	CPen penR(PS_SOLID, 1, RGB(255, 0, 0));
	CBrush brush(NULL_BRUSH);

	if (TF == TRUE)
	{
		BeginWaitCursor();
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		cv::Mat img;
		if (presentPos <= 1)
		{
			img = cv::imread("E:\\programing\\월인천강지곡 권상\\01_scan\\001.jpg", cv::ImreadModes::IMREAD_UNCHANGED);
			presentPos = 1;
			scount1.Format(_T("%d 개"), sheet1);
			m_static4.SetWindowText(scount1);
			scount1.Format(_T("%d 종"), sheet1 - skcount1);
			m_static5.SetWindowText(scount1);
			scount1.Format(_T("%d 개"), sheet1 - stcount1);
			m_static6.SetWindowText(scount1);
		}
		else if (presentPos == 2)
		{
			img = cv::imread("E:\\programing\\월인천강지곡 권상\\01_scan\\002.jpg", cv::ImreadModes::IMREAD_UNCHANGED);
			scount2.Format(_T("%d 개"), sheet2);
			m_static4.SetWindowText(scount2);
			scount2.Format(_T("%d 종"), sheet2 - skcount2);
			m_static5.SetWindowText(scount2);
			scount2.Format(_T("%d 개"), sheet2 - stcount2);
			m_static6.SetWindowText(scount2);
		}
		else if (presentPos >= 3)
		{
			img = cv::imread("E:\\programing\\월인천강지곡 권상\\01_scan\\003.jpg", cv::ImreadModes::IMREAD_UNCHANGED);
			presentPos = 3;
			scount3.Format(_T("%d 개"), sheet3);
			m_static4.SetWindowText(scount3);
			scount3.Format(_T("%d 종"), sheet3 - skcount3);
			m_static5.SetWindowText(scount3);
			scount3.Format(_T("%d 개"), sheet3 - stcount3);
			m_static6.SetWindowText(scount3);
		}
		CDC* pDC;
		CImage* mfcImg = nullptr;
		pDC = m_pic1.GetDC();

		CRect rect;
		m_pic1.GetClientRect(&rect);
		cv::resize(img, img, cv::Size(rect.Width(), rect.Height()));

		BITMAPINFO bitmapInfo;
		//bitmapInfo.bmiHeader.biYPelsPerMeter = 0;
		bitmapInfo.bmiHeader.biBitCount = 24;
		bitmapInfo.bmiHeader.biWidth = img.cols;
		bitmapInfo.bmiHeader.biHeight = -img.rows;
		bitmapInfo.bmiHeader.biPlanes = 1;
		bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bitmapInfo.bmiHeader.biCompression = BI_RGB;
		//bitmapInfo.bmiHeader.biClrImportant = 0;
		//bitmapInfo.bmiHeader.biClrUsed = 0;
		//bitmapInfo.bmiHeader.biSizeImage = 0;
		//bitmapInfo.bmiHeader.biXPelsPerMeter = 0;

		if (img.channels() == 3)
		{
			mfcImg = new CImage();
			mfcImg->Create(img.cols, img.rows, 24);
		}
		else if (img.channels() == 1)
		{
			cv::cvtColor(img, img, cv::COLOR_GRAY2RGB);
			mfcImg = new CImage();
			mfcImg->Create(img.cols, img.rows, 24);
		}
		else if (img.channels() == 4)
		{
			bitmapInfo.bmiHeader.biBitCount = 32;
			mfcImg = new CImage();
			mfcImg->Create(img.cols, img.rows, 32);
		}
		::StretchDIBits(mfcImg->GetDC(), 0, 0, img.cols, img.rows,
			0, 0, img.cols, img.rows, img.data, &bitmapInfo,
			DIB_RGB_COLORS, SRCCOPY);

		mfcImg->BitBlt(::GetDC(m_pic1.m_hWnd), 0, 0);

		mfcImg->ReleaseDC();
		delete mfcImg;
		mfcImg = nullptr;
		img.release();
		ReleaseDC(pDC);

		if (presentPos <= 1)
		{
			for (int i = 0; i < TypeDB.m_Chars.GetSize(); i++)
			{
				SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
				if (pSCharInfo->m_sheet == 1)
				{
					dc.SelectStockObject(NULL_BRUSH);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					dc.SelectObject(&penG);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					if (pSCharInfo->m_line == 1 && pSCharInfo->m_order == 1)
					{
						m_static9.SetWindowText(pSCharInfo->m_char);
						set.Format(_T("%d장   %d행   %d번"), pSCharInfo->m_sheet, pSCharInfo->m_line, pSCharInfo->m_order);
						m_static10.SetWindowText(set);
					}
				}
			}
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(0);
			dc.SelectStockObject(NULL_BRUSH);
			dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
			dc.SelectObject(&penR);
			dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
			old_i = 0;
		}
		else if (presentPos == 2)
		{
			for (int i = 0; i < TypeDB.m_Chars.GetSize(); i++)
			{
				SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
				if (pSCharInfo->m_sheet == 2)
				{
					dc.SelectStockObject(NULL_BRUSH);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					dc.SelectObject(&penG);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					if (pSCharInfo->m_line == 1 && pSCharInfo->m_order == 1)
					{
						m_static9.SetWindowText(pSCharInfo->m_char);
						set.Format(_T("%d장   %d행   %d번"), pSCharInfo->m_sheet, pSCharInfo->m_line, pSCharInfo->m_order);
						m_static10.SetWindowText(set);
					}
				}
			}
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(0);
			dc.SelectStockObject(NULL_BRUSH);
			dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
			dc.SelectObject(&penR);
			dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
			old_i = 0;
		}
		else if (presentPos >= 3)
		{
			for (int i = 0; i < TypeDB.m_Chars.GetSize(); i++)
			{
				SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
				if (pSCharInfo->m_sheet == 3)
				{
					dc.SelectStockObject(NULL_BRUSH);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					dc.SelectObject(&penG);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					if (pSCharInfo->m_line == 1 && pSCharInfo->m_order == 1)
					{
						m_static9.SetWindowText(pSCharInfo->m_char);
						set.Format(_T("%d장   %d행   %d번"), pSCharInfo->m_sheet, pSCharInfo->m_line, pSCharInfo->m_order);
						m_static10.SetWindowText(set);
					}
				}
			}
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(0);
			dc.SelectStockObject(NULL_BRUSH);
			dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
			dc.SelectObject(&penR);
			dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
			old_i = 0;
		}

		EndWaitCursor();
	}
	*pResult = 0;
}

void CTermpDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CString set;
	CClientDC dc(this);
	CPen penR(PS_SOLID, 1, RGB(255, 0, 0));
	CPen penG(PS_SOLID, 1, RGB(0, 255, 0));
	CBrush brush(NULL_BRUSH);
//	SCharInfo* ppSCharInfo = TypeDB.m_Chars.GetAt(old_i);
	if (presentPos <= 1)
	{
		SCharInfo* ppSCharInfo = TypeDB.m_Chars.GetAt(old_i);
		for (int i = 0; i < TypeDB.m_Chars.GetSize(); i++)
		{
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
			if (pSCharInfo->m_sheet == 1)
				if ((26 + pSCharInfo->m_sx / 34 <= point.x) && (148 + pSCharInfo->m_sy / 34 <= point.y) && (26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34 >= point.x) && (148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34 >= point.y))
				{
					dc.SelectStockObject(NULL_BRUSH);
					dc.Rectangle(26 + ppSCharInfo->m_sx / 34, 148 + ppSCharInfo->m_sy / 34, 26 + (ppSCharInfo->m_sx + ppSCharInfo->m_width) / 34, 148 + (ppSCharInfo->m_sy + ppSCharInfo->m_height) / 34);
					dc.SelectObject(&penG);
					dc.Rectangle(26 + ppSCharInfo->m_sx / 34, 148 + ppSCharInfo->m_sy / 34, 26 + (ppSCharInfo->m_sx + ppSCharInfo->m_width) / 34, 148 + (ppSCharInfo->m_sy + ppSCharInfo->m_height) / 34);
					dc.SelectStockObject(NULL_BRUSH);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					dc.SelectObject(&penR);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					m_static9.SetWindowText(pSCharInfo->m_char);
					set.Format(_T("%d장   %d행   %d번"), pSCharInfo->m_sheet, pSCharInfo->m_line, pSCharInfo->m_order);
					m_static10.SetWindowText(set);
					old_i = i;
					break;
				}
		}
	}
	else if (presentPos == 2)
	{
		SCharInfo* ppSCharInfo = TypeDB.m_Chars.GetAt(old_i);
		for (int i = 0; i < TypeDB.m_Chars.GetSize(); i++)
		{
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
			if (pSCharInfo->m_sheet == 2)
				if ((26 + pSCharInfo->m_sx / 34 <= point.x) && (148 + pSCharInfo->m_sy / 34 <= point.y) && (26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34 >= point.x) && (148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34 >= point.y))
				{
					dc.SelectStockObject(NULL_BRUSH);
					dc.Rectangle(26 + ppSCharInfo->m_sx / 34, 148 + ppSCharInfo->m_sy / 34, 26 + (ppSCharInfo->m_sx + ppSCharInfo->m_width) / 34, 148 + (ppSCharInfo->m_sy + ppSCharInfo->m_height) / 34);
					dc.SelectObject(&penG);
					dc.Rectangle(26 + ppSCharInfo->m_sx / 34, 148 + ppSCharInfo->m_sy / 34, 26 + (ppSCharInfo->m_sx + ppSCharInfo->m_width) / 34, 148 + (ppSCharInfo->m_sy + ppSCharInfo->m_height) / 34);
					dc.SelectStockObject(NULL_BRUSH);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					dc.SelectObject(&penR);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					m_static9.SetWindowText(pSCharInfo->m_char);
					set.Format(_T("%d장   %d행   %d번"), pSCharInfo->m_sheet, pSCharInfo->m_line, pSCharInfo->m_order);
					m_static10.SetWindowText(set);
					old_i = i;
					break;
				}
		}
	}
	else if (presentPos == 3)
	{
		SCharInfo* ppSCharInfo = TypeDB.m_Chars.GetAt(old_i);
		for (int i = 0; i < TypeDB.m_Chars.GetSize(); i++)
		{
			SCharInfo* pSCharInfo = TypeDB.m_Chars.GetAt(i);
			if (pSCharInfo->m_sheet == 3)
				if ((26 + pSCharInfo->m_sx / 34 <= point.x) && (148 + pSCharInfo->m_sy / 34 <= point.y) && (26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34 >= point.x) && (148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34 >= point.y))
				{
					dc.SelectStockObject(NULL_BRUSH);
					dc.Rectangle(26 + ppSCharInfo->m_sx / 34, 148 + ppSCharInfo->m_sy / 34, 26 + (ppSCharInfo->m_sx + ppSCharInfo->m_width) / 34, 148 + (ppSCharInfo->m_sy + ppSCharInfo->m_height) / 34);
					dc.SelectObject(&penG);
					dc.Rectangle(26 + ppSCharInfo->m_sx / 34, 148 + ppSCharInfo->m_sy / 34, 26 + (ppSCharInfo->m_sx + ppSCharInfo->m_width) / 34, 148 + (ppSCharInfo->m_sy + ppSCharInfo->m_height) / 34);
					dc.SelectStockObject(NULL_BRUSH);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					dc.SelectObject(&penR);
					dc.Rectangle(26 + pSCharInfo->m_sx / 34, 148 + pSCharInfo->m_sy / 34, 26 + (pSCharInfo->m_sx + pSCharInfo->m_width) / 34, 148 + (pSCharInfo->m_sy + pSCharInfo->m_height) / 34);
					m_static9.SetWindowText(pSCharInfo->m_char);
					set.Format(_T("%d장   %d행   %d번"), pSCharInfo->m_sheet, pSCharInfo->m_line, pSCharInfo->m_order);
					m_static10.SetWindowText(set);
					old_i = i;
					break;
				}
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}
