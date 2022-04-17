'for Form'
Imports System.Windows.Forms
'Dot net Callable dll'
Imports AutomationServerTypeLibForDotNet64

Public Class VBAutomation
    Inherits Form
    Public Sub New()
        Dim MyIDispatch As Object
        Dim MyRef As New CMyMathClass
        MyIDispatch = MyRef
        Dim iNum1 = 175
        Dim iNum2 = 125
        Dim str As String = String.Format("Addition of Two Numbers")
        MsgBox(str)
        Dim iSum = MyIDispatch.SumOfTwoIntegers(iNum1, iNum2)
        str = String.Format("Sum of {0} and {1} is {2}", iNum1, iNum2, iSum)
        MsgBox(str)

        str = String.Format("subtraction is")
        MsgBox(str)
        Dim iSub = MyIDispatch.SubtractionOfTwoIntegers(iNum1, iNum2)
        str = String.Format("Subtraction of {0} and {1} is {2}", iNum1, iNum2, iSub)
        MsgBox(str)
        End
    End Sub

    <STAThread()>
    Shared Sub Main()
        Application.EnableVisualStyles()
        Application.Run(New VBAutomation())
    End Sub
End Class
