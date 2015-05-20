// TabSheet.cpp : implementation file
//

#include "stdafx.h"
#include "TabSheet.h"


// CTabSheet

IMPLEMENT_DYNAMIC(CTabSheet, CTabCtrl)

	CTabSheet::CTabSheet()
{
	m_nNumOfPages = 0;
	m_nCurrentPage = 0;

}

CTabSheet::~CTabSheet()
{
}


BEGIN_MESSAGE_MAP(CTabSheet, CTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CTabSheet::OnTcnSelchange)
END_MESSAGE_MAP()



// CTabSheet message handlers



BOOL CTabSheet::AddPage(CString szTitle, CDialog * pDialog, UINT ID)
{
	if (MAX_PAGES == m_nNumOfPages){
		return FALSE;
	}
	m_pPages[m_nNumOfPages] = pDialog;
	m_IDD[m_nNumOfPages] = ID;
	m_Title[m_nNumOfPages] = szTitle;

	InsertItem(m_nNumOfPages, szTitle);

	CRect innerRect = GetInnerRect();
	m_pPages[m_nNumOfPages]->Create(ID, this);
	m_pPages[m_nNumOfPages]->SetParent(this);
	m_pPages[m_nNumOfPages]->MoveWindow(&innerRect);

	if (m_nCurrentPage ==0 && m_nNumOfPages == 0) {
		m_pPages[m_nNumOfPages]->ShowWindow(SW_NORMAL);
	}else{
		m_pPages[m_nNumOfPages]->ShowWindow(SW_HIDE);
	}

	m_nNumOfPages++;
	return TRUE;
}

void CTabSheet::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	if (m_nCurrentPage != GetCurFocus()){
		m_pPages[m_nCurrentPage]->ShowWindow(SW_HIDE);
		m_nCurrentPage = GetCurFocus();
		m_pPages[m_nCurrentPage]->ShowWindow(SW_SHOW);
	}

	*pResult = 0;
}


CRect CTabSheet::GetInnerRect(void)
{
	CRect tabRect, itemRect;
	int nX = 0, nY = 0, nXc = 0, nYc = 0;
	UINT nCount = 0;

	GetClientRect(&tabRect);
	GetItemRect(0, &itemRect);
	nX = itemRect.left;
	nY = itemRect.bottom + 1;
	nXc = tabRect.right - 3;
	nYc = tabRect.bottom - 2;

	return CRect(nX,nY,nXc,nYc);
}
