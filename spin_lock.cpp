// spin_lock.cpp

__int64 __fastcall load_spin_lock(__int64 a1, __int64 a2, char a3)
{
  int v3; // edi
  char v4; // al
  __int64 *v5; // rdx
  __int64 v6; // rbx
  char v7; // r8
  __int64 result; // rax
  __int64 **v9; // rax

  v3 = a2;
  if ( a3 )
  {
    result = qword_1400030B0;
    if ( qword_1400030B0 && qword_1400030B0 == a1 )
      return load_proc(&qword_1400032A8, a2);
  }
  else
  {
    v4 = KeAcquireSpinLockRaiseToDpc(&qword_1400032A0);
    v6 = qword_1400032A8;
    v7 = v4;
    if ( (__int64 *)qword_1400032A8 == &qword_1400032A8 )
    {
LABEL_5:
      LOBYTE(v5) = v4;
      return KeReleaseSpinLock(&qword_1400032A0, v5);
    }
    else
    {
      while ( 1 )
      {
        v5 = *(__int64 **)v6;
        if ( v3 == *(_DWORD *)(v6 + 24) )
          break;
        v6 = *(_QWORD *)v6;
        if ( v5 == &qword_1400032A8 )
          goto LABEL_5;
      }
      if ( v5[1] != v6 || (v9 = *(__int64 ***)(v6 + 8), *v9 != (__int64 *)v6) )
        __fastfail(3u);
      *v9 = v5;
      v5[1] = (__int64)v9;
      LOBYTE(v5) = v7;
      KeReleaseSpinLock(&qword_1400032A0, v5);
      ObfDereferenceObject(*(_QWORD *)(v6 + 16));
      return ExFreePoolWithTag(v6, 945115461i64);
    }
  }
  return result;
}
void __fastcall unknown_spin_lock(_QWORD *a1)
{
  _QWORD *v2; // rdi
  _QWORD *v3; // rcx
  char v4; // al
  __int64 v5; // rdx

  if ( a1 )
  {
    while ( 1 )
    {
      v4 = KeAcquireSpinLockRaiseToDpc(&qword_1400032A0);
      if ( (_QWORD *)*a1 == a1 )
        break;
      v2 = (_QWORD *)a1[1];
      if ( (_QWORD *)*v2 != a1 || (v3 = (_QWORD *)v2[1], (_QWORD *)*v3 != v2) )
        __fastfail(3u);
      a1[1] = v3;
      LOBYTE(v5) = v4;
      *v3 = a1;
      KeReleaseSpinLock(&qword_1400032A0, v5);
      ObfDereferenceObject(v2[2]);
      ExFreePoolWithTag(v2, 945115461i64);
    }
    LOBYTE(v5) = v4;
    KeReleaseSpinLock(&qword_1400032A0, v5);
  }
}
char __fastcall spin_lock(_QWORD *a1, __int64 a2)
{
  char v2; // di
  __int64 v6; // rdx
  _QWORD *i; // rax

  v2 = 0;
  if ( !a1 )
    return 0;
  LOBYTE(v6) = KeAcquireSpinLockRaiseToDpc(&qword_1400032A0);
  for ( i = (_QWORD *)*a1; i != a1; i = (_QWORD *)*i )
  {
    if ( i[2] == a2 )
    {
      v2 = 1;
      break;
    }
  }
  KeReleaseSpinLock(&qword_1400032A0, v6);
  return v2;
}