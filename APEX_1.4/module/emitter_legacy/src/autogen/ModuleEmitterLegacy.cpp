/*
* Copyright (c) 2008-2015, NVIDIA CORPORATION.  All rights reserved.
*
* NVIDIA CORPORATION and its licensors retain all intellectual property
* and proprietary rights in and to this software, related documentation
* and any modifications thereto.  Any use, reproduction, disclosure or
* distribution of this software and related documentation without an express
* license agreement from NVIDIA CORPORATION is strictly prohibited.
*
* This code was autogenerated from ModuleLegacy.template
*/

#include "ApexUsingNamespace.h"
#include "Apex.h"
#include "ApexLegacyModule.h"
#include "ApexRWLockable.h"
#include "ModuleEmitterLegacyRegistration.h"

namespace nvidia 
{ 
namespace apex
{
namespace legacy
{

class ModuleEmitterLegacy : public ApexLegacyModule, public ApexRWLockable
{
public:
	APEX_RW_LOCKABLE_BOILERPLATE

	ModuleEmitterLegacy(ApexSDKIntl* inSdk)
	{
  	  mName = "Emitter_Legacy";
	  mSdk = inSdk;
	  mApiProxy = this;
	  ModuleEmitterLegacyRegistration::invokeRegistration(mSdk->getParameterizedTraits());
	}

protected:
	void releaseLegacyObjects()
        {
          ModuleEmitterLegacyRegistration::invokeUnregistration(mSdk->getParameterizedTraits());
        }
};

void instantiateModuleEmitterLegacy()
{
	ApexSDKIntl *sdk = GetInternalApexSDK();
	ModuleEmitterLegacy *impl = PX_NEW(ModuleEmitterLegacy)(sdk);
	sdk->registerExternalModule((Module *) impl, (ModuleIntl *) impl);
}

}
}
}
