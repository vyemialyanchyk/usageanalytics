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

#include "ITracker.h"

class IURLBuildingStrategy;
class IHttpGetRequest;

// Reports (tracks) usage
// @see based on <a
//      href="http://jgoogleAnalytics.googlecode.com">http://jgoogleAnalytics
//      .googlecode.com</a>
class Tracker : public ITracker
{
protected:
	IURLBuildingStrategy* m_pUrlBuildingStrategy;
	IHttpGetRequest* m_pHttpRequest;
public:
	Tracker( IURLBuildingStrategy* pUrlBuildingStrategy, const String& userAgent );
	virtual ~Tracker();

	void trackSynchronously( IFocusPoint* pFocusPoint );

	void trackAsynchronously( IFocusPoint* pFocusPoint );

	String getTrackingUrl( IFocusPoint* pFocusPoint );
};
