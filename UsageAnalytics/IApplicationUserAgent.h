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

class IApplicationUserAgent
{
public:
	virtual ~IApplicationUserAgent() {};

	virtual String getBrowserLanguage() = 0;

	virtual String getOS() = 0;

	// Returns the version of the operating system this jre is currently running on.
	// @return the os version
	// @see <a href="http://lopica.sourceforge.net/os.html">list of os versions
	//      and os names</a>
	virtual String getOSVersion() = 0;

	virtual String getApplicationName() = 0;

	virtual String getApplicationVersion() = 0;

	virtual String toString() = 0;
};
