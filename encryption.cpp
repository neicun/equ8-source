// encryption.cpp

__int64 __fastcall get_decrypted_mem(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // rbx
  __int64 v5; // r14
  __int64 v9; // rbx
  __int64 PoolWithQuotaTag; // rax

  v4 = -1i64;
  v5 = a4;
  do
    ++v4;
  while ( *(_WORD *)(a2 + 2 * v4) );
  v9 = (unsigned int)(2 * v4);
  if ( (unsigned int)v9 + a4 >= 0x10000 )
    return 2147483653i64;
  PoolWithQuotaTag = ExAllocatePoolWithQuotaTag(1i64, (unsigned int)v9 + a4, 945115461i64);
  *(_QWORD *)(a1 + 8) = PoolWithQuotaTag;
  if ( !PoolWithQuotaTag )
    return 3221225495i64;
  *(_WORD *)a1 = v9 + v5;
  *(_WORD *)(a1 + 2) = v9 + v5;
  decryption(PoolWithQuotaTag, a2, v9);
  decryption(v9 + *(_QWORD *)(a1 + 8), a3, v5);
  return 0i64;
}
__m128i *__fastcall decryption(__m128i *_RCX, unsigned __int64 a2, unsigned __int64 a3)
{
  __m128i *v3; // r11
  bool v4; // cf
  unsigned __int64 k; // r9
  __int64 v7; // rax
  unsigned __int64 m; // r8
  __int8 v9; // al
  unsigned int v11; // ecx
  unsigned __int64 v12; // r9
  __m128i v13; // xmm0
  __m128i v14; // xmm1
  int v15; // eax
  int v16; // eax
  __m128i v17; // xmm1
  __m128i v18; // xmm1
  unsigned __int64 i; // r9
  __int64 v21; // rax
  unsigned __int64 j; // r8
  __int8 v23; // al
  __m128i *v24; // rax
  __int64 v25; // rcx
  unsigned __int64 v26; // r9
  __m128i v27; // xmm0
  __m128i v28; // xmm1
  int v29; // eax
  int v30; // eax
  __m128i v31; // xmm1
  __m128i v32; // xmm1
  void *retaddr; // [rsp+0h] [rbp+0h] BYREF

  v3 = _RCX;
  v4 = a2 < (unsigned __int64)_RCX;
  _RDX = a2 - (_QWORD)_RCX;
  if ( v4 )
  {
    _RCX = (__m128i *)((char *)_RCX + a3);
    if ( a3 >= 0x4F )
    {
      if ( _RDX > 0xFFFFFFFFFFFFFFF0ui64 )
      {
        for ( ; ((unsigned __int8)_RCX & 0xF) != 0; _RCX->m128i_i8[0] = _RCX->m128i_i8[_RDX] )
        {
          _RCX = (__m128i *)((char *)_RCX - 1);
          --a3;
        }
      }
      else
      {
        v24 = _RCX;
        v25 = (unsigned __int8)_RCX & 0xF;
        if ( (_DWORD)v25 )
        {
          a3 -= (unsigned int)v25;
          v25 = -(__int64)(unsigned int)v25;
          v24[-1] = _mm_loadu_si128((__m128i *)((char *)v24 + _RDX - 16));
        }
        _RCX = (__m128i *)((char *)v24 + v25);
      }
      v26 = a3 >> 5;
      if ( a3 >> 5 <= 0x2000 || _RDX > 0xFFFFFFFFFFFFFE00ui64 )
        goto LABEL_38;
      do
      {
        v29 = 4;
        do
        {
          _RCX -= 8;
          __asm
          {
            prefetchnta byte ptr [rcx+rdx]
            prefetchnta byte ptr [rcx+rdx+40h]
          }
          --v29;
        }
        while ( v29 );
        _RCX += 32;
        v30 = 8;
        do
        {
          v31 = _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX - 32));
          _mm_stream_si128(_RCX - 1, _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX - 16)));
          _mm_stream_si128(_RCX - 2, v31);
          _RCX -= 4;
          v32 = _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX));
          _mm_stream_si128(_RCX + 1, _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX + 16)));
          _mm_stream_si128(_RCX, v32);
          --v30;
        }
        while ( v30 );
        a3 -= 512i64;
      }
      while ( a3 >= 0x200 );
      _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
      v26 = a3 >> 5;
      if ( a3 >> 5 )
      {
LABEL_38:
        a3 &= 0x1Fu;
        do
        {
          v27 = _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX - 16));
          v28 = _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX - 32));
          _RCX -= 2;
          _RCX[1] = v27;
          *_RCX = v28;
          --v26;
        }
        while ( v26 );
      }
    }
    for ( i = a3 >> 3; i; _RCX->m128i_i64[0] = v21 )
    {
      v21 = *(__int64 *)((char *)&_RCX->m128i_i64[-1] + _RDX);
      _RCX = (__m128i *)((char *)_RCX - 8);
      --i;
    }
    for ( j = a3 & 7; j; _RCX->m128i_i8[0] = v23 )
    {
      v23 = _RCX->m128i_i8[_RDX - 1];
      _RCX = (__m128i *)((char *)_RCX - 1);
      --j;
    }
    return v3;
  }
  else
  {
    if ( a3 >= 0x4F )
    {
      if ( _RDX < 0x10 )
      {
        for ( ; ((unsigned __int8)_RCX & 0xF) != 0; _RCX = (__m128i *)((char *)_RCX + 1) )
        {
          --a3;
          _RCX->m128i_i8[0] = _RCX->m128i_i8[_RDX];
        }
      }
      else
      {
        v11 = -(int)_RCX & 0xF;
        if ( v11 )
        {
          a3 -= v11;
          *v3 = _mm_loadu_si128((__m128i *)((char *)v3 + _RDX));
        }
        _RCX = (__m128i *)((char *)v3 + v11);
      }
      v12 = a3 >> 5;
      if ( a3 >> 5 <= 0x2000 || _RDX < 0x200 )
        goto LABEL_13;
      do
      {
        v15 = 4;
        do
        {
          __asm
          {
            prefetchnta byte ptr [rcx+rdx]
            prefetchnta byte ptr [rcx+rdx+40h]
          }
          _RCX += 8;
          --v15;
        }
        while ( v15 );
        _RCX -= 32;
        v16 = 8;
        do
        {
          v17 = _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX + 16));
          _mm_stream_si128(_RCX, _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX)));
          _mm_stream_si128(_RCX + 1, v17);
          _RCX += 4;
          v18 = _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX - 16));
          _mm_stream_si128(_RCX - 2, _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX - 32)));
          _mm_stream_si128(_RCX - 1, v18);
          --v16;
        }
        while ( v16 );
        a3 -= 512i64;
      }
      while ( a3 >= 0x200 );
      _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
      v12 = a3 >> 5;
      if ( a3 >> 5 )
      {
LABEL_13:
        a3 &= 0x1Fu;
        do
        {
          v13 = _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX));
          v14 = _mm_loadu_si128((__m128i *)((char *)_RCX + _RDX + 16));
          _RCX += 2;
          _RCX[-2] = v13;
          _RCX[-1] = v14;
          --v12;
        }
        while ( v12 );
      }
    }
    for ( k = a3 >> 3; k; _RCX[-1].m128i_i64[1] = v7 )
    {
      v7 = *(__int64 *)((char *)_RCX->m128i_i64 + _RDX);
      _RCX = (__m128i *)((char *)_RCX + 8);
      --k;
    }
    for ( m = a3 & 7; m; _RCX[-1].m128i_i8[15] = v9 )
    {
      v9 = _RCX->m128i_i8[_RDX];
      _RCX = (__m128i *)((char *)_RCX + 1);
      --m;
    }
    return v3;
  }
}