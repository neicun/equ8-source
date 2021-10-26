// device.cpp

__int64 __fastcall get_device(__int64 parameter)
{
  _DWORD *PoolWithTag; // rdi
  int decrypted_object; // ebx
  int v3; // eax
  unsigned int v4; // eax
  __int64 v5; // rsi
  unsigned int v6; // edx
  _WORD *v7; // rcx
  unsigned int v8; // er14
  char v10[16]; // [rsp+30h] [rbp-40h] BYREF
  int v11; // [rsp+40h] [rbp-30h] BYREF
  __int64 v12; // [rsp+48h] [rbp-28h]
  __int64 v13; // [rsp+50h] [rbp-20h]
  int v14; // [rsp+58h] [rbp-18h]
  __int128 v15; // [rsp+60h] [rbp-10h]
  unsigned int v16; // [rsp+A0h] [rbp+30h] BYREF
  __int64 v17; // [rsp+A8h] [rbp+38h] BYREF

  v17 = 0i64;
  PoolWithTag = 0i64;
  if ( !parameter || !*(_QWORD *)(parameter + 8) || !*(_WORD *)parameter )
    return 3221225485i64;
  v13 = parameter;
  v11 = 48;
  v12 = 0i64;
  v14 = 576;
  v15 = 0i64;
  decrypted_object = ZwOpenKey(&v17, 983103i64, &v11);
  if ( decrypted_object < 0 )
    goto LABEL_17;
  RtlInitUnicodeString(v10, L"SessionId");
  v3 = ZwQueryValueKey(v17, v10, 1i64, 0i64, 0, &v16);
  decrypted_object = v3;
  if ( v3 == -1073741789 || v3 == -2147483643 )
  {
    PoolWithTag = (_DWORD *)ExAllocatePoolWithTag(1i64, v16, 945115461i64);
    if ( PoolWithTag )
    {
      decrypted_object = ZwQueryValueKey(v17, v10, 1i64, PoolWithTag, v16, &v16);
      if ( decrypted_object < 0 )
      {
LABEL_17:
        init_pool();
        goto LABEL_18;
      }
      if ( PoolWithTag[1] == 1 )
      {
        v4 = 0;
        v5 = (__int64)PoolWithTag + (unsigned int)PoolWithTag[2];
        v6 = PoolWithTag[3] >> 1;
        if ( v6 )
        {
          v7 = (_WORD *)((char *)PoolWithTag + (unsigned int)PoolWithTag[2]);
          do
          {
            if ( !*v7 )
              break;
            ++v4;
            ++v7;
          }
          while ( v4 < v6 );
        }
        v8 = 2 * v4;
        decrypted_object = get_decrypted_object(
                             (__int64)&device_name,
                             (__int64)L"\\Device\\",
                             (__int64)PoolWithTag + (unsigned int)PoolWithTag[2],
                             2 * v4);
        if ( decrypted_object < 0 )
          goto LABEL_17;
        decrypted_object = get_decrypted_object((__int64)&symbolic_link_name, (__int64)L"\\DosDevices\\", v5, v8);
      }
    }
  }
  if ( decrypted_object < 0 )
    goto LABEL_17;
LABEL_18:
  if ( PoolWithTag )
    ExFreePoolWithTag(PoolWithTag, 945115461i64);
  if ( v17 )
    ZwClose();
  return (unsigned int)decrypted_object;
}