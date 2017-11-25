// Tree.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_ActiveX.h"
#include "Tree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTree dialog


CTree::CTree(CWnd* pParent /*=NULL*/) : CDialog(CTree::IDD, pParent){
	//{{AFX_DATA_INIT(CTree)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTree::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTree)
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTree, CDialog)
	//{{AFX_MSG_MAP(CTree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTree message handlers

BOOL CTree::OnInitDialog(){
	CDialog::OnInitDialog();
    CTreeCtrl *tree =NULL;
    RECT rt = {100, 100, 200, 200};
    //tree->Create(WS_VISIBLE|WS_CHILD|WS_BORDER|WS_TABSTOP|TVS_HASLINES|TVS_HASBUTTONS|TVS_SINGLEEXPAND, CRect(&rt), this, IDC_TREE1);
    HTREEITEM raiz, sub, h;
    //m_Tree.Create(WS_VISIBLE|WS_CHILD|WS_BORDER|WS_TABSTOP|TVS_HASLINES|TVS_HASBUTTONS|TVS_SINGLEEXPAND, rt, this, IDC_TREE1); 

    //m_Tree.GetTreeCtrl();
    raiz = m_Tree.InsertItem("Simpson");
    sub = m_Tree.InsertItem("Jaqueline", raiz);
    h = raiz;
    raiz = m_Tree.InsertItem("Marge", sub);
    sub = m_Tree.InsertItem("Bart", raiz);
    sub = m_Tree.InsertItem("Lisa", raiz);
    sub = m_Tree.InsertItem("Maggie", raiz);
    raiz = h;
    sub = m_Tree.InsertItem("Abraham", raiz);
    raiz = m_Tree.InsertItem("Homero", sub);
    sub = m_Tree.InsertItem("Bart", raiz);
    sub = m_Tree.InsertItem("Lisa", raiz);
    sub = m_Tree.InsertItem("Maggie", raiz);
	//HTREE
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
