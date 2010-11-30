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
#include "IFocusPoint.h"
#include "IURLBuildingStrategy.h"
#include "HttpGetRequest.h"
#include "Tracker.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Tracker::Tracker( IURLBuildingStrategy* pUrlBuildingStrategy, const String& userAgent )
{
	m_pHttpRequest = new HttpGetRequest( userAgent );
	m_pUrlBuildingStrategy = pUrlBuildingStrategy;
}

Tracker::~Tracker()
{
	if( m_pHttpRequest )
	{
		delete m_pHttpRequest;
		m_pHttpRequest = 0;
	}
}

void Tracker::trackSynchronously( IFocusPoint* pFocusPoint )
{
	m_pHttpRequest->request( getTrackingUrl( pFocusPoint ) );
}

void Tracker::trackAsynchronously( IFocusPoint* pFocusPoint )
{
	m_pHttpRequest->request( getTrackingUrl( pFocusPoint ) );
}

String Tracker::getTrackingUrl( IFocusPoint* pFocusPoint )
{
	return m_pUrlBuildingStrategy->build( pFocusPoint );
}
