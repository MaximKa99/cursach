// AppDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "App.h"
#include "AppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
//	afx_msg void OnFuncsChangeregister();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_COMMAND(ID_FUNCS_CHANGEREGISTER, &CAboutDlg::OnFuncsChangeregister)
END_MESSAGE_MAP()


// Диалоговое окно CAppDlg



CAppDlg::CAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_APP_DIALOG, pParent)
	, StrOne(_T(""))
	, StrTwo(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR1, StrOne);
	DDX_Text(pDX, IDC_STR2, StrTwo);
	DDX_Control(pDX, IDC_LIST3, list);
}

BEGIN_MESSAGE_MAP(CAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ChgRg, &CAppDlg::OnClickedChgrg)
	ON_BN_CLICKED(IDC_CntNmbs, &CAppDlg::OnClickedCntnmbs)
	ON_BN_CLICKED(IDC_FndCmns, &CAppDlg::OnClickedFndcmns)
	ON_BN_CLICKED(IDC_SORT, &CAppDlg::OnClickedSort)
	ON_BN_CLICKED(IDC_EXIT, &CAppDlg::OnClickedExit)
	ON_COMMAND(ID_FUNCS_CHANGEREGISTER, &CAppDlg::OnFuncsChangeregister)
	ON_COMMAND(ID_FUNCS_SORT, &CAppDlg::OnFuncsSort)
	ON_COMMAND(ID_FUNCS_COUNTNUMBERS, &CAppDlg::OnFuncsCountnumbers)
	ON_COMMAND(ID_FUNCS_FINDCOMMONS, &CAppDlg::OnFuncsFindcommons)
	ON_BN_CLICKED(IDC_SAVE, &CAppDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_LOAD, &CAppDlg::OnBnClickedLoad)
	ON_COMMAND(ID_APP_SAVE, &CAppDlg::OnAppSave)
	ON_COMMAND(ID_APP_LOAD, &CAppDlg::OnAppLoad)
	ON_COMMAND(ID_APP_EXIT32776, &CAppDlg::OnAppExit32776)
END_MESSAGE_MAP()


// Обработчики сообщений CAppDlg

BOOL CAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	this->StrOne = "Stroke1";
	this->StrTwo = "Stroke2";

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	UpdateData(FALSE);

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAppDlg::OnClickedChgrg()
{
	if (!UpdateData()) {
		return;
	}

	this->list.ResetContent();

	CString updatedOne = StrOne;
	CString updatedTwo = StrTwo;

	LPTSTR p1 = updatedOne.GetBuffer(80);

	while (*p1 != 0) {
		if (*p1 >= 65 && *p1 <= 90) {
			*p1 = *p1 + 32;
		} else if (*p1 >= 97 && *p1 <= 122) {
			*p1 = *p1 - 32;
		}

		p1++;
	}

	LPTSTR p2 = updatedTwo.GetBuffer(80);

	while (*p2 != 0) {
		if (*p2 >= 65 && *p2 <= 90) {
			*p2 = *p2 + 32;
		} else if (*p2 >= 97 && *p2 <= 122) {
			*p2 = *p2 - 32;
		}

		p2++;
	}

	StrTwo.ReleaseBuffer();

	this->list.AddString(updatedOne);
	this->list.AddString(updatedTwo);

	UpdateData(FALSE);
}


void CAppDlg::OnClickedCntnmbs()
{
	if (!UpdateData()) {
		return;
	}

	this->list.ResetContent();

	LPTSTR p1 = StrOne.GetBuffer(80);
	LPTSTR p2 = StrTwo.GetBuffer(80);

	int countOne = 0;

	while (*p1 != 0) {

		if (*p1 >= '0' && *p1 <= '9') {
			countOne++;
		}

		p1++;
	}

	int countTwo = 0;

	while (*p2 != 0) {

		if (*p2 >= '0' && *p2 <= '9') {
			countTwo++;
		}

		p2++;
	}

	CString result1;
	CString result2;

	result1.Format(_T("%d"), countOne);
	result2.Format(_T("%d"), countTwo);

	this->list.AddString(result1);
	this->list.AddString(result2);

	UpdateData(FALSE);
}


void CAppDlg::OnClickedFndcmns()
{
	if (!UpdateData()) {
		return;
	}

	this->list.ResetContent();

	CString result;

	LPTSTR p1 = this->StrOne.GetBuffer(80);
	LPTSTR p2 = this->StrTwo.GetBuffer(80);

	while (*p1 != 0 && *p2 != 0) {

		if (*p1 == *p2) {
			result.AppendChar(*p1);
		}

		p1++;
		p2++;
	}

	this->list.AddString(result);

	UpdateData(FALSE);
}

void bubleSort(LPTSTR p, int size) {
	bool success = false;

	while (!success) {
		success = true;

		int i = 0;
		while (i < size - 1) {
			if (*(p + i) > *(p + i + 1)) {
				success = false;
				int temp = *(p + i);

				*(p + i) = *(p + i + 1);
				*(p + i + 1) = temp;
			}


			i++;
		}
	}
}

void CAppDlg::OnClickedSort()
{
	if (!UpdateData()) {
		return;
	}

	this->list.ResetContent();

	CString result1 = this->StrOne;
	CString result2 = this->StrTwo;

	bubleSort(result1.GetBuffer(80), result1.GetLength());
	bubleSort(result2.GetBuffer(80), result2.GetLength());

	result1.ReleaseBuffer();
	result2.ReleaseBuffer();

	this->list.AddString(result1);
	this->list.AddString(result2);

	UpdateData(FALSE);
}

void CAppDlg::OnClickedExit()
{
	this->EndDialog(-1);
}


void CAppDlg::OnFuncsChangeregister()
{
	this->OnClickedChgrg();
}


void CAppDlg::OnFuncsSort()
{
	this->OnClickedSort();
}


void CAppDlg::OnFuncsCountnumbers()
{
	this->OnClickedCntnmbs();
}


void CAppDlg::OnFuncsFindcommons()
{
	this->OnClickedFndcmns();
}


void CAppDlg::OnBnClickedSave()
{
	if (!UpdateData()) {
		return;
	}

	CString strFilePath = _T("./RESULT.TXT");

	CFile theFile(strFilePath, CFile::modeReadWrite | CFile::modeCreate);

	int size = this->list.GetCount();

	for (int i = 0; i < size; i++) {
		CString item;

		this->list.GetText(i, item);

		theFile.Write(item,
			item.GetLength() * sizeof(TCHAR));
		theFile.Write(_T("\n"),
			1 * sizeof(TCHAR));
	}
}


void CAppDlg::OnBnClickedLoad()
{
	if (!UpdateData()) {
		return;
	}

	LPCTSTR pszFilter = 
		_T("Text (*.txt)|*.txt|");

	CFileDialog fileDialog(TRUE, _T("line"), NULL,
		OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, pszFilter, AfxGetMainWnd());

	if (IDOK == fileDialog.DoModal()) {
		CStdioFile file(fileDialog.GetPathName(), CFile::modeRead | CFile::typeText);

		CArray<CString> strokes;

		bool keepReading = true;
		while (keepReading) {
			CString stroke;
			if (file.ReadString(stroke)) {
				strokes.Add(stroke);
			}
			else {
				keepReading = false;
			}
		}

		if (strokes.GetSize() == 2) {
			this->StrOne = strokes.GetAt(0);
			this->StrTwo = strokes.GetAt(1);
			UpdateData(FALSE);
		}
	}
}


void CAppDlg::OnAppSave()
{
	this->OnBnClickedSave();
}


void CAppDlg::OnAppLoad()
{
	this->OnBnClickedLoad();
}


void CAppDlg::OnAppExit32776()
{
	this->OnClickedExit();
}
