// resolver.cpp
char __fastcall resolve(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v6; // rcx
  _WORD *v7; // r9
  _WORD *v8; // rax
  __int64 v9; // r8
  signed int v10; // edx
  __int64 v11; // r11

  if ( !a1 || !a2 )
    return 0;
  v6 = 0i64;
  v7 = (_WORD *)(a1 + 32);
  if ( v7 )
  {
    v8 = v7;
    v9 = 128i64;
    do
    {
      if ( !*v8 )
        break;
      ++v8;
      --v9;
    }
    while ( v9 );
    v10 = v9 == 0 ? 0xC000000D : 0;
    v6 = v9 ? 128 - v9 : 0i64;
  }
  else
  {
    v10 = -1073741811;
  }
  if ( v10 < 0 || a3 > v6 + 8 )
    return 0;
  if ( a3 )
  {
    v11 = a2 - (_QWORD)v7;
    do
    {
      *v7 ^= *(_WORD *)((char *)v7 + v11);
      ++v7;
      --a3;
    }
    while ( a3 );
  }
  return 1;
}