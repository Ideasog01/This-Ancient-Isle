// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AncientIsle/AncientIsleGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAncientIsleGameModeBase() {}
// Cross Module References
	ANCIENTISLE_API UClass* Z_Construct_UClass_AAncientIsleGameModeBase_NoRegister();
	ANCIENTISLE_API UClass* Z_Construct_UClass_AAncientIsleGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_AncientIsle();
// End Cross Module References
	void AAncientIsleGameModeBase::StaticRegisterNativesAAncientIsleGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AAncientIsleGameModeBase_NoRegister()
	{
		return AAncientIsleGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AAncientIsleGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAncientIsleGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_AncientIsle,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAncientIsleGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AncientIsleGameModeBase.h" },
		{ "ModuleRelativePath", "AncientIsleGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAncientIsleGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAncientIsleGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAncientIsleGameModeBase_Statics::ClassParams = {
		&AAncientIsleGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AAncientIsleGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAncientIsleGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAncientIsleGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAncientIsleGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAncientIsleGameModeBase, 1876830015);
	template<> ANCIENTISLE_API UClass* StaticClass<AAncientIsleGameModeBase>()
	{
		return AAncientIsleGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAncientIsleGameModeBase(Z_Construct_UClass_AAncientIsleGameModeBase, &AAncientIsleGameModeBase::StaticClass, TEXT("/Script/AncientIsle"), TEXT("AAncientIsleGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAncientIsleGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
