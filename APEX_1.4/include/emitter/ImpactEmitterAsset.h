//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Copyright (c) 2018 NVIDIA Corporation. All rights reserved.



#ifndef IMPACT_EMITTER_ASSET_H
#define IMPACT_EMITTER_ASSET_H

#include "Apex.h"

namespace nvidia
{
namespace apex
{


PX_PUSH_PACK_DEFAULT

#define IMPACT_EMITTER_AUTHORING_TYPE_NAME "ImpactEmitterAsset"

class ImpactEmitterActor;

///Impact emitter asset class
class ImpactEmitterAsset : public Asset
{
protected:
	PX_INLINE ImpactEmitterAsset() {}
	virtual ~ImpactEmitterAsset() {}

public:
	/// Get the setID that corresponds to the set name \sa ImpactEmitterActor::registerImpact()
	virtual uint32_t			querySetID(const char* setName) = 0;

	/**
	\brief Get a list of the event set names.  The name index in the outSetNames list is the setID.
	\param [in,out] inOutSetNames An array of const char * with at least nameCount
	\param [in,out] nameCount The size of setNames as input and output, set to -1 if setIDs > nameCount
	*/
	virtual void				getSetNames(const char** inOutSetNames, uint32_t& nameCount) const = 0;
};

///Impact emitter asset authoring. Used to create Impact Emitter assets
class ImpactEmitterAssetAuthoring : public AssetAuthoring
{
protected:
	virtual ~ImpactEmitterAssetAuthoring() {}

public:
};


PX_POP_PACK

}
} // end namespace nvidia

#endif // IMPACT_EMITTER_ASSET_H
