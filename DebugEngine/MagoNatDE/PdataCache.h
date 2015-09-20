/*
Copyright (c) 2010 Aldo J. Nunez

Licensed under the Apache License, Version 2.0.
See the LICENSE text file for details.
*/

#pragma once

namespace Mago
{
	class PdataCache
	{
	    typedef AddressRange64 MapKey;
	
	    typedef bool (*RangePred)( const MapKey& left, const MapKey& right );
	    static bool RangeLess( const MapKey& left, const MapKey& right );
	
	    typedef std::vector<BYTE> PdataBuffer;
	    typedef std::map<MapKey, int, RangePred> PdataMap;
	
	    PdataBuffer mBuffer;
	    PdataMap    mMap;
	    int         mEntrySize;
	
	public:
	    PdataCache( int pdataSize );
	    void* Find( Address64 address );
	    void* Add( Address64 begin, Address64 end, void* pdata );
	};
	
}
