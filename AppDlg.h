
// AppDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CAppDlg
class CAppDlg : public CDialogEx
{
// Создание
public:
	CAppDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Strokes;
	afx_msg void OnClickedChgrg();
	afx_msg void OnClickedCntnmbs();
	afx_msg void OnClickedFndcmns();
	afx_msg void OnClickedSort();
	CString results;
	CString StrOne;
	CString StrTwo;
	CListBox list;
	afx_msg void OnClickedExit();
	afx_msg void OnFuncsChangeregister();
	afx_msg void OnFuncsSort();
	afx_msg void OnFuncsCountnumbers();
	afx_msg void OnFuncsFindcommons();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnAppSave();
	afx_msg void OnAppLoad();
	afx_msg void OnAppExit32776();
};
