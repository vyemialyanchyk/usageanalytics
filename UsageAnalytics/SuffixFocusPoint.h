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

#include "FocusPoint.h"

// A focus point that always reports the current Application version as last component.
class SuffixFocusPoint : public FocusPoint
{
protected:
	String m_strSuffix;
public:
	SuffixFocusPoint( const String& strName, const String& strSuffix );
	virtual ~SuffixFocusPoint();

	virtual String getURI();

	virtual String getTitle();
};
