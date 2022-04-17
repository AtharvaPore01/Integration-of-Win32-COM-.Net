using System;
using System.Drawing;
using System.Windows.Forms;

//code
public class CSharpWindow : Form
{
	public static void Main()
    {
        Application.Run(new CSharpWindow());
    }

	public CSharpWindow()
    {
        Width = 800;
        Height = 600;
        ResizeRedraw = true;
    }
}


