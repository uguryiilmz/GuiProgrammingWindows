Imports Microsoft.VisualBasic.PowerPacks

Public Class Form1
    Dim show_speed As Integer
    Dim move_right As Boolean
    Dim move_top As Boolean
    Dim speed As Integer
    Dim containerShape As New ShapeContainer
    Dim x_speed As Integer
    Dim y_speed As Integer
    Dim ovalShape As New OvalShape
    Dim angle As Double


    Private Function DrawBall()
        containerShape.Parent = Me
        ovalShape.Parent = containerShape
        ovalShape.FillStyle = FillStyle.Solid
        ovalShape.FillColor = Color.Blue
        ovalShape.Size = New System.Drawing.Size(24, 24)
        ovalShape.Location = New System.Drawing.Point((ClientSize.Width - 24) \ 2, (ClientSize.Height - 24) \ 2)
    End Function



    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        DrawBall()
        Timer1.Stop()
        Label3.Text = "8"
        TrackBar2.Value = 45
        Label4.Text = "45"
        speed = Label3.Text
        x_speed = Math.Cos(Math.PI * angle / 180.0) * ((2 * speed) ^ (0.5))
        y_speed = Math.Sin(Math.PI * angle / 180.0) * ((2 * speed) ^ (0.5))
    End Sub


    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        If (ovalShape.Top - y_speed) <= 0 Then
            move_top = False
        End If
        If (ovalShape.Left - x_speed) <= 0 Then
            move_right = True
        End If
        If (ovalShape.Bottom + y_speed) >= Me.ClientRectangle.Bottom Then
            move_top = True
        End If
        If move_right = False Then
            ovalShape.Left -= x_speed
        Else
            ovalShape.Left += x_speed
        End If
        If (ovalShape.Right + x_speed) >= Me.ClientRectangle.Right Then
            move_right = False
        End If
        If move_top = False Then
            ovalShape.Top += y_speed
        Else
            ovalShape.Top -= y_speed
        End If
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Timer1.Start()
    End Sub
    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Timer1.Stop()
    End Sub

    Private Sub Button3_Click_1(sender As Object, e As EventArgs) Handles Button3.Click
        show_speed = Convert.ToInt32(Label3.Text)
        show_speed = show_speed + 20
        Label3.Text = Convert.ToString(show_speed)
        speed = Label3.Text
        x_speed = Math.Cos(Math.PI * angle / 180.0) * ((2 * Convert.ToInt32(speed)) ^ (0.5))
        y_speed = Math.Sin(Math.PI * angle / 180.0) * ((2 * Convert.ToInt32(speed)) ^ (0.5))
    End Sub

    Private Sub TrackBar2_ValueChanged(sender As Object, e As EventArgs) Handles TrackBar2.ValueChanged
        angle = TrackBar2.Value
        Label4.Text = TrackBar2.Value
        x_speed = Math.Cos(Math.PI * angle / 180.0) * ((2 * speed) ^ (0.5))
        y_speed = Math.Sin(Math.PI * angle / 180.0) * ((2 * speed) ^ (0.5))
    End Sub

End Class
