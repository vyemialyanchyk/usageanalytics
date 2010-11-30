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

#include "IURLBuildingStrategy.h"

class IGoogleAnalyticsParameters;

// Class that builds an URL that passes given parameters to google analytics
// @see <a
//      href="http://code.google.com/apis/analytics/docs/tracking/gaTrackingTroubleshooting.html#gifParameters">GIF
//      Request Parameters</a>
// @see <a
//      href="http://code.google.com/apis/analytics/docs/concepts/gaConceptsCookies.html#cookiesSet">Cookies
//      Set By Google Analytics</a>
// @see <a
//      href="http://www.morevisibility.com/analyticsblog/from-__utma-to-__utmz-google-analytics-cookies.html">From
//      __utma to __utmz (Google Analytics Cookies)</a>
class GoogleAnalyticsUrlStrategy : public IURLBuildingStrategy
{
protected:
	static String TRACKING_URL;
	//
	IGoogleAnalyticsParameters* m_pGoogleParameters;
public:
	GoogleAnalyticsUrlStrategy( IGoogleAnalyticsParameters* pGoogleAnalyticsParameters );

	virtual ~GoogleAnalyticsUrlStrategy();

	String build( IFocusPoint* focusPoint );

	// Returns the google analytics cookies. These cookies determines user
	// identity, session identity etc.
	// 
	// @return the cookies
	// 
	// @see <a
	//      href="http://www.analyticsexperts.com/google-analytics/information-about-the-utmlinker-and-the-__utma-__utmb-and-__utmc-cookies/">Information
	//      about the utmLinker and the __utma, __utmb and __utmc cookies</a>
	// @see <a
	//      href="http://www.martynj.com/google-analytics-cookies-tracking-multiple-domains-filters">cookie
	//      values and formats</a>
	String getCookies();

	String getRandomNumber();

	void appendParameter( const String& name, const String& val, String& builder );

	void appendParameter( const String& name, const String& val, bool appendAmpersand, String& builder );
};
