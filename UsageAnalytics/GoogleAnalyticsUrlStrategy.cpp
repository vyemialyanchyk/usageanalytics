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
#include "IURLBuildingStrategy.h"
#include "IGoogleAnalyticsParameters.h"
#include "GoogleAnalyticsUrlStrategy.h"
#include "GoogleAnalyticsCookie.h"
#include "IFocusPoint.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

String GoogleAnalyticsUrlStrategy::TRACKING_URL = _T("http://www.google-analytics.com/__utm.gif");

GoogleAnalyticsUrlStrategy::GoogleAnalyticsUrlStrategy( IGoogleAnalyticsParameters* pGoogleAnalyticsParameters ) :
	m_pGoogleParameters(pGoogleAnalyticsParameters)
{
	srand( (unsigned)time( 0 ) );
}

GoogleAnalyticsUrlStrategy::~GoogleAnalyticsUrlStrategy()
{
}

String GoogleAnalyticsUrlStrategy::build( IFocusPoint* focusPoint )
{
	String builder( TRACKING_URL );
	builder += IGoogleAnalyticsParameters::URL_PARAM_DELIMITER;
	appendParameter( IGoogleAnalyticsParameters::PARAM_TRACKING_CODE_VERSION,
		IGoogleAnalyticsParameters::VALUE_TRACKING_CODE_VERSION, builder) ;
	appendParameter( IGoogleAnalyticsParameters::PARAM_UNIQUE_TRACKING_NUMBER, getRandomNumber(), builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_HOST_NAME, m_pGoogleParameters->getHostname(), builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_LANGUAGE_ENCODING,
		IGoogleAnalyticsParameters::VALUE_ENCODING_UTF8, builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_SCREEN_RESOLUTION, m_pGoogleParameters->getScreenResolution(),
		builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_SCREEN_COLOR_DEPTH, m_pGoogleParameters->getScreenColorDepth(),
		builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_BROWSER_LANGUAGE, m_pGoogleParameters->getBrowserLanguage(),
		builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_PAGE_TITLE, focusPoint->getTitle(), builder );
	//appendParameter( IGoogleAnalyticsParameters::PARAM_HID, getRandomNumber(), builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_FLASH_VERSION, m_pGoogleParameters->getFlashVersion(), builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_REFERRAL, m_pGoogleParameters->getReferral(), builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_PAGE_REQUEST, focusPoint->getURI(), builder );

	appendParameter( IGoogleAnalyticsParameters::PARAM_ACCOUNT_NAME, m_pGoogleParameters->getAccountName(), builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_COOKIES, getCookies(), builder );
	appendParameter( IGoogleAnalyticsParameters::PARAM_GAQ, _T("1"), false, builder );

	// update visit timestamps and count
	m_pGoogleParameters->visit();

	return builder;
}

String GoogleAnalyticsUrlStrategy::getCookies()
{
	String builder;
	String param;
	// unique visitor id cookie has to be unique per eclipse installation
	//String timeStamp = _T("-1");
	// //String.valueOf( System.currentTimeMillis() );

	param = _T("");
	param += _T("999.");
	param += m_pGoogleParameters->getUserId() + IGoogleAnalyticsParameters::DOT;
	param += m_pGoogleParameters->getFirstVisit() + IGoogleAnalyticsParameters::DOT;
	param += m_pGoogleParameters->getLastVisit() + IGoogleAnalyticsParameters::DOT;
	param += m_pGoogleParameters->getCurrentVisit() + IGoogleAnalyticsParameters::DOT;
	param += UIntToString( m_pGoogleParameters->getVisitCount() );
	param += IGoogleAnalyticsParameters::SEMICOLON;
	GoogleAnalyticsCookie gac1( IGoogleAnalyticsParameters::PARAM_COOKIES_UNIQUE_VISITOR_ID,
		param, IGoogleAnalyticsParameters::PLUS_SIGN );
	gac1.appendTo( builder );

	param = _T("");
	param += _T("999.");
	param += m_pGoogleParameters->getFirstVisit() + IGoogleAnalyticsParameters::DOT;
	param += _T("1.1.");
	GoogleAnalyticsCookie gac2( IGoogleAnalyticsParameters::PARAM_COOKIES_REFERRAL_TYPE, param );
	gac2.appendTo( builder );

	// new
	/** /
	param = _T("");
	param += _T("1");
	GoogleAnalyticsCookie gac3( IGoogleAnalyticsParameters::PARAM_COOKIES_SESSION, param, 
		IGoogleAnalyticsParameters::SEMICOLON, IGoogleAnalyticsParameters::PLUS_SIGN );
	gac3.appendTo( builder );
	/**/
	// new
	/** /
	param = _T("");
	param += _T("1");
	GoogleAnalyticsCookie gac4( IGoogleAnalyticsParameters::PARAM_COOKIES_BROWSERSESSION, param, 
		IGoogleAnalyticsParameters::SEMICOLON, IGoogleAnalyticsParameters::PLUS_SIGN );
	gac4.appendTo( builder );
	/**/

	param = _T("");
	param += _T("(direct)");
	GoogleAnalyticsCookie gac5( IGoogleAnalyticsParameters::PARAM_COOKIES_UTMCSR, param, IGoogleAnalyticsParameters::PIPE );
	gac5.appendTo( builder );

	param = _T("");
	param += _T("(direct)");
	GoogleAnalyticsCookie gac6( IGoogleAnalyticsParameters::PARAM_COOKIES_UTMCCN, param, IGoogleAnalyticsParameters::PIPE );
	gac6.appendTo( builder );

	param = _T("");
	param += _T("(none)");
	GoogleAnalyticsCookie gac7( IGoogleAnalyticsParameters::PARAM_COOKIES_UTMCMD, param, IGoogleAnalyticsParameters::PIPE );
	gac7.appendTo( builder );

	param = m_pGoogleParameters->getKeyword();
	GoogleAnalyticsCookie gac8( IGoogleAnalyticsParameters::PARAM_COOKIES_KEYWORD, param, IGoogleAnalyticsParameters::PIPE );
	gac8.appendTo( builder );

	// <tt>User defined Value<tt> cookie format: (domain hash).(setvar value)
	// 
	// @see <a
	//      href="http://www.martynj.com/google-analytics-cookies-tracking-multiple-domains-filters">__utmv,
	//      __utmb, __utmc cookies formats and more</a>
	param = getRandomNumber();
	param += IGoogleAnalyticsParameters::DOT;
	param += m_pGoogleParameters->getUserDefined();
	GoogleAnalyticsCookie gac9( IGoogleAnalyticsParameters::PARAM_COOKIES_USERDEFINED, param );
	gac9.appendTo( builder );

	builder += IGoogleAnalyticsParameters::SEMICOLON;

	return builder;
}

String GoogleAnalyticsUrlStrategy::getRandomNumber()
{
	return UIntToString( (unsigned int)( rand() ) );
}

void GoogleAnalyticsUrlStrategy::appendParameter( const String& name, const String& val, String& builder )
{
	appendParameter( name, val, true, builder );
}

void GoogleAnalyticsUrlStrategy::appendParameter( const String& name, const String& val, 
	bool appendAmpersand, String& builder )
{
	builder += name;
	builder += IGoogleAnalyticsParameters::EQUALS_SIGN;
	builder += val;
	if( appendAmpersand )
	{
		builder += IGoogleAnalyticsParameters::AMPERSAND;
	}
}
