using namespace Platform;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Text;
using namespace Windows::UI::Xaml;
using namespace Windows::UI;

ref class MyApp sealed : public Windows::UI::Xaml::Application
{
public:
	virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ pArgs)override;
};


//void MyCallBackMethod(ApplicationInitializationCallbackParams^ pParams)
//{
//	MyApp^ app = ref new MyApp();
//}

int main(Array<String^>^ pArgs)
{
	Application::Start(ref new ApplicationInitializationCallback([](ApplicationInitializationCallbackParams^ pParams) {MyApp^ app = ref new MyApp(); }));
	
	/*ApplicationInitializationCallback^ pCallback = ref new ApplicationInitializationCallback(MyCallBackMethod);
	Application::Start(pCallback);*/

	return(0);
}

void MyApp::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ pArgs)
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


