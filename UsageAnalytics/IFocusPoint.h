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

class IFocusPoint
{
public:
	virtual ~IFocusPoint() {};

	virtual String getName() const = 0;

	virtual IFocusPoint* setChild( IFocusPoint* pChildFocusPoint ) = 0;

	virtual IFocusPoint* getChild() const = 0;

	virtual String getURI() = 0;

	virtual String getTitle() = 0;
};
