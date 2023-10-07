// HelloBangSeeDlg.h : header file
//

#if !defined(AFX_HELLOBANGSEEDLG_H__430B2E66_E978_4F9E_B9F1_B1A1B488AA9F__INCLUDED_)
#define AFX_HELLOBANGSEEDLG_H__430B2E66_E978_4F9E_B9F1_B1A1B488AA9F__INCLUDED_
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "signal.h"
#include "win32cond.h"
#include <wincrypt.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHelloBangSeeDlg dialog

class CHelloBangSeeDlg : public CDialog
{
// Construction
public:
	CHelloBangSeeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHelloBangSeeDlg)
	enum { IDD = IDD_HELLOBANGSEE_DIALOG };
	CEdit	m_Bangla;
	CString	m_English;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelloBangSeeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHelloBangSeeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELLOBANGSEEDLG_H__430B2E66_E978_4F9E_B9F1_B1A1B488AA9F__INCLUDED_)
