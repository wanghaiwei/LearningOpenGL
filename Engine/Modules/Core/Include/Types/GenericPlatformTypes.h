/**
 * Created by rayfalling on 2020/8/30.
 * 
 * Typedef file for project.
 * Use for cross platform data type.
 * Generic platform definition.
 * */
#pragma once

#ifndef VISREAL_GENERIC_PLATFORM_TYPES_HPP
#define VISREAL_GENERIC_PLATFORM_TYPES_HPP
namespace Engine::Core::Types {
    //---------------------------------------------------------------------
    // Utility for automatically setting up the pointer-sized integer type
    //---------------------------------------------------------------------

    template<typename T32BITS, typename T64BITS, int PointerSize>
    struct [[maybe_unused]] SelectIntPointerType {
        // nothing here are is it an error if the partial specializations fail
    };

    template<typename T32BITS, typename T64BITS>
    struct [[maybe_unused]] SelectIntPointerType<T32BITS, T64BITS, 8> {
        typedef T64BITS TIntPointer; // select the 64 bit type
    };

    template<typename T32BITS, typename T64BITS>
    struct [[maybe_unused]] SelectIntPointerType<T32BITS, T64BITS, 4> {
        typedef T32BITS TIntPointer; // select the 32 bit type
    };

    struct GenericPlatformTypes {
        // Unsigned base types.
        typedef unsigned char      uint8;       // 8-bit  unsigned.
        typedef unsigned short int uint16;      // 16-bit unsigned.
        typedef unsigned int       uint32;      // 32-bit unsigned.
        typedef unsigned long long uint64;      // 64-bit unsigned.

        // Signed base types.
        typedef signed char      int8;          // 8-bit  signed.
        typedef signed short int int16;         // 16-bit signed.
        typedef signed int       int32;         // 32-bit signed.
        typedef signed long long int64;         // 64-bit signed.

        // Character types.
        typedef char    CHAR;                   // An ANSI character       -                  8-bit fixed-width representation of 7-bit characters.
        typedef wchar_t WCHAR;                  // A wide character        - In-memory only.  ?-bit fixed-width representation of the platform's natural wide character set.  Could be different sizes on different platforms.
        typedef uint8   CHAR8;                  // An 8-bit character type - In-memory only.  8-bit representation.  Should really be char8_t but making this the generic option is easier for compilers which don't fully support C++11 yet (i.e. MSVC).
        typedef uint16  CHAR16;                 // A 16-bit character type - In-memory only.  16-bit representation.  Should really be char16_t but making this the generic option is easier for compilers which don't fully support C++11 yet (i.e. MSVC).
        typedef uint32  CHAR32;                 // A 32-bit character type - In-memory only.  32-bit representation.  Should really be char32_t but making this the generic option is easier for compilers which don't fully support C++11 yet (i.e. MSVC).
        typedef WCHAR   TCHAR;                  // A switchable character  - In-memory only.  Either CHAR or CHAR, depending on a licensee's requirements.

        typedef SelectIntPointerType<uint32, uint64, sizeof(void *)>::TIntPointer PTR_SIZE;        // unsigned int the same size as a pointer
        typedef SelectIntPointerType<int32, int64, sizeof(void *)>::TIntPointer   SPTR_SIZE;       // signed int the same size as a pointer
        typedef PTR_SIZE                                                          SIZE_T;          // unsigned int the same size as a pointer
        typedef SPTR_SIZE                                                         SSIZE_T;         // signed int the same size as a pointer
    };
}

#endif //VISREAL_GENERIC_PLATFORM_TYPES_HPP