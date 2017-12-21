google analitics for C++ desktop applications

The project includes a sources of library that provide capability to anonymously reports information back to the library user. The library was developed using C++ as a basic language. The main intention of the library is a use in the desktop applications. StopKa file manager & desktop search tool (http://www.stopka.us) is an example application which is track it's usage using the library.

usageanalytics => Automatically exported from code.google.com/p/usageanalytics

library use example:

UsageReport::UsageReport( IApplicationPreferences* pAppPrefs ) : m_pAppPrefs(pAppPrefs)
{
	m_pStopKaEnvironment = CUsageActivator::getInstance().getStopKaEnvironment( m_pAppPrefs );
	m_pApplicationEnvironment = CUsageActivator::getInstance().getApplicationEnvironment();
	m_pGoogleAnalyticsParameters = CUsageActivator::getInstance().getGoogleAnalyticsParameters();
	m_pFocusPoint = new SuffixFocusPoint( _T("StopKa"), m_pStopKaEnvironment->getStopKaVersion() );
	IFocusPoint* pFocusPoint = 0;
	pFocusPoint = m_pFocusPoint->setChild( new FocusPoint( _T("usageanalytics") ) );
	pFocusPoint = pFocusPoint->setChild( new FocusPoint( _T("startup") ) );
	pFocusPoint = pFocusPoint->setChild( new FocusPoint( _T("1.5.0.160310") ) );
}
