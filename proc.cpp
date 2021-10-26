// proc.cpp

__int64 __fastcall resolve_proc(__int64 a1, __int64 a2)
{
  unsigned int v2; // edi
  __int64 v4; // rax
  __int64 v5; // rcx
  __int64 ThreadProcess; // rbp
  char v7; // r12
  int v8; // er14
  _DWORD *v9; // rsi
  int v10; // er15
  __int64 v11; // rdx
  __int64 v12; // rcx
  int ProcessId; // ebp
  int CurrentProcessId; // esi
  char v15; // bl
  __int64 v16; // rdx
  __int64 v17; // r8
  __int64 v18; // r9
  _DWORD *v19; // rax
  char *v20; // rdx

  v2 = 0;
  if ( byte_140003099 )
  {
    if ( a2 )
    {
      if ( *(_QWORD *)(a2 + 8) )
      {
        if ( *(_QWORD *)(a2 + 32) )
        {
          v4 = ((__int64 (*)(void))IoGetCurrentProcess)();
          if ( !(unsigned __int8)spin_lock(&qword_1400032B8, v4) )
          {
            v5 = *(_QWORD *)(a2 + 16);
            if ( v5 == PsProcessType )
            {
              ThreadProcess = *(_QWORD *)(a2 + 8);
              v7 = 2;
              v8 = 1062401;
            }
            else
            {
              if ( v5 != PsThreadType )
                return 0i64;
              v7 = 4;
              v8 = 1051648;
              ThreadProcess = PsGetThreadProcess(*(_QWORD *)(a2 + 8));
            }
            if ( *(_DWORD *)a2 == 1 || *(_DWORD *)a2 == 2 )
            {
              v9 = *(_DWORD **)(a2 + 32);
              v10 = v9[1];
              if ( (qword_1400030A8 != IoGetCurrentProcess(v5, (unsigned int)(*(_DWORD *)a2 - 1)) || *v9 == 8)
                && ThreadProcess != IoGetCurrentProcess(v12, v11) )
              {
                if ( (unsigned __int8)spin_lock(&qword_1400032A8, ThreadProcess) )
                {
                  *v9 &= v8;
                  if ( v10 != *v9 )
                  {
                    ProcessId = PsGetProcessId(ThreadProcess);
                    CurrentProcessId = PsGetCurrentProcessId();
                    v15 = v7 | *(_BYTE *)(a2 + 4) & 1;
                    ExAcquireFastMutex(&dword_1400030B8, v16, v17, v18);
                    if ( (unsigned int)dword_1400030F0 < 0x20 )
                    {
                      if ( dword_1400030F0 )
                      {
                        v19 = &unk_140003108;
                        while ( *(v19 - 1) != CurrentProcessId || *v19 != ProcessId || *((_BYTE *)v19 + 4) != v15 )
                        {
                          ++v2;
                          v19 = (_DWORD *)((char *)v19 + 13);
                          if ( v2 >= dword_1400030F0 )
                            goto LABEL_24;
                        }
                      }
                      else
                      {
LABEL_24:
                        v20 = (char *)&unk_140003100 + 13 * (unsigned int)dword_1400030F0++;
                        *((_DWORD *)v20 + 1) = CurrentProcessId;
                        *((_DWORD *)v20 + 2) = ProcessId;
                        *(_DWORD *)v20 = v10;
                        v20[12] = v15;
                      }
                    }
                    ExReleaseFastMutex(&dword_1400030B8);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0i64;
}
__int64 __fastcall init_proc(__int64 a1, __int64 a2)
{
  __int64 PoolWithTag; // rax
  _QWORD *v5; // rbx
  char v7; // al
  __int64 v8; // rdx
  _QWORD *v9; // rcx

  if ( !a1 || !a2 )
    return 3221225485i64;
  PoolWithTag = ExAllocatePoolWithTag(0i64, 32i64, 945115461i64);
  v5 = (_QWORD *)PoolWithTag;
  if ( !PoolWithTag )
    return 3221225495i64;
  *(_QWORD *)(PoolWithTag + 16) = a2;
  *(_DWORD *)(PoolWithTag + 24) = PsGetProcessId(a2);
  v7 = KeAcquireSpinLockRaiseToDpc(&qword_1400032A0);
  v9 = *(_QWORD **)(a1 + 8);
  if ( *v9 != a1 )
    __fastfail(3u);
  v5[1] = v9;
  LOBYTE(v8) = v7;
  *v5 = a1;
  *v9 = v5;
  *(_QWORD *)(a1 + 8) = v5;
  KeReleaseSpinLock(&qword_1400032A0, v8);
  return 0i64;
}

__int64 __fastcall load_proc(__int64 a1, unsigned int a2)
{
  __int64 result; // rax
  unsigned int v4; // ebx
  __int64 v5; // [rsp+40h] [rbp+18h] BYREF

  v5 = 0i64;
  result = PsLookupProcessByProcessId(a2, &v5);
  if ( (int)result >= 0 )
  {
    v4 = init_proc(a1, v5);
    if ( v4 )
    {
      ObfDereferenceObject(v5);
      return v4;
    }
    else
    {
      return 0i64;
    }
  }
  return result;
}

__int64 __fastcall get_proc(__int64 a1, __int64 a2)
{
  __int64 CurrentProcess; // rbx

  CurrentProcess = IoGetCurrentProcess(a1, a2);
  ObfReferenceObject(CurrentProcess);
  return init_proc((__int64)&qword_1400032A8, CurrentProcess);
}