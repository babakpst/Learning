namespace RandomImagesCs
{
  using System;
  using System.Runtime.InteropServices;

  public static class NativeMethods
  {
    [DllImport("RandomImagesCpp.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void GenerateBitmap(IntPtr src);
  }
}