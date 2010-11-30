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

#include "IFocusPoint.h"

// Focus point of the application. It can represent data points like application
// load, application module load, user actions, error events etc.
// @see based on <a
//      href="http://jgoogleAnalytics.googlecode.com">http://jgoogleAnalytics
//      .googlecode.com</a>
class FocusPoint : public IFocusPoint
{
public:
	static String URI_SEPARATOR;
	static String TITLE_SEPARATOR;
protected:
	String m_strName;
	IFocusPoint* m_pChildFocusPoint;
public:
	FocusPoint( const String& strName );
	virtual ~FocusPoint();

	virtual String getName() const;

	virtual IFocusPoint* setChild( IFocusPoint* pChildFocusPoint );

	virtual IFocusPoint* getChild() const;

	virtual String getURI();

	virtual String getTitle();

	void appendContentURI( String& strBuilder, IFocusPoint* pFocusPoint );

	void appendToURI( const String& toAppend, String& strBuilder );

	void appendToTitle( const String& toAppend, String& strBuilder );

	void appendContentTitle( String& strBuilder, IFocusPoint* pFocusPoint );
};
