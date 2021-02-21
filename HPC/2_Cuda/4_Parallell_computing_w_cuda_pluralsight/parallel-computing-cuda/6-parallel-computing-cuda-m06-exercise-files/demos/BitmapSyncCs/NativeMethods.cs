using System;
using System.Runtime.InteropServices;

namespace BitmapSyncCs
{
  public static class NativeMethods
  {
    [DllImport("BitmapSyncCpp.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void GenerateBitmap(IntPtr src, int dimension);
  }
}