#ifndef CCASCARON_FRAME_H
#define CCASCARON_FRAME_H

int x = 0, y = 9;
BOOL flag = false;

class CCascaron_Frame: public CFrameWnd{ //clase marco
    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT, CPoint);
    afx_msg void OnChar(UINT);
    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CCascaron_Frame, CFrameWnd)
    ON_WM_CHAR()
    ON_WM_LBUTTONDOWN()
    ON_WM_PAINT()
END_MESSAGE_MAP()

#endif