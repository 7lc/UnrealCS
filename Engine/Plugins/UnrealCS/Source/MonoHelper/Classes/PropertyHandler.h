// Copyright xg_55,All Rights Reserved.Support E-mail: xg_55@126.com
// For details, see LICENSE.txt

#pragma once
#include "MonoTextBuilder.h"
#include "InclusionLists.h"

class MONOHELPER_API IPropertyHandler
{
public:
	virtual ~IPropertyHandler(){}
	//����C++�������ƣ���ǰ׺
	virtual FString GetCppTypeName(UProperty* P) = 0;
	virtual FString GetCppParamTypeName(UProperty* P) = 0;
	//������ΪC++����ʱ����������
	virtual FString GetCppMarshalTypeName(UProperty* P) = 0;
	virtual FString GetCppMarshalReturnTypeName(UProperty* P) = 0;

	virtual FString BuildCppFuncPreCall(UProperty* P) = 0;
	virtual FString BuildCppCallParam(UProperty* P) = 0;
	virtual FString BuildCppFuncPostSet(UProperty* P) = 0;
	virtual FString BuildCppFuncReturn(UProperty* P) = 0;
	virtual FMonoTextBuilder BuildCppProperty(const FString& FieldName,UProperty* P) = 0;

	//���ش�ǰ׺��C#����
	virtual FString GetCSharpTypeName(UProperty* P) = 0;
	//������C++��Сһ��
	virtual FString GetCSharpMemberTypeName(UProperty* P) = 0;
	virtual FString GetCSharpParamTypeName(UProperty* P) = 0;
	//������ΪC#��̬����ʱ����������
	virtual FString GetCSharpMarshalTypeName(UProperty* P) = 0;
	virtual FString GetCSharpMarshalReturnTypeName(UProperty* P) = 0;

	virtual FString BuildCSharpFuncPreCall(UProperty* P) = 0;
	virtual FString BuildCSharpCallParam(UProperty* P) = 0;
	virtual FString BuildCSharpFuncPostSet(UProperty* P) = 0;
	virtual FString BuildCSharpFuncReturn(UProperty* P) = 0;


	virtual FMonoTextBuilder BuildCSharpClassProperty(UProperty* P) = 0;
	virtual FMonoTextBuilder BuildCSharpStructProperty(const FString& StructName, UProperty* P) = 0;

	virtual FString GetCSharpDefaultParameterValue(UFunction* Function, UProperty* ParamProperty) = 0;
	virtual FString GetNullReturnCSharpValue(UFunction* Function, UProperty* ParamProperty) = 0;
};


class MONOHELPER_API PropertyHandlerFactroy :public IPropertyHandler
{
	TMap<UClass*, IPropertyHandler*> PropertyHandlers;
	IPropertyHandler* EnumHandler;

public:
	PropertyHandlerFactroy();
	~PropertyHandlerFactroy();


	IPropertyHandler* GetPropertyHandler(UProperty* Property);

	bool IsPropertySupported(UProperty* Property);

	virtual FString GetCppTypeName(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->GetCppTypeName(P);
	}
	//����C++�������ƣ���ǰ׺
	virtual FString GetCppParamTypeName(UProperty* P)override
	{
		check(P);
		return GetPropertyHandler(P)->GetCppParamTypeName(P);
	}
	//������ΪC++����ʱ����������
	virtual FString GetCppMarshalTypeName(UProperty* P)override
	{
		check(P);
		return GetPropertyHandler(P)->GetCppMarshalTypeName(P);
	}

	virtual FString GetCppMarshalReturnTypeName(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->GetCppMarshalReturnTypeName(P);
	}

	//ת��
	virtual FString BuildCppFuncPreCall(UProperty* P)override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCppFuncPreCall(P);
	}
	virtual FString BuildCppCallParam(UProperty* P)override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCppCallParam(P);
	}
	//ת��
	virtual FString BuildCppFuncPostSet(UProperty* P)override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCppFuncPostSet(P);
	}
	virtual FString BuildCppFuncReturn(UProperty* P)override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCppFuncReturn(P);
	}
	virtual FMonoTextBuilder BuildCppProperty(const FString& FieldName, UProperty* P)override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCppProperty(FieldName,P);
	}

	//���ش�ǰ׺��C#����
	virtual FString GetCSharpTypeName(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->GetCSharpTypeName(P);
	}

	virtual FString GetCSharpMemberTypeName(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->GetCSharpMemberTypeName(P);
	}
	virtual FString GetCSharpParamTypeName(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->GetCSharpParamTypeName(P);
	}
	//������ΪC#��̬����ʱ����������
	virtual FString GetCSharpMarshalTypeName(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->GetCSharpMarshalTypeName(P);
	}
	virtual FString GetCSharpMarshalReturnTypeName(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->GetCSharpMarshalReturnTypeName(P);
	}

	virtual FString BuildCSharpFuncPreCall(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCSharpFuncPreCall(P);
	}
	virtual FString BuildCSharpCallParam(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCSharpCallParam(P);
	}
	virtual FString BuildCSharpFuncPostSet(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCSharpFuncPostSet(P);
	}
	virtual FString BuildCSharpFuncReturn(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCSharpFuncReturn(P);
	}


	virtual FMonoTextBuilder BuildCSharpClassProperty(UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCSharpClassProperty(P);
	}
	virtual FMonoTextBuilder BuildCSharpStructProperty(const FString& StructName, UProperty* P) override
	{
		check(P);
		return GetPropertyHandler(P)->BuildCSharpStructProperty(StructName,P);
	}

	virtual FString GetCSharpDefaultParameterValue(UFunction* Function, UProperty* ParamProperty) override
	{
		check(ParamProperty);
		return GetPropertyHandler(ParamProperty)->GetCSharpDefaultParameterValue(Function, ParamProperty);
	}

	virtual FString GetNullReturnCSharpValue(UFunction* Function, UProperty* ParamProperty) override
	{
		check(ParamProperty);
		return GetPropertyHandler(ParamProperty)->GetNullReturnCSharpValue(Function, ParamProperty);
	}
};
