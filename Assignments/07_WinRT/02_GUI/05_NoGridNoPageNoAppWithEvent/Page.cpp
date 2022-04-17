#include"pch.h"
#include"Hello.h"
#include"Page.h"

//namespace
using namespace Windows::Foundation;			//For TypedEventHandler
using namespace Windows::UI::Xaml::Media;		//For TextBlock, SolidColorBrush
using namespace Windows::UI::Text;				//For FontStyle, FontWeight
using namespace Windows::UI::Xaml;				//For HorizontalAlignment, VerticalAlignment, RoutedEventArgs
using namespace Windows::UI;					//For Colors

MyPage::MyPage()
{
	Window::Current->CoreWindow->KeyDown += ref new TypedEventHandler<CoreWindow^, KeyEventArgs^>(this, &MyPage::OnKeyDown);

	Grid^ grid = ref new Grid();
	grid->Background = ref new SolidColorBrush(Colors::Black);

	textBlock = ref new TextBlock();
	textBlock->Text = "Hello World!!!";
	textBlock->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily("Segoe UI");
	textBlock->FontSize = 80;
	textBlock->FontStyle = Windows::UI::Text::FontStyle::Normal;
	textBlock->FontWeight = FontWeights::Bold;
	textBlock->Foreground = ref new SolidColorBrush(Colors::Green);
	textBlock->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;
	textBlock->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;

	grid->Children->Append(textBlock);
	
	Button^ pButton = ref new Button();
	pButton->Content = "Press";
	pButton->Width = 40;
	pButton->Height = 40;
	pButton->BorderThickness = 5;
	pButton->BorderBrush = ref new SolidColorBrush(Colors::White);
	pButton->Foreground = ref new SolidColorBrush(Colors::Black);
	pButton->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily("Segoe UI");
	pButton->FontSize = 10;
	pButton->FontWeight = FontWeights::Bold;
	pButton->FontStyle = Windows::UI::Text::FontStyle::Normal;
	pButton->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;
	pButton->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Bottom;
	pButton->Click += ref new RoutedEventHandler(this, &MyPage::OnButtonClick);		//Button ahe pn Click mhanun register kar mhanun '+=' vaparla ahe

	grid->Children->Append(pButton);
	this->Content = grid;

}

void MyPage::OnKeyDown(CoreWindow^ pSender, KeyEventArgs^ pArgs)
{
	textBlock->Text = "Key Is Pressed!!!";
}

void MyPage::OnButtonClick(Object^ pSender, RoutedEventArgs^ pArgs)
{
	textBlock->Text = "Mouse Is Clicked!!!";
}


