using System;
using System.Drawing;
using System.Windows.Forms;

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
        BackColor = Color.Black;
        ResizeRedraw = true;
    }
	protected override void OnPaint(PaintEventArgs pea)
    {
        Graphics grfx = pea.Graphics;   //This is HDC hdc From SDK code 
        StringFormat strfmt = new StringFormat();
        strfmt.Alignment = StringAlignment.Center;
		strfmt.LineAlignment = StringAlignment.Center;
        grfx.DrawString("Hello World...!!!!!!!!!!!!!!!!!!!!!!!!!!!",
						Font,
						new SolidBrush(System.Drawing.Color.Green),
						ClientRectangle,
						strfmt);
    }
}

