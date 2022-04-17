//Headers
#include"pch.h"
#include"Page.h"
#include"Hello.h"

//namespaces
using namespace Windows::UI::Xaml::Media;		//For TextBlock, SolidColorBrush
using namespace Windows::UI::Xaml::Controls;	//For Grid, Page
using namespace Windows::UI::Text;				//For FontStyle, FontWeight
using namespace Windows::UI::Xaml;				//For HorizontalAlignment, VerticalAlignment, RoutedEventArgs, ApplicationInitializationCallback, ApplicationInitializationCallbackParams
using namespace Windows::UI;

//Callback Function
void MyCallBackMethod(ApplicationInitializationCallbackParams^ pParams)
{
	App^ app = ref new App();
}

//Main
int main(Array<String^>^ pArgs)
{
	ApplicationInitializationCallback^ pCallback = ref new ApplicationInitializationCallback(MyCallBackMethod);
	Application::Start(pCallback);

	return(0);
}

//CoClass's Method
void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ pArgs)
{
	MyPage^ page = ref new MyPage();
	
	Window::Current->Content = page;	//Content is the property
	Window::Current->Activate();		//Activate is the Method
}


