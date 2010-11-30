/////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2010 Vitali Yemialyanchyk
//
// Distributed under license by Vitali Yemialyanchyk. All rights reserved.
// This program is made available under the terms of the
// MIT License, which accompanies this distribution,
// and is available at http://www.opensource.org/licenses/mit-license.php
//
// Contributor:
//   Vitali Yemialyanchyk - initial API and implementation
//     developer of http://www.stopka.us -> StopKa file manager & desktop search tool
/////////////////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "HttpGetRequest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool WINAPI ReadCallbackFunc( DWORD dwBytesSent, DWORD_PTR dwParam )
{
	return true;
}

HttpGetRequest::HttpGetRequest( const String& userAgent ) : m_userAgent(userAgent)
{
	//m_client.SetProxy( _T("myproxyserver"), 80 );
	// This disables auxiliary processing such as
	// the automatic handling of redirected URLs
	// and authorization of protected URLs.
	m_navData.RemoveFlags( ATL_HTTP_FLAG_PROCESS_RESULT );
	// This restores the default behavior
	//m_navData.AddFlags( ATL_HTTP_FLAG_PROCESS_RESULT );
	m_navData.SetReadStatusCallback( ReadCallbackFunc, 0 );
}

HttpGetRequest::~HttpGetRequest()
{
}

void HttpGetRequest::request( const String& urlString )
{
	m_client.Navigate( urlString.c_str(), &m_navData );
}
