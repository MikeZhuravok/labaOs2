#pragma once
#ifdef _STATIC
#define RSA_API
#else
	#ifdef _USRDLL
	#define RSA_API __declspec(dllexport)
	#else
	#define RSA_API __declspec(dllimport)
	#endif 
#endif


#ifdef __cplusplus
extern "C"
{
#endif
	RSA_API bool __stdcall isSimple(int a);
	RSA_API bool _stdcall isCoprime(int a, int b);
	RSA_API int _stdcall moduleCounting(int a, int p, int m);
	RSA_API void __stdcall makeKeys(int* openKey, int* closedKey);
	RSA_API void __stdcall Encrypt(unsigned char* data, int* openKey, int len, unsigned int* result);
	RSA_API void __stdcall Decrypt(unsigned int* data, int* closedKey, int len, unsigned char* result);


#ifdef __cplusplus
}
#endif
