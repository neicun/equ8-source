// functions.cpp

__int64 load_functions()
{
  __int64 v0; // rbx
  __int64 result; // rax
  __int64 v2; // [rsp+20h] [rbp-59h] BYREF
  int v3; // [rsp+28h] [rbp-51h]
  __int64 (__fastcall *v4)(); // [rsp+30h] [rbp-49h]
  __int64 v5; // [rsp+38h] [rbp-41h]
  __int64 v6; // [rsp+40h] [rbp-39h]
  __int64 v7; // [rsp+48h] [rbp-31h]
  __int64 (__fastcall *v8)(); // [rsp+50h] [rbp-29h]
  __int64 v9; // [rsp+58h] [rbp-21h]
  int v10; // [rsp+60h] [rbp-19h] BYREF
  __int128 _id; // [rsp+68h] [rbp-11h]
  __int64 v12; // [rsp+78h] [rbp-1h]
  __int64 *v13; // [rsp+80h] [rbp+7h]
  char _rtl_format_message[16]; // [rsp+88h] [rbp+Fh] BYREF
  char _ob_register_callbacks[16]; // [rsp+98h] [rbp+1Fh] BYREF
  char _ob_unregister_callbacks[16]; // [rsp+A8h] [rbp+2Fh] BYREF
  __int128 id; // [rsp+B8h] [rbp+3Fh] BYREF

  qword_1400032A0 = 0i64;
  qword_1400030C0 = 0i64;
  dword_1400030C8 = 0;
  qword_1400032B0 = (__int64)&qword_1400032A8;
  qword_1400032A8 = (__int64)&qword_1400032A8;
  qword_1400032C0 = (__int64)&qword_1400032B8;
  qword_1400032B8 = (__int64)&qword_1400032B8;
  dword_1400030B8 = 1;
  KeInitializeEvent(&unk_1400030D0, 1i64, 0i64);
  if ( !(unsigned __int8)resolve(resolving_str, &unk_140002120, 15i64) )
    return 3221225476i64;
  RtlInitUnicodeString(_rtl_format_message, aRtlformatmessa);
  rtl_format_message = (__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD))MmGetSystemRoutineAddress(_rtl_format_message);// fake function, not same argument types, but nice job equ8!
  RtlInitUnicodeString(_ob_register_callbacks, L"ObRegisterCallbacks");
  RtlInitUnicodeString(_ob_unregister_callbacks, L"ObUnRegisterCallbacks");
  ob_register_callbacks = MmGetSystemRoutineAddress(_ob_register_callbacks);
  ob_unregister_callbacks = MmGetSystemRoutineAddress(_ob_unregister_callbacks);
  v0 = ob_unregister_callbacks;
  if ( !(unsigned __int8)resolve(resolving_str, &unk_140002120, 15i64) )
    return 3221225476i64;
  if ( !ob_register_callbacks )
    goto LABEL_6;
  if ( !v0 )
    goto LABEL_6;
  create_value(&v10, 0i64, 40i64);
  create_value(&v2, 0i64, 32i64);
  v6 = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  RtlInitUnicodeString(&id, L"363705");
  v5 = 0i64;
  v9 = 0i64;
  v12 = 0i64;
  v2 = PsProcessType;
  v6 = PsThreadType;
  v13 = &v2;
  v3 = 3;
  v4 = resolve_proc;
  LODWORD(v7) = 3;
  v8 = resolve_proc;
  v10 = 131328;
  _id = id;
  result = ((__int64 (__fastcall *)(int *, __int64 *))ob_register_callbacks)(&v10, &qword_1400030A0);
  if ( (int)result >= 0 )
  {
LABEL_6:
    byte_140003098 = (int)PsSetCreateProcessNotifyRoutine(load_spin_lock, 0i64) >= 0;
    return 0i64;
  }
  return result;
}