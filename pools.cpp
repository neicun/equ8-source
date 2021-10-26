// pools.cpp

__int64 init_pool()
{
  __int64 result; // rax

  if ( device_ptr )
  {
    ExFreePoolWithTag(device_ptr, 945115461i64);
    result = 0i64;
    device_name = 0i64;
    device_ptr = 0i64;
  }
  if ( symbolic_ptr )
  {
    ExFreePoolWithTag(symbolic_ptr, 945115461i64);
    result = 0i64;
    symbolic_link_name = 0i64;
    symbolic_ptr = 0i64;
  }
  return result;
}