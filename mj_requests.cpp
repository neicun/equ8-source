// mj_requests.cpp

__int64 __fastcall mj_power(__int64 a1, __int64 a2)
{
  __int64 v3; // r8
  __int64 v4; // r9

  byte_140003099 = 0;
  unknown_spin_lock(&qword_1400032B8);
  unknown_spin_lock(&qword_1400032A8);
  qword_1400030A8 = 0i64;
  if ( !a2 )
    return 3221225473i64;
  *(_DWORD *)(a2 + 48) = 0;
  *(_QWORD *)(a2 + 56) = 0i64;
  IofCompleteRequest(a2, 0i64, v3, v4);
  return 0i64;
}

__int64 __fastcall mj_query_security(__int64 a1, __int64 a2)
{
  __int64 v2; // rdi
  __int64 v3; // r8
  __int64 v4; // r9
  int v5; // ebx

  v2 = a2;
  LOBYTE(a2) = 1;
  v5 = 0;
  if ( !(unsigned __int8)SeSinglePrivilegeCheck(7i64, a2) )
    v5 = -1073741727;
  if ( !v2 )
    return 3221225473i64;
  if ( v5 >= 0 )
  {
    v5 = get_proc();
    qword_1400030A8 = IoGetCurrentProcess();
    qword_1400030B0 = PsGetProcessId(qword_1400030A8);
  }
  *(_QWORD *)(v2 + 56) = 0i64;
  *(_DWORD *)(v2 + 48) = v5;
  IofCompleteRequest(v2, 0i64, v3, v4);
  return 0i64;
}


__int64 __fastcall mj_create_mailslot(__int64 a1, __int64 a2)
{
  __int64 result; // rax

  if ( byte_140003098 )
  {
    LOBYTE(a2) = 1;
    PsSetCreateProcessNotifyRoutine(load_spin_lock, a2);
    byte_140003098 = 0;
  }
  byte_140003099 = 0;
  unknown_spin_lock(&qword_1400032B8);
  unknown_spin_lock(&qword_1400032A8);
  if ( qword_1400030A0 )
    ((void (*)(void))ob_unregister_callbacks)();
  if ( symbolic_ptr )
    IoDeleteSymbolicLink(&symbolic_link_name);
  result = init_pool();
  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 8) )
      return IoDeleteDevice();
  }
  return result;
}