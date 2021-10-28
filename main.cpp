// main.cpp

NTSTATUS real_driver_entry(_QWORD *driver_object, __int64 registry_path) // Decompiler defines it as __int64 __fastcall
{
  int device;
  char exclusive;
  __int64 device_object;

  device_object = 0i64;
  device = get_device(registry_path);
  if ( device >= 0 )
  {
    exclusive = 1;
    device = IoCreateDevice(driver_object, 0i64, &device_name, 34i64, 0, exclusive, &device_object);
    if ( device >= 0 )
    {
      device = IoCreateSymbolicLink(&symbolic_link_name, &device_name);
      if ( device >= 0 )
      {
        driver_object[28] = request;
        driver_object[14] = mj_query_security;
        driver_object[16] = mj_power;
        driver_object[13] = mj_create_mailslot;
        device = load_functions();
        if ( device >= 0 )
          return (unsigned int)device;
        IoDeleteSymbolicLink(&symbolic_link_name);
      }
    }
  }
  init_pool();
  if ( device_object )
    IoDeleteDevice();
  return (unsigned int)device;
}

NTSTATUS DriverEntry(__int64 DriverObject, __int64 RegistryPath) // Decompiler defines it as __int64 __fastcall 
{
  _security_init_cookie();
  return real_driver_entry((_QWORD *)DriverObject, RegistryPath);
}
