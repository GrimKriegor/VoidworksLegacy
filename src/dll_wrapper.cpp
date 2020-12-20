#include <voidworks/dll_wrapper.h>

HINSTANCE BaseAddress, BaseAddressGenuine;
wchar_t* BaseFileName, FullFilePath[512];

void WrapGenuineDll(HINSTANCE baseaddr)
{
  BaseAddress = baseaddr;
  BaseFileName = FullFilePath + GetModuleFileNameW(BaseAddress, FullFilePath, _countof(FullFilePath));
  while (BaseFileName-- > FullFilePath) if (*BaseFileName == L'\\') break;
}

void UnloadDll()
{
  if (!BaseAddress) { return; }
  FreeLibraryAndExitThread(BaseAddress, 0);
}

importD3D(FARPROC D3DAssemble_, DebugSetMute_, D3DCompile_, D3DCompressShaders_, D3DCreateBlob_, D3DDecompressShaders_, D3DDisassemble_, D3DDisassemble10Effect_, D3DGetBlobPart_, D3DGetDebugInfo_, D3DGetInputAndOutputSignatureBlob_, D3DGetInputSignatureBlob_, D3DGetOutputSignatureBlob_, D3DPreprocess_, D3DReflect_, D3DReturnFailure1_, D3DStripShader_)
  void LoadGenuineDll() {
  if (!BaseAddressGenuine) {
    static wchar_t filename[512];
    GetSystemDirectoryW(filename, _countof(filename));
    BaseAddressGenuine = LoadLibraryW(wcscat(filename, BaseFileName));
    IMPORT(D3DAssemble);
    IMPORT(DebugSetMute);
    IMPORT(D3DCompile);
    IMPORT(D3DCompressShaders);
    IMPORT(D3DCreateBlob);
    IMPORT(D3DDecompressShaders);
    IMPORT(D3DDisassemble);
    IMPORT(D3DDisassemble10Effect);
    IMPORT(D3DGetBlobPart);
    IMPORT(D3DGetDebugInfo);
    IMPORT(D3DGetInputAndOutputSignatureBlob);
    IMPORT(D3DGetInputSignatureBlob);
    IMPORT(D3DGetOutputSignatureBlob);
    IMPORT(D3DPreprocess);
    IMPORT(D3DReflect);
    IMPORT(D3DReturnFailure1);
    IMPORT(D3DStripShader);
  }
}
