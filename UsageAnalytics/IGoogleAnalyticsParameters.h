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

// An interface that provides methods for all parameters that google analytics needs to know about.
// @see <a
//      href="http://code.google.com/apis/analytics/docs/tracking/gaTrackingTroubleshooting.html#gifParameters">GIF
//      Request Parameters</a>
class IGoogleAnalyticsParameters
{
public:
	IGoogleAnalyticsParameters();
	virtual ~IGoogleAnalyticsParameters();
public:
	//
	static CharType AMPERSAND;
	static CharType EQUALS_SIGN;
	static CharType URL_PARAM_DELIMITER;
	static CharType PLUS_SIGN;
	static CharType DOT;
	static CharType SEMICOLON;
	static CharType PIPE;

	static String PARAM_HID;
	static String PARAM_PAGE_REQUEST;
	static String PARAM_ACCOUNT_NAME;
	static String PARAM_HOST_NAME;
	static String PARAM_COOKIES;
	static String PARAM_COOKIES_UNIQUE_VISITOR_ID;
	static String PARAM_COOKIES_SESSION;
	static String PARAM_COOKIES_BROWSERSESSION;
	static String PARAM_COOKIES_REFERRAL_TYPE;
	static String PARAM_COOKIES_UTMCSR;
	static String PARAM_COOKIES_UTMCCN;
	static String PARAM_COOKIES_UTMCMD;
	static String PARAM_COOKIES_KEYWORD;
	static String PARAM_COOKIES_USERDEFINED;

	static String PARAM_REFERRAL;
	static String PARAM_TRACKING_CODE_VERSION;
	static String PARAM_UNIQUE_TRACKING_NUMBER;
	static String PARAM_LANGUAGE_ENCODING;
	static String PARAM_SCREEN_RESOLUTION;
	static String PARAM_SCREEN_COLOR_DEPTH;
	static String PARAM_PRODUCT_NAME;
	static String PARAM_PRODUCT_CODE;
	static String PARAM_FLASH_VERSION;
	static String PARAM_BROWSER_LANGUAGE;
	static String PARAM_REPEAT_CAMPAIGN_VISIT;
	static String PARAM_PAGE_TITLE;
	static String PARAM_GAQ;
	static String PARAM_AD_CONTENT;

	static String VALUE_TRACKING_CODE_VERSION;
	static String VALUE_NO_REFERRAL;
	static String VALUE_ENCODING_UTF8;

	static String SCREERESOLUTION_DELIMITER;
	static String SCREENCOLORDEPTH_POSTFIX;

public:

	virtual String getAccountName() = 0;

	virtual String getReferral() = 0;

	virtual String getScreenResolution() = 0;

	virtual String getScreenColorDepth() = 0;

	virtual String getBrowserLanguage() = 0;

	virtual String getHostname() = 0;

	virtual String getUserAgent() = 0;

	virtual String getUserId() = 0;

	virtual String getKeyword() = 0;

	virtual String getFirstVisit() = 0;

	virtual String getLastVisit() = 0;

	virtual String getCurrentVisit() = 0;

	virtual unsigned long getVisitCount() = 0;

	// Signals that a visit was executed. The
	// consequence is that visit timestamps and visit counters get updated
	// @see #getLastVisit()
	// @see #getCurrentVisit()
	// @see #getVisitCount()
	virtual void visit() = 0;

	virtual String getFlashVersion() = 0;

	// Returns a user defined value that may be queried in Google Analytics.
	// @return a user defined value
	virtual String getUserDefined() = 0;
};
