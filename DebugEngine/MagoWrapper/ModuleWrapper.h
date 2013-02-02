// MagoWrapper.h

#pragma once


namespace MagoWrapper {

	class ModuleWrapper 
	{
		private:
			IModule* mModule;
			LONG mRefCount;
	public:
		ModuleWrapper(IModule* mod);

		void AddRef();
		void Release();

		// TODO: Die Methoden für diese Klasse hier hinzufügen.
	};
}
