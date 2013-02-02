// Dies ist die Haupt-DLL.

#include "stdafx.h"

#include "ModuleWrapper.h"


namespace MagoWrapper{

	ModuleWrapper::ModuleWrapper(IModule* mod) : mRefCount( 0 )
	{
		mModule = mod;
	}

	void ModuleWrapper::AddRef()
	{
		InterlockedIncrement( &mRefCount );
	}

	void ModuleWrapper::Release()
	{
		LONG newRefCount = InterlockedDecrement( &mRefCount );
		_ASSERT( newRefCount >= 0 );
		if ( newRefCount == 0 )
		{
			delete this;
		}
	}
}

