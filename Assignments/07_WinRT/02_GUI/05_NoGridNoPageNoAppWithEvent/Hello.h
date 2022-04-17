#pragma once

#include"pch.h"

using namespace Platform;	// used for ^, objects, Strings, Arrays etc.


//CoClass
ref class App sealed : public Windows::UI::Xaml::Application
{
public:
	
	virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ pArgs)override;
};
