//Headers
#include"pch.h"
#include"Hello.h"

//namespaces
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Text;
using namespace Windows::UI::Xaml;
using namespace Windows::UI;

void MyCallBackMethod(ApplicationInitializationCallbackParams^ pParams)
{
	App^ app = ref new App();
}

int main(Array<String^>^ pArgs)
{
	ApplicationInitializationCallback^ pCallback = ref new ApplicationInitializationCallback(MyCallBackMethod);
	Application::Start(pCallback);

	return(0);
}

void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ pArgs)
{
	Page^ page = ref new Page();
	Grid^ grid = ref new Grid();
	grid->Background = ref new SolidColorBrush(Colors::Black);

	TextBlock^ textBlock = ref new TextBlock();

	textBlock->Text = "Hello World!!!";
	textBlock->FontFamily = ref new FontFamily("Segoe UI");
	textBlock->FontSize = 80;
	textBlock->FontStyle = FontStyle::Normal;
	textBlock->FontWeight = FontWeights::Bold;
	textBlock->Foreground = ref new SolidColorBrush(Colors::Green);
	textBlock->HorizontalAlignment = HorizontalAlignment::Center;
	textBlock->VerticalAlignment = VerticalAlignment::Center;
	
	grid->Children->Append(textBlock);
	page->Content = grid;
	
	Window::Current->Content = page;
	Window::Current->Activate();
}


