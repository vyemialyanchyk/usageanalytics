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
#include "SuffixFocusPoint.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

SuffixFocusPoint::SuffixFocusPoint( const String& strName, const String& strSuffix ) :
	FocusPoint(strName), m_strSuffix(strSuffix)
{
}

SuffixFocusPoint::~SuffixFocusPoint()
{
}

String SuffixFocusPoint::getURI()
{
	String strBuilder;
	appendContentURI( strBuilder, this );
	appendToURI( m_strSuffix, strBuilder );
	return strBuilder;
}

String SuffixFocusPoint::getTitle()
{
	String strBuilder;
	appendContentTitle( strBuilder, this );
	appendToTitle( m_strSuffix, strBuilder );
	return strBuilder;
}
