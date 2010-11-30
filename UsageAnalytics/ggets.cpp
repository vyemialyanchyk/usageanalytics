// File ggets.c  - goodgets is a safe alternative to gets
// By C.B. Falconer.  Public domain 2002-06-22
//    attribution appreciated.

// Revised 2002-06-26  New prototype.
//         2002-06-27  Incomplete final lines
//         2006-03-29  This version "templatised" for 
//                     Unicode and made to use "new/delete"
//                     by David Pritchard

// fggets and ggets [which is fggets(ln, stdin)] set *ln to
// a buffer filled with the next complete line from the text
// stream f.  The storage has been allocated within fggets,
// and is normally reduced to be an exact fit.  The trailing
// \n has been removed, so the resultant line is ready for
// dumping with puts.  The buffer will be as large as is
// required to hold the complete line.

// Note: this means a final file line without a \n terminator
// has an effective \n appended, as EOF occurs within the read.

// If no error occurs fggets returns 0.  If an EOF occurs on
// the input file, EOF is returned.  For memory allocation
// errors some positive value is returned.  In this case *ln
// may point to a partial line.  For other errors memory is
// freed and *ln is set to NULL.

// Freeing of assigned storage is the callers responsibility

#include "stdafx.h"
#include "TemplateSmartPtr.h"
#include "ggets.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif 

char* GetFileString( char* string, int n, FILE* stream )
{
	return fgets( string, n, stream );
}

wchar_t* GetFileString( wchar_t* string, int n, FILE* stream )
{
	return fgetws( string, n, stream );
}

// Same with strchr
char* FindCharInString( const char* string, int c )
{	
	// This *should* work OK even with UTF-8, since we're only searching for
	// '\n' in practice. Careful if you try to use this for anything other
	// than ASCII characters. 
	return (char*)_mbschr( (const unsigned char*)string, c );
}

wchar_t* FindCharInString( const wchar_t* string, wint_t c )
{	
	return (wchar_t*)wcschr( string, c );
}
