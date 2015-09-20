/*
Copyright (c) 2010 Aldo J. Nunez

Licensed under the Apache License, Version 2.0.
See the LICENSE text file for details.
*/


#include "Common.h"
#include "PdataCache.h"

namespace Mago
{
	PdataCache::PdataCache(int pdataSize)
		: mMap(RangeLess),
		mEntrySize(pdataSize)
	{
	}

	bool PdataCache::RangeLess(const MapKey& left, const MapKey& right)
	{
		return left.End < right.Begin;
	}

	void* PdataCache::Find(Address64 address)
	{
		MapKey range = { address, address };

		PdataMap::iterator it = mMap.find(range);
		if (it == mMap.end())
			return NULL;

		return &mBuffer[it->second];
	}

	void* PdataCache::Add(Address64 begin, Address64 end, void* pdata)
	{
		size_t origSize = mBuffer.size();
		mBuffer.resize(mBuffer.size() + mEntrySize);

		memcpy(&mBuffer[origSize], pdata, mEntrySize);

		MapKey range = { begin, end };
		mMap.insert(PdataMap::value_type(range, origSize));
		return &mBuffer[origSize];
	}

}