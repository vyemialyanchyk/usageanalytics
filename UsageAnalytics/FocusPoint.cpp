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
#include "FocusPoint.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

String FocusPoint::URI_SEPARATOR = _T("/");
String FocusPoint::TITLE_SEPARATOR = _T("-");

FocusPoint::FocusPoint( const String& strName ) : m_strName(strName), m_pChildFocusPoint(0)
{
}

FocusPoint::~FocusPoint()
{
	if( m_pChildFocusPoint )
	{
		delete m_pChildFocusPoint;
		m_pChildFocusPoint = 0;
	}
}

String FocusPoint::getName() const
{
	return m_strName;
}

IFocusPoint* FocusPoint::setChild( IFocusPoint* pChildFocusPoint )
{
	if( m_pChildFocusPoint )
	{
		delete m_pChildFocusPoint;
		m_pChildFocusPoint = 0;
	}
	m_pChildFocusPoint = pChildFocusPoint;
	return m_pChildFocusPoint;
}

IFocusPoint* FocusPoint::getChild() const
{
	return m_pChildFocusPoint;
}

String FocusPoint::getURI()
{
	String strBuilder;
	appendContentURI( strBuilder, this );
	return strBuilder;
}

String FocusPoint::getTitle()
{
	String strBuilder;
	appendContentTitle( strBuilder, this );
	return strBuilder;
}

void FocusPoint::appendContentURI( String& strBuilder, IFocusPoint* pFocusPoint )
{
	IFocusPoint* pParentFocuPoint = pFocusPoint->getChild();
	appendToURI( pFocusPoint->getName(), strBuilder );
	if( pParentFocuPoint != 0 )
	{
		appendContentURI( strBuilder, pParentFocuPoint );
	}
}

void FocusPoint::appendToURI( const String& toAppend, String& strBuilder )
{
	strBuilder += URI_SEPARATOR;
	strBuilder += toAppend;
}

void FocusPoint::appendToTitle( const String& toAppend, String& strBuilder )
{
	strBuilder += TITLE_SEPARATOR;
	strBuilder += toAppend;
}

void FocusPoint::appendContentTitle( String& strBuilder, IFocusPoint* pFocusPoint )
{
	IFocusPoint* pChildFocusPoint = pFocusPoint->getChild();
	strBuilder += pFocusPoint->getName();
	if( pChildFocusPoint != 0 )
	{
		strBuilder += TITLE_SEPARATOR;
		appendContentTitle( strBuilder, pChildFocusPoint );
	}
}
