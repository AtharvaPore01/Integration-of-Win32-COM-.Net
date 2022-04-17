#pragma once
//namespaces
using namespace Windows::UI::Xaml::Controls;	//For Page
using namespace Windows::UI::Core;				//For CoreWindow, KeyEventArgs
using namespace Windows::UI::Xaml;				//For HorizontalAlignment, VerticalAlignment, RoutedEventArgs, ApplicationInitializationCallback, ApplicationInitializationCallbackParams

//coclass

ref class MyPage sealed : Page
{
	//code
private:
	TextBlock^ textBlock;

public:
	MyPage();
	void OnKeyDown(CoreWindow^ pSender, KeyEventArgs^ pArgs);

	void OnButtonClick(Object^ pSender, RoutedEventArgs^ pArgs);
};

