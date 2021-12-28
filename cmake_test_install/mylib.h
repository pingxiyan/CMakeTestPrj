#include <iostream>
#include <string>

#ifndef _MY_LIB_H_
#define _MY_LIB_H_


#if defined(_WIN32)
#ifdef IMPLEMENT_ENC_API
#define ENC_API(type) extern "C" __declspec(dllexport) type __cdecl
#define ENC_API_CPP(type) __declspec(dllexport) type __cdecl
#define ENC_API_CLASS(type) __declspec(dllexport) type
#else
#define ENC_API(type) extern "C" __declspec(dllimport) type __cdecl
#define ENC_API_CPP(type) __declspec(dllimport) type __cdecl
#define ENC_API_CLASS(type) __declspec(dllimport) type
#endif
#else
#ifdef IMPLEMENT_ENC_API
#define ENC_API(type) extern "C" __attribute__((visibility("default"))) type
#define ENC_API_CPP(type) __attribute__((visibility("default"))) type
#define ENC_API_CLASS(type) __attribute__((visibility("default"))) type
#else
#define ENC_API(type) extern "C" type
#define ENC_API_CPP(type) type
#define ENC_API_CLASS(type) type
#endif
#endif


ENC_API_CPP(int) call_my_lib(std::string str);

#endif
