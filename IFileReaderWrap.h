//---------------------------------------------------------------------------
#include "IFileReader.h"


#ifndef IFileReaderWrapH
#define IFileReaderWrapH

class IFileReaderWrap : public IFileReader
{   protected:
		IFileReader* ifr;
		virtual int open_bin_f(int)=0;
	public:

		IFileReaderWrap(/*char* filename*/IFileReader* ifr): ifr(ifr){};
};

//---------------------------------------------------------------------------
#endif
