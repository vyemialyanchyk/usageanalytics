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

#pragma once

#include "IHttpGetRequest.h"

class HttpGetRequest : public IHttpGetRequest
{
protected:
	String m_userAgent;
	//
	CAtlHttpClient m_client;
	//
	CAtlNavigateData m_navData;
public:
	HttpGetRequest( const String& userAgent );
	virtual ~HttpGetRequest();
	//
	void request( const String& urlString );
};
