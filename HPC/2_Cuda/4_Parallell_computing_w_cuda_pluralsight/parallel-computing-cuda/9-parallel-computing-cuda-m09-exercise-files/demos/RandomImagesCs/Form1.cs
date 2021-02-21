namespace RandomImagesCs
{
  using System;
  using System.Drawing;
  using System.Drawing.Imaging;
  using System.Windows.Forms;

  public partial class Form1 : Form
  {
    public Form1()
    {
      InitializeComponent();
    }

    private void btnUpdate_Click(object sender, EventArgs e)
    {
      int dim = 512;
      var bmp = new Bitmap(dim, dim);
      var data = bmp.LockBits(new Rectangle(0, 0, dim, dim), ImageLockMode.ReadWrite, bmp.PixelFormat);
      NativeMethods.GenerateBitmap(data.Scan0);
      bmp.UnlockBits(data);

      pictureBox.BackgroundImage = bmp;
    }
  }
}
