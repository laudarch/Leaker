#include "MenuViewWnd.h"


void MenuViewWnd::init(){
	
	paintManager_.AddMessageFilter(this);

}


LRESULT MenuViewWnd::MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled){

	switch(uMsg)
	{
	case WM_KILLFOCUS:
		onKillFocus(uMsg,wParam,lParam);
		bHandled = true;
		break;
	case WM_KEYDOWN:
		onKeyDown(uMsg,wParam,lParam);
		bHandled = true;
		break;
	default:
		bHandled = false;
	}
	return 0L;
}

LRESULT MenuViewWnd::onKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam){
	
	if(m_hWnd != (HWND) wParam ){
		owner_->disableMenuActive();
		PostMessage(WM_CLOSE);
	}
    return 0;
}

LRESULT MenuViewWnd::onKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam){
	if( wParam == VK_ESCAPE ){
		owner_->disableMenuActive();
		Close();
	}
    return 0;
}