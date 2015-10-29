//---------------------------------------------------------------------------

#ifndef IConverterH
#define IConverterH
#include <vector>

template<typename I, typename O>
class IConverter {
	I in;
	std::vector<O> *out;
public:
	IConverter(){
		out = new std::vector<O>();
	};
	virtual std::vector<O> convert(I) = 0;

};
//---------------------------------------------------------------------------
#endif
