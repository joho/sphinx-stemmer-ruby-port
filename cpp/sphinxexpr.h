//
// $Id: sphinxexpr.h 2153 2010-01-04 19:17:57Z shodan $
//

//
// Copyright (c) 2001-2010, Andrew Aksyonoff
// Copyright (c) 2008-2010, Sphinx Technologies Inc
// All rights reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License. You should have
// received a copy of the GPL license along with this program; if you
// did not, you can find it at http://www.gnu.org/
//

#ifndef _sphinxexpr_
#define _sphinxexpr_

#include "sphinxstd.h"

/// forward decls
class CSphMatch;
struct CSphSchema;
struct CSphString;

/// expression evaluator
/// can always be evaluated in floats using Eval()
/// can sometimes be evaluated in integers using IntEval(), depending on type as returned from sphExprParse()
struct ISphExpr : public ISphRefcounted
{
public:
	/// evaluate this expression for that match
	virtual float Eval ( const CSphMatch & tMatch ) const = 0;

	/// evaluate this expression for that match, using int math
	virtual int IntEval ( const CSphMatch & tMatch ) const { assert ( 0 ); return (int) Eval ( tMatch ); }

	/// evaluate this expression for that match, using int64 math
	virtual int64_t Int64Eval ( const CSphMatch & tMatch ) const { assert ( 0 ); return (int64_t) Eval ( tMatch ); }

	/// check for arglist subtype
	virtual bool IsArglist () const { return false; }

	/// setup MVA pool
	virtual void SetMVAPool ( const DWORD * ) {}
};

/// parses given expression, builds evaluator
/// returns NULL and fills sError on failure
/// returns pointer to evaluator on success
/// fills pAttrType with result type (for now, can be SPH_ATTR_SINT or SPH_ATTR_FLOAT)
ISphExpr * sphExprParse ( const char * sExpr, const CSphSchema & tSchema, DWORD * pAttrType, bool * pUsesWeight, CSphString & sError );

#endif // _sphinxexpr_

//
// $Id: sphinxexpr.h 2153 2010-01-04 19:17:57Z shodan $
//
